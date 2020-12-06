#/bin/bash
rm y.tab.c
rm y.tab.h
rm lex.yy.c
rm compiler
yacc -d c.y
lex c.l
g++ lex.yy.c y.tab.c file.c table.cpp tree.cpp item.cpp -o compiler -lm
# g++ lex.yy.c c.tab.c file.c table.cpp tree.cpp item.cpp -o compiler -lm -ll
./compiler example.c
