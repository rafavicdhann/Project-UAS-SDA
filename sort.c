#include <stdio.h>

#include "sort.h"

void swapSort(
    WordFreq *a,
    WordFreq *b)
{
    WordFreq temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(
    WordFreq arr[],
    int n,
    int root)
{
    int largest = root;

    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if(left < n &&
       arr[left].frequency >
       arr[largest].frequency)
    {
        largest = left;
    }

    if(right < n &&
       arr[right].frequency >
       arr[largest].frequency)
    {
        largest = right;
    }

    if(largest != root)
    {
        swapSort(
            &arr[root],
            &arr[largest]);

        heapify(
            arr,
            n,
            largest);
    }
}

void heapSortAscending(
    WordFreq arr[],
    int n)
{
    for(int i = n/2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for(int i = n - 1; i > 0; i--)
    {
        swapSort(
            &arr[0],
            &arr[i]);

        heapify(
            arr,
            i,
            0);
    }
}

void heapSortDescending(
    WordFreq arr[],
    int n)
{
    heapSortAscending(arr, n);

    int left = 0;
    int right = n - 1;

    while(left < right)
    {
        swapSort(
            &arr[left],
            &arr[right]);

        left++;
        right--;
    }
}

void insertionSort(
    WordFreq arr[],
    int n)
{
    for(int i = 1; i < n; i++)
    {
        WordFreq key = arr[i];

        int j = i - 1;

        while(j >= 0 &&
              arr[j].frequency >
              key.frequency)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}
