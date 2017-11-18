#ifndef ADD_ELEMENTS_H_INCLUDED
#define ADD_ELEMENTS_H_INCLUDED

const char *numbers;
int index[2];
#include "struct.h"
#include "change_level.h"

enum WaitFor newDigit(struct ElementArray ***main, struct Element **lastNumber, struct Element newElement);
enum WaitFor newBasicOperator(struct ElementArray ***main, struct Element **lastNumber, struct Element newElement);
enum WaitFor newComplexOperator(struct ElementArray ***main, struct Element **lastNumber, struct Element newElement);
enum WaitFor newMinus(struct Element **lastNumber);

#endif