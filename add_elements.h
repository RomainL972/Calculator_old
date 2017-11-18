#ifndef ADD_ELEMENTS_H_INCLUDED
#define ADD_ELEMENTS_H_INCLUDED

char numbers[];
int level;
#include "struct.h"
#include "change_level.h"

void newDigit(Element **lastNumber, Element newElement);
void newBasicOperator(ElementArray ***main, Element **lastNumber, Element newElement);
void newComplexOperator(ElementArray ***main, Element **lastNumber, Element newElement);
void newMinus(ElementArray **lastNumber);

#endif