#ifndef ENUM_H_INCLUDED
#define ENUM_H_INCLUDED

enum TypeElement
{
	NUM, REF
};

enum Operators
{
	ADD, SUB, TIMES, DIV, BRAQO, BRAQC
};

enum TypeExpression
{
	MAIN, TIMESORDIV, BRAQUETS
};

enum Sign
{
	POS, NEG
};

enum WaitFor
{
	NUMBER = 1 << 0,
	OPERATOR = 1 << 1,
	BRAQUETSO = 1 << 2,
	BRAQUETSC = 1 << 3,
	MINUS = 1 << 4
};

#endif
