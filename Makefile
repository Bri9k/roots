roots: roots.c function.c
	gcc roots.c -lm -o roots
clean:
	rm roots *~
