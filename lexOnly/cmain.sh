rm cmain
lex cmain.l
g++ lex.yy.c table.cpp file.c tree.cpp item.cpp -o cmain
./cmain example.c

