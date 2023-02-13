# Write a Python program to find the maximum and minimum element present
# in a list of elements using different approach. Show the running
# time complexity w.r.t different input cases (best/average/worst).

import random
import time

# Approach 1: Linear Search
def linear_search(arr, n):
    max = arr[0]
    min = arr[0]
    for i in range(1, n):
        if arr[i] > max:
            max = arr[i]
        if arr[i] < min:
            min = arr[i]
    return (max, min)

# Approach 2: Divide and Conquer
def divide_and_conquer(arr, l, r):
    if l == r:
        return (arr[l], arr[l])
    elif r - l == 1:
        if arr[r] > arr[l]:
            return (arr[r], arr[l])
        else:
            return (arr[l], arr[r])
    else:
        mid = l + (r - l) // 2
        left_max, left_min = divide_and_conquer(arr, l, mid)
        right_max, right_min = divide_and_conquer(arr, mid + 1, r)
        max = left_max if left_max > right_max else right_max
        min = left_min if left_min < right_min else right_min
        return (max, min)
    
if __name__=="__main__":
    n = 1000000
    arr = []
    print("Finding max and min in Python")
    print("Input size:", n)

    # Best Case: Array is already sorted
    for i in range(n):
        arr.append(i)
    start = time.time()
    result = linear_search(arr, n)
    end = time.time()
    print("Linear Search (Best Case):", '{:.4f}'.format(end - start), "seconds")
    start = time.time()
    result = divide_and_conquer(arr, 0, n - 1)
    end = time.time()
    print("Divide & Conquer (Best Case):", '{:.4f}'.format(end - start), "seconds")
    arr.clear()

    # Average Case: Array is random
    for i in range(n):
        arr.append(random.randint(0, n))
    start = time.time()
    result = linear_search(arr, n)
    end = time.time()
    print("Linear Search (Average Case):", '{:.4f}'.format(end - start), "seconds")
    start = time.time()
    result = divide_and_conquer(arr, 0, n - 1)
    end = time.time()
    print("Divide & Conquer (Average Case):", '{:.4f}'.format(end - start), "seconds")
    arr.clear()

    # Worst Case: Array is sorted in reverse order
    for i in range(n):
        arr.append(n - i)
    start = time.time()
    result = linear_search(arr, n)
    end = time.time()
    print("Linear Search (Worst Case):", '{:.4f}'.format(end - start), "seconds")
    start = time.time()
    result = divide_and_conquer(arr, 0, n - 1)
    end = time.time()
    print("Divide & Conquer (Worst Case):", '{:.4f}'.format(end - start), "seconds")
    arr.clear()


# OUTPUT
# Finding max and min in Python
# Input size: 1000000
# Linear Search (Best Case): 0.0623 seconds
# Divide & Conquer (Best Case): 0.3470 seconds
# Linear Search (Average Case): 0.0957 seconds
# Divide & Conquer (Average Case): 0.3358 seconds
# Linear Search (Worst Case): 0.1042 seconds
# Divide & Conquer (Worst Case): 0.3095 seconds