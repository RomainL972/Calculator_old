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
    addNumber(main, lastNumber);
    if(main[index[0]][index[1]]->type == TIMESORDIV && isOperator(newElement.digit) == 1)
        changeLevel(index[0]-1, main, MAIN);
    if((tempPtr = realloc(main[index[0]][index[1]]->expression, sizeof main[index[0]][index[1]]->expression + sizeof *main[index[0]][index[1]]->expression)))
        main[index[0]][index[1]]->expression = tempPtr;
    else
        exit(EXIT_FAILURE);
    newExpressionSize = sizeof main[index[0]][index[1]]->expression / sizeof *main[index[0]][index[1]]->expression;
    main[index[0]][index[1]]->expression[newExpressionSize -1] = &newElement;
    return NUMBER | MINUS | BRAQUETSO;
}

enum WaitFor newComplexOperator(struct ElementArray ***main, struct Element **lastNumber, struct Element newElement)
{
    if(main[index[0]][index[1]]->type != TIMESORDIV)
        changeLevel(index[0] + 1, main, TIMESORDIV);
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

void addNumber(struct ElementArray ***main, struct Element **number) {
    void *tempPtr;
    unsigned int numberDigits = sizeof number / sizeof *number;
    unsigned int i;
    unsigned int oldExpressionSize = sizeof main[index[0]][index[1]]->expression / sizeof *main[index[0]][index[1]]->expression;
    if((tempPtr = realloc(main[index[0]][index[1]]->expression, sizeof main[index[0]][index[1]]->expression + sizeof *main[index[0]][index[1]]->expression * numberDigits)))
        main[index[0]][index[1]]->expression = tempPtr;
    else
        exit(EXIT_FAILURE);
    for(i = 0; i < numberDigits; i++) {
        main[index[0]][index[1]]->expression[oldExpressionSize + i] = number[i];
    }
    if((tempPtr = realloc(number, 0)))
        number = tempPtr;
    else
        exit(EXIT_FAILURE);
}