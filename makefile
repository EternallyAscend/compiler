LEX=lex #flex
YACC=yacc #bison
CC=g++ -w
C=gcc -w
OBJECT=ccompiler
FILE=example.c
ASSEMBLY=assembly
PROMOTE=promote

$(OBJECT): lex.yy.o  y.tab.o
	$(CC) lex.yy.o y.tab.o file.c table.cpp tree.cpp item.cpp indirectTriple.c pointer.cpp -o $(OBJECT)
	$(C) assmain.c assfunction.c file.c -o $(ASSEMBLY)
	$(CC) promote.cpp -o $(PROMOTE)
	# @./$(OBJECT) $(FILE) 
 
#lex.yy.o: lex.yy.c c.tab.h file.c table.h
lex.yy.o: lex.yy.c y.tab.h file.c table.h
	$(CC) -c lex.yy.c
 
# c.tab.o: c.tab.c file.h table.h
y.tab.o: y.tab.c file.h table.h
	$(CC) -c y.tab.c
#	$(CC) -c c.tab.c

#c.tab.c c.tab.h: c.y
y.tab.c y.tab.h: c.y
	$(YACC) -d c.y
 
lex.yy.c: c.l
	$(LEX) c.l
 
clean:
	@rm -f $(OBJECT) $(ASSEMBLY) $(PROMOTE) *.o lex.yy.c y.tab.c y.tab.h # c.tab.c c.tab.h
