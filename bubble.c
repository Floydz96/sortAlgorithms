#include <stdio.h>
#include <helper.h>
#include <bubble.h>

void bubbleSort(int *arr, int size) {
  int passes = 0;
  int swapped;

  do {
    swapped = 0;

    for (int i = 0; i < size - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        swapElements(arr, i, i + 1);
        swapped = 1; 
      }
    }

    passes++;
  } while (swapped); // Continue as long as swaps were made in the pass

  printf("Finished after %d passes.\n", passes);
}

void badBubbleSort(int *arr, int size) {
  int passes = 0;

  int i;

  do {
    
    for(i = 0; i < size - 1; i++) {
      if(arr[i] > arr[i + 1])
        swapElements(arr, i, i + 1);
    }
    passes++;
    
  } while (!isOrdered(arr, size)); // at each completly pass, check entire array,
                                   // what wastes computation 

  printf("\nfinished after %d passes.\n", passes);
}
