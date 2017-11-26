#include "parse.h"

const char *numbers;

int main(int argc, const char *argv[])
{
    testArgv(argc, argv);
    numbers = argv[1];
    struct ElementArray *** thing = parseStdinInit();
    return 0;
}