all : main.c string.c parse.c string.h parse.h struct.h enum.h add_elements.c add_elements.h tests.c tests.h
	gcc *.c *.h -o Calculator -W -Wall -ansi -pedantic

clean :
	rm -rf *.o Calculator

run :
	./Calculator 0123456789
