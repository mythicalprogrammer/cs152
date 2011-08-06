all:
	bison -v -d --file-prefix=y project2.y
	flex project2.lex
	g++ -o  parser y.tab.c lex.yy.c -lfl

clean:
	rm -rf *~ y.output y.tab.h y.tab.c lex.yy.c parser
