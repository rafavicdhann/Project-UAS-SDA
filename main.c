#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "word.h"
#include "file_handler.h"
#include "heap.h"
#include "sort.h"

#define K 100

void saveResult(
    const char *filename,
    WordFreq data[],
    int size,
    double timeMs)
{
    FILE *fp = fopen(filename, "w");

    if(fp == NULL)
    {
        printf("Gagal membuat file hasil!\n");
        return;
    }

    for(int i = 0; i < size; i++)
    {
        fprintf(fp,
                "%s (%lld)\n",
                data[i].word,
                data[i].frequency);
    }

    fprintf(fp,
            "\nWaktu proses : %.3f ms\n",
            timeMs);

    fclose(fp);
}

void displayResult(
    WordFreq data[],
    int size,
    double timeMs)
{
    printf("\n");

    for(int i = 0; i < size; i++)
    {
        printf("%3d. %-30s %lld\n",
               i + 1,
               data[i].word,
               data[i].frequency);
    }

    printf("\nWaktu proses : %.3f ms\n",
           timeMs);
}

int main()
{
    char vocabFile[256];
    char docwordFile[256];

    int totalWords = 0;

    WordFreq *words = NULL;

    WordFreq most[K];
    WordFreq least[K];

    double mostTime = 0;
    double leastTime = 0;

    int choice;

    printf("====================================\n");
    printf(" BIG CHALLENGE SDA\n");
    printf("====================================\n");

    printf("\nMasukkan file vocabulary : ");
    scanf("%255s", vocabFile);

    printf("Masukkan file docword    : ");
    scanf("%255s", docwordFile);

    words = loadVocabulary(
                vocabFile,
                &totalWords);

    if(words == NULL)
    {
        return 1;
    }

    loadDocword(
        docwordFile,
        words,
        totalWords);

    do
    {
        printf("\n");
        printf("====================================\n");
        printf(" MENU\n");
        printf("====================================\n");
        printf("1. 100 kata paling sering\n");
        printf("2. 100 kata paling jarang\n");
        printf("3. Tampilkan kata paling sering\n");
        printf("4. Tampilkan kata paling jarang\n");
        printf("5. Keluar\n");
        printf("Pilihan : ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                clock_t start = clock();

                getMostFrequent(
                    words,
                    totalWords,
                    K,
                    most);

                heapSortDescending(
                    most,
                    K);

                clock_t end = clock();

                mostTime =
                    ((double)(end - start))
                    * 1000
                    / CLOCKS_PER_SEC;

                saveResult(
                    "most_frequent.txt",
                    most,
                    K,
                    mostTime);

                printf("\nData berhasil disimpan ke most_frequent.txt\n");

                break;
            }

            case 2:
            {
                clock_t start = clock();

                getLeastFrequent(
                    words,
                    totalWords,
                    K,
                    least);

                heapSortDescending(
                    least,
                    K);

                clock_t end = clock();

                leastTime =
                    ((double)(end - start))
                    * 1000
                    / CLOCKS_PER_SEC;

                saveResult(
                    "least_frequent.txt",
                    least,
                    K,
                    leastTime);

                printf("\nData berhasil disimpan ke least_frequent.txt\n");

                break;
            }

            case 3:
            {
                displayResult(
                    most,
                    K,
                    mostTime);

                break;
            }

            case 4:
            {
                displayResult(
                    least,
                    K,
                    leastTime);

                break;
            }

            case 5:
            {
                printf("\nProgram selesai.\n");
                break;
            }

            default:
            {
                printf("\nPilihan tidak valid!\n");
            }
        }

    } while(choice != 5);

    free(words);

    return 0;
}
