# DS-SEP-2025-99

This repository contains implementations of various data structures and sorting/search algorithms in C++, as part of the Data Structures assignment for SEP-2025/99.

---

## Contents

| File | Description |
|------|-------------|
| `Stack_implementation.cpp` | Stack using array / static storage |
| `Stack_implementation_using_linkedlist.cpp` | Stack implemented via linked list |
| `queue_implementation_using_array.cpp` | Queue using array (circular or simple) |
| `Bubble_sort.cpp` | Bubble Sort algorithm (optimized using flag for early termination) |
| `merge_sort.cpp` | Merge Sort implementation using divide & conquer |
| `quick_sort.cpp` | Quicksort implementation with pivot partitioning |
| `Binary_and_Linear_search.cpp` | Both Linear Search and Binary Search algorithms |
| `Binary_search_tree.cpp` | BST insertion, search (without deletion) |
| `Binary_search_tree_with_deletion.cpp` | BST with insertion, search, **and** deletion of nodes |

---

## How to Build & Run

These are simple standalone `.cpp` files. You can compile and run any of them using `g++` (or your preferred C++ compiler).

Example:

```bash
g++ -std=c++17 Bubble_sort.cpp -o Bubble_sort
./Bubble_sort
