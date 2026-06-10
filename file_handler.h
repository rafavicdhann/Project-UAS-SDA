#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include "word.h"

WordFreq* loadVocabulary(const char *filename, int *totalWords);

void loadDocword(
    const char *filename,
    WordFreq words[],
    int totalWords
);

#endif
