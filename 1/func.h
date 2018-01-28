#ifndef H_FUNC
#define H_FUNC
#include <stdio.h>
#include <malloc.h>
#define OK 0
#define IOERROR -1
#define ERR_OPEN_FILE -2
typedef struct node
{
	int value;
	struct node *next;
} node;    
void print_node(node *head);
int read_data(FILE *in, node **head_one, node **head_two);
void delete_node(node **head);//free memory for struct "node"
void push(node **head, int data);//add new element in struct "node"
int size_node(node *head);
int sum_node(node *head_one, node *head_two, node **result);
int round_up_number(node **head);
void reverse(node **head);
int translate_to_int(node *head);
#endif
