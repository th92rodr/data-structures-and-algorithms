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

  // Is subset
  //int array1[] = {11, 1, 13, 16, 3, 7};
  //int array2[] = {11, 3, 7, 1};

  // Is not subset
  //int array1[] = {10, 5, 2, 13, 19, 8};
  //int array2[] = {19, 5, 3, 9};

  // Is subset
  int array1[] = { 1, 2, 3, 4, 5, 6 };
  int array2[] = { 1, 2, 4, 5 };

  printf("Array 1: \n");
  for (int i = 0; i < 6; i++) {
    printf(" (%d) ", array1[i]);
    insertion(hash, array1[i], 1);
  }

  printf("\nArray 2: \n");
  bool is_subset = true;
  for (int i = 0; i < 4; i++) {
    printf(" (%d) ", array2[i]);
    if (!search(hash, array2[i]))
      is_subset = false;
  }

  if (is_subset)
    printf("\nArray 2 is a subset of Array 1\n");
  else
    printf("\nArray 2 is not a subset of Array 1\n");
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
