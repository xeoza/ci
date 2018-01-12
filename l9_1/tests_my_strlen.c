#include "functions.h"
#include <string.h>

int tests_my_strlen()
{
    int error = 0;
    if (my_strlen("") != 0) 
        error++;
    if (my_strlen("abc") != 3) 
        error++;
    if (my_strlen("qwerty") != 6) 
        error++;
    if (my_strlen("") != strlen("")) 
        error++;
    if (my_strlen("abc") != strlen("abc")) 
        error++;
    if (my_strlen("qwerty") != strlen("qwerty")) 
        error++;
    
    return error;
}