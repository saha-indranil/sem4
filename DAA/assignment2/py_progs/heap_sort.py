# Write a Python program to sort a list of element in an Array using Heap Sort.
# Show the running time complexity w.r.t different input cases (best/average/worst).


import random
import time


def heapify(arr, n, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2
    if left < n and arr[left] > arr[largest]:
        largest = left
    if right < n and arr[right] > arr[largest]:
        largest = right
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)


def heap_sort(arr):
    n = len(arr)
    for i in range(n//2 - 1, -1, -1):
        heapify(arr, n, i)
    for i in range(n-1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)
    return arr


if __name__ == "__main__":
    n = 100000
    arr = []
    print("Heap Sort in Python")
    print("Input size:", n)

    # Best Case: Array is already sorted
    for i in range(n):
        arr.append(i) 
    start = time.time()
    heap_sort(arr)
    end = time.time()
    print("Best Case:", '{:.4f}'.format(end - start), "seconds")
    arr.clear()

    # Average Case: Array is random
    for i in range(n):
        arr.append(random.randint(0, n))
    start = time.time()
    heap_sort(arr)
    end = time.time()
    print("Average Case:", '{:.4f}'.format(end - start), "seconds")
    arr.clear()

    # Worst Case: Array is sorted in reverse order
    for i in range(n):
        arr.append(n-i)
    start = time.time()
    heap_sort(arr)
    end = time.time()
    print("Worst Case:", '{:.4f}'.format(end - start), "seconds")
    arr.clear()

# OUTPUT
# Heap Sort in Python
# Input size: 100000
# Best Case: 0.5421 seconds
# Average Case: 0.5695 seconds
# Worst Case: 0.4919 seconds