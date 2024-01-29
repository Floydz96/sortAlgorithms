#include "quick.h"
#include <helper.h>
#include <stdio.h>

/*

The `quick.c` program serves as an implementation of the renowned quicksort
algorithm, a highly efficient and widely used sorting technique. This algorithm
is well-documented and can be found on its Wikipedia page [1], as well as in the
official paper authored by Tony Hoare [2]. In this document, we delve into the
specifics of the `quick.c` implementation, highlighting the differences between
the Hoare partition scheme and the Lomuto partition scheme, both integral
components of the quicksort algorithm.

**Quicksort Algorithm Overview:**

Quicksort is a highly efficient comparison-based sorting algorithm. It was
developed by the British computer scientist Tony Hoare in 1960 and is renowned
for its average-case time complexity of O(n log n), making it one of the fastest
sorting algorithms available.

**Hoare Partition Scheme:**

The Hoare partition scheme, as introduced by Tony Hoare himself, is an essential
step within the quicksort algorithm. It divides an array into two subarrays,
each of which is then sorted recursively. The Hoare scheme is known for its
efficiency and elegance. It selects a pivot element and rearranges the array
elements such that all elements smaller than the pivot are on its left, and all
elements greater than the pivot are on its right. The pivot's final position in
the sorted array is then determined.

**Lomuto Partition Scheme:**

The Lomuto partition scheme is an alternative approach to partitioning in
quicksort, introduced by Nico Lomuto. While it is conceptually simpler, it tends
to have less efficient performance in practice compared to the Hoare scheme. In
the Lomuto scheme, the pivot is placed at its final position by scanning the
array from left to right and moving elements less than the pivot to the left of
it.

**Comparing Hoare and Lomuto Partition Schemes:**

The key difference between the Hoare and Lomuto partition schemes lies in their
approach to partitioning. The Hoare scheme is more efficient due to its
bidirectional approach, whereas the Lomuto scheme uses a unidirectional scan,
resulting in more swaps and generally lower performance. The choice between
these partition schemes may depend on factors such as ease of implementation
versus optimization for specific data distributions.

---

References:
1. Wikipedia: Quicksort Algorithm. https://en.wikipedia.org/wiki/Quicksort
2. Hoare, C. A. R. (1962). Quicksort. The Computer Journal, 5(1), 10-16.
*/

int lomutoPartition(int *arr, int low, int high);
int hoarePartition(int *arr, int low, int high);

int (*chooseAlgorithm(int algorithmImplementation))(int *, int, int) {
  int (*algorithms[2])(int *, int, int) = {&lomutoPartition, &hoarePartition};

  return algorithms[algorithmImplementation];
}

void quickSort(int *arr, int low, int high, int algoIndex) {
  if (low >= high || low < 0)
    return;

  int (*partitionFunction)(int *, int, int) = chooseAlgorithm(algoIndex);
  int part = partitionFunction(arr, low, high);

  quickSort(arr, low, part - 1, algoIndex);
  quickSort(arr, part + 1, high, algoIndex);
}

int lomutoPartition(int *arr, int low, int high) {
  int pivot = arr[high];

  int i = low - 1;

  for (int j = low; j <= high - 1; j++) {
    if (arr[j] <= pivot) {
      i++;
      swapElements(arr, i, j);
    }
  }

  i++;
  swapElements(arr, i, high);
  return i;
}

int hoarePartition(int *arr, int low, int high) {
  int pivot = arr[low];
  int i = low - 1;
  int j = high + 1;
  
  while (1) {
    // scan for a higher value than the pivot in the left side
    do {
      i++;
    } while (arr[i] < pivot);

    do {
      j--;
    } while (arr[j] > pivot);

    if(i >= j)
      return j;

    swapElements(arr, i, j);
  }
}