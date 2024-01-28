#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int getRandomIntInRange(int min, int max) {
  return (rand() % (max - min + 1)) + min;
}

int alreadyContains(int *arr, int size, int val) {
  int i;
  for (i = 0; i < size; i++) {
    if (arr[i] == val) return 1;
  }

  return 0;
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

void printArray(int *arr, int size);

void bogoSort(int *arr, int size);
void shuffleArray(int *arr, int size);

int main(int argc, char *argv[]) {
  if (argc < 2) {
    exit(1);
  }

  int size = atoi(argv[1]);
  int maxNumSize = atoi(argv[2]);

  srand(time(NULL));
  int *arrayToOrder = createArray(size, maxNumSize);

  printf("before sort: \n");
  printArray(arrayToOrder, size);
  
  clock_t start_time, end_time;
  double execution_time_ms;
  
  start_time = clock();
  bogoSort(arrayToOrder, size);
  end_time = clock();
  
  execution_time_ms = ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000;
  
  printf("\nafter sort: \n");
  printArray(arrayToOrder, size);
  
  printf("\nExecution time: %.5f ms\n", execution_time_ms);
  
  free(arrayToOrder);

  return 0;
}

int isOrdered(int *arr, int size);

void bogoSort(int *arr, int size) {
  while (true) {
    // printf("\n\n\n%d \n\n", isOrdered(arr, size));

    if (isOrdered(arr, size)) break;

    shuffleArray(arr, size);
    //sleep(2);
  }
}

void swap(int *arr, int pos1, int pos2) {
  int buff = arr[pos1];
  arr[pos1] = arr[pos2];
  arr[pos2] = buff;
}

void shuffleArray(int *arr, int size) {
  int i;

  for (i = 0; i < size; i++) {
    swap(arr, i, getRandomIntInRange(0, size - 1));
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

void printArray(int *arr, int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
}
