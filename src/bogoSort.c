#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <helper.h>
#include <bogo.h>


void bogoSort(int *arr, int size) {
  while (true) {
    // printf("\n\n\n%d \n\n", isOrdered(arr, size));

    if (isOrdered(arr, size)) break;

    shuffleArray(arr, size);
    //sleep(2);
  }
}

void shuffleArray(int *arr, int size) {
  int i;

  for (i = 0; i < size; i++) {
    swapElements(arr, i, getRandomIntInRange(0, size - 1));
  }

}