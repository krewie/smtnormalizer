/* -*- C++ -*-
 *
 * A simple scrambler for SMT-LIB v2 scripts
 * 
 * Author: Alberto Griggio <griggio@fbk.eu>
 *
 * Copyright (C) 2011 Alberto Griggio
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
#include "scrambler.h"
#include <tr1/unordered_map>
#include <tr1/unordered_set>
#include <sstream>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <assert.h>
#include <ctype.h>
#include <sstream>
#include <cmath>
#include <queue>
#include <stdexcept>

#define LESS 1
#define GREATER 3
#define EQUAL 2

namespace scrambler {

namespace {

bool no_scramble = false;
bool scramble_named_annot = false;
bool lift_named_annot = false;
bool debug = false;

typedef std::tr1::unordered_map<std::string, size_t> NameMap_temp;
typedef std::tr1::unordered_map<std::string, std::string> NameMap;
NameMap names;

NameMap var_map;

int name_idx = 1;

std::string make_name(int n)
{
    std::ostringstream tmp;
    tmp << "v" << n;
    return tmp.str();
}

std::vector<int> scopes;

std::vector<node *> commands;

uint64_t seed;
const uint64_t a = 25214903917ULL;
const uint64_t c = 11U;
const uint64_t mask = ~(2ULL << 48);

bool sort_commands = false;


const char *unquote(const char *n)
{
    if (no_scramble || !n[0] || n[0] != '|') {
        return n;
    }
    static std::string buf;
    buf = n;
    assert(!buf.empty());
    if (buf.size() > 1 && buf[0] == '|' && buf[buf.size()-1] == '|') {
        buf = buf.substr(1, buf.size()-2);
    }
    return buf.c_str();
}

size_t next_rand_int(size_t upper_bound)
{
    seed = ((seed * a) + c) & mask;
    return (size_t)(seed >> 16U) % upper_bound;
}

std::string get_name(const char *n)
{
    std::string sn(unquote(n));
    NameMap::iterator it = names.find(sn);
    if (it != names.end()) {
        return it->second;
    } else {
        return sn;
    }
}


int logic_dl = -1;
bool logic_is_dl()
{
    if (logic_dl == -1) {
        if (commands.size() > 0 && commands[0]->symbol == "set-logic") {
            std::string &logic = commands[0]->children[0]->symbol;
            logic_dl = (logic == "QF_IDL" ||
                        logic == "QF_RDL" ||
                        logic == "QF_UFIDL") ? 1 : 0;
        }
    }
    return logic_dl == 1;
}


} // namespace


void set_new_name(const char *n)
{
    n = unquote(n);
    std::string star = "?";
    std::string c = star + n;
    names[n] = c.c_str();
}

void set_new_var(const char *n)
{
    n = unquote(n);
    names[n] = make_name(name_idx++);
}


void push_namespace()
{
    scopes.push_back(name_idx);
}


void pop_namespace()
{
    if (scopes.empty()) {
        std::cerr << "ERROR pop command over an empty stack" << std::endl;
        exit(1);
    }
    name_idx = scopes.back();
    scopes.pop_back();
}


void add_node(const char *s, node *n1, node *n2, node *n3, node *n4)
{
    node *ret = new node;
    ret->symbol = get_name(s);
    ret->needs_parens = true;
    if (n1) {
        ret->children.push_back(n1);
    }
    if (n2) {
        ret->children.push_back(n2);
    }
    if (n3) {
        ret->children.push_back(n3);
    }
    if (n4) {
        ret->children.push_back(n4);
    }
    commands.push_back(ret);
}


node *make_node(const char *s, node *n1, node *n2)
{
    node *ret = new node;
    ret->needs_parens = true;
    if (s) {
        ret->symbol = get_name(s);
    }
    if (n1) {
        ret->children.push_back(n1);
    }
    if (n2) {
        ret->children.push_back(n2);
    }
    if (!ret->symbol.empty() && ret->children.empty()) {
        ret->needs_parens = false;
    }
    return ret;
}


void del_node(node *n)
{
    for (size_t i = 0; i < n->children.size(); ++i) {
        del_node(n->children[i]);
    }
    delete n;
}


void node::add_children(std::vector<node *> *c)
{
    children.insert(children.end(), c->begin(), c->end());
}


node *make_node(std::vector<node *> *v)
{
    node *ret = new node;
    ret->needs_parens = true;
    ret->symbol = "";
    ret->children.assign(v->begin(), v->end());
    return ret;
}


node *make_node(node *n, std::vector<node *> *v)
{
    node *ret = new node;
    ret->needs_parens = true;
    ret->symbol = "";
    ret->children.push_back(n);
    ret->children.insert(ret->children.end(), v->begin(), v->end());
    return ret;
}


void set_seed(int s)
{
    seed = s;
}

const char first(std::string s1)
{
    if(!s1.empty())
    {
        return s1.at(0);
    }
    else
    {
        return *"";
    }
}

int cmp_arg(std::vector<node *> *v1, std::vector<node *> *v2)
{
    size_t ret_val;
    if( (*v1).size() < (*v2).size())
    {
        return LESS;
    }else if( (*v1).size() == (*v2).size())
    {
        for(size_t i = 0; i < (*v1).size(); i++)
        {
            if( (*v1)[i]->symbol.empty() & (*v2)[i]->symbol.empty() )
            {
                ret_val = cmp_arg(&(*v1)[i]->children, &(*v2)[i]->children);
                if(ret_val < EQUAL)
                {
                    return LESS;
                }else if(ret_val > EQUAL)
                {
                    return GREATER;
                }
            }
            else if( (*v1)[i]->symbol > (*v2)[i]->symbol)
            {
                if( first((*v1)[i]->symbol) != '?' || first((*v2)[i]->symbol) != '?' )
                {
                    return GREATER;
                }
            }
            else if( (*v1)[i]->symbol < (*v2)[i]->symbol)
            {
                if( first((*v1)[i]->symbol) != '?' || first((*v2)[i]->symbol) != '?' )
                {
                    return LESS;
                }
            }
        }
        return 2;
    }
}

void order_parens(std::vector<node *> *v, size_t start, size_t end)
{
    for(size_t i = start; i <= end-1; i++)
    {
        for(size_t j = i+1; j <= end-1; j++)
        {
            if( (*v)[i]->needs_parens != 0 & (*v)[j]->needs_parens != 0 )
            {
                if( (*v)[i]->children[0]->symbol > (*v)[j]->children[0]->symbol )
                    std::swap((*v)[i], (*v)[j]);
                if( (*v)[i]->children[0]->symbol == (*v)[j]->children[0]->symbol )
                {
                    if(!(*v)[i]->children[0]->symbol.empty() & !(*v)[j]->children[0]->symbol.empty())
                    {
                       if( (*v)[i]->children.size() < (*v)[j]->children.size())
                            std::swap( (*v)[i], (*v)[j] );
                        else if ((*v)[i]->children.size() == (*v)[j]->children.size())
                        {
                            if(cmp_arg(&(*v)[i]->children, &(*v)[j]->children) == LESS)
                                std::swap( (*v)[i], (*v)[j] );
                        }
                    }
                }
            }
        }
    }
}

/* Sorts "let" binds */       
void sort_binds(std::vector<node *> *v)
{
    for (size_t i = 0; i < (*v).size(); i++) {
        for (size_t j = i+1; j < (*v).size(); j++) {
            if( cmp_arg(&(*v)[i]->children[0]->children, &(*v)[j]->children[0]->children) == 1 )
            {
                std::swap( (*v)[i], (*v)[j] );
            }
        }
    }
}

