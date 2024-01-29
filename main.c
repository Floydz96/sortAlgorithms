#include <bogo.h>
#include <bubble.h>
#include <helper.h>
#include <pthread.h>
#include <quick.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int switchSortAlgorithm();
int switchQuickSortAlgorithm();

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

  switch (switchSortAlgorithm()) {
    case 1: {
      bogoSort(arrayToOrder, size);
      break;
    }
    case 2: {
      bubbleSort(arrayToOrder, size);
      break;
    }
    case 3: {
      
      int algorithm = switchQuickSortAlgorithm();
      
      quickSort(arrayToOrder, 0, size - 1, algorithm - 1);
      break;
    }
    case 4: {
      break;
    }
    default: {
      printf("Not implemented yet.");
      exit(1);
    }
  }

  end_time = clock();

  execution_time_ms = ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000;

  printf("\nafter sort: \n");
  printArray(arrayToOrder, size);

  printf("\nExecution time: %.5f ms\n", execution_time_ms);

  free(arrayToOrder);

  return 0;
}

int waitIntInput() {
  char input[3];
  int number;
  if (fgets(input, sizeof(input), stdin) != NULL) {
    while (1) {
      if (sscanf(input, "%d", &number) != 1) {
        printf("Choose a valid number.");
        continue;
      }

      break;
    }

    return number;
  }

  exit(1);
}

int switchSortAlgorithm() {
  printf("\n\n");
  printf("1. BogoSort\n");
  printf("2. BubbleSort\n");
  printf("3. QuickSort\n");
  printf("4. Comparision Test\n");
  printf("\n\n");
  
  return waitIntInput();
}

int switchQuickSortAlgorithm() {
  printf("\n\n");
  printf("1. Hoare Partition Scheme\n");
  printf("2. Lomuto Partition Scheme\n");
  printf("\n\n");

  return waitIntInput();
}