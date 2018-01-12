#include <stdio.h>
#include <stdlib.h>

void matrix_free(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
        free(matrix[i]);

    free(matrix);
}

void BubleSort(int* a, int N)
{
	for(int i = 0 ; i < N ; i++)
	{
        for(int j = 0 ; j < N - i - 1 ; j++)
        {
            if(a[j] > a[j+1])
            {
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}

int **matrix_init(int n, int m)
{
    int **matrix = calloc(n, sizeof(int *));
    if (!matrix)
        return NULL;

    for (int i = 0; i < n; i++)
    {
        matrix[i] = calloc(m, sizeof(int));

        if (!matrix[i])
        {
            matrix_free(matrix, n);
            return NULL;
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            matrix[i][j] = 0;

    return matrix;
}

int getSize(FILE *data, int *n, int *m)
{
    if (fscanf(data, "%d %d", n, m) == 2)
        return 0;
    return -1;
}

int getMatrix(FILE *data, int **matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (fscanf(data, "%d", &matrix[i][j]) != 1)
                return -1;
    return 0;

}

int main(int argc, char *argv[])
{
    setbuf(stdout, NULL);

    if (argc != 2)
    {
        printf("Wrong number of arguments!\n");
        return -1;
    }

    FILE *data = fopen(argv[1], "r");

    int n;
    int m;

    if (getSize(data, &n, &m) != 0)
    {
        fclose(data);
        printf("Wrong size in file!\n");
        return -2;
    }


    int **matrix = matrix_init(n, m);
    if (getMatrix(data, matrix, n, m) != 0)
    {
        matrix_free(matrix, n);
        fclose(data);
        printf("Wrong data in file!\n");
        return -3;
    }

    for(int i = 0; i<n; i++)
    {
    	for (int j = 0; j < m; j++)
    	{
    		printf("%d ", matrix[i][j]);
    	}
    	printf("\n");
    }

    for (int i = 0; i < n; i++)
    {
    	if (i % 2 != 0)
    	{
    		BubleSort(matrix[i], m);
    	}
    }
    printf("Sorted\n");
    for(int i = 0; i<n; i++)
    {
    	for (int j = 0; j < m; j++)
    	{
    		printf("%d ", matrix[i][j]);
    	}
    	printf("\n");
    }


    matrix_free(matrix, n);

    fclose(data);
    return 0;
}
