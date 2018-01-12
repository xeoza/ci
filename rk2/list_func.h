#ifndef __LIST_FUNC_H__
#define __LIST_FUNC_H__

#define MAX_LEN_NAME 80
#define MAX_EXAM 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stud stud_t;
struct stud
{
	char name[MAX_LEN_NAME + 1];
	int marks[MAX_EXAM];
	stud_t *next;
};

int fscan_list(FILE * stream, stud_t **head);
void fprint_list(FILE * stream, stud_t *head);
void print_list(stud_t *head);

void free_list(stud_t **head);
double find_min_array(stud_t *head);
stud_t * rm_stud(stud_t *head, double min);
stud_t * sort(stud_t *head);


#endif
