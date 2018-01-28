#include "func.h"

void push(node **head, char *data)
{
	node *tmp = (node *) malloc(sizeof(node));
	if (!tmp)
		return;
	strcpy(tmp->word, data);
	tmp->next = (*head);
	(*head) = tmp;
}
void reverse(node **head)
{
	if (*head == NULL) return;
	node *curr, *next, *prev = NULL;
	curr = *head;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}

int replace_min_max(node **head)
{
	int rc = OK;
	if(*head)
	{
		int min = strlen((*head)->word), max = strlen((*head)->word);
		node *tmp = *head, *max_l, *min_l;
		puts("ok");
		while(*head)
		{
			if (strlen((*head)->word) > max)
			{
				max = strlen((*head)->word);
				max_l = *head;
			}

			if (strlen((*head)->word) < min)
			{
				min = strlen((*head)->word);
				min_l = *head;
			}
			*head = (*head)->next;
		}
		puts("ok");
		*head = tmp;
		char tmp_word[20];
		strcpy(tmp_word, max_l->word);
		strcpy(max_l->word, min_l->word);
		strcpy(min_l->word, tmp_word);
	}
	else
		rc = IOERROR;
	return rc;
}
void printf_list(node *head)
{
	if(head)
	{
		while(head)
		{
			printf("%s\n", head->word);
			head = head->next;
		}
	}
}
int read_data(FILE *in, node **head)
{
	int rc = OK;
	if (in)
	{
		char tmp[20];
		while (fscanf(in, "%s", tmp) == 1)
		{
			push(head, tmp);
		}
	}
	else
	{
		rc = IOERROR;
	}
	return rc;
}
void delete_list(node **head)
{
	node *tmp = NULL;
	while ((*head)->next)
	{
		tmp = (*head);
		*head = (*head)->next;
		free(tmp);
	}
	free(*head);
}