void order_parens(std::vector<node *> *v)
{
    order_parens(v, 0, v->size());
}


bool is_commutative(node *n)
{
    std::string *curs = &(n->symbol);
    if (curs->empty() && !n->children.empty()) {
        curs = &(n->children[0]->symbol);
    }
    std::string &s = *curs;
    if (s == "and" || s == "or" || s == "xor" || s == "distinct") {
        return true;
    }
    if (!logic_is_dl()) {
        if (s == "*" || s == "+" || s == "=") {
            return true;
        }
        if (s == "bvand" || s == "bvor" || s == "bvxor" ||
            s == "bvnand" || s == "bvnor" || s == "bvcomp" ||
            s == "bvadd" || s == "bvmul") {
            return true;
        }
    }
    return false;
}


bool flip_antisymm(node *n, node **out_n)
{
    std::string *curs = &(n->symbol);
    if (curs->empty() && !n->children.empty()) {
        curs = &(n->children[0]->symbol);
    }
    std::string &s = *curs;
    if (!logic_is_dl()) {
        if (s == "<") {
            *out_n = make_node(">");
            return true;
        } 
        else if (s == "<=") {
            *out_n = make_node(">=");
            return true;
        } 
        else if (s == "bvslt") {
            *out_n = make_node("bvsgt");
            return true;
        } else if (s == "bvsle") {
            *out_n = make_node("bvsge");
            return true;
        } else if (s == "bvult") {
            *out_n = make_node("bvugt");
            return true;
        } else if (s == "bvule") {
            *out_n = make_node("bvuge");
            return true;
        } 
    }
    return false;
}


