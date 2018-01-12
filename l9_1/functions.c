#include "functions.h"
#include <string.h>
#define NOTEQUALS 0
#define EQUALS 1

size_t my_strlen(const char *string)
{
    size_t i = 0;
    while (string[i] != '\0')
        i++;
    return i;
}

int my_strcmp(const char *str1, const char *str2) 
{
    if (my_strlen(str1) != my_strlen(str2))
        return NOTEQUALS;
    for (int i = 0; i < my_strlen(str1); i++) 
    {
        if (str1[i] != str2[i])
            return NOTEQUALS;
    }
    return EQUALS;
}

/*
str – указатель на строку, в которой ведется поиск.
sym – указатель на строку с набором символов, которые должны входить в участок строки str.
Функция strspn определяет наибольшую длину начального участка строки, на которую указывает аргумент str, содержащего только символы строки,
 на которую указывает аргумент sym.
Если первый символ строки str не входит в строку sym, то возвращаемая длина – 0.
*/
size_t my_strspn(const char *str, const char *sym) 
{
    assert(str);
    assert(sym);
    size_t str1_len = my_strlen(str);
    size_t str2_len = my_strlen(sym);
    short flag;
    for (size_t i = 0; i < str1_len; i++) 
    {
        flag = 0;
        for (size_t j = 0; j < str2_len; j++) 
        {
            if (str[i] == sym[j])
            {
                flag = 1;
            }
        }
        if (!flag)
            return i;
    }
    return str1_len;
}
/*
str – указатель на дублируемую строку.
Возвращаемое значение:
NULL – если не удалость выделить память под новую строку или скопировать строку на которую указывает аргумент str.
Указатель на дублирующую строку.

Описание:
Функция strdup дублирует строку, на которую указывает аргумент str. 
Память под дубликат строки выделяется с помощью функции malloc, и по окончанию работы с дубликатом должна быть 
очищена с помощью функции free.
*/
char *my_strdup(const char *str) 
{
    if (!str) 
        return NULL;
    int len = my_strlen(str) + 1;
    char *buf = malloc(len);
    if (buf) 
        memcpy(buf, str, len);
    return buf;
}
