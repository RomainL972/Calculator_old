#ifndef PARSE_H_INCLUDED
#define PARSE_H_INCLUDED 1

#include "string.h"
#include "struct.h"
#include "enum.h"
#include "tests.h"
#include "add_elements.h"
#include <stdlib.h>
#include <stdio.h>

void testArgv(int argc, const char *argv[]);
void initElement(char digit, struct Element *newElement);
struct ElementArray*** parseStdinInit();
struct ElementArray*** readStdin(struct ElementArray ***mainElement, struct Element **lastNumber, enum WaitFor nextWanted);

#endif