namespace {

std::string make_annot_name(int n)
{
    std::ostringstream tmp;
    tmp << "y" << n;
    return tmp.str();
}

void set_named_annot(node *n)
{
    NameMap::iterator it = names.find(n->symbol);
    if (it != names.end()) {
        n->symbol = it->second;
    } else {
        std::string nn = make_annot_name(name_idx++);
        names[n->symbol] = nn;
        n->symbol = nn;
    }
}


bool is_named_annot(node *n, node **out=NULL)
{
    if (n->symbol == "!" && n->children.size() >= 2) {
        for (size_t j = 1; j < n->children.size(); ++j) {
            node *attr = n->children[j];
            if (attr->symbol == ":named" &&
                !attr->children.empty()) {
                if (out) {
                    *out = attr;
                }
                return true;
            }
        }
    }
    return false;
}


typedef std::tr1::unordered_set<std::string> StringSet;

std::string get_named_annot(node *root)
{
    std::vector<node *> to_process;
    std::tr1::unordered_set<node *> seen;

    to_process.push_back(root);
    while (!to_process.empty()) {
        node *cur = to_process.back();
        to_process.pop_back();

        if (!seen.insert(cur).second) {
            continue;
        }
        if (cur->symbol == "!") {
            if (cur->children.size() >= 1) {
                to_process.push_back(cur->children[0]);
            }
            if (cur->children.size() >= 2) {
                for (size_t j = 1; j < cur->children.size(); ++j) {
                    node *attr = cur->children[j];
                    if (attr->symbol == ":named" &&
                        !attr->children.empty()) {
                        return attr->children[0]->symbol;
                    }
                }
            }
        } else {
            for (size_t j = 0; j < cur->children.size(); ++j) {
                to_process.push_back(cur->children[j]);
            }
        }
    }

    return "";
}

/* Temporary debug function, should be removed later... */

void print_node_best(NameMap *v, std::ostream &out, node *n, bool keep_annontations)
{
    if (!no_scramble && !keep_annontations && n->symbol == "!") {
        print_node_best(v, out, n->children[0], keep_annontations);
    } else {
        std::string name;
        if (lift_named_annot && keep_annontations) {
            node *annot = NULL;
            if (n->symbol == "assert") {
                name = get_named_annot(n);
                if (!name.empty()) {
                    if (scramble_named_annot) {
                        NameMap::iterator it = names.find(name);
                        if (it != names.end()) {
                            name = it->second;
                        } else {
                            std::string nn = make_annot_name(name_idx++);
                            names[name] = nn;
                            name = nn;
                        }
                    }
                }
            } else if (is_named_annot(n, &annot)) {
                if (n->children.size() == 2) {
                    n = n->children[0];
                } else {
                    n->children.erase(
                        std::find(n->children.begin(), n->children.end(),
                                  annot));
                    del_node(annot);
                }
            }
        }
        if (n->needs_parens) {
            out << '(';
        }
        if (!n->symbol.empty()) {
            if(keep_annontations)
            {
            out << n->symbol;
            }
            else{
            if( first(n->symbol) == '?' )
            {
                out << (*v)[n->symbol];
            }else
            {
                out << n->symbol;
            }
        }
        }
        if (!name.empty()) {
            out << " (!";
        }
        if (scramble_named_annot && keep_annontations) {
            node *annot;
            if (is_named_annot(n, &annot)) {
                set_named_annot(annot->children[0]);
            }
        }
        for (size_t i = 0; i < n->children.size(); ++i) {
            if (i > 0 || !n->symbol.empty()) {
                out << ' ';
            }
            print_node_best(v, out, n->children[i], keep_annontations);
        }
        if (!name.empty()) {
            out << " :named " << name << ")";
        }
        if (n->needs_parens) {
            out << ')';
        }
    }
}


void print_node(std::ostream &out, node *n, bool keep_annontations)
{
    if (!no_scramble && !keep_annontations && n->symbol == "!") {
        print_node(out, n->children[0], keep_annontations);
    } else {
        std::string name;
        if (lift_named_annot && keep_annontations) {
            node *annot = NULL;
            if (n->symbol == "assert") {
                name = get_named_annot(n);
                if (!name.empty()) {
                    if (scramble_named_annot) {
                        NameMap::iterator it = names.find(name);
                        if (it != names.end()) {
                            name = it->second;
                        } else {
                            std::string nn = make_annot_name(name_idx++);
                            names[name] = nn;
                            name = nn;
                        }
                    }
                }
            } else if (is_named_annot(n, &annot)) {
                if (n->children.size() == 2) {
                    n = n->children[0];
                } else {
                    n->children.erase(
                        std::find(n->children.begin(), n->children.end(),
                                  annot));
                    del_node(annot);
                }
            }
        }
        if (n->needs_parens) {
            out << '(';
        }
        if (!n->symbol.empty()) {
            if(keep_annontations)
            {
                out << n->symbol;
            }
            else
            {
                if( first(n->symbol) == '?' )
                {
                    out << n->symbol;
                }
                else
                {
                    out << n->symbol;
                }
            }
        }
        if (!name.empty()) {
            out << " (!";
        }
        if (scramble_named_annot && keep_annontations) {
            node *annot;
            if (is_named_annot(n, &annot)) {
                set_named_annot(annot->children[0]);
            }
        }
        for (size_t i = 0; i < n->children.size(); ++i) {
            if (i > 0 || !n->symbol.empty()) {
                out << ' ';
            }
            print_node(out, n->children[i], keep_annontations);
        }
        if (!name.empty()) {
            out << " :named " << name << ")";
        }
        if (n->needs_parens) {
            out << ')';
        }
    }
}

void print_command(std::ostream &out, node *n, bool keep_annontations)
{
    print_node(out, n, keep_annontations);
    out << std::endl;
}

std::tr1::unordered_map<std::string, int> sort_priorities;
void init_sort_priorities()
{
    sort_priorities["set-info"] = -1;
    sort_priorities["set-logic"] = 1;
    sort_priorities["declare-sort"] = 2;
    sort_priorities["define-sort"] = 3;
    sort_priorities["declare-fun"] = 4;
    sort_priorities["define-sort"] = 5;
    sort_priorities["define-fun"] = 6;
    sort_priorities["assert"] = 7;
    sort_priorities["check-sat"] = 8;
    sort_priorities["get-unsat-core"] = 9;
    sort_priorities["exit"] = 10;
}

bool commands_lt(node *a, node *b)
{
    if (a == b) {
        return false;
    }
    int pa = sort_priorities[a->symbol];
    int pb = sort_priorities[b->symbol];

    assert(pa != 0);
    assert(pb != 0);

    return pa < pb;
}

void sort_command_list()
{
    if (sort_commands) {
        init_sort_priorities();
        std::stable_sort(commands.begin(), commands.end(), commands_lt);
    }
}

void node_mute(node *n, NameMap *q)
{
    if (!n->symbol.empty()) {
        if( first(n->symbol) == '?' )
        {
            (*q)[n->symbol] = "_";
        }
    }
    for (size_t i = 0; i < n->children.size(); ++i) {
        node_mute(n->children[i], q);
    }
}

void extend(NameMap *v, node *n)
{
    size_t counter;
    counter = stoi((*v)["max-key"]);
    if (!n->symbol.empty()) {
        if( first(n->symbol) == '?' )
        {
            if((*v)[n->symbol].compare("_") == 0)
            {
                if ( (*v).find((*v)[n->symbol]) == (*v).end() ) {
                    (*v)[n->symbol] = make_name(counter++);
                    //update max-key value
                    if( (*v).find("max-key") == (*v).end() || stoi((*v)["max-key"]) < counter )
                    {
                        (*v)["max-key"] = std::to_string(counter);
                    }
                }
            }
        }
    }
    for (size_t i = 0; i < n->children.size(); ++i) {
                extend(v, n->children[i]);
    }
}

/* Initializes v with input variables as keys and '_' as value */
void init_map(std::vector<node *> *cmds, NameMap *v)
{
    for ( auto &val : *cmds) 
    {
        if(val->symbol == "assert")
        {
            for(size_t j = 0; j < val->children.size(); j++)
            {
                node_mute(val->children[j], v);
            }
        }
    }
    (*v)["max-key"] = "0";
}

NameMap cpyMap(NameMap V)
{
    NameMap copy_;
    copy_.insert(V.begin(), V.end());
    return copy_;
}

void rollback_map(NameMap *v, std::string prev_max_key)
{
    for(NameMap::iterator iterator = (*v).begin(); iterator != (*v).end(); iterator++) 
    {
        if(iterator->first != "max-key" && iterator->second != "_")
        {   /* Comparing integer value of output variables */
            if(std::stoi((iterator->second).substr(1, std::string::npos)) >= std::stoi(prev_max_key))
                iterator->second = "_";
        }
    }
    (*v)["max-key"] = prev_max_key;
}

/* 
Forward declaration..
*/
int vec_node_order(NameMap *v, NameMap *b, std::vector<node *> v1, std::vector<node *> v2);
int node_order(NameMap *v, NameMap *b, node *n1, node *n2)
{
    std::string sym1, sym2;
    if(n1->symbol.empty() && !n2->symbol.empty())
    {
        return GREATER;
    }else if(!n1->symbol.empty() && n2->symbol.empty())
    {
        return LESS;
    }else if(!n1->symbol.empty() && !n2->symbol.empty())
    {
        /* Handling variable symbols */
        sym1 = ((*v).find(n1->symbol) == (*v).end()) ? n1->symbol : (*v)[n1->symbol];
        sym2 = ((*b).find(n2->symbol) == (*b).end()) ? n2->symbol : (*b)[n2->symbol];
        if(sym1 < sym2)
        {
            if(sym1.compare("_") == 0) /* Handeling term order */
                return GREATER;
            else
                return LESS;
        }
        else if(sym1 > sym2)
        {
            if(sym2.compare("_") == 0)
                return LESS;
            else
                return GREATER;
        }
    }
    switch(vec_node_order(v, b, n1->children, n2->children))
    {
    case LESS: return LESS; 
    break;
    case GREATER: return GREATER;
    break;
    case EQUAL: return EQUAL;
    }
}

struct Comparator {
    NameMap paramA;
    Comparator(NameMap paramA) { this->paramA = paramA; }
    /*
    Returns
    GREATER : true
    Less / EQUAL : false
    */
    bool operator () (node *n1, node *n2) {
        return (node_order(&paramA, &paramA, n1, n2) <= EQUAL) ? false : true;
    }
};

std::vector<node *> sort_command_vector(std::vector<node *> *cmds, NameMap *v)
{
    std::sort((*cmds).begin(), (*cmds).end(), Comparator(*v));
    return *cmds;
}


/*
Deletes element at index, sorts the list after.
*/
std::vector<node *> delnode(std::vector<node *> v, node* index, NameMap *m)
{
    std::vector<node *> new_(v);
    new_.erase(std::remove(new_.begin(), new_.end(), index), new_.end());
    sort_command_vector(&new_ , m);
    return new_;
}

