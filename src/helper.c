#include <helper.h>
#include <stdio.h>
#include <stdlib.h>

int getRandomIntInRange(int min, int max) {
  return (rand() % (max - min + 1)) + min;
}

int *createArray(int size, int maxNumSize) {
  int *arrayBuffer = (int *)malloc(size * sizeof(int));

  if (arrayBuffer == NULL) {
    exit(1);
  }

  int i;

  for (i = 0; i < size; i++) {
    int randNumber;

    do {
      randNumber = getRandomIntInRange(1, maxNumSize);
    } while (alreadyContains(arrayBuffer, size, randNumber));

    arrayBuffer[i] = randNumber;
  }

  return arrayBuffer;
}

// this function takes so long when generating large arrays
int alreadyContains(int *arr, int size, int val) {
  int i;
//  for (i = 0; i < size; i++) {
//    if (arr[i] == val)
//      return 0;
//  }

  return 0;
}

void printArray(int *arr, int size) {
  int i;
  printf("\n");
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int isOrdered(int *arr, int size) {
  int i;
  for (i = size - 1; i >= 1; i--) {
    // printf("array size is %d and pos1 %d and pos2 %d", size, arr[i], arr[i -
    // 1]);
    if (!(arr[i] > arr[i - 1]))
      return 0;
  }

  return 1;
}

void swapElements(int *arr, int pos1, int pos2) {
  int buff = arr[pos1];
  arr[pos1] = arr[pos2];
  arr[pos2] = buff;
}