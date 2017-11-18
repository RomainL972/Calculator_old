#include "parse.h"

const char *numbers;

int main(int argc, const char *argv[])
{
    testArgv(argc, argv);
    numbers = argv[1];
    parseStdinInit();
    return 0;
}