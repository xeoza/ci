#include "functions.h"
#include <string.h>
//app.exe action mtr_1.txt [mtr_2.txt] res.txt
//a - summa; m - multiplication; o - new_operation (for this operation mtr_2.txt don`t have) 
int main(int argc, char **argv)
{
    setbuf(stdout, NULL);
    int rc = SUCCESS;

    if ((*argv[1] == 'a' || *argv[1] == 'm') && (argc == 5))
    {
        FILE * mtr1, * mtr2, * res;
        mtr1 = fopen(argv[2], "r");
        if (mtr1)
        {
            mtr2 = fopen(argv[3], "r");
            if (mtr2)
            {
                res = fopen(argv[4], "w");
                if (res)
                {
                    int n, m;
                    double **matrix1;
                    matrix1 = read_matrix(mtr1, &n, &m);
                    if (matrix1)
                    {
                        int a, b;
                        double **matrix2, **matrixr;
                        matrix2 = read_matrix(mtr2, &a, &b); 
                        if (matrix2)
                        {
                            if (*argv[1] == 'a')
                            {
                                matrixr = add(matrix1, matrix2, n, m, a, b);
                            }
                            if (*argv[1] == 'm') 
                            {
                                matrixr = multi(matrix1, matrix2, n, m, a, b);
                            }
                            if (matrixr)
                            {
                                fprint_matrix(res, matrixr, n, b);
                                free_matrix(matrixr, n);
                            }
                            else
                                rc = ALLOC_ERR;
                            free_matrix(matrix2, a);
                        }
                        else
                            rc = ALLOC_ERR;
                        free_matrix(matrix1, n);
                    }
                    else
                        rc = ALLOC_ERR;
                }
                else
                    rc = FILE_NOT_EXIST;
                fclose(mtr2);
            }
            else
                rc = FILE_NOT_EXIST;
            fclose(mtr1);
        }
        else
            rc = FILE_NOT_EXIST;
    }
    else if ((*argv[1] == 'o') && (argc == 4))
    {
        FILE * mtr1, * res;
        mtr1 = fopen(argv[2], "r");
        if (mtr1)
        {
            res = fopen(argv[3], "w");
            if (res)
            {
                int n, m;
                double **matrix1, answer;
                matrix1 = read_matrix(mtr1, &n, &m);
                if (matrix1)
                {
                    if (n == m)
                    {
                        answer = determinant(matrix1, n);
                        if (answer != ALLOC_ERR)
                        {
                            fprintf(res, "%lf", answer);
                        }
                        else
                            rc = ALLOC_ERR;
                    }
                    else 
                        rc = IOERROR;
                    free_matrix(matrix1, n);
                }
                else
                    rc = ALLOC_ERR;
                fclose(res);
            }
            else
                rc = FILE_NOT_EXIST;
            fclose(mtr1);
        }
        else
            rc = FILE_NOT_EXIST;
    }
    else
        rc = IOERROR;

    printf("Err_code = %d", rc);
    return rc;
}
 