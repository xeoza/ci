#include "func.h"
#define SUCCESS 0
#define WORD_MAX_LEN 20
/* программа которая читает из текстового файла слова и помещает их в линейный односвязный список затем находит элементы содержащие самое длинное и самое короткое слово и меняет их местами слова из этого списка записать в новый файл 20символов*/
void printListF(FILE *f, list_t *head)
{
    list_t *cur = head;

    while(cur)
    {
        fprintf(f, "%s\n", cur->word);
        cur = cur->next;
    }
}

void workWords(FILE *f, list_t *head)
{
    list_t *min = head;
    list_t *max = head;
    list_t *cur = head->next;
    char tmp[20];

    while(cur)
    {
        if (strlen(cur->word) < strlen(min->word))
        {
            min = cur;
        }
        if (strlen(cur->word) > strlen(max->word))
        {
            max = cur;
        }
        cur = cur->next;
    }

    strcpy(tmp, max->word);
    strcpy(max->word, min->word);
    strcpy(min->word, tmp);
    printListF(f, head);
}

int readData(FILE * f, char *word)
{
    if (fscanf(f, "%20s\n", word) != 1)
    {
        printf("Error in word\n");
        return -1;
    }

    return SUCCESS;
}

list_t *initNewNode(char *word)
{
    list_t *new_node;

    new_node = malloc(sizeof(list_t));
    if (!new_node)
        return NULL;

    strcpy(new_node->word, word);
    new_node->next = NULL;

    return new_node;
}

int readListF(FILE * f, list_t **head)
{
    int rc = SUCCESS;
    list_t *new_node;
    list_t *cur;

    char word[WORD_MAX_LEN];
    while(!feof(f))
    {
        rc = readData(f, word);
        if (rc == SUCCESS)
        {
            new_node = initNewNode(word);
            if (new_node)
            {
                if (*head == NULL)
                {
                    *head = new_node;
                    cur = *head;
                }
                else
                {
                        cur->next = new_node;
                        cur = cur->next;
                }
            }
            else
            {
                printf("memory error\n");
                return rc;
            }
        }
        else
        {
            printf("error in reading data rc^ %d\n", rc);
            return rc;
        }
    }
    return rc;
}

void freeList(list_t *head)
{
    list_t *next;
    for ( ; head; head = next)
    {
        next = head->next;
        free(head);
    }
}