                                            /*partial*/                   /*best*/
int vec_node_order(NameMap *v, NameMap *b, std::vector<node *> v1, std::vector<node *> v2)
{
    size_t lenv1 = v1.size(), lenv2 = v2.size();
    //l = (lenv1 < lenv2) ? lenv1 : lenv2;
    
    if(lenv1 < lenv2)
    {
        return LESS;
    }
    else if(lenv1 > lenv2)
    {
        return GREATER;
    }

    for(size_t i = 0; i < lenv1; i++)
    {
        switch(node_order(v, b, v1[i], v2[i]))
        {
            case LESS: return LESS;
            break;
            case GREATER: return GREATER;
            break;
            case EQUAL: continue;
        }
    }
    return EQUAL;
}

/*Copy v1 onto v2*/
void cpy_vector(std::vector<node *> *v1, std::vector<node *> *v2)
{
    for(size_t i = 0; i < (*v1).size(); i++)
    {
        (*v2).push_back((*v1).at(i));
    }
}

void normalize_aux(NameMap v, NameMap *best_map, std::vector<node *> *best, 
                    std::vector<node *> *partial, std::vector<node *> cmds)
{
    std::string prev_max_key;
    //For every command in cmds vector
    for ( auto &val : cmds) {
        if(val->symbol == "assert")
        {
            prev_max_key = v["max-key"];
            //extend(&v, val->children[0]);
            extend(&v, val);
            (*partial).push_back(val);
            if((!(*best).empty()) &&  vec_node_order(&v, best_map, *partial, *best) == GREATER)
            {
                (*partial).erase(std::remove((*partial).begin(), (*partial).end(), val), (*partial).end());
                rollback_map(&v, prev_max_key);
                continue;
            }
            if(cmds.size() == 1)
            {
                (*best).clear();
                cpy_vector(partial, best);
                (*best_map).clear();
                (*best_map).insert(v.begin(), v.end());
                (*partial).erase(std::remove((*partial).begin(), (*partial).end(), val), (*partial).end());     
            }
            else
            {
                normalize_aux(cpyMap(v), best_map, best, partial, delnode((cmds), val, &v));
                (*partial).erase(std::remove((*partial).begin(), (*partial).end(), val), (*partial).end());
                rollback_map(&v, prev_max_key);
            }
        }
    }
}

void normalize(std::vector<node *> *cmds, size_t assert_count)
{
    NameMap v, v_best;
    std::vector<node *> best, partial;

    init_map(cmds, &v);    
    sort_command_vector(cmds, &v);
    normalize_aux(v, &v_best, &best, &partial, *cmds);
    
    for(NameMap::const_iterator it = (v_best).begin(); it != (v_best).end(); ++it)
    {
        std::cout << it->first << " " << it->second << "\n";
    }
    std::cout << "-----\n";
                
    if((best).empty())
    {
        std::cout << "NO RESULT\n";
    }else
    {
        std::cout << "RESULT : \n"; 
        for (size_t i = 0; i < best.size(); ++i) {
            print_node_best(&v_best, std::cout, best[i], false);
            std::cout << "\n";
        }
        std::cout << "---\n";
    }
    //print_best / print script
}

void print_scrambled(std::ostream &out, bool keep_annotations)
{
    sort_command_list();
    size_t assert_count = 0;
    // identify consecutive declarations and shuffle them
    for (size_t i = 0; i < commands.size(); ) {
        if (commands[i]->symbol == "declare-fun") {
            size_t j = i+1;
            while (j < commands.size() &&
                   commands[j]->symbol == "declare-fun") {
                ++j;
            }
            if (j - i > 1) {
                //Sort on defs
            }
            i = j;
        } else {
            ++i;
        }
    }

    // identify consecutive assertions and shuffle them
    for (size_t i = 0; i < commands.size(); ) {
        if (commands[i]->symbol == "assert") {
            size_t j = i+1;
            while (j < commands.size() && commands[j]->symbol == "assert"){
                ++j;
            }
            if (j - i > 1) {
                //normalize(&commands, i , j);
                assert_count += j-i;        
            }
            i = j;
        } else {
            ++i;
        }
    }    

    /* Temporary - will be removed, removes everything except assert expressions */
    for(std::vector<node *>::iterator it2 = commands.begin(); it2 != commands.end();)
    {
       if((*it2)->symbol != "assert")
       {
          it2 = commands.erase(it2); 
       }
       else
       {
          ++it2;
       }
    }

    normalize(&commands, assert_count);

    for (size_t i = 0; i < commands.size(); ++i) {
        //print_command(out, commands[i], keep_annotations);
        del_node(commands[i]);
    }
    commands.clear();
}

void print_unfolded(const std::string &unfold_pattern, bool keep_annotations,
                    int unfold_start, int unfold_end)
{
    // unfold the incremental benchmark into a list of individual benchmarks
    size_t num_queries = 0;
    for (size_t i = 0; i < commands.size(); ++i) {
        if (commands[i]->symbol == "check-sat") {
            ++num_queries;
        }
    }
    std::cout << "Unfolding " << num_queries
              << " queries into individual scripts..." << std::endl;
    std::vector<int> idx;
    std::ostringstream tmpname;
    tmpname << num_queries;
    size_t w = tmpname.str().length();
    for (size_t i = 1; i <= num_queries; ++i) {
        if (unfold_start >= 0 && i < unfold_start) {
            continue;
        }
        if (unfold_end >= 0 && i > unfold_end) {
            continue;
        }
        
        idx.clear();
        tmpname.str("");
        tmpname << unfold_pattern << "."
                << std::setfill('0') << std::setw(w) << i << ".smt2";
        std::string fn = tmpname.str();

        // print out all the commands in the scope of the current query
        for (size_t j = 0, n = 0; j < commands.size(); ++j) {
            if (commands[j]->symbol == "check-sat") {
                ++n;
                if (n == i) {
                    idx.push_back(j);
                    std::ofstream out(fn.c_str());
                    for (size_t k = 0; k < idx.size(); ++k) {
                        if (idx[k] >= 0) {
                            print_command(out, commands[idx[k]],
                                          keep_annotations);
                        }
                    }
                    std::cout << "Written " << fn << std::endl;
                    break; // process next query
                }
            } else {                    
                if (commands[j]->symbol == "push") {
                    int howmany =
                        atoi(commands[j]->children[0]->symbol.c_str());
                    while (howmany-- > 0) {
                        idx.push_back(-1);
                    }
                } else if (commands[j]->symbol == "pop") {
                    int howmany =
                        atoi(commands[j]->children[0]->symbol.c_str());
                    while (howmany-- > 0) {
                        while (!idx.empty()) {
                            int n = idx.back();
                            idx.pop_back();
                            if (n == -1) {
                                break;
                            }
                        }
                    }
                } else {
                    idx.push_back(j);
                }
            }
        }
    }    
}


void usage(const char *program)
{
    std::cout << "Syntax: " << program << " [options] < input_file.smt2\n"
              << "where options are:\n"
              << "  -term_annot [true|false]\n"
              << "  -seed n (if 0, no scrambling is performed)\n"
              << "  -unfold PATTERN\n"
              << "  -unfold_start N\n"
              << "  -unfold_end N\n"
              << "  -core NAMES_FILE\n"
              << "  -scramble_named_annot [true|false]\n"
              << "  -lift_named_annot [true|false]\n";
    std::cout.flush();
    exit(1);
}


void filter_named(const StringSet &to_keep)
{
    size_t i, k;
    for (i = k = 0; i < commands.size(); ++i) {
        node *cur = commands[i];
        bool keep = true;
        if (cur->symbol == "assert") {
            std::string name = get_named_annot(cur);
            // if (!name.empty()) {
            //     std::cout << ";; found name: " << name << std::endl;
            // }
            if (!name.empty() && to_keep.find(name) == to_keep.end()) {
                // std::cout << ";;  removing name: " << name << std::endl;
                keep = false;
            }
        }
        if (keep) {
            commands[k++] = cur;
        }
    }
    commands.resize(k);
}


bool parse_names(std::istream &src, StringSet &out)
{
    std::string name;
    src >> name;
    if (!src || name != "unsat") {
        return false;
    }
    // skip chars until a '(' is found
    char c;
    while (src.get(c) && c != '(') {
        if (!isspace(c)) {
            return false;
        }
    }
    if (!src) {
        return false;
    }
    bool done = false;
    while (src && !done) {
        src >> name;
        if (name.empty()) {
            return false;
        }
        if (name[name.size()-1] == ')') {
            name = name.substr(0, name.size()-1);
            done = true;
        }
        if (!name.empty()) {
            out.insert(name);
        }
    }

    std::vector<std::string> outnames(out.begin(), out.end());
    std::sort(outnames.begin(), outnames.end());
    
    std::cout << ";; parsed " << outnames.size() << " names:";
    for (size_t i = 0; i < outnames.size(); ++i) {
        std::cout << " " << outnames[i];
    }
    std::cout << std::endl;

    return true;
}

} // namespace

} // namespace scrambler

