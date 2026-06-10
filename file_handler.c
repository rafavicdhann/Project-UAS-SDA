#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_handler.h"

WordFreq* loadVocabulary(const char *filename, int *totalWords)
{
    FILE *fp = fopen(filename, "r");

    if(fp == NULL)
    {
        printf("Gagal membuka file vocabulary!\n");
        return NULL;
    }

    char buffer[256];

    int count = 0;

    while(fgets(buffer, sizeof(buffer), fp))
    {
        count++;
    }

    rewind(fp);

    WordFreq *words =
        (WordFreq*)malloc(count * sizeof(WordFreq));

    if(words == NULL)
    {
        printf("Alokasi memori gagal!\n");
        fclose(fp);
        return NULL;
    }

    int i = 0;

    while(fgets(buffer, sizeof(buffer), fp))
    {
        buffer[strcspn(buffer, "\n")] = '\0';

        strcpy(words[i].word, buffer);
        words[i].frequency = 0;

        i++;
    }

    *totalWords = count;

    fclose(fp);

    return words;
}

void loadDocword(
    const char *filename,
    WordFreq words[],
    int totalWords
)
{
    FILE *fp = fopen(filename, "r");

    if(fp == NULL)
    {
        printf("Gagal membuka file docword!\n");
        return;
    }

    long long D;
    long long W;
    long long N;

    fscanf(fp, "%lld", &D);
    fscanf(fp, "%lld", &W);
    fscanf(fp, "%lld", &N);

    printf("\nJumlah Dokumen : %lld\n", D);
    printf("Jumlah Kata    : %lld\n", W);
    printf("Jumlah NNZ     : %lld\n", N);

    int docID;
    int wordID;
    int count;

    while(fscanf(fp,
                 "%d %d %d",
                 &docID,
                 &wordID,
                 &count) == 3)
    {
        if(wordID >= 1 && wordID <= totalWords)
        {
            words[wordID - 1].frequency += count;
        }
    }

    fclose(fp);

    printf("\nFrekuensi berhasil dihitung.\n");
}
