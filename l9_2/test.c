#include "functions.h"

int main()
{
    int rc = SUCCESS, count_err = 0;
    //Test my_getdelim
    {
        FILE *stream = fopen("test.txt", "r");
        char *line = NULL;
        size_t len = 0;
        ssize_t read;
        stream = fopen("test.txt", "r");
        if (stream == NULL)
        {
            puts("\nTest my_getdelim FAIL");     
            rc = TEST_ERR;
        }
        if((int)(read = my_getdelim(&line, &len, '\n',stream)) != 13)
        {
            rc = TEST_ERR;
            count_err++;
        }
        if((int)(read = my_getdelim(&line, &len, '\n', stream)) != 14)
        {
            rc = TEST_ERR;
            count_err++;
        }
        free(line);
        fclose(stream);
    }
    {
        FILE *stream = NULL;
        char *line = NULL;
        size_t len = 0;
        ssize_t read;
        if((int)(read = my_getdelim(&line, &len, '\n', stream)) != -1)
        {
            rc = TEST_ERR;
            count_err++;
        }
        free(line);
    }
    {
        FILE *stream = NULL;
        char *line = NULL;
        size_t *len = NULL;
        ssize_t read;
        if((int)(read = my_getdelim(&line, len, '\n', stream)) != -1)
        {
            puts("Hi");
            rc = TEST_ERR;
            count_err++;
        }
        free(line);        
    }
    if (count_err != 0)
    {
        puts("\nTest my_getdelim FAIL");
        rc = TEST_ERR;
    }
    else
        puts("\nTest my_getdelim passed");
    count_err = 0;
    //Test str_replace
    {
        char *result = str_replace("Hello world!", "world", "Moscow");
        if(strcmp(result, "Hello Moscow!") != 0)
            count_err++;
        free(result);
    }
    {
        char a1[] = "Relax. You will graduate, you will find a job."
            "You will find true love. The whole life is ahead. "
            "It just takes time for everything to be in right place."
            "So enjoy the present, live a colourful life, breath deeply,"
            "it's only the start of something cool";
        char a2[] = "Relax. You want graduate, you want find a job."
            "You want find true love. The whole life is ahead. "
            "It just takes time for everything to be in right place."
            "So enjoy the present, live a colourful life, breath deeply,"
            "it's only the start of something cool";
        char *result = str_replace(a2, "want", "will");
        if(strcmp(result, a1) != 0)
            count_err++;        
        free(result);
    }
    {
        char *result = str_replace("Hello world!", "abc", "def");
        if(strcmp(result, "Hello world!") != 0)
            count_err++; 
        free(result);
    }
    if (count_err != 0)
    {
        puts("Test str_replace FAIL");
        rc = TEST_ERR;
    }
    else
        puts("Test str_replace passed");
    count_err = 0;
    //Test my_strncat
    {
        char a1[] = "To be,", a2[] = " or not to be";
        my_strncat(a1, a2, 19);
        if (strcmp(a1, "To be, or not to be") != 0)
            count_err++;
    }
    {
        char a1[] = "Five", a2[] = " = 5", a3[] = "Five";
        my_strncat(a1, a2, 4);
        strncat(a3, a2, 4);
        if(strcmp(a1, a3) != 0)
            count_err++;
    }
    if (count_err != 0)
    {
        puts("Test my_strncat FAIL");
        rc = TEST_ERR;
    }
    else
        puts("Test my_strncat passed");
    count_err = 0;
    //Test my_strlen
    {
        if(my_strlen("Hello") != 5)
            count_err++;
    }
    
    {
        if(my_strlen("BMSTU") != strlen("BMSTU"))
            count_err++;
    }
    {
        if(my_strlen("") != strlen(""))
            count_err++;
    }
    if (count_err != 0)
    {
        puts("Test my_strlen FAIL");
        rc = TEST_ERR;
    }
    else
        puts("Test my_strlen passed");
    count_err = 0;
    //Test my_strstr
    {
        char str[] = "This program for Linux Ubuntu", str2[] = "This program for Linux Ubuntu";
        if(strcmp(my_strstr(str, "Linux"), strstr(str2, "Linux")) != 0)
            count_err++;
    }
    {
        char str[] = "Danila";
        if(my_strstr(str, "Zykin") != NULL)
            count_err++;
    }
    if (count_err != 0)
    {
        puts("Test my_strstr FAIL");
        rc = TEST_ERR;
    }
    else
        puts("Test my_strstr passed");
    count_err = 0;
    //Test my_strdup
    {
        char str [11] = "0123456789", *res1, *res2;
        res1 = my_strdup(str);
        res2 = strdup(str);
        if(strcmp(res1, res2) != 0)
            count_err++;
        free(res1);
        free(res2);
    }
    {
        char str[] = "", *res = my_strdup(str);
        if(strcmp(res ,str) != 0)
            count_err++;
        free(res);
    }
    if (count_err != 0)
    {
        puts("Test my_strdup FAIL");
        rc = TEST_ERR;
    }
    else
        puts("Test my_strdup passed");
    return rc;
} 