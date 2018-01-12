#ifndef H_FUNCTIONS
#define H_FUNCTIONS
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#define SUCCESS 0
#define IOERROR -1
#define FILE_NOT_EXIST -2
#define ERROR_PRINT -3
#define ALLOC_ERR -4
#define EQUAL 5
#define NOT_EQUAL -5
#define EPS 1e-6
double **allocate_matrix_solid(const int n, const int m);
double **add(double **mtr1, double **mtr2, const int na, const int ma, const int nb, const int mb);
void init_matrix(double **mtr, const int n, const int m);
double **multi(double **mtr1, double **mtr2, const int n, const int m, const int l, const int k);
double **read_matrix(FILE *file_in, int *n, int *m);
void fprint_matrix(FILE *file_out, double **matrix, const int n, const int m);
int compare_matrix(double **mtr1, const int na, const int ma, double **mtr2, const int nb, const int mb);
int compare_double(double a, double b);
void free_matrix(double **data, int n);
double determinant(double **mas, int m);
void minor(double **mas, double **p, int i, int j, int m);
#endif