char *c_strdup(const char *s)
{
    char *ret = (char *)malloc(strlen(s) + 1);
    strcpy(ret, s);
    return ret;
}

extern int yyparse();

using namespace scrambler;

int main(int argc, char **argv)
{
    bool keep_annotations = true;
    bool unfold = false;
    std::string unfold_pattern;
    int unfold_start = -1;
    int unfold_end = -1;
    bool create_core = false;
    std::string core_file;
    
    set_seed(time(0));

    for (int i = 1; i < argc; ) {
        if (strcmp(argv[i], "-seed") == 0 && i+1 < argc) {
            std::istringstream s(argv[i+1]);
            int x;
            if (s >> x && x >= 0) {
                if (x > 0) {
                    set_seed(x);
                } else {
                    no_scramble = true;
                }
            } else {
                std::cerr << "Invalid value for -seed: " << argv[i+1]
                          << std::endl;
                return 1;
            }
            i += 2;
        } else if (strcmp(argv[i], "-term_annot") == 0 && i+1 < argc) {
            if (strcmp(argv[i+1], "true") == 0) {
                keep_annotations = 1;
            } else if (strcmp(argv[i+1], "false") == 0) {
                keep_annotations = 0;
            } else {
                usage(argv[0]);
            }
            i += 2;
        } else if (strcmp(argv[i], "-unfold") == 0 && i+1 < argc) {
            unfold_pattern = argv[i+1];
            unfold = true;
            i += 2;
        } else if (strcmp(argv[i], "-unfold_start") == 0 && i+1 < argc) {
            std::istringstream s(argv[i+1]);
            int x;
            if (s >> x && x >= 0) {
                unfold_start = x;
            } else {
                usage(argv[0]);
            }
            i += 2;
        } else if (strcmp(argv[i], "-unfold_end") == 0 && i+1 < argc) {
            std::istringstream s(argv[i+1]);
            int x;
            if (s >> x && x >= 0) {
                unfold_end = x;
            } else {
                usage(argv[0]);
            }
            i += 2;
        } else if (strcmp(argv[i], "-sort") == 0) {
            sort_commands = true;
            ++i;
        } else if (strcmp(argv[i], "-core") == 0 && i+1 < argc) {
            create_core = true;
            core_file = argv[i+1];
            i += 2;
        } else if (strcmp(argv[i], "-scramble_named_annot") == 0 && i+1 < argc){
            if (strcmp(argv[i+1], "true") == 0) {
                scramble_named_annot = true;
            } else if (strcmp(argv[i+1], "false") == 0) {
                scramble_named_annot = false;
            } else {
                usage(argv[0]);
            }
            i += 2;
        } else if (strcmp(argv[i], "-lift_named_annot") == 0 && i+1 < argc) {
            if (strcmp(argv[i+1], "true") == 0) {
                lift_named_annot = true;
            } else if (strcmp(argv[i+1], "false") == 0) {
                lift_named_annot = false;
            } else {
                usage(argv[0]);
            }
            i += 2;            
        } else {
            usage(argv[0]);
        }
    }

    StringSet names;
    if (create_core) {
        std::ifstream src(core_file.c_str());
        if (!parse_names(src, names)) {
            std::cout << "ERROR in parsing core names from " << core_file
                      << std::endl;
            return 1;
        }
    }
    
    while (!std::cin.eof()) {
        yyparse();
        if (!unfold) {
            if (!commands.empty() && commands.back()->symbol == "check-sat") {
                if (create_core) {
                    filter_named(names);
                }
                print_scrambled(std::cout, keep_annotations);
            }
        }
    }

    if (create_core) {
        filter_named(names);
    }
    
    if (!unfold) {
        if (!commands.empty()) {
            print_scrambled(std::cout, keep_annotations);
        }
    } else {
        print_unfolded(unfold_pattern, keep_annotations,
                       unfold_start, unfold_end);
    }
    
    return 0;
}
