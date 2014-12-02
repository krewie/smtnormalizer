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

    //if (no_scramble) {
        names[n] = c.c_str();
    /*
    } else {
        names[n] = make_name(name_idx++); //name_idx++
    }
    */
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

void sort_priority_list(std::vector<node *> *v, size_t start, size_t end)
{
    if(!no_scramble)
    {
        for(size_t i = start; i <= end-1; i++)
        {
            for(size_t j = i+1; j <= end-1; j++)
            {
                if(strcmp((*v)[i]->symbol.c_str(), (*v)[j]->symbol.c_str()) > 0)
                {
                    
                    if( first((*v)[i]->symbol) != '?' || first((*v)[j]->symbol) != '?' )
                    {
                    std::swap( (*v)[i], (*v)[j] );
                    }
                }
            }
        }
    }
}


size_t cmp_arg_val(NameMap_temp *m, std::vector<node *> *v)
{
    size_t nr_of_arg = 0;
    for(size_t i = 0; i < (*v).size(); i++)
    {
        if((*v)[i]->symbol.empty())
        {
            nr_of_arg += cmp_arg_val(m, &(*v)[i]->children);
        }else
        {
            if(first((*v)[i]->symbol) == '?')
            {
                if ( (*m).find((*v)[i]->symbol.c_str()) == (*m).end() ) {
                  (*m)[(*v)[i]->symbol.c_str()] = 1;
                } else {
                  (*m)[(*v)[i]->symbol.c_str()] += 1;
                }
                nr_of_arg++;
            }
        }
    }
    return nr_of_arg;
}


int cmp_arg(std::vector<node *> *v1, std::vector<node *> *v2)
{
    size_t ret_val;
    if( (*v2).size() > (*v1).size() )
    {
        return 1;
    }else if( (*v1).size() == (*v2).size())
    {
        for(size_t i = 0; i < (*v1).size(); i++)
        {
            if( (*v1)[i]->symbol.empty() & (*v2)[i]->symbol.empty() )
            {
                ret_val = cmp_arg(&(*v1)[i]->children, &(*v2)[i]->children);
                if(ret_val < 2)
                {
                    return 1;
                }else if(ret_val > 2)
                {
                    return 3;
                }
            }
            else if(strcmp( (*v1)[i]->symbol.c_str(), (*v2)[i]->symbol.c_str()) > 0)
            {
                if( first((*v1)[i]->symbol) != '?' || first((*v2)[i]->symbol) != '?' )
                {
                    return 1;
                }
            }
            else if(strcmp( (*v1)[i]->symbol.c_str(), (*v2)[i]->symbol.c_str()) < 0)
            {
                if( first((*v1)[i]->symbol) != '?' || first((*v2)[i]->symbol) != '?' )
                {
                    return 3;
                }
            }
        }
        return 2;
    }
}

void order_parens(std::vector<node *> *v, size_t start, size_t end)
{
    if(!no_scramble)
    {
        for(size_t i = start; i <= end-1; i++)
        {
            for(size_t j = i+1; j <= end-1; j++)
            {
                if( (*v)[i]->needs_parens != 0 & (*v)[j]->needs_parens != 0 )
                {
                    if(strcmp((*v)[i]->children[0]->symbol.c_str(), (*v)[j]->children[0]->symbol.c_str()) > 0)
                    {
                        std::swap( (*v)[i], (*v)[j] );
                    }
                    if(strcmp((*v)[i]->children[0]->symbol.c_str(), (*v)[j]->children[0]->symbol.c_str()) == 0)
                    {
                        if(!(*v)[i]->children[0]->symbol.empty() & !(*v)[j]->children[0]->symbol.empty() )
                        {
                           if( (*v)[i]->children.size() < (*v)[j]->children.size() )
                            {
                                std::swap( (*v)[i], (*v)[j] );
                            }
                            else if ((*v)[i]->children.size() == (*v)[j]->children.size())
                            {
                                if(cmp_arg(&(*v)[i]->children, &(*v)[j]->children) == 1)
                                {
                                    std::swap( (*v)[i], (*v)[j] );
                                }    
                            }
                        }
                    }
                }
            }
        }
    }
}

