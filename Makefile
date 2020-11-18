all:
	flex aritimetica.l
	bison -d aritimetica.y
	gcc aritimetica.tab.c lex.yy.c -o cmp