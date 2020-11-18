all:
	flex cmp.l
	bison -d cmp.y
	gcc cmp.tab.c lex.yy.c -o cmp