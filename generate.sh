#/bin/bash
yacc -d c.y
lex c.l
g++ lex.yy.c y.tab.c file.c table.cpp tree.cpp item.cpp -o complier
