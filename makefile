all : main.o string.c parse.c string.h parse.h struct.h enum.h add_elements.c add_elements.h calculator.c calculator.h tests.c tests.h
	gcc *.c *.h -o Calculator -W -Wall -ansi -pedantic
	./Calculator 0123456789

clean :
	rm -rf *.o Calculator

run :
	./Calculator 0123456789