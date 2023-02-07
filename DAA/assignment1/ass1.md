## DAA Assignment 1

| No. | C :godmode:                        | Python :snake:                       |
| --- | ---------------------------------- | ------------------------------------ |
| #1  | [Searching](./c_progs/searching.c) | [Searching](./py_progs/searching.py) |
| #2  | [Insertion](./c_progs/insertion.c) | [Insertion](./py_progs/insertion.py) |
| #3  | [Selection](./c_progs/selection.c) | [Selection](./py_progs/selection.py) |
| #4  | [Bubble](./c_progs/bubble.c)       | [Bubble](./py_progs/bubble.py)       |

_5. Critically comment that if in all the above program instead of dynamic array,
if we use static array then whether that would effect the complexity or not._

**Using a static array instead of a dynamic array would not affect the time complexity of the sorting algorithms in the above programs. Time complexity is a measure of how the running time of an algorithm increases with the size of the input, and it does not depend on whether the array is static or dynamic.**

**The main difference between using a static array and a dynamic array is the way memory is allocated. In a static array, memory is allocated at compile time, while in a dynamic array, memory is allocated at runtime using functions such as malloc() or calloc(). This can affect the amount of memory required by the program and the performance of memory-related operations, but it does not affect the time complexity of the sorting algorithms.**

**In general, the choice between using a static array and a dynamic array depends on the specific requirements of the program, such as the size of the array and whether it needs to be resized during the execution of the program.**
