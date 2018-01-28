#ifndef H_FUNC
#define H_FUNC
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define OK 0
#define IOERROR -1
#define ERR_NO_FILE -2
typedef struct node
{
	char word[20];
	struct node *next;
}node;
void push(node **head, char *data);
int read_data(FILE *in, node **head);
void delete_list(node **head);
void printf_list(node *head);
void reverse(node **head);
int replace_min_max(node **head);
#endif