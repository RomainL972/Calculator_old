#include "add_elements.h"

enum WaitFor newDigit(struct ElementArray ***main, struct Element **lastNumber, struct Element newElement) {
    enum WaitFor next;
    void *tempPtr;
    if((tempPtr = realloc(lastNumber, sizeof(lastNumber) + sizeof(*lastNumber))))
        lastNumber = tempPtr;
    else
        exit(EXIT_FAILURE);
	lastNumber[sizeof(lastNumber) / sizeof(*lastNumber) -1] = &newElement;
    next = NUMBER | OPERATOR | BRAQUETSO;
    if(main[index[0]][index[1]]->type == BRAQUETS)
        next = BRAQUETSC | next;
    return next;
}

enum WaitFor newBasicOperator(struct ElementArray ***main, struct Element **lastNumber, struct Element newElement) {
    int newExpressionSize;
    void *tempPtr;
    int i;
    for (i = 0; (unsigned) i < sizeof lastNumber / sizeof *lastNumber + 1; i++)
    {
        if((tempPtr = realloc(main[index[0]][index[1]]->expression, sizeof main[index[0]][index[1]]->expression + sizeof *main[index[0]][index[1]]->expression)))
            main[index[0]][index[1]]->expression = tempPtr;
        else
            exit(EXIT_FAILURE);
        newExpressionSize = sizeof main[index[0]][index[1]]->expression / sizeof *main[index[0]][index[1]]->expression;
        if(i == sizeof lastNumber / sizeof *lastNumber)
            main[index[0]][index[1]]->expression[newExpressionSize -1] = &newElement;
        else
            main[index[0]][index[1]]->expression[newExpressionSize -1] = lastNumber[i];
        if((tempPtr = realloc(lastNumber, 0)))
            lastNumber = tempPtr;
        else
            exit(EXIT_FAILURE);
    }
    return NUMBER | MINUS | BRAQUETSO;
}

enum WaitFor newComplexOperator(struct ElementArray ***main, struct Element **lastNumber, struct Element newElement)
{
    changeLevel(index[0] + 1, main/*, TIMESORDIV*/);
    return newBasicOperator(main, lastNumber, newElement);
}

enum WaitFor newMinus(struct Element **lastNumber)
{
    struct Element *newElement;
    void *tempPtr;
    newElement = malloc(sizeof *newElement);
    if(!newElement)
        exit(EXIT_FAILURE);
    newElement->type = NUM;
    newElement->digit = '-';
    if((tempPtr = realloc(lastNumber, sizeof(lastNumber) + sizeof(*lastNumber))))
        lastNumber = tempPtr;
    else
        exit(EXIT_FAILURE);
    lastNumber[sizeof(lastNumber) / sizeof(*lastNumber) -1] = newElement;
    return NUMBER | BRAQUETSO;
}