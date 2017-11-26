#ifndef CHANGE_LEVEL_H_INCLUDED
#define CHANGE_LEVEL_H_INCLUDED

#include "struct.h"
#include "add_elements.h"
#include <stdlib.h>

int index[2];

void newBraquet(struct ElementArray ***main, struct Element **lastNumber);
void endBraquet(struct ElementArray ***main, struct Element **lastNumber);
void changeLevel(int newLevel, struct ElementArray ***main, enum TypeExpression type);

#endif