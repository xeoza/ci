#include "functions.h"
int test_multiplication(void)
{
    int fc, rc = 0;
    int na = 3, ma = 4;
    int nb = 2, mb = 1;
    double **result;

    //Test #1
    {
        double **mtr1 = allocate_matrix_solid(na, ma);
        double **mtr2 = allocate_matrix_solid(nb, mb);
        if (mtr1 && mtr2)
        {
            init_matrix(mtr1, na, ma);
            init_matrix(mtr2, nb, mb);
            result = multi(mtr1, mtr2, na, ma, nb, mb);

            if (result == NULL)
            {
                puts("Test 1 passed.");
            }
            else
            {
                free_matrix(result, na);
                puts("Test 1 FAIL");
                rc = IOERROR;
            }
            free_matrix(mtr1, na);
            free_matrix(mtr2, nb);
        }
        else
        {
            puts("Test 1 FAIL");
            rc = IOERROR;
        }
    }

    //Test #2; А * 0 
    nb = 4;
    mb = 3;
    {
        double **mtr1 = allocate_matrix_solid(na, ma);
        double **mtr2 = allocate_matrix_solid(nb, mb);
        if (mtr1 && mtr2)
        {
            for (int i = 0; i < na; i++)
                for (int j = 0; j < ma; j++)
                    mtr1[i][j] = i + j;
            init_matrix(mtr2, nb, mb);


            result = multi(mtr1, mtr2, na, ma, nb, mb);
            double **mtr_r = allocate_matrix_solid(na, mb);
            if (mtr_r && result)
            {
                init_matrix(mtr_r, na, mb);
                fc = compare_matrix(result, na, mb, mtr_r, na, mb);
                if (fc == EQUAL)
                    puts("Test 2 passed.");
                else
                {
                    puts("Test 2 FAIL");
                    rc = IOERROR;
                }
            }
            else
            {
                puts("Test 2 FAIL");
                rc = IOERROR;
            }
            free_matrix(mtr_r, na);
            free_matrix(result, na);
            free_matrix(mtr1, na);
            free_matrix(mtr2, nb);
        }
        else
        {
            puts("Test 2 FAIL");
            rc = IOERROR;
        }
    }

    //Test #3; A * (-A)
    {
        double **mtr1 = allocate_matrix_solid(na, ma);
        double **mtr2 = allocate_matrix_solid(nb, mb);
        if (mtr1 && mtr2)
        {
            for (int i = 0; i < na; i++)
                for (int j = 0; j < ma; j++)
                    mtr1[i][j] = i + j;
            for (int i = 0; i < nb; i++)
                for (int j = 0; j < mb; j++)
                    mtr2[i][j] = -(i + j);


            result = multi(mtr1, mtr2, na, ma, nb, mb);
            double **mtr_r = allocate_matrix_solid(na, mb);
            if (mtr_r && result)
            {
                mtr_r[0][0] = -14;
                mtr_r[0][1] = -20;
                mtr_r[0][2] = -26;

                mtr_r[1][0] = -20;
                mtr_r[1][1] = -30;
                mtr_r[1][2] = -40;

                mtr_r[2][0] = -26;
                mtr_r[2][1] = -40;
                mtr_r[2][2] = -54;
                fc = compare_matrix(result, na, mb, mtr_r, na, mb);
                if (fc == EQUAL)
                    puts("Test 3 passed.");
                else
                {
                    puts("Test 3 FAIL");
                    rc = IOERROR;
                }
                free_matrix(mtr_r, na);
                free_matrix(result, na);
            }
            else
            {
                puts("Test 3 FAIL");
                rc = IOERROR;
            }
            free_matrix(mtr1, na);
            free_matrix(mtr2, nb);
        }
        else
        {
            puts("Test 3 FAIL");
            rc = IOERROR;
        }
    }

    //Test #4 A * A
    na = 3;
    ma = 3;
    {
        double **mtr1 = allocate_matrix_solid(na, ma);
        double **mtr2 = allocate_matrix_solid(na, ma);
        if (mtr1 && mtr2)
        {
            for (int i = 0; i < na; i++)
                for (int j = 0; j < ma; j++)
                {
                    mtr1[i][j] = i + j;
                    mtr2[i][j] = i - j;
                }


            result = multi(mtr1, mtr2, na, ma, na, ma);
            double **mtr_r = allocate_matrix_solid(na, ma);
            if (mtr_r && result)
            {
                mtr_r[0][0] = 5;
                mtr_r[0][1] = 2;
                mtr_r[0][2] = -1;

                mtr_r[1][0] = 8;
                mtr_r[1][1] = 2;
                mtr_r[1][2] = -4;

                mtr_r[2][0] = 11;
                mtr_r[2][1] = 2;
                mtr_r[2][2] = -7;
                fc = compare_matrix(result, na, ma, mtr_r, na, ma);
                if (fc == EQUAL)
                    puts("Test 4 passed.");
                else
                {
                    puts("Test 4 FAIL");
                    rc = IOERROR;
                }
                free_matrix(mtr_r, na);
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
    na = 3;
    ma = 3;
    //Test #5
    {
        double **mtr1 = allocate_matrix_solid(na, ma);
        double **mtr2 = allocate_matrix_solid(ma, 1);
        if (mtr1 && mtr2)
        {
            for (int i = 0; i < na; i++)
            {
                mtr2[i][0] = i;
                for (int j = 0; j < ma; j++)
                    mtr1[i][j] = i + j;
            }

            result = multi(mtr1, mtr2, na, ma, ma, 1);
            double **mtr_r = allocate_matrix_solid(na, 1);
            if (mtr_r && result)
            {
                mtr_r[0][0] = 5;
                mtr_r[1][0] = 8;
                mtr_r[2][0] = 11;
                fc = compare_matrix(result, na, 1, mtr_r, na, 1);
                if (fc == EQUAL)
                    puts("Test 5 passed.");
                else
                {
                    puts("Test 5 FAIL");
                    rc = IOERROR;
                }
                free_matrix(mtr_r, na);
                free_matrix(result, na);
            }
            else
            {
                puts("Test 5 FAIL");
                rc = IOERROR;
            } 
            free_matrix(mtr1, na);
            free_matrix(mtr2, ma);
        }
        else
        {
            puts("Test 5 FAIL");
            rc = IOERROR;
        }
    }

    //Test #6
    {

        double **mtr1 = allocate_matrix_solid(1, ma);
        double **mtr2 = allocate_matrix_solid(na, ma);
        if (mtr1 && mtr2)
        {
            for (int i = 0; i < na; i++)
            {
                mtr1[0][i] = i;
                for (int j = 0; j < ma; j++)
                    mtr2[i][j] = i + j;
            }

            result = multi(mtr1, mtr2, 1, ma, na, ma);
            double mtr_r[3][1] = { { 5 }, { 8 }, { 11 } }; 
            double *mtr_r2[3] = { mtr_r[0], mtr_r[1], mtr_r[2] };
            if (result)
            {
                fc = compare_matrix(result, 1, ma, mtr_r2, 1, ma);
                if (fc == EQUAL)
                    puts("Test 6 passed.");
                else
                {
                    puts("Test 6 FAIL");
                    rc = IOERROR;
                }
                free_matrix(result, 1);
            }
            else
            {
                puts("Test 6 FAIL");
                rc = IOERROR;
            }
            free_matrix(mtr1, 1);
            free_matrix(mtr2, na);
        }
        else
        {
            puts("Test 6 FAIL");
            rc = IOERROR;
        } 
    }

    //Test #7
    {

        double **mtr1 = allocate_matrix_solid(na, ma);
        double **mtr2 = allocate_matrix_solid(na, ma);
        if (mtr1 && mtr2)
        {
            mtr1[0][0] = 2;
            mtr1[0][1] = 5;
            mtr1[0][2] = 7;

            mtr1[1][0] = 6;
            mtr1[1][1] = 3;
            mtr1[1][2] = 4;

            mtr1[2][0] = 5;
            mtr1[2][1] = -2;
            mtr1[2][2] = -3;

            mtr2[0][0] = 1;
            mtr2[0][1] = -1;
            mtr2[0][2] = 1;

            mtr2[1][0] = -38;
            mtr2[1][1] = 41;
            mtr2[1][2] = -34;

            mtr2[2][0] = 27;
            mtr2[2][1] = -29;
            mtr2[2][2] = 24;
            result = multi(mtr1, mtr2, na, ma, na, ma);
            double **mtr_r = allocate_matrix_solid(na, na);
            if (mtr_r && result)
            {
                init_matrix(mtr_r, na, ma);
                mtr_r[0][0] = 1;
                mtr_r[1][1] = 1;
                mtr_r[2][2] = 1;
                fc = compare_matrix(result, na, ma, mtr_r, na, ma);
                if (fc == EQUAL)
                    puts("Test 7 passed.");
                else
                {
                    puts("Test 7 FAIL");
                    rc = IOERROR;
                }
            }
            else
            {
                puts("Test 7 FAIL");
                rc = IOERROR;
            }            
            free_matrix(mtr1, na);
            free_matrix(mtr2, na);
            free_matrix(mtr_r, na);
            free_matrix(result, na);
        }
        else
        {
            puts("Test 7 FAIL");
            rc = IOERROR;
        }
    }

    return rc;
}
