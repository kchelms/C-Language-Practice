all: compile_libraries compile_main generate_bin clean

compile_libraries:
	gcc -c stack.c -o stack.o
	gcc -c queue.c -o queue.o
	gcc -c towerOfHanoi.c -o towerOfHanoi.o

compile_main: main.c 
	gcc -c main.c -o main.o

generate_bin: main.o
	gcc -Wall main.o stack.o queue.o towerOfHanoi.o -o run

clean:
	rm main.o stack.o queue.o towerOfHanoi.o