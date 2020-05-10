#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int contador_swaps;
unsigned int contador_comparaciones;
// checks if the array is sorted
bool array_is_sorted(int array[], unsigned int length) {
    bool ans = 1;
    for (unsigned int i = 0u; i < (length - 1); i++) {
        if (array[i] > array[(i + 1)]) {
            ans = 0;
        }
    }
    return ans;
}

// swap 2 elements in an array
void swap(int array[], unsigned int i, unsigned int j) {
    unsigned int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

// searches the smallest int in an array from i to length
int min_pos_from(int array[], unsigned int length, unsigned int i) {
    int min = array[i];
    for (unsigned int k = i; k < length; k++) {
        contador_comparaciones = contador_comparaciones + 2;
        if (array[k] < array[min]) {
            min = k;
        }
    }
    return min;
}

// implementation of insertion sort
/*void insertion_sort(int array[], unsigned int length){
    //first loop goes from left to right, and selects the next item to insert
    for (unsigned int i = 1; i < length; i++) {
        unsigned int j = i;
            //second loop goes from right to left and inserts the item in its
place while ((j > 0u) && (array[j] < array[j-1])) { swap(array, j, (j-1)); j = j
- 1;
        }
    }
}
*/

void insert(int array[], int i) {
    int j = i;
    while (j > 0 && array[j] < array[j - 1]) {
        contador_comparaciones = contador_comparaciones + 2;
        contador_swaps++;
        swap(array, j - 1, j);
        j = j - 1;
    }
}
// implementation of insertion sort
void insertion_sort(int array[], unsigned int length) {
    unsigned int contador_comparaciones;
    for (unsigned int i = 1; i < length; i++) {
        contador_comparaciones++;
        insert(array, i);
    }
}

// another implementation of insertion sort
void another_insertion_sort(int array[], unsigned int length) {
    // first loop goes from left to right, and selects the next item to insert
    for (unsigned int i = 1; i < length; i++) {
        unsigned int j = i;
        // second loop goes from right to left and inserts the item in its place
        while ((j > 0u) && (array[j] < array[j - 1])) {
            swap(array, j, (j - 1));
            j = j - 1;
        }
    }
}

// implementation of selection sort
void selection_sort(int array[], unsigned int length) {
    unsigned int contador_swaps;
    unsigned int contador_comparaciones;
    for (unsigned int i = 0u; i < length; i++) {
        contador_comparaciones++;
        contador_swaps++;
        swap(array, i, min_pos_from(array, length, i));
    }
}

// places smaller ints before ppiv and bigger ints after
int partition(int array[], unsigned int lft, unsigned int rgt) {
    unsigned int i;
    unsigned int j;
    unsigned int ppiv = lft;
    i = lft + 1;
    j = rgt;
    while (i <= j) {
        contador_comparaciones++;
        if (array[i] <= array[ppiv]) {
            contador_comparaciones++;
            i = i + 1;
        } else if (array[j] >= array[ppiv]) {
            contador_comparaciones++;
            j = j - 1;
        } else if ((array[i] > array[ppiv]) && (array[j] < array[ppiv])) {
            contador_comparaciones = contador_comparaciones + 2;
            swap(array, i, j);
            i = i + 1;
            j = j - 1;
        }
    }
    swap(array, ppiv, j);  // setting the pivot in a more central position
    contador_swaps++;
    ppiv = j;
    return (ppiv);
}

// partition for extra marks
int extra_partition(int array[], unsigned int lft, unsigned int rgt) {
    int random_position = (rand() % (rgt + 1 - lft)) + lft;
    swap(array, lft, random_position);
    contador_swaps++;
    unsigned int i;
    unsigned int j;
    unsigned int ppiv = lft;
    i = lft + 1;
    j = rgt;
    while (i <= j) {
        if (array[i] <= array[ppiv]) {
            contador_comparaciones++;
            i = i + 1;
        } else if (array[j] >= array[ppiv]) {
            j = j - 1;
            contador_comparaciones++;
        } else if ((array[i] > array[ppiv]) && (array[j] < array[ppiv])) {
            swap(array, i, j);
            contador_comparaciones = contador_comparaciones + 2;
            contador_swaps++;
            i = i + 1;
            j = j - 1;
        }
    }
    swap(array, ppiv, j);  // setting the pivot in a more central position
    contador_swaps++;
    ppiv = j;
    return (ppiv);
}

// implementation of recursive quick_sort
void quick_sort_rec(int array[], int lft, int rgt) {
    int ppiv;
    if (rgt > lft) {
        contador_comparaciones++;
        ppiv = extra_partition(array, lft, rgt);
        quick_sort_rec(array, lft, ppiv - 1);
        quick_sort_rec(array, ppiv + 1, rgt);
    }
}

// main call of quick_sort
void quick_sort(int array[], unsigned int length) {
    quick_sort_rec(array, 0, (length - 1));
}

void stupid_sort(int array[], unsigned int length) {
    unsigned int i = 0u;
    unsigned int contador_swaps;
    unsigned int contador_comparaciones;
    while (i < length - 1) {
        contador_comparaciones++;
        if (array[i] >= array[i + 1]) {
            contador_comparaciones++;
            swap(array, i, i + 1);
            contador_swaps++;
            i = 0u;
        } else
            i++;
    }
}
