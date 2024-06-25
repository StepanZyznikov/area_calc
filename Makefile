all: integral

integral: main.o functions.o integral.o root.o other_functions.o getopt.o
	gcc -m32 main.o functions.o integral.o root.o other_functions.o getopt.o -o integral

test: integral.o root.o other_functions.o test.o
	gcc -m32 integral.o root.o other_functions.o test.o -o test

%.o: %.asm
	nasm -f win32 $< -o $@
	
%.o: %.c
	gcc -c -m32 $< -o $@

clean:
	erase -rf *.o