bool map_compare (NameMap const &lhs, NameMap const &rhs) {
    // No predicate needed because there is operator== for pairs already.
    return lhs.size() == rhs.size()
        && std::equal(lhs.begin(), lhs.end(),
                      rhs.begin());
}

void sort_by_occurance(std::vector<node *> *v, size_t start, size_t end)
{
    NameMap_temp map1, map2;
    size_t len1, len2, occur1, occur2;
    for (size_t i = start; i <= end-1; i++) {
        for(size_t j = i+1; j <= end; j++) {
            if(cmp_arg(&(*v)[i]->children, &(*v)[j]->children) == 2)
            {        
                len1 = cmp_arg_val(&map1, &(*v)[i]->children);
                len2 = cmp_arg_val(&map2, &(*v)[j]->children);
                occur1 = map1.size();
                occur2 = map2.size();
                if(occur1 != occur2 && len1 == len2)
                {
                    if(occur2 < occur1)
                    {
                        std::swap( (*v)[i], (*v)[j] );
                        //std::cout << "swap i : " << i << " j : " << j << "\n";
                    }
                }
                map1.clear();
                map2.clear();

            }
        }
    }
} 

void sort_asserts_and_def(std::vector<node *> *v, size_t start, size_t end)
{
    /* Sort so that lets / forall / exists are partitioned within the vector*/
    for (size_t i = start; i < end; i++) {
        for (size_t j = i+1; j < end; j++) {
            if(cmp_arg(&(*v)[i]->children, &(*v)[j]->children) == 1)
            {
                std::swap( (*v)[i], (*v)[j] );
            }
        }
    }
    
    for (size_t i = start; i < end; i++) {
        for (size_t j = i+1; j < end; j++) {
            if( (*v)[i]->children[0]->symbol == "let" and (*v)[j]->children[0]->symbol == "let")
            {
                if(cmp_arg(&(*v)[i]->children[0]->children[0]->children, &(*v)[j]->children[0]->children[0]->children) == 1)
                {
                    std::swap( (*v)[i], (*v)[j] );
                }
                else if(cmp_arg(&(*v)[i]->children[0]->children[0]->children, &(*v)[j]->children[0]->children[0]->children) == 2)
                {
                    if(cmp_arg(&(*v)[i]->children[0]->children[1]->children, &(*v)[j]->children[0]->children[1]->children) == 1)
                    {
                        std::swap( (*v)[i], (*v)[j] );
                    }
                }
            }
        }
    }
    sort_by_occurance(v, start, end);
    
}
        
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


/* Actually sort list */
void shuffle_list(std::vector<node *> *v, size_t start, size_t end)
{
    if (!no_scramble) {
        sort_priority_list(v, start, end);
        order_parens(v, start, end);
    }
}

void print_list(std::vector<node *> *v)
{
    for(std::vector<node *>::const_iterator it = v->begin(); it != v->end(); ++it)
    {
        std::cout << "Symbol : " << (*it)->symbol << " Need parens: " << "\n";
        if( ((*it)->children).size() != 0)
            print_list( &((*it)->children) );
        std::cout << "===\n";
    }
}

