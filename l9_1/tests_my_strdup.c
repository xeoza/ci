#include "functions.h"
#include <string.h>
#include <stdio.h>
int tests_my_strdup()
{
    int error = 0;
    char *tmp = my_strdup("qwerty"), *tmp2;
    if (!my_strcmp(tmp, "qwerty"))
        error++;
    free(tmp);

    tmp = my_strdup("");
    if (!my_strcmp(tmp, "")) 
        error++;
    free(tmp);
    
    tmp = my_strdup("");
    tmp2 = strdup("");
    if (!my_strcmp(tmp, tmp2))
        error++;
    free(tmp);
    free(tmp2);
    
    tmp = my_strdup("0123456789");
    tmp2 = strdup("0123456789");
    if (!my_strcmp(tmp, tmp2))
        error++;
    free(tmp);
    free(tmp2);
    
    return error;
}