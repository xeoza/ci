#ifndef FUNC_H
#define FUNC_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

int readData(FILE * f, char *word);

void workWords(FILE *f, list_t *head);

list_t *initNewNode(char *word);

int readListF(FILE * f, list_t **head);

void printListF(FILE *f, list_t *head);

void freeList(list_t *head);

#endif
