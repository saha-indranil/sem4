// Write a C program to sort a list of element in an Array using Merge Sort.
// Show the running time complexity w.r.t different input cases (best/average/worst).

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int *arr, int left, int mid, int right)
{
    int i, j, k;
    int left_size = mid - left + 1;
    int right_size = right - mid;

    int *left_array = (int *)malloc(left_size * sizeof(int));
    int *right_array = (int *)malloc(right_size * sizeof(int));

    for (i = 0; i < left_size; i++)
        left_array[i] = arr[left + i];
    for (j = 0; j < right_size; j++)
        right_array[j] = arr[mid + 1 + j];

    i = j = 0;
    k = left;
    while (i < left_size && j < right_size)
    {
        if (left_array[i] <= right_array[j])
            arr[k++] = left_array[i++];
        else
            arr[k++] = right_array[j++];
    }

    while (i < left_size)
        arr[k++] = left_array[i++];
    while (j < right_size)
        arr[k++] = right_array[j++];

    free(left_array);
    free(right_array);
}

void merge_sort(int *arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main()
{
    int n = 1000000, i;
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
    merge_sort(arr, 0, n - 1);
    end = clock();
    printf("Best Case: %.2f ms\n", ((double)(end - start)) * 1000 / CLOCKS_PER_SEC);

    // Average Case: Array is random
    for (i = 0; i < n; i++)
        arr[i] = rand() % n;
    start = clock();
    merge_sort(arr, 0, n - 1);
    end = clock();
    printf("Average Case: %.2f ms\n", ((double)(end - start)) * 1000 / CLOCKS_PER_SEC);

    // Worst Case: Array is sorted in reverse order
    for (i = 0; i < n; i++)
        arr[i] = n - i;
    start = clock();
    merge_sort(arr, 0, n - 1);
    end = clock();
    printf("Worst Case %.2f ms\n", ((double)(end - start)) * 1000 / CLOCKS_PER_SEC);

    free(arr);
    return 0;
}

// OUTPUT
// Merge sort in C
// Input size: 1000000
// Best Case: 230.00 ms
// Average Case: 315.00 ms
// Worst Case 229.00 ms