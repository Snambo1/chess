#include "strutil.h"

#include <ctype.h>
#include <string.h>

//removes whitespace from the end of a string
void trim_right(char *str) {
    char *tail = str + strlen(str) - 1;

    while (isspace(*tail) && tail >= str) {
        *tail = '\0';
        tail--;
    }
}
