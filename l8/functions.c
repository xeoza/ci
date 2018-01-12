#include "functions.h"
#include <math.h>
#include <assert.h>
#define MY_EOF -1 //indicate that the End-of-File
#define MY_SEEK_END 2 /* relative to end of file */

void minor(double **mas, double **p, int i, int j, int m) 
{
    if (p)
    {
        int di = 0, dj;
        di = 0;
        for (int ki = 0; ki < m - 1; ki++) 
        { 
            if (ki == i) 
                di = 1;
            dj = 0;
            for (int kj = 0; kj < m - 1; kj++) 
            {
                if (kj == j) 
                    dj = 1;
                p[ki][kj] = mas[ki + di][kj + dj];
            }
        }
    }
}
double determinant(double **mas, int m) 
{
    double det = 0;
    assert((m > 0) && mas);
    if (m == 1) 
    {
        det = mas[0][0];
        return det;
    }
    if (m == 2) 
    {
        det = (mas[0][0] * mas[1][1]) - (mas[1][0] * mas[0][1]);
        return det;
    }
    if (m > 2) 
    {
        int j = 0, k = 1, n = m - 1;
        double **minor1 = allocate_matrix_solid(m - 1, m - 1), det = 0;
        for (int i = 0; i < m; i++) 
        {
            minor(mas, minor1, i, j, m);
            det = det + k * mas[i][0] * determinant(minor1, n);
            k = -k;
        }
        free_matrix(minor1, m - 1);
        return det;
    }
    else
        return IOERROR;
}

/*
double **allocate_matrix_solid(const int n, const int m)
{
    double **data = malloc(n * sizeof(double*) + n * m * sizeof(double));
    
    if (!data)
        return NULL;

    for (int i = 0; i < n; i++)
        data[i] = (double*)((char*) data + n * sizeof(double*) + i * m * sizeof(double));
    return data;
}
void free_matrix(double **data, int n)
{
    if (data != NULL)
        free(data);
}*/

double **allocate_matrix_solid(const int n, const int m)
{
    double **data = calloc(n, sizeof(double*));
    if (!data)
        return NULL;

    for (int i = 0; i < n; i++)
    {
        data[i] = malloc(m * sizeof(double));
        if (!data[i])
        {
            free_matrix(data, n);
            return NULL;
        }
    }

    return data;
}

void free_matrix(double **data, int n)
{
    for (int i = 0; i < n; i++)
        free(data[i]);
    free(data);
}

int compare_double(double a, double b)
{
    if (fabs(a - b) <= EPS * fmax(fabs(a), fabs(b)))
    {
    // Числа равны с относительной точностью eps (0 < eps < 1)
        return EQUAL;
    }
    else
        return NOT_EQUAL;
}
int compare_matrix(double **mtr1, const int na, const int ma, double **mtr2, const int nb, const int mb)
{
    if (na != nb || ma != mb)
        return NOT_EQUAL;
    
    if (!mtr1 && !mtr2)
        return IOERROR;

    int rc = 0;
    for (int i = 0; i < na; i++)
    {
        for (int j = 0; j < ma; j++)
        {
            rc = compare_double(mtr1[i][j], mtr2[i][j]);
            if (rc == NOT_EQUAL)
                return NOT_EQUAL;
        }
    }
    return EQUAL;
}
double **add(double **mtr1, double **mtr2, const int na, const int ma, const int nb, const int mb)
{
    if (na != nb || ma != mb)
        return NULL;
    if (mtr1 && mtr2)
    {
        double **mtr_res = allocate_matrix_solid(na, ma);
        if (mtr_res)
        {
            for (int i = 0; i < na; i++)
            {
                for (int j = 0; j < ma; j++)
                    mtr_res[i][j] = mtr1[i][j] + mtr2[i][j];
            }
            return mtr_res;
        }
        else
        {
            free_matrix(mtr_res, na);
            return NULL;
        }
    }
    else 
    {
        return NULL;
    }
}
void init_matrix(double **mtr, const int n, const int m)
{
    if (mtr)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                mtr[i][j] = 0;
            }
        }
    }  
}
double **multi(double **mtr1, double **mtr2, const int n, const int m, const int l, const int k)
{
    if (m != l)
        return NULL;

    double **mtr_res = allocate_matrix_solid(n, k);

    if (mtr_res && mtr1 && mtr2)
    {
        //init_matrix(mtr_res, n, k);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                mtr_res[i][j] = 0;
                for (int l = 0; l < m; l++)
                {
                    mtr_res[i][j] += mtr1[i][l] * mtr2[l][j];
                }
            }
        }
        return mtr_res;
    }
    else
    {
        free_matrix(mtr_res, n);
        return NULL;
    }
}

double **read_matrix(FILE *file_in, int *n, int *m)
{
    if (!file_in)
        return NULL;
           
    fseek(file_in, 0, MY_SEEK_END);
    int pos = ftell(file_in);
    //pos < 2 сразу return
    if (pos < 2)
        return NULL;
    rewind(file_in);
    if ((fscanf(file_in, "%d %d", n, m) != 2) && (*n > 0 && *m > 0))
        return NULL;
    fscanf(file_in, "\n");
    pos = 0;
    double **matrix = allocate_matrix_solid(*n, *m);
    if (matrix == NULL)
        return NULL;
    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *m; j++)
        {
            if (fscanf(file_in, "%lf", &(matrix[i][j])) != MY_EOF)
                pos++;
        }
    }
    if (pos != (*n * *m))
    {
        free_matrix(matrix, *n);
        return NULL;
    }
    else
        return matrix;
}

void fprint_matrix(FILE *file_out, double **matrix, const int n, const int m)
{
    if (file_out)
    {
        fprintf(file_out, "%d \t %d\n", n, m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                fprintf(file_out, "%f ", matrix[i][j]);

            fprintf(file_out, "\n");
        }
    }
}
