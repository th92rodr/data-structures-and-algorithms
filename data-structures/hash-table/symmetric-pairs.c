#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"

#define HASH_SIZE 20

void insertion(int hash[], int key, int value);
int search(int hash[], int key);
void print_hash(int hash[]);

void main() {
  int hash[HASH_SIZE];
  for (int i = 0; i < HASH_SIZE; i++)
    hash[i] = 0;

  int array[5][2] = { { 1, 2 }, { 6, 4 }, { 5, 10 }, { 4, 6 }, { 10, 5 } };

  printf("Input: \n");
  for (int i = 0; i < 5; i++) {
    printf(" (%d , %d) \n", array[i][0], array[i][1]);
    insertion(hash, array[i][0], array[i][1]);
  }

  printf("Output: \n");
  for (int i = 0; i < 5; i++) {
    if (array[i][0] == search(hash, array[i][1]))
      printf(" (%d , %d) \n", array[i][0], array[i][1]);
  }
}

void insertion(int hash[], int key, int value) {
  hash[key] = value;
}

int search(int hash[], int key) {
  return hash[key];
}

void print_hash(int hash[]) {
  printf("=====================================\n");
  for (int i = 0; i < HASH_SIZE; i++) {
    printf("| %d \n", hash[i]);
  }
  printf("=====================================\n");
}
