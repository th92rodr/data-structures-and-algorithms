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
void quick_sort(int *array, int start, int end);
int partition(int *array, int start, int end);
void heap_sort(int *array, int size);
void heapify(int *array, int size, int root);

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
        quick_sort(array, 0, size - 1);
        break;
    case 5:
        heap_sort(array, size);
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

/**
 * QUICK SORT
 *
 * It is a divide and conquer algorithm.
 * It picks an element as pivot and partitions the array around the picket pivot.
 * By partition, it means to put the pivot element at its correct position in sorted array,
 * and put all smaller elements (smaller than pivot) before it, and put all greater elements (greater than pivot) after it.
 *
 * O(n * (log n))
 *
 **/
void quick_sort(int *array, int start, int end) {
    if (start < end) {
        // Place the selected pivot at its right position and return this position
        int pivot = partition(array, start, end);

        // Sort the elements before the pivot
        quick_sort(array, start, pivot - 1);

        // Sort the elements after the pivot
        quick_sort(array, pivot + 1, end);
    }
}
int partition(int *array, int start, int end) {
    // Get the first element as pivot
    int pivot = array[start];
    // Assume the pivot correct position is at the begining of the array
    int pivotCorrectPosition = start;

    // Compare all the others elements with the pivot
    // If the element is smaller than the pivot, increase the pivot correct position
    // and place this smaller element before this position
    for (int i = start+1; i <= end; i++) {
        if (array[i] < pivot) {
            pivotCorrectPosition++;
            swap(&array[pivotCorrectPosition], &array[i]);
        }
    }

    // Place the pivot in the correct position
    swap(&array[pivotCorrectPosition], &array[start]);

    return pivotCorrectPosition;
}

/**
 * HEAP SORT
 *
 * This algorithm views the array as a tree.
 * At first it turns the array into a max-heap (all nodes from the tree are greater than their children,
 * i.e., the largest element is at the root and both its children are smaller than it, and so on).
 * Then repeatedly swaps the first value of the array with the last value, decreasing the range of values
 * considered in the heap one by one, and sifting the new first value into its position in the heap.
 * This repeats until the range of considered values is just one value.
 *
 * O(n * (log n))
 *
 **/
void heap_sort(int *array, int size) {
    for (int i = size/2 - 1; i >= 0; i--) {
        heapify(array, size, i);
    }

    for (int i = size - 1; i > 0; i--) {
        swap(&array[0], &array[i]);
        heapify(array, i, 0);
    }
}
void heapify(int *array, int size, int root) {
    int largest = root;
    int left = 2*root + 1;
    int right = 2*root + 2;

    // If left child is bigger than root, replace root by child
    if (left < size && array[largest] < array[left]) {
        largest = left;
    }

    // If right child is bigger than root, replace root by child
    if (right < size && array[largest] < array[right]) {
        largest = right;
    }

    // If the original root is not the largest element, swap the largest to the root
    if (largest != root) {
        swap(&array[root], &array[largest]);

        // Heapify the sub-tree
        heapify(array, size, largest);
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
