// Write a C program to find the maximum and minimum element present
// in a list of elements using different approach. Show the running
// time complexity w.r.t different input cases (best/average/worst).
// Finally comment which one is better & why.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Approach 1: Linear Search
void linear_search(int *arr, int n, int *max, int *min)
{
    int i;
    *max = arr[0];
    *min = arr[0];
    for (i = 1; i < n; i++)
    {
        if (arr[i] > *max)
        {
            *max = arr[i];
        }
        if (arr[i] < *min)
        {
            *min = arr[i];
        }
    }
}

// Approach 2: Divide and Conquer
void divide_and_conquer(int *arr, int l, int r, int *max, int *min)
{
    int mid;
    if (l == r)
    {
        *max = arr[l];
        *min = arr[l];
    }
    else if (r - l == 1)
    {
        if (arr[r] > arr[l])
        {
            *max = arr[r];
            *min = arr[l];
        }
        else
        {
            *max = arr[l];
            *min = arr[r];
        }
    }
    else
    {
        mid = l + (r - l) / 2;
        int left_max, left_min, right_max, right_min;
        divide_and_conquer(arr, l, mid, &left_max, &left_min);
        divide_and_conquer(arr, mid + 1, r, &right_max, &right_min);
        *max = (left_max > right_max) ? left_max : right_max;
        *min = (left_min < right_min) ? left_min : right_min;
    }
}

int main()
{
    int n = 100000000, i, max, min;
    clock_t start, end;
    int *arr;

    // Allocating memory dynamically
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 0;
    }
    printf("Finding max and min in C\n");
    printf("Input size: %d\n", n);

    // Best Case: Array is already sorted
    for (i = 0; i < n; i++)
        arr[i] = i;
    start = clock();
    linear_search(arr, n, &max, &min);
    end = clock();
    printf("Linear Search (Best Case): %.2f ms\n", ((double)(end - start)) * 1000 / CLOCKS_PER_SEC);
    start = clock();
    divide_and_conquer(arr, 0, n - 1, &max, &min);
    end = clock();
    printf("Divide & Conquer (Best Case): %.2f ms\n", ((double)(end - start)) * 1000 / CLOCKS_PER_SEC);

    // Average Case: Array is random
    for (i = 0; i < n; i++)
        arr[i] = rand() % (n * 10);
    start = clock();
    linear_search(arr, n, &max, &min);
    end = clock();
    printf("Linear Search (Average Case): %.2f ms\n", ((double)(end - start)) * 1000 / CLOCKS_PER_SEC);
    start = clock();
    divide_and_conquer(arr, 0, n - 1, &max, &min);
    end = clock();
    printf("Divide & Conquer (Average Case): %.2f ms\n", ((double)(end - start)) * 1000 / CLOCKS_PER_SEC);

    // Worst Case: Array is sorted in reverse order
    for (i = 0; i < n; i++)
        arr[i] = n - i;
    start = clock();
    linear_search(arr, n, &max, &min);
    end = clock();
    printf("Linear Search (Worst Case): %.2f ms\n", ((double)(end - start)) * 1000 / CLOCKS_PER_SEC);
    start = clock();
    divide_and_conquer(arr, 0, n - 1, &max, &min);
    end = clock();
    printf("Divide & Conquer (Worst Case): %.2f ms\n", ((double)(end - start)) * 1000 / CLOCKS_PER_SEC);

    free(arr);
    return 0;
}

// OUTPUT
// Finding max and min in C
// Input size: 100000000
// Linear Search (Best Case): 341.00 ms
// Divide & Conquer (Best Case): 670.00 ms
// Linear Search (Average Case): 269.00 ms
// Divide & Conquer (Average Case): 1536.00 ms
// Linear Search (Worst Case): 319.00 ms
// Divide & Conquer (Worst Case): 672.00 ms

// Linear Search(Best/Average/Worst):
// Time Complexity = O(n)
// Space Complexity = O(1)

// Divide & Conquer(Best/Average/Worst):
// Time Complexity = O(nlogn)
// Space Complexity = O(logn)