import random
import time

def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

if __name__ == "__main__":
    n = 500
    arr = [[0] * n for _ in range(100)]

    # Best Case: Array is already sorted
    for j in range(n):
        arr[0][j] = j
    start = time.time()
    for i in range(100):
        insertion_sort(arr[0])
    end = time.time()
    print("Best Case: ", end - start, "s")

    # Average Case: Array is random
    for i in range(100):
        for j in range(n):
            arr[i][j] = random.randint(0, n)
    start = time.time()
    for i in range(100):
        insertion_sort(arr[i])
    end = time.time()
    print("Average Case: ", end - start, "s")

    # Worst Case: Array is sorted in reverse order
    for i in range(100):
        for j in range(n):
            arr[i][j] = n - j - 1
    start = time.time()
    for i in range(100):
        insertion_sort(arr[i])
    end = time.time()
    print("Worst Case: ", end - start, "s")
