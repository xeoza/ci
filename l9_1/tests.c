#include "functions.h"
#include "tests_my_strlen.h"
#include "tests_my_strdup.h"
#include "tests_my_strspn.h"
#include <stdio.h>
#include <string.h>
#define SUCCESS 0
#define FAIL_TESTS -1

int main()
{
    int error, rc = 0;
    error = tests_my_strlen();
    if (error == 0)
    {
        rc ++;
        printf("Tests 'my_strlen'passed.\n");
    }
    else
        printf("Tests 'my_strlen' FAIL. There are %d errors\n", error);
    error = 0;
    error = tests_my_strdup();
    if (error == 0)
    {
        rc ++;
        printf("Tests 'my_strdup'passed.\n");
    }
    else
        printf("Tests 'my_strdup' FAIL. There are %d errors\n", error);
    error = 0;
    error = tests_my_strspn();
    if (error == 0)
    {
        rc ++;
        printf("Tests 'my_strspn'passed.\n");
    }
    else
        printf("Tests 'my_strspn' FAIL. There are %d errors\n", error);
    if (rc == 3)
        return SUCCESS;
    else 
        return FAIL_TESTS;
}
