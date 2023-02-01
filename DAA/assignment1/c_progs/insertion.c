// Write a program to perform insertion sort using dynamic memory allocation.
// Show the running time complexity w.r.t different input cases. Finally comment
// that whether it is matching with the expected complexity of O(n^2) or not.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int *arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int n = 1000, i, j;
    clock_t start, end;
    int **arr;

    // Allocating memory dynamically
    arr = (int **)malloc(1000 * sizeof(int *));
    for (i = 0; i < 1000; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 0;
    }

    // Best Case: Array is already sorted
    for (j = 0; j < n; j++)
        arr[0][j] = j;
    start = clock();
    for (i = 0; i < 1000; i++)
        insertionSort(arr[0], n);
    end = clock();
    printf("Best Case: %ld ms\n", (end - start));

    // Average Case: Array is random
    for (i = 0; i < 1000; i++)
    {
        for (j = 0; j < n; j++)
            arr[i][j] = rand() % n;
    }
    start = clock();
    for (i = 0; i < 1000; i++)
        insertionSort(arr[i], n);
    end = clock();
    printf("Average Case: %ld ms\n", (end - start));

    // Worst Case: Array is sorted in reverse order
    for (i = 0; i < 1000; i++)
    {
        for (j = 0; j < n; j++)
            arr[i][j] = n - j - 1;
    }
    start = clock();
    for (i = 0; i < 1000; i++)
        insertionSort(arr[i], n);
    end = clock();
    printf("Worst Case %ld ms\n", (end - start));

    // Deallocate memory
    for (int i = 0; i < 1000; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}

// OUTPUT
// Best Case: 2 ms
// Average Case: 632 ms
// Worst Case 1246 ms

// The expected time complexity of insertion sort is O(n^2)
// in the worst case, where n is the number of elements in the array.
// This is because in the worst case, the algorithm must make n-1
// comparisons and swaps for each element. The overall complexity
// would be O(n^2) because each comparison and swap takes O(n) time.

// But🍑 The best-case time complexity of insertion sort is O(n),
// where n is the number of elements in the array. In the best case,
// the input array is already sorted, so the algorithm will make only
// n-1 comparisons, but no swaps, resulting in a time complexity of O(n).