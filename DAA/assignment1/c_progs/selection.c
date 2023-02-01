// Write a C program to perform selection sort using dynamic memory allocation.
// Show the running time complexity w.r.t different input cases. Finally comment
// that whether it is matching with the expected complexity of O(n^2) or not.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int *arr, int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
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
        selection_sort(arr[0], n);
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
        selection_sort(arr[i], n);
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
        selection_sort(arr[i], n);
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
// Best Case: 113.00 ms
// Average Case: 137.00 ms
// Worst Case 104.00 ms

// In this case, the algorithm needs to make n-1 passes through the array to sort it,
// but each pass takes O(n) time. Thus the time complexity of selection sort is O(n^2)
// in all the three cases: best, average and worst.
