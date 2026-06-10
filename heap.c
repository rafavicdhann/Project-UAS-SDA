#include <stdio.h>
#include <string.h>

#include "heap.h"

/* ================= MIN HEAP ================= */

void swapWord(WordFreq *a, WordFreq *b)
{
    WordFreq temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(
    WordFreq heap[],
    int size,
    int root)
{
    int smallest = root;

    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if(left < size &&
       heap[left].frequency <
       heap[smallest].frequency)
    {
        smallest = left;
    }

    if(right < size &&
       heap[right].frequency <
       heap[smallest].frequency)
    {
        smallest = right;
    }

    if(smallest != root)
    {
        swapWord(
            &heap[root],
            &heap[smallest]);

        minHeapify(
            heap,
            size,
            smallest);
    }
}

void buildMinHeap(
    WordFreq heap[],
    int size)
{
    for(int i = size/2 - 1; i >= 0; i--)
    {
        minHeapify(heap, size, i);
    }
}

/* ================= MAX HEAP ================= */

void maxHeapify(
    WordFreq heap[],
    int size,
    int root)
{
    int largest = root;

    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if(left < size &&
       heap[left].frequency >
       heap[largest].frequency)
    {
        largest = left;
    }

    if(right < size &&
       heap[right].frequency >
       heap[largest].frequency)
    {
        largest = right;
    }

    if(largest != root)
    {
        swapWord(
            &heap[root],
            &heap[largest]);

        maxHeapify(
            heap,
            size,
            largest);
    }
}

void buildMaxHeap(
    WordFreq heap[],
    int size)
{
    for(int i = size/2 - 1; i >= 0; i--)
    {
        maxHeapify(heap, size, i);
    }
}

/* ================= TOP K SERING ================= */

void getMostFrequent(
    WordFreq words[],
    int n,
    int k,
    WordFreq result[])
{
    for(int i = 0; i < k; i++)
    {
        result[i] = words[i];
    }

    buildMinHeap(result, k);

    for(int i = k; i < n; i++)
    {
        if(words[i].frequency >
           result[0].frequency)
        {
            result[0] = words[i];

            minHeapify(
                result,
                k,
                0);
        }
    }
}

/* ================= TOP K JARANG ================= */

void getLeastFrequent(
    WordFreq words[],
    int n,
    int k,
    WordFreq result[])
{
    for(int i = 0; i < k; i++)
    {
        result[i] = words[i];
    }

    buildMaxHeap(result, k);

    for(int i = k; i < n; i++)
    {
        if(words[i].frequency <
           result[0].frequency)
        {
            result[0] = words[i];

            maxHeapify(
                result,
                k,
                0);
        }
    }
}
