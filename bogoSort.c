#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <helper.h>


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