#include "functions.h"
int test_minor(void)
{
    int rc = 0;
    {
        double mtr1[3][3] = { { 5, 7, 1 }, { -4, 1, 0 }, { 2, 0, 3 } }; 
        double *mtr1_1[3] = { mtr1[0], mtr1[1], mtr1[2] };
        double **minor1 = allocate_matrix_solid(2, 2);
        minor(mtr1_1, minor1, 0, 0, 3);
        if (minor1)
        {
            if (compare_double(determinant(minor1, 2), 2))
                puts("Test 1 passed.");
            else
            {
                puts("Test 1 FAIL");
                rc = IOERROR;
            }
            free_matrix(minor1, 2);
        }
        else
        {
            puts("Test 1 FAIL");
            rc = IOERROR;
        }
    }
    return rc;
}
int test_determination(void)
{
    int rc = 0;
    double result;
    {
        double **matrix = allocate_matrix_solid(2, 2);
        if (matrix)
        {
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    matrix[i][j] = i + j + 2;

            result = determinant(matrix, 2);
            if (compare_double(result, -1))
                puts("Test 1 passed.");
            else
            {
                puts("Test 1 FAIL");
                rc = IOERROR;
            }
            free_matrix(matrix, 2);
        }
        else
        {
            puts("Test 1 FAIL");
            rc = IOERROR;
        }
    }

    //Test #2
    {
        double **matrix = allocate_matrix_solid(4, 4);
        if (matrix)
        {
            init_matrix(matrix, 4, 4);
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    if (i == j)
                        matrix[i][j] = 1;

            result = determinant(matrix, 4);
            if (compare_double(result, 1))
                puts("Test 2 passed.");
            else
            {
                puts("Test 2 FAIL");
                rc = IOERROR;
            }
            free_matrix(matrix, 4);
        }
        else
        {
            puts("Test 2 FAIL");
            rc = IOERROR;
        }
    }

    //Test #3
    {
        double **matrix = allocate_matrix_solid(4, 4);
        if (matrix)
        {
            init_matrix(matrix, 4, 4);
            result = determinant(matrix, 4);
            if (compare_double(result, 0))
                puts("Test 3 passed.");
            else
            {
                puts("Test 3 FAIL");
                rc = IOERROR;
            }
            free_matrix(matrix, 4);
        }
        else     
        {
            puts("Test 3 FAIL");
            rc = IOERROR;
        }
    }

    //Test #4
    {
        double **matrix = allocate_matrix_solid(3, 3);
        if (matrix)
        {
            int k = 0;
            for (int i = 0; i < 3; i ++)
            {
                for (int j = 0; j < 3; j++)
                {
                    matrix[i][j] = k;
                    k++;
                }
            }
            result = determinant(matrix, 3);
            if (compare_double(result, 0))
                puts("Test 4 passed.");
            else
            {
                puts("Test 4 FAIL");
                rc = IOERROR;
            }
            free_matrix(matrix, 3);
        }
        else
        {
            puts("Test 4 FAIL");
            rc = IOERROR;
        }
    }
    
    //Test #5
    {
        double **matrix = allocate_matrix_solid(3, 3);
        if (matrix)
        {
            init_matrix(matrix, 3, 3);
            result = determinant(matrix, 1);
            if (compare_double(result, 0))
                puts("Test 5 passed.");
            else
            {
                puts("Test 5 FAIL");
                rc = IOERROR;
            }
            free_matrix(matrix, 3);
        }
        else
        {
            puts("Test 5 FAIL");
            rc = IOERROR;
        }
    }
    return rc;
}
