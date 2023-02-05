// Write a C program to perform bubble sort using dynamic memory allocation.
// Show the running time complexity w.r.t different input cases. Finally comment
// that whether it is matching with the expected complexity of O(n^2) or not.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int *arr, int n)
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
    int n = 10000, i;
    clock_t start, end;
    int *arr;

    // Allocating memory dynamically
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 0;
    }
    printf("Merge sort in C\n");
    printf("Input size: %d\n", n);

    // Best Case: Array is already sorted
    for (i = 0; i < n; i++)
        arr[i] = i;
    start = clock();
    bubble_sort(arr, n);
    end = clock();
    printf("Best Case: %.2f ms\n", ((double)(end - start)) * 1000 / CLOCKS_PER_SEC);

    // Average Case: Array is random
    for (i = 0; i < n; i++)
        arr[i] = rand() % n;
    start = clock();
    bubble_sort(arr, n);
    end = clock();
    printf("Average Case: %.2f ms\n", ((double)(end - start)) * 1000 / CLOCKS_PER_SEC);

    // Worst Case: Array is sorted in reverse order
    for (i = 0; i < n; i++)
        arr[i] = n - i;
    start = clock();
    bubble_sort(arr, n);
    end = clock();
    printf("Worst Case %.2f ms\n", ((double)(end - start)) * 1000 / CLOCKS_PER_SEC);

    free(arr);
    return 0;
}

// OUTPUT
// Merge sort in C
// Input size: 10000
// Best Case: 126.00 ms
// Average Case: 176.00 ms
// Worst Case 209.00 ms

// Best Case: When the array is already sorted, the inner loop won't
// execute at all, leading to O(n) time complexity.
// Average Case: In the average case, the time complexity of Bubble Sort is O(n^2).
// Worst Case: When the array is sorted in reverse order, in each iteration,
// the largest element has to be compared n times to reach its final position,
// leading to n^2 comparisons and swaps.
