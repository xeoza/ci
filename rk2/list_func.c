#include "list_func.h"
#include <assert.h>

int read_data(FILE *stream, char *name, int *marks)
{
	//printf("INFUNC\n");
	if (fscanf(stream, "%80s", name) != 1)
		return -1;
	for (int i = 0; i < MAX_EXAM; i++)
	{
		if (fscanf(stream, "%d", &marks[i]) != 1)
			return -1;
	}
	//printf("READDATAIN\n");
	return 0;
}

stud_t * create_node(const char *name, const int *marks)
{
	stud_t *node = (stud_t *) malloc(sizeof(stud_t));
	if (!node)
		return NULL;
	strcpy(node->name, name);
	memmove(node->marks, marks, MAX_EXAM * sizeof(int));
	node->next = NULL;
	return node;
}

int fscan_list(FILE * stream, stud_t **head)
{

	char name[MAX_LEN_NAME + 1];
	int marks[MAX_EXAM];
	int cn_read = 0;
	stud_t *tmp = NULL;

	while (read_data(stream, name, marks) == 0)
	{
		tmp = create_node(name, marks);
		if (tmp == NULL)
		{
			return -1;
		}
		if (*head == NULL)
		{
			*head = tmp;
		}
		else 
		{
			tmp->next = *head;
			*head = tmp;
		}
		cn_read++;
	}
	return cn_read;
}

void free_list(stud_t **head)
{
	stud_t *tmp = NULL;
	for (stud_t *cur = *head; cur != NULL; cur = cur->next)
	{
		tmp = cur;
		free(tmp);
	}
	*head = NULL;
}

void fprint_list(FILE * stream, stud_t *head)
{
	for (stud_t *cur = head; cur != NULL; cur = cur->next)
	{
		fprintf(stream, "%s\n", cur->name);
		for (int i = 0; i < MAX_EXAM; i++)
			fprintf(stream, "%d ", cur->marks[i]);
		fprintf(stream, "\n");
	}
}

void print_list(stud_t *head)
{
	for (stud_t *cur = head; cur != NULL; cur = cur->next)
	{
		printf("%s\n", cur->name);
		for (int i = 0; i < MAX_EXAM; i++)
			printf("%d ", cur->marks[i]);
		printf("\n");
	}
}


double avr_marks(const int *marks, int size)
{
	double sum = 0;
	for (int i = 0; i < size; i++)
		sum += marks[i];
	return sum / size;
}

double find_min_array(stud_t *head)
{
	assert (head != NULL);
	double min = avr_marks(head->marks, MAX_EXAM);
	head = head->next;
	while (head)
	{
		double sr = avr_marks(head->marks, MAX_EXAM);
		if (sr < min)
		{
			min = sr;
			//printf("min = %lf\n", min);
		}

		head = head->next;
	}
	return min;
}

/*int rm_stud(stud_t **head, double min)
{
	double avg;
	stud_t *cur;
	stud_t *tmp;
	for (cur = *head; cur != NULL; cur = cur->next)
	{
		avg = avr_marks(cur->marks, MAX_EXAM);
		if (avg <= min)
		{
			tmp = cur;
			cur = cur->next;
			free(tmp);
		}
	}
	return 0;
}*/


stud_t * rm_stud(stud_t *head, double min)
{
	stud_t *node;
	stud_t *cur = head;
	stud_t *prev = NULL;

	while (cur != NULL)
	{
		if (avr_marks(cur->marks, MAX_EXAM) ==  min)
		{
			if (prev != NULL)
			{
				prev->next = cur->next;
			}
			else
				head = cur->next;
			node = cur;
			cur = cur->next;
			free(node);
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}

stud_t * sort(stud_t *head)
{
	stud_t *node, *new_head, *cur, *prev;
	new_head = NULL;
	while (head != NULL)
	{
		node = head;
		head = head->next;
		for (cur = new_head, prev = NULL; cur != NULL && 
			avr_marks(node->marks, MAX_EXAM) > avr_marks(cur->marks, MAX_EXAM);
			 prev = cur, cur = cur->next);
		if (prev == NULL)
		{
			node->next = new_head;
			new_head = node;
		}
		else
		{
			node->next = cur;
			prev->next = node;
		}
	}
	return new_head;
}
