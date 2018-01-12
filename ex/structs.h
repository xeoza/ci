#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct Node
{
    struct Node *next;
    char word[20];
} list_t;

#endif
