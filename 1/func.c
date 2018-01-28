#include "func.h"

void push(node **head, int data)//add new element in struct "node"
{
	node *tmp = (node *) malloc(sizeof(node));
	tmp->value = data;
	tmp->next = (*head);
	*head = tmp;
}

void delete_node(node **head)//free memory for struct "node"
{
	node *tmp = NULL;
	while ((*head)->next)
	{
		tmp = (*head);
		(*head) = (*head)->next;
		free (tmp);

	}
	free(*head);
}

int read_data(FILE *in, node **head_one, node **head_two)
{
	int rc = OK;
	if (in)
	{
		int first_value, second_value;
		if (fscanf(in, "%d ", &first_value) == 1)
		{
			if (fscanf(in, "%d", &second_value) == 1)
			{
				while(first_value > 0)
				{
					push(head_one, (first_value % 10));
					first_value /= 10;
				}
				while(second_value > 0)
				{
					push(head_two, (second_value % 10));
					second_value /= 10;
				}  
			}
			else
			{
				rc = IOERROR;
			}
		}
		else
		{
			rc = IOERROR;
		}
	}
	else
	{
		rc = ERR_OPEN_FILE;
	}
	return rc;
}
int size_node(node *head)
{
	int n = 0;
	//for(int n = 0, (head != NULL), ((head = head->next) && (n++)));
	while (head)
	{
		n++;
		head = head->next;
	}
	return n;
}
int sum_node(node *head_one, node *head_two, node **result)
{
	int rc = OK;
	if (head_one && head_two)
	{
		int s_one = size_node(head_one), s_two = size_node(head_two);
		int tmp;
		if (s_one >= s_two)
		{	
			while (head_two)
			{
				tmp = (head_two)->value + (head_one)->value;
				(head_two) = (head_two)->next;
				(head_one) = (head_one)->next;
				push(result, tmp);
				//push_back(result, tmp);
			}
		}
		else
		{
			while (head_one)
			{
				tmp = (head_one)->value + (head_two)->value;
				(head_one) = (head_one)->next;
				(head_two) = (head_two)->next;
				push(result, tmp);
				//push_back(result, tmp);
			}
		}
	}
	else
	{
		rc = IOERROR;
	}
	return rc;
}
void print_node(node *head)
{
	while (head)
	{
		printf("%d\n", head->value);
		head = head->next;
	}
}
int round_up_number(node **head)
{
	int rc = OK;
	node *tmp = *head;
	if (*head)
	{
		while (*head)
		{
			if ((*head)->value > 9)
			{
				if((*head)->next)
				{
					(*head)->value -= 10;
					(*head) = (*head)->next;
					(*head)->value += 1;
				}
				else
				{
					(*head) = (*head)->next;
				}
			}
			else
			{
				(*head) = (*head)->next;
			}
		}
	}
	else
	{
		rc = IOERROR;
	}
	*head = tmp; 
	return rc;
}

void reverse(node **head)
{
    if (*head == NULL) return;
    node * curr, *next, *prev = NULL;
    curr = *head;
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}
int translate_to_int(node *head)
{
	if (head)
	{
		int tmp = head->value;
		while (head->next)
		{
			head = head->next;
			tmp = tmp * 10 + head->value;
		}
		return tmp;
	}
	return IOERROR;
}