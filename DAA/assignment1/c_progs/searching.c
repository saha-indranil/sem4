// Write a C program to search an element in an Array using dynamic memory
// allocation. Apply different algorithm separately. Show the running time
// complexity w.r.t different input cases(best/average/worst). Finally comment
// that which one is better and why.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to search using linear search
int linearSearch(int *arr, int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

// Function to search using binary search
int binarySearch(int *arr, int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main()
{
    int n = 1000, i, j, x, result;
    int *arr;
    clock_t start, end;

    // Allocating memory dynamically
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 0;
    }

    // Initializing the array with random numbers
    srand(time(NULL));
    for (i = 0; i < n; i++)
        arr[i] = rand() % (n * 10);

    // Sorting the array
    int temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Linear Search: Best Case
    x = arr[0];
    start = clock();
    for (i = 0; i < 10000; i++)
        result = linearSearch(arr, n, x);
    end = clock();
    printf("Best case scenario for linear search: %.2f ms\n", ((double)(end - start)) * 1000 / CLOCKS_PER_SEC);

    // Binary Search: Best Case
    x = arr[(n - 1) / 2];
    start = clock();
    for (i = 0; i < 10000; i++)
        result = binarySearch(arr, 0, n - 1, x);
    end = clock();
    printf("Best case scenario for binary search: %.2f ms\n", ((double)(end - start)) * 1000 / CLOCKS_PER_SEC);

    // Linear Search: Average Case
    x = arr[n / 2];
    start = clock();
    for (i = 0; i < 10000; i++)
        result = linearSearch(arr, n, x);
    end = clock();
    printf("Average case scenario for linear search: %.2f ms\n", ((double)(end - start)) * 1000 / CLOCKS_PER_SEC);

    // Binary Search: Average Case
    x = arr[62];
    start = clock();
    for (i = 0; i < 10000; i++)
        result = binarySearch(arr, 0, n - 1, x);
    end = clock();
    printf("Average case scenario for binary search: %.2f ms\n", ((double)(end - start)) * 1000 / CLOCKS_PER_SEC);

    // Linear Search: Worst Case
    x = arr[n - 1];
    start = clock();
    for (i = 0; i < 10000; i++)
        result = linearSearch(arr, n, x);
    end = clock();
    printf("Worst case scenario for linear search: %.2f ms\n", ((double)(end - start)) * 1000 / CLOCKS_PER_SEC);

    // Binary Search: Worst Case
    x = arr[n - 1];
    start = clock();
    for (i = 0; i < 10000; i++)
        result = binarySearch(arr, 0, n - 1, x);
    end = clock();
    printf("Worst case scenario for binary search: %.2f ms\n", ((double)(end - start)) * 1000 / CLOCKS_PER_SEC);

    free(arr);
    return 0;
}

// OUTPUT
// Best case scenario for linear search: 0.00 ms
// Best case scenario for binary search: 0.00 ms
// Average case scenario for linear search: 22.00 ms
// Average case scenario for binary search: 1.00 ms
// Worst case scenario for linear search: 33.00 ms
// Worst case scenario for binary search: 4.00 ms

// Binary search is more efficient than linear search because
// it divides the search area in half with each iteration, reducing
// the amount of elements that need to be searched through.This
// results in a faster search time, especially as the size of
// the search area increases.