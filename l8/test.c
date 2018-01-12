#include "tests_determination.h"
#include "tests_summ.h"
#include "tests_multiplication.h"
#include <stdio.h>
#define TEST_ERR -1

int main(void)
{
    int fc = 0, rc = 0;
    puts("Tests multiplication:");
    fc = test_multiplication();
    if (fc != 0)
        rc = TEST_ERR;
    puts("Tests summ:");
    fc = test_summ();
    if (fc != 0)
        rc = TEST_ERR;
    puts("Tests minor:");
    fc = test_minor();
    if (fc != 0)
        rc = TEST_ERR;
    puts("Tests determination:");
    fc = test_determination();
    if (fc != 0)
        rc = TEST_ERR;
    return rc;
}