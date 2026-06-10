#ifndef WORD_H
#define WORD_H

#define MAX_WORD_LENGTH 100
#define TOP_K 100

typedef struct
{
    char word[MAX_WORD_LENGTH];
    long long frequency;
} WordFreq;

#endif
