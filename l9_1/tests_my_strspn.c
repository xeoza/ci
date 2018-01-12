#include "functions.h"
#include <string.h>
int tests_my_strspn()
{
    int error = 0;

    if (!(my_strspn("", "") == 0))
        error++;
    if (!(my_strspn("abc", "abc") == 3)) 
        error++;
    if (!(my_strspn("Danila", "Da") == 2)) 
        error++;
    if (!(my_strspn("Zykin", "Zyk") == 3)) 
        error++;

    if (!(my_strspn("qwertyuiop", "qwertyuiop") == strspn("qwertyuiop", "qwertyuiop")))
        error++;
    if (!((my_strspn("12-ears", "1234567890")) == (strspn("12-ears", "1234567890"))))
        error++;
    return error;
}