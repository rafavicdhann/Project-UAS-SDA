#ifndef HEAP_H
#define HEAP_H

#include "word.h"

void getMostFrequent(
    WordFreq words[],
    int n,
    int k,
    WordFreq result[]
);

void getLeastFrequent(
    WordFreq words[],
    int n,
    int k,
    WordFreq result[]
);

#endif
