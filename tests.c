#include "tests.h"

int isDigit(char test, char numbers[]) {
	return strFind(numbers, test);
}

int isOperator(char test) {
	if(strFind("+-", test))
		return 1;
	if(strFind("*/", test))
		return 2;
	return 0;
}

int isMinus(char test) {
	return (test == '-');
}

int isBraquO(char test) {
	return (test == '(');
}

int isBraquC(char test) {
	return (test == ')');
}