void shuffle_list(std::vector<node *> *v)
{
    shuffle_list(v, 0, v->size());
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
    if (no_scramble) {
        return false;
    }
    
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
            else{
            if( first(n->symbol) == '?' )
            {
                out << n->symbol;
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

void node_vars(node *n, NameMap *q, size_t &counter)
{
    if (!n->symbol.empty()) {
        if( first(n->symbol) == '?' )
        {
            counter++;
            if ( (*q).find(make_name(counter)) == (*q).end() ) {
                (*q)[make_name(counter)] = n->symbol;
            }
        }
    }
    for (size_t i = 0; i < n->children.size(); ++i) {
                node_vars(n->children[i], q, counter);
    }
}

size_t factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

void fill_varq_n(node *n, std::queue<std::string> &q)
{
    if (!n->symbol.empty()) {
        if( first(n->symbol) == '?' )
        {
            q.push(n->symbol);
        }
    }
    for(int i = 0; i < n->children.size(); i++)
    {
        fill_varq_n( n->children[i], q );
    }
}

void fill_varq(std::vector<node *> *cmds, std::queue<std::string> &q, size_t start, size_t end)
{
    for(int i = start; i < end; i++)
    {
        fill_varq_n((*cmds)[i], q);
    }
}

void node_rename(node *n, NameMap *q, size_t &counter)
{
    if (!n->symbol.empty()) {
        if( first(n->symbol) == '?' )
        {
            if((*q)[n->symbol].compare("_") == 0)
            {
                (*q)[n->symbol] = make_name(counter++);
            }
        }
    }
    for (size_t i = 0; i < n->children.size(); ++i) {
                node_rename(n->children[i], q, counter);
    }
}

size_t node_count_fac(node *n)
{
    size_t fac = 0;
    if(n->permutes == true)
    {
        fac += n->permutations;
    }
    for (size_t i = 0; i < n->children.size(); i++) {
        fac += node_count_fac(n->children[i]);
    }
    return fac;
}


void reset_children(node *n)
{
    if(n->children.size() > 1)
    {
        n->permutes = true;
        n->perm_rounds = factorial(n->children.size()-1);
        n->finished = false;
    }
    for (size_t i = 0; i < n->children.size(); ++i) {
                reset_children(n->children[i]);
    }
}

/*Permute elements in */
/*skip denotes how many of the first elements that should not permute*/
void permute(std::vector<node *> *children, int k, int skip){
    int i;

    if (k==0)
        ;
    else{
        for (i=k-1;i>=skip;i--){
            std::swap( (*children)[i],(*children)[k-1]);
            permute(children, k-1, skip);
        }
    }
}

int permute_statement(node *n)
{
    int ret_val = 0;
    for(int i = 0; i < n->children.size(); i++)
    {
        if(n->children[i]->children.size() > 0)
        {
            ret_val = permute_statement( n->children[i] );
            if( ret_val == 1)
            {
                return 1;
            }else if( ret_val == 2)
            {
                reset_children(n->children[i]);
            }
        }
    }
    if(n->permutes == 1 && n->finished != 1)
    {
        //std::cout << "här : " << n->children[0]->symbol << "\n";
        permute(&n->children, n->children.size(), 1);
        n->perm_rounds -= 1;
        if(n->perm_rounds == 0)
        {
            n->finished = true;
        }
        if(n->finished == true)
        {
            return 2;
        }else{
            return 1;
        }
    }
}

void print_command(std::ostream &out, node *n, bool keep_annontations)
{
    print_node(out, n, keep_annontations);
    out << std::endl;
}


void permute_script_acc(std::vector<node *> *stmts,size_t &st_index, size_t &p)
{
    size_t perm = node_count_fac((*stmts)[st_index]);
    std::cout << "p : " << p << "\n";
    std::cout << "perm : " << perm << "\n";
    std::cout << "index : " << st_index << "\n";
    if(p < perm)
    {
        permute_statement((*stmts)[st_index]);
        p++;
        std::cout << perm << "\n";
        if(p == perm)
        {
            st_index--;
            p = 1;
        }
    }
}

/*

void permute_script(std::vector<node *> *stmts,size_t start, size_t end)
{
    for(size_t j = 0; j < end-start; j++)
    {
        std::cout << j << "\n";
        for(size_t i = end-1; i >= start; i--)
        {
            std::cout << "FOR I : " << i << "-----\n";
            permute_script_acc(stmts, i, start);
            std::cout << "RESET: ---- \n";
            permute_script_acc(stmts, i, start);
            std::cout << "------\n";
        }
    permute(stmts, end, 3); //Ändra 3 här; supposed to skip the first def statements
    }
}
*/

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
/*
size_t init_calc(std::vector<node *> *commands, std::vector<node *> *cmds, NameMap *partial_map, size_t start, size_t end)
{
    size_t counter = 0;

    //1. Replace variables by _ 
    for(size_t i = start; i < end; i++)
    {
        for(size_t j = 0; j < (*cmds)[i]->children.size(); j++)
        {
            node_mute((*cmds)[i]->children[j], partial_map);
        }
    }

    //Calculate variables
    for(size_t i = start; i < end; i++)
    {
        for(size_t j = 0; j < (*cmds)[i]->children.size(); j++)
        {
            node_rename((*cmds)[i]->children[j], partial_map, counter);
        }
    }
}

void compute_variables(std::vector<node *> &commands, size_t start, size_t end)
{
    size_t p = 1;
    std::queue<std::string> q1; //fifo queue for vars
    std::queue<std::string> q2;
    std::vector<node *> *minimal;
    std::vector<node *> cmds(commands);
    NameMap partial_map;

    //Call after every permutation of rows / assertions 
    init_calc(&commands, &cmds, &partial_map, start, end);
    fill_varq(&cmds, q1, start, end);

    size_t index = end-1;
    std::cout << "---\n";
    for (size_t l = 0; l < (cmds).size(); ++l) 
    {
    print_command(std::cout, (cmds)[l], false);
    }
    
    permute_script_acc(&cmds, index, p);
    
    for (size_t l = 0; l < (cmds).size(); ++l) 
    {
    print_command(std::cout, (cmds)[l], false);
    }
    std::cout << "---\n";

    fill_varq(&cmds, q2, start, end);

    while (!q1.empty())
    {
        std::cout << ' ' << q1.front();
        q1.pop();
    }
    std::cout << "\n";
    while (!q2.empty())
    {
        std::cout << ' ' << q2.front();
        q2.pop();
    }

    //permute_script(commands, start, end);

/* 2. Sort assertions and arguments by commutative operator : already done */
/* 3. Depth-first search + extend partial map + re-sort assertions */
    /*
    for(size_t i = end-1; i >= start; i--)
    {
    std::cout << i << "\n";
    permute_statement((*commands)[i]);
    std::cout << "out" << "\n";
    }
    

}
*/

void node_mute(node *n, NameMap *q)
{
    if (!n->symbol.empty()) {
        if( first(n->symbol) == '?' )
        {
            (*q)[n->symbol] = '_';
        }
    }
    /*
    if(n->children.size() > 1)
    {
        n->permutes = true;
        n->perm_rounds = factorial(n->children.size()-1);
        n->permutations = n->perm_rounds;
    }
    */
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

std::string cmd_string(NameMap *v, node *n, bool keep_annontations)
{
    std::string out = "";
    if (!no_scramble && !keep_annontations && n->symbol == "!") {
        out += cmd_string(v, n->children[0], keep_annontations);
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
            out += '(';
        }
        if (!n->symbol.empty()) {
            if(keep_annontations)
            {
            out += n->symbol;
            }
            else{
            if( first(n->symbol) == '?' )
            {
                out += (*v)[n->symbol];
            }else
            {
                out += n->symbol;
            }
        }
        }
        if (!name.empty()) {
            out += " (!";
        }
        if (scramble_named_annot && keep_annontations) {
            node *annot;
            if (is_named_annot(n, &annot)) {
                set_named_annot(annot->children[0]);
            }
        }
        for (size_t i = 0; i < n->children.size(); ++i) {
            if (i > 0 || !n->symbol.empty()) {
                out += ' ';
            }
            out += cmd_string(v, n->children[i], keep_annontations);
        }
        if (!name.empty()) {
            out += " :named " + name + ")";
        }
        if (n->needs_parens) {
            out += ')';
        }
    }
    return out;
}

/*
return 1 : if partial > best
return 0 : if partial == best
return -1: if partial < best
*/
/*
int statement_comp(std::string partial, std::string best, size_t row, size_t &counter)
{
    if(best.empty())
    {
        return 1;
    }
    else
    {
        if((partial.find(make_name(counter)) != std::string::npos) && (best.find(make_name(counter)) != std::string::npos))
    }
}
*/

std::string filter(std::string s1, size_t start)
{
  std::string vars = "";
  std::size_t pos1 = s1.find("v", start);
  if(pos1 != std::string::npos)
  {
    vars += s1.substr(pos1, 2);
    vars += filter(s1, pos1+2);
  }
  return vars;
}

std::vector<node *> delnode(std::vector<node *> v, node* index)
{
    std::vector<node *> new_(v);
    new_.erase(std::remove(new_.begin(), new_.end(), index), new_.end());
    return new_;
}

NameMap cpyMap(NameMap V)
{
    NameMap copy_;
    copy_.insert(V.begin(), V.end());
    return copy_;
}

void rollback_map(NameMap *v, std::string prev_max_key)
{
    typedef NameMap::iterator it_type;
    for(it_type iterator = (*v).begin(); iterator != (*v).end(); iterator++) 
    {
        if(iterator->second.compare(std::string("v")+prev_max_key) >= 0)
        {
            iterator->second = "_";
        }
    }
    (*v)["max-key"] = prev_max_key;
}

void normalize_aux(NameMap v, NameMap *best_map, std::string &best, std::string &partial, std::vector<node *> cmds)
{
    std::string prev_max_key, prev_partial;
    //For every command in cmds vector
    for ( auto &val : cmds) {
        if(val->symbol == "assert")
        {
            prev_max_key = v["max-key"];
            prev_partial = partial;
            extend(&v, val->children[0]);
            partial += (cmd_string(&v, val, false) + "\n");
            if( (!best.empty()) &&  (filter(partial, 0) > filter(best, 0)) )
            {
                partial = prev_partial;
                rollback_map(&v, prev_max_key);
                continue;
            }
            if(cmds.size() == 1)
            {
                best = partial;
                (*best_map).insert(v.begin(), v.end());
            }
            else
            {
                normalize_aux(cpyMap(v), best_map, best, partial, delnode((cmds), val));
                partial = prev_partial;
                rollback_map(&v, prev_max_key);
            }
        }
    }
}

void normalize(std::vector<node *> *cmds, size_t assert_count)
{
    NameMap v, v_best;
    //best should be a vector
    std::string best = "", partial = "";
    init_map(cmds, &v);

    normalize_aux(v, &v_best, best, partial, *cmds);
    std::cout << "\nBEST MAP\n";
    for(NameMap::const_iterator it = (v_best).begin(); it != (v_best).end(); ++it)
    {
        std::cout << it->first << " " << it->second << "\n";
    }
    std::cout << "-----\n";

    if(best.empty())
    {
        std::cout << "NO RESULT\n";
    }else
    {
        std::cout << "RESULT : \n" << best << "\n";
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
                //sort_asserts_and_def(&commands, i, j);
                //shuffle_list(&commands, i, j);
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
                sort_asserts_and_def(&commands, i, j);
                assert_count += j-i;
                /*
                for(NameMap_temp::const_iterator it = t.begin(); it != t.end(); ++it)
                {
                    std::cout << it->first << " " << it->second << "\n";
                }
                */
        
            }
            i = j;
        } else {
            ++i;
        }
    }    

    //Destructive but temporary
    for(size_t i = 0; i < commands.size(); i++){
        if(commands[i]->symbol != "assert")
        {
            commands.erase(std::remove(commands.begin(), commands.end(), commands[i]), commands.end());
        }
    }
    commands.erase(std::remove(commands.begin(), commands.end(), commands[0]), commands.end());

    normalize(&commands, assert_count);


    for (size_t i = 0; i < commands.size(); ++i) {
        print_command(out, commands[i], keep_annotations);
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
