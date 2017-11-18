#include "change_level.h"

void changeLevel(int newLevel, struct ElementArray ***main/*, enum TypeExpression type*/) {
    void *tempPtr = NULL;
    int newSecondIndex;
    if((unsigned)newLevel > sizeof main / sizeof *main -1) {
        if((tempPtr = realloc(main, sizeof(main) + sizeof(*main))))
            main = tempPtr;
        else
            exit(EXIT_FAILURE);
    }
    newSecondIndex = sizeof main[newLevel] / sizeof *main[newLevel];
    if((tempPtr = realloc(main[newLevel], sizeof main[newLevel] + sizeof *main[newLevel])))
        main[newLevel] = tempPtr;
    else
        exit(EXIT_FAILURE);
    if((tempPtr = realloc(main[newLevel][newSecondIndex], sizeof *main[newLevel])))
        main[newLevel][newSecondIndex] = tempPtr;
    else
        exit(EXIT_FAILURE);
    index[0] = newLevel;
    index[1] = newSecondIndex;
}