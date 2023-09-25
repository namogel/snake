warn:
	gcc -std=c99 -Wextra -Wall -W *.c -lncurses -lm
comp:
	gcc -std=c99 *.c -lncurses -lm
clean:
	rm -f a.out
