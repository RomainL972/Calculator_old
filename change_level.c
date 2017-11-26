#include "change_level.h"

void newBraquet(struct ElementArray ***main, struct Element **lastNumber) {
    if(sizeof lastNumber) {
        struct Element newElement;
        newElement.type = NUM;
        newElement.digit = '*';
        newComplexOperator(main, lastNumber, newElement);
    }
    changeLevel(index[0]+1, main, BRAQUETS);
}

void endBraquet(struct ElementArray ***main, struct Element **lastNumber) {
    addNumber(main, lastNumber);
    if(main[index[0]][index[1]]->type == TIMESORDIV)
        changeLevel(index[0]-2, main, MAIN);
    else
        changeLevel(index[0]-1, main, MAIN);
}

void changeLevel(int newLevel, struct ElementArray ***main, enum TypeExpression type) {
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
    main[newLevel][newSecondIndex]->type = type;
    index[0] = newLevel;
    index[1] = newSecondIndex;
}