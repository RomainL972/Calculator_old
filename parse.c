#include "parse.h"

const char *numbers;
int index[2];

void testArgv(int argc, char const *argv[])
{
    if (argc != 2 || strFindArray(argv[1], "+-*/()") || strDouble(argv[1])) {
        exit(EXIT_FAILURE);
    }
}

void initElement(char digit, struct Element *newElement) {
    newElement->type = NUM;
    newElement->digit = digit;
}

struct ElementArray*** parseStdinInit() {
    struct ElementArray*** mainElement;
    enum WaitFor nextWanted;
    struct Element **lastNumber;
    mainElement = malloc(sizeof *mainElement);
    if(!mainElement)
        exit(EXIT_FAILURE);
    *mainElement = malloc(sizeof **mainElement);
    if(!*mainElement)
        exit(EXIT_FAILURE);
    **mainElement = malloc(sizeof ***mainElement);
    if(!**mainElement)
        exit(EXIT_FAILURE);
    mainElement[0][0]->type = MAIN;
    mainElement[0][0]->priority = 0;
    mainElement[0][0]->expression = malloc(sizeof *mainElement[0][0]->expression);
    if(!mainElement[0][0]->expression)
        exit(EXIT_FAILURE);
    lastNumber = malloc(sizeof *lastNumber);
    if(!lastNumber)
        exit(EXIT_FAILURE);
    nextWanted = NUMBER | BRAQUETSO | MINUS;
    readStdin(mainElement, lastNumber, nextWanted);
    return mainElement;
}

struct ElementArray*** readStdin(struct ElementArray ***mainElement, struct Element **lastNumber, enum WaitFor nextWanted) {
    struct Element newElement;
    char inChar;
    index[0] = 0;index[1] = 0;
    while((inChar = getchar()) != EOF) {
        initElement(inChar, &newElement);
        if(isDigit(inChar, numbers) && nextWanted & NUMBER) {
            nextWanted = newDigit(mainElement, lastNumber, newElement);
        }
        else if(isOperator(inChar) == 1 && nextWanted & OPERATOR) {
            nextWanted = newBasicOperator(mainElement, lastNumber, newElement);
        }
        else if(isOperator(inChar) == 2 && nextWanted & OPERATOR) {
            nextWanted = newComplexOperator(mainElement, lastNumber, newElement);
        }
    }
    return mainElement;
}