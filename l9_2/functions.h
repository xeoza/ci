#ifndef GETLINE_H
#define GETLINE_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>

#define SUCCESS 0
#define IOERROR -1
#define TEST_ERR -2

#define MY_EOF -1 //indicate that the End-of-File
#define MY_SEEK_END 2 /* relative to end of file */

size_t count_strstr(const char *needle, const char *haystack);
size_t my_strlen(const char *str);
char *my_strncat(char *destptr, const char *srcptr, size_t num);
char *my_strstr(char *string1, const char *string2);
char *my_strdup(const char *str);

char *str_replace(const char *source, const char *search, const char *replace);
//ssize_t getline(char **lineptr, size_t *n, FILE *stream);
ssize_t my_getdelim(char **lineptr, size_t *n, int delimiter, FILE *stream); 

#endif /* GETLINE_H */