#ifndef STRPROJECT_STRING__H
#define STRPROJECT_STRING__H

#define MAX_STRING_SIZE 100

#include <stdlib.h>


typedef struct WordDescriptor {
    char *begin;
    char *end;
} WordDescriptor;

char _stringBuffer[MAX_STRING_SIZE + 1];

size_t strlen_(char *begin);

char *find(char *begin, char *end, int ch);

char *findNonSpace(char *begin);

char *findSpace(char *begin);

char *findNonSpaceReverse(char *rbegin, const char *rend);

char *findSpaceReverse(char *rbegin, const char *rend);

int strcmp(const char *lhs, const char *rhs);

char *copy(const char *beginSource, const char *endSource, char *beginDestination);

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

char *getEndOfString(char *s);

int getWord(char *beginSearch, WordDescriptor *word);

void assertString(const char *expected, char *got, char const *fileName, char const *funcName, int line);

#endif
