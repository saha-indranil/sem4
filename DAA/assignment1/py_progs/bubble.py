# Write a python program to perform bubble sort using dynamic memory 
# allocation. Show the running time complexity w.r.t different input cases.

import random
import time

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1] :
                arr[j], arr[j+1] = arr[j+1], arr[j]

if __name__ == "__main__":
    n = 5000
    arr = []
    print("Bubble Sort in Python")
    print("Input size:", n)

    # Best Case: Array is already sorted
    for i in range(n):
        arr.append(i) 
    start = time.time()
    bubble_sort(arr)
    end = time.time()
    print("Best Case:", '{:.4f}'.format(end - start), "seconds")
    arr.clear()

    # Average Case: Array is random
    for i in range(n):
        arr.append(random.randint(0, n))
    start = time.time()
    bubble_sort(arr)
    end = time.time()
    print("Average Case:", '{:.4f}'.format(end - start), "seconds")
    arr.clear()

    # Worst Case: Array is sorted in reverse order
    for i in range(n):
        arr.append(n-i)
    start = time.time()
    bubble_sort(arr)
    end = time.time()
    print("Worst Case:", '{:.4f}'.format(end - start), "seconds")
    arr.clear()

# OUTPUT
# Bubble Sort in Python
# Input size: 5000
# Best Case: 0.7112 seconds
# Average Case: 1.2552 seconds
# Worst Case: 1.6796 seconds