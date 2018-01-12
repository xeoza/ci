#include "functions.h"

ssize_t my_getdelim(char **lineptr, size_t *n, int delimiter, FILE *stream) 
{
    char c, *cur_pos, *new_lineptr;
    size_t new_lineptr_len;

    if (lineptr == NULL || n == NULL || stream == NULL) 
    {
        return -1;
    }

    if (*lineptr == NULL) 
    {
        *n = 128; 
        if ((*lineptr = (char *)malloc(*n)) == NULL) 
        {
            return -1;
        }
    }

    cur_pos = *lineptr;
    for (; ;) 
    {
        c = getc(stream);

        if (ferror(stream) || (c == MY_EOF && cur_pos == *lineptr))
        {
            return -1;
        }
        if (c == MY_EOF)
        {
            break;
        }
        if ((*lineptr + *n - cur_pos) < 2)
        {
            new_lineptr_len = *n * 2;
            if ((new_lineptr = (char *)realloc(*lineptr, new_lineptr_len)) == NULL) 
            {
                return -1;
            }
            *lineptr = new_lineptr;
            *n = new_lineptr_len;
        }

        *cur_pos++ = c;

        if (c == delimiter)
        {
            break;
        }
    }

    *cur_pos = '\0';
    return (ssize_t)(cur_pos - *lineptr);
}

ssize_t getline(char **lineptr, size_t *n, FILE *stream)
{
    return my_getdelim(lineptr, n, '\n', stream);
}


size_t count_strstr(const char *needle, const char *haystack) 
{
    if (NULL == needle || NULL == haystack) 
        return -1;

    char *pos = (char *)haystack;
    size_t i = 0, l = my_strlen(needle);
    if (l == 0) 
        return 0;

    while ((pos = my_strstr(pos, needle))) 
    {
        pos += l;
        i++;
    }
    
    return i;
}

char *str_replace(const char *source, const char *search, const char *replace)
{
    char *pos = (char *) source;
    int count = count_strstr(search, source);

    if (count <= 0) 
        return my_strdup(source);

    int size = (my_strlen(source)
        - (my_strlen(search) * count)
        + my_strlen(replace) * count) + 1;

    char *result = (char *) malloc(size);
    if (NULL == result) 
        return NULL;
    memset(result, '\0', size);
    char *current;
    while ((current = my_strstr(pos, search))) 
    {
        int len = current - pos;
        my_strncat(result, pos, len);
        my_strncat(result, replace, my_strlen(replace));
        pos = current + my_strlen(search);
    }

    if (pos != (source + my_strlen(source))) 
    {
        my_strncat(result, pos, (source - pos));
    }

    return result;
}

/*
Объединение строк. Функция добавляет копию строки srcptr в конец строки destptr.
Нулевой символ конца строки destptr заменяется первым символом строки srcptr, и 
новый нуль-символ добавляется в конец уже новой строки, сформированной объединением 
символов двух строк в строке destptr.
*/

char *my_strncat(char *destptr, const char *srcptr, size_t num)
{
	if (num != 0) 
    {
		char *d = destptr;
		const char *s = srcptr;

		while (*d != 0)
			d++;
		do 
        {
			if ((*d = *s++) == 0)
				break;
			d++;
		} while (--num != 0);
		*d = 0;
	}
	return (destptr);
}
/*
Длина строки.
*/
size_t my_strlen(const char *string)
{
    size_t i = 0;
    while (string[i] != '\0')
        i++;
    return i;
}
/*
Функция ищет первое вхождение подстроки string2 в строке string1. 
Возвращает указатель на первое вхождение строки string2 в строку 
string1, или пустой указатель, если строка string2 не является частью
строки string1. В данном поиске нуль-символ не  учитывается.
*/
char *my_strstr(char *string1, const char *string2)
{
    int pos, shift;

    if (string2[0] == '\0')
    {
        return string1;
    }
    for (shift = 0; string1[shift] != '\0'; shift++)
    {
        for (pos = 0; string1[pos + shift] == string2[pos]; pos++)
        {
            if (string2[pos + 1] == '\0')
            {
                return string1 + shift;
            }
        }
    }
    return NULL;
}
/*
Функция strdup дублирует строку, на которую указывает аргумент str. 
Память под дубликат строки выделяется с помощью функции malloc, и по 
окончанию работы с дубликатом должна быть очищена с помощью функции free.
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