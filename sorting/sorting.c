/****************************************************************
SORTING METHODS
    BubbleSort
    SelectionSort
    InsertionSort
    QuickSort
    HeapSort
    MergeSort

    compile: gcc sorting.c -lm -o sorting.o
    execute: ./sorting.o
*****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "stdbool.h"

void bubble_sort(int *array, int size);
void selection_sort(int *array, int size);
void insertion_sort(int *array, int size);

int* generate_array(int size);
void swap(int* a, int* b);
void print_array(int *array, int size);

int main() {
    int size, op;

    printf("Number of elements in the array: ");
    scanf(" %d", &size);

    // Generate random array
    int *array = generate_array(size);

    printf("\nArray: ");
    print_array(array, size);

    printf("\n\nChoose sorting method: \n"
    " <1> Bubble Sort \n"
    " <2> Selection Sort \n"
    " <3> Insertion Sort \n"
    " <4> Quick Sort \n"
    " <5> Heap Sort \n"
    " <6> Merge Sort \n\n ");
    scanf(" %d", &op);

    switch(op) {
    case 1:
        bubble_sort(array, size);
        break;
    case 2:
        selection_sort(array, size);
        break;
    case 3:
        insertion_sort(array, size);
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    }

    printf("\nSorted array: ");
    print_array(array, size);

    free(array);
    return 0;
}

/**
 * BUBBLE SORT
 *
 * Keep comparing adjacent elements and swapping them if they are in the wrong order.
 * Doing this we always push the bigger element to the last position, in a way we don't need to compare it again.
 *
 * O(n²)
 *
 **/
void bubble_sort(int *array, int size) {
    bool keep_going = true;
    int exclude_last = 1;
    while (keep_going) {
        keep_going = false;
        for (int i = 0; i < size - exclude_last; i++) {
            if (array[i] > array[i+1]) {
                swap(&array[i], &array[i+1]);
                keep_going = true;
            }
        }
        exclude_last++;
    }
}

/**
 * SELECTION SORT
 *
 * Find the smallest element and swap it with the first position, as the first position is already sorted don't consider it anymore.
 *
 * O(n²)
 *
 **/
void selection_sort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minor = array[i],
            minor_index = i;
        for (int j = i + 1; j < size; j++) {
            if (minor > array[j]) {
                minor = array[j];
                minor_index = j;
            }
        }
        swap(&array[i], &array[minor_index]);
    }
}

/**
 * INSERTION SORT
 *
 * Keep comparing adjacent elements and swapping them if they are in the wrong order.
 * Doing this we always push the smaller element to the first position, in a way we don't need to compare it again.
 *
 * O(n²)
 *
 **/
void insertion_sort(int *array, int size) {
    for (int i = 1; i < size; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (array[j+1] < array[j]) {
                swap(&array[j+1], &array[j]);
            } else {
                break;
            }
        }
    }
}


int* generate_array(int size) {
    int *array;
    array = (int*) malloc(size * sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }

    return array;
}

void swap(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void print_array(int *array, int size) {
    printf("\n***************\n");
    for (int i = 0; i < size; i++ ) {
        printf(" %d", array[i]);
    }
    printf("\n***************\n");
}
