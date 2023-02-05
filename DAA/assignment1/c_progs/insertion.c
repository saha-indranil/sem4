// Write a C program to perform insertion sort using dynamic memory allocation.
// Show the running time complexity w.r.t different input cases. Finally comment
// that whether it is matching with the expected complexity of O(n^2) or not.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int *arr, int n)
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
    printf("Insertion sort in C\n");
    printf("Input size: %d\n", n);

    // Best Case: Array is already sorted
    for (i = 0; i < n; i++)
        arr[i] = i;
    start = clock();
    insertion_sort(arr, n);
    end = clock();
    printf("Best Case: %.2f ms\n", ((double)(end - start)) * 1000 / CLOCKS_PER_SEC);

    // Average Case: Array is random
    for (i = 0; i < n; i++)
        arr[i] = rand() % n;
    start = clock();
    insertion_sort(arr, n);
    end = clock();
    printf("Average Case: %.2f ms\n", ((double)(end - start)) * 1000 / CLOCKS_PER_SEC);

    // Worst Case: Array is sorted in reverse order
    for (i = 0; i < n; i++)
        arr[i] = n - i;
    start = clock();
    insertion_sort(arr, n);
    end = clock();
    printf("Worst Case %.2f ms\n", ((double)(end - start)) * 1000 / CLOCKS_PER_SEC);

    free(arr);
    return 0;
}

// OUTPUT
// Insertion sort in C
// Input size: 10000
// Best Case: 0.00 ms
// Average Case: 73.00 ms
// Worst Case 126.00 ms

// The expected time complexity of insertion sort is O(n^2)
// in the worst case, where n is the number of elements in the array.
// This is because in the worst case, the algorithm must make n-1
// comparisons and swaps for each element. The overall complexity
// would be O(n^2) because each comparison and swap takes O(n) time.

// But🍑 The best-case time complexity of insertion sort is O(n),
// where n is the number of elements in the array. In the best case,
// the input array is already sorted, so the algorithm will make only
// n-1 comparisons, but no swaps, resulting in a time complexity of O(n).