#include <stdio.h>
#include <stdlib.h>
#include <helper.h>

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

int alreadyContains(int *arr, int size, int val) {
  int i;
  for (i = 0; i < size; i++) {
    if (arr[i] == val) return 1;
  }

  return 0;
}

void printArray(int *arr, int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
}

int isOrdered(int *arr, int size) {
  int i;
  for (i = size - 1; i >= 1; i--) {
    // printf("array size is %d and pos1 %d and pos2 %d", size, arr[i], arr[i -
    // 1]);
    if (!(arr[i] > arr[i - 1])) return 0;
  }

  return 1;
}
