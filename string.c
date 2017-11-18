#include "string.h"

int strLength(const char str[])
{
    int i;
    for(i = 0; str[i] != '\0'; i++);
    return i;
}

int strFind(const char str[], const char find)
{
    int i;
    int length = strLength(str);
    for(i = 0; str[i] != find && i < length; i++);
    if(i == length)
        return 0;
    else
        return i;
}

float strFindArray(const char str[], const char find[]) {
    int i;
    int result;
    for(i = 0; i < strLength(find); i++) {
        if((result = strFind(str, find[i])))
            return i + result / 10;
    }
    return 0;
}

int strDouble(const char str[])
{
    int count[256] = {0};
    int i = 0;
    for(i = 0; i < strLength(str); i++) {
        if(count[(int)str[i]] == 0)
            count[(int)str[i]] = 1;
        else
            return 1;
    }
    return 0;
}