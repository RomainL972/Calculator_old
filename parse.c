#include "parse.h"

char *numbers;
int level;

void testArgv(int argc, char const *argv[])
{
    if (argc != 2 || strFind(argv[1], "+-*/()") || strDouble(argv[1])) {
        exit(EXIT_FAILURE);
    }
}

void initElement(char digit, struct Element *newElement, int level) {
    newElement->type = NUM;
    newElement->digit = digit;
}

struct ElementArray*** parseStdinInit(char numbers[]) {
    struct ElementArray*** mainElement;
    enum WaitFor nextWanted;
    struct Element **lastNumber;
    mainElement = malloc(sizeof *mainElement);
    *mainElement = malloc(sizeof **mainElement);
    **mainElement = malloc(sizeof ***mainElement);
    mainElement[0][0]->type = MAIN;
    mainElement[0][0]->priority = 0;
    mainElement[0][0]->expression = malloc(sizeof *(mainElement[0][0]->expression))
    mainElement[0][0]->expression[0] = malloc(sizeof *(mainElement[0][0]->expression[0]))
    lastNumber = malloc(sizeof *lastNumber);
    lastNumber[0] = malloc(sizeof **lastNumber);
    readStdin(mainElement, lastNumber, nextWanted)
    return mainElement;
}

struct ElementArray*** readStdin(ElementArray ***mainElement, struct Element **lastNumber, enum WaitFor nextWanted) {
    level = 0;
    struct Element newElement;
    void *tempPtr;
    while((char inChar = getchar()) != EOF) {
        initElement(inChar, newElement);
        if(isDigit(inChar, numbers) && nextWanted & NUMBER) {
            /*lastNumber[sizeof(lastNumber) / sizeof(*lastNumber) -1] = &newElement;
            if((tempPtr = realloc(lastNumber, sizeof(lastNumber) + sizeof(*lastNumber))))
                lastNumber = tempPtr;*/
        }
        else if(isOperator(inChar) == 1 && nextWanted & OPERATOR) {
            for (int i = 0; i < sizeof lastNumber / sizeof *lastNumber + 1; ++i)
            {
                if((tempPtr = realloc(mainElement[level], sizeof(mainElement[level]) + sizeof(*mainElement[level]))))
                    mainElement[level] = tempPtr;
                if((tempPtr = realloc(mainElement[level][sizeof mainElement[level] / sizeof *mainElement[level] -1], sizeof(*mainElement[level]))))
                    mainElement[level][sizeof mainElement[level] / sizeof *mainElement[level] -1] = tempPtr;
                if(i == sizeof lastNumber / sizeof *lastNumber)
                    mainElement[level][sizeof mainElement[level] / sizeof *mainElement[level] -1] = &newElement;
                else
                    mainElement[level][sizeof mainElement[level] / sizeof *mainElement[level] -1] = lastNumber[i];
            }
        }
        else if(isOperator(inChar) == 2 && nextWanted & OPERATOR) {
            /*if((tempPtr = realloc(mainElement, sizeof(mainElement) + sizeof(*mainElement))))
                mainElement = tempPtr;
            level++;
            if((tempPtr = realloc(mainElement[level], sizeof(mainElement[level]) + sizeof(*mainElement[level]))))
                mainElement[level] = tempPtr;
            if((tempPtr = realloc(mainElement[level][sizeof mainElement[level] / sizeof *mainElement[level] -1], sizeof(*mainElement[level]))))
                mainElement[level][sizeof mainElement[level] / sizeof *mainElement[level] -1] = tempPtr;*/
        }
    }
}