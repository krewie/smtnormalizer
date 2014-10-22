CXX = g++-4.9
CXXFLAGS = -g -O3 
LDFLAGS = -g

OBJECTS = scrambler.o \
	  parser.o \
	  lexer.o

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

scrambler: $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $@


scrambler.cpp: parser.cpp

parser.cpp: parser.y lexer.cpp
	/usr/local/Cellar/bison/3.0.2/bin/bison -o $@ $<

lexer.cpp: lexer.l
	flex --header-file="lexer.h" -o $@ $<

clean:
	rm -f $(OBJECTS) lexer.cpp lexer.h parser.cpp parser.h scrambler
