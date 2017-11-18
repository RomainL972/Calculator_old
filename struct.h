#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

#include "enum.h"

struct Element
{
	enum TypeElement type;
	char digit;
	struct ElementArray *reference;
};

struct ElementArray
{
	struct Element **expression;
	enum TypeExpression type;
	struct Number result;
	int priority;
};

struct Number
{
	char *digits;
	enum Sign sign;
};

#endif
