#ifndef PARSE_H_INCLUDED
#define PARSE_H_INCLUDED 1

#include "string.h"
#include "struct.h"
#include "enum.h"
#include "tests.h"
#include <stdlib.h>
#include <stdio.h>

void testArgv(int argc, char const *argv[]);
struct ElementArray** parseStdin();
int calculate(struct ElementArray** equations);

#endif