#include "functions.h"

int test_summ(void)
{
    int fc, rc = 0;
    int na = 3, ma = 3;
    double **result;
    //Test #1
    {
        double **mtr1 = allocate_matrix_solid(na, ma);
        double **mtr2 = allocate_matrix_solid(na, ma);
        if (mtr1 && mtr2)
        {
            init_matrix(mtr1, na, ma);
            for (int i = 0; i < na; i++)
                for (int j = 0; j < na; j++)
                    mtr2[i][j] = i + j;

            result = add(mtr1, mtr2, na, ma, na, ma);
            if (result)
            {
                fc = compare_matrix(result, na, ma, mtr2, na, ma);
                if (fc == EQUAL)
                    puts("Test 1 passed.");
                else
                {
                    puts("Test 1 FAIL");
                    rc = IOERROR;
                }
                free_matrix(result, na);
            }            
            else
            {
                puts("Test 1 FAIL");
                rc = IOERROR;
            }            
            free_matrix(mtr1, na);
            free_matrix(mtr2, na);
        }
		else
		{
			puts("Test 1 FAIL");
			rc = IOERROR;
		}
    }

    //Test #2
    {
        double **mtr1 = allocate_matrix_solid(na, ma);
        double **mtr2 = allocate_matrix_solid(na, ma);
        if (mtr1 && mtr2)
        {
            for (int i = 0; i < na; i++)
            {
                for (int j = 0; j < na; j++)
                {
                    mtr1[i][j] = i + j;
                    mtr2[i][j] = -(i + j);
                }
            }
            result = add(mtr2, mtr1, na, ma, na, ma);
            if (result)
            {
                init_matrix(mtr1, na, ma);
                fc = compare_matrix(result, na, ma, mtr1, na, ma);
                if (fc == EQUAL)
                    puts("Test 2 passed.");
                else
                {
                    puts("Test 2 FAIL");
                    rc = IOERROR;
                }
                free_matrix(result, na);
            }
            else
            {
                puts("Test 2 FAIL");
                rc = IOERROR;
            }
            free_matrix(mtr1, na);
            free_matrix(mtr2, na);
        }
		else
		{
			puts("Test 2 FAIL");
			rc = IOERROR;
		}
    }

    //Test #3
    {
        double **mtr1 = allocate_matrix_solid(na, ma);
        double **mtr2 = allocate_matrix_solid(na, ma);
        if (mtr1 && mtr2)
        {
            for (int i = 0; i < na; i++)
            {
                for (int j = 0; j < ma; j++)
                {
                    mtr1[i][j] = i + j;
                    mtr2[i][j] = i;
                }
            }
            result = add(mtr2, mtr1, na, ma, na, ma);
            if (result)
            {
                for (int i = 0; i < na; i++)
                    for (int j = 0; j < ma; j++)
                        mtr1[i][j] = 2 * i + j;
                fc = compare_matrix(result, na, ma, mtr1, na, ma);
                if (fc == EQUAL)
                    puts("Test 3 passed.");
                else
                {
                    puts("Test 3 FAIL");
                    rc = IOERROR;
                }
                free_matrix(result, na);
            }            
            else
            {
                puts("Test 3 FAIL");
                rc = IOERROR;
            }
            free_matrix(mtr1, na);
            free_matrix(mtr2, na);
        }
		else
		{
			puts("Test 3 FAIL");
			rc = IOERROR;
		}
    }

    //Test #4
    na = 2; ma = 3;
    {
        double **mtr1 = allocate_matrix_solid(na, ma);
        double **mtr2 = allocate_matrix_solid(na, ma);
        if (mtr1 && mtr2)
        {
            for (int i = 0; i < na; i++)
                for (int j = 0; j < ma; j++)
                {
                    mtr1[i][j] = j;
                    mtr2[i][j] = i;
                }
            result = add(mtr2, mtr1, na, ma, na, ma);
            if (result)
            {
                for (int i = 0; i < na; i++)
                    for (int j = 0; j < ma; j++)
                        mtr1[i][j] = i + j;
                fc = compare_matrix(result, na, ma, mtr1, na, ma);
                if (fc == EQUAL)
                    puts("Test 4 passed.");
                else
                {
                    puts("Test 4 FAIL");
                    rc = IOERROR;
                }	   
                free_matrix(result, na);
            }        
            else
            {
                puts("Test 4 FAIL");
                rc = IOERROR;
            }	
            free_matrix(mtr1, na);
            free_matrix(mtr2, na);
        }        
        else
		{
			puts("Test 4 FAIL");
			rc = IOERROR;
		}
    }

    //Test #5
    {
        double **mtr1 = allocate_matrix_solid(na, ma);
        double **mtr2 = allocate_matrix_solid(na, ma);
        if (mtr1 && mtr2)
        {
            for (int i = 0; i < na; i++)
                for (int j = 0; j < ma; j++)
                {
                    mtr1[i][j] = 3 * j;
                    mtr2[i][j] = 2 * i;
                }

            result = add(mtr2, mtr1, na, ma, na, ma);
            if (result)
            {
                for (int i = 0; i < na; i++)
                    for (int j = 0; j < ma; j++)
                        mtr1[i][j] = 2 * i + 3 * j;
                fc = compare_matrix(result, na, ma, mtr1, na, ma);
                if (fc == EQUAL)
                    puts("Test 5 passed.");
                else
                {
                    puts("Test 5 FAIL");
                    rc = IOERROR;
                }   
                free_matrix(result, na);
            }
            else
            {
                puts("Test 5 FAIL");
                rc = IOERROR;
            }	
            free_matrix(mtr1, na);
            free_matrix(mtr2, na);
        }        
        else
		{
			puts("Test 5 FAIL");
			rc = IOERROR;
		}
    }

    //Test #6
    {
        double **mtr1 = allocate_matrix_solid(na, ma);
        double **mtr2 = allocate_matrix_solid(na, ma);
        if (mtr1 && mtr2)
        {
            for (int i = 0; i < na; i++)
            {
                for (int j = 0; j < ma; j++)
                {
                    mtr1[i][j] = -j;
                    mtr2[i][j] = -i;
                }
            }
            result = add(mtr2, mtr1, na, ma, na, ma);
            if (result)
            {
                for (int i = 0; i < na; i++)
                    for (int j = 0; j < ma; j++)
                        mtr1[i][j] = - i - j;
                fc = compare_matrix(result, na, ma, mtr1, na, ma);
                if (fc == EQUAL)
                    puts("Test 6 passed.");
                else
                {
                    puts("Test 6 FAIL");
                    rc = IOERROR;
                }	
                free_matrix(result, na);                
            }            
            else
            {
                puts("Test 6 FAIL");
                rc = IOERROR;
            }	
            free_matrix(mtr1, na);
            free_matrix(mtr2, na);
        }        
        else
		{
			puts("Test 6 FAIL");
			rc = IOERROR;
		}
    }

    return rc;
}
