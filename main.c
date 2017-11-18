#include "parse.h"

char *numbers;

int main(int argc, char const *argv[])
{
    testArgv(argc, argv);
    numbers = argv[1];
    calculate(parseStdin(argv[1]));
    return 0;
}