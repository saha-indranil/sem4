// Write a C program to perform bubble sort using dynamic memory allocation.
// Show the running time complexity w.r.t different input cases. Finally comment
// that whether it is matching with the expected complexity of O(n^2) or not.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int arr[], int n)
{
    int i, j, swap;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = swap;
            }
        }
    }
}

int main()
{
    int n = 1000, i, j, loops = 100;
    clock_t start, end;
    int **arr;

    // Allocating memory dynamically
    arr = (int **)malloc(loops * sizeof(int *));
    for (i = 0; i < loops; i++)
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
    for (i = 0; i < loops; i++)
        bubble_sort(arr[0], n);
    end = clock();
    printf("Best Case: %.2f ms\n", ((double)(end - start)) * 1000 / CLOCKS_PER_SEC);

    // Average Case: Array is random
    for (i = 0; i < loops; i++)
    {
        for (j = 0; j < n; j++)
            arr[i][j] = rand() % n;
    }
    start = clock();
    for (i = 0; i < loops; i++)
        bubble_sort(arr[i], n);
    end = clock();
    printf("Average Case: %.2f ms\n", ((double)(end - start)) * 1000 / CLOCKS_PER_SEC);

    // Worst Case: Array is sorted in reverse order
    for (i = 0; i < loops; i++)
    {
        for (j = 0; j < n; j++)
            arr[i][j] = n - j - 1;
    }
    start = clock();
    for (i = 0; i < loops; i++)
        bubble_sort(arr[i], n);
    end = clock();
    printf("Worst Case %.2f ms\n", ((double)(end - start)) * 1000 / CLOCKS_PER_SEC);

    // Deallocate memory
    for (int i = 0; i < loops; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}

// OUTPUT
// Best Case: 110.00 ms
// Average Case: 188.00 ms
// Worst Case 217.00 ms

// Best Case: When the array is already sorted, the inner loop won't
// execute at all, leading to O(n) time complexity.
// Average Case: In the average case, the time complexity of Bubble Sort is O(n^2).
// Worst Case: When the array is sorted in reverse order, in each iteration,
// the largest element has to be compared n times to reach its final position,
// leading to n^2 comparisons and swaps.
