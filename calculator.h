#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#include "struct.h"
#include "string.h"

struct Number add(struct Number num1, struct Number num2);
struct Number sub(struct Number num1, struct Number num2);
struct Number times(struct Number num1, struct Number num2);
struct Number div(struct Number num1, struct Number num2);

#endif