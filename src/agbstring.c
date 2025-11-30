#include <agbstring.h>

int strlength(const char *str)
{
    int len = 0;
    char currentChar = '0';
    int i = 0;
    while (1)
    {
        currentChar = str[i];
        if (currentChar == '\0') break;
        i++;
        len++;
    }
    return len;
}

int strStartsWith(const char* str, const char* substr)
{
    int len = strlength(str);
    int substrLen = strlength(substr);
    int match = 0;

    for (int i = 0; i < substrLen; i++)
    {
        if (str[i] != substr[i]) break;
        match++;
    }

    return match == substrLen;
}


int strEndsWith(const char* str, const char* substr)
{
    int len = strlength(str);
    int substrLen = strlength(substr);
    int match = 0;

    for (int i = 0; i < substrLen; i++)
    {
        if (str[len - substrLen + i] != substr[i]) break;
        match++;
    }

    return match == substrLen;
}
