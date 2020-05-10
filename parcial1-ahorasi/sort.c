#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

bool goes_before(Team x, Team y) {
    bool before = false;
    if (x.points > y.points)
    {
        before = true;
    }
    else if (x.points == y.points)
    {
        if ((x.goal_favor - x.goal_against) > (y.goal_favor - y.goal_against)) 
        { 
           before = true;
        }
    }    
    //completar aqui
    return before; 
}

bool array_is_sorted(Team t[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(t[i - 1u], t[i])) {
        ++i;
    }
    return (i == length);
}

static void swap(Team a[], unsigned int i, unsigned int j) {
    Team tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

static void insert(Team a[], unsigned int i) {
    unsigned int j = i;
    while (j > 0 && !goes_before(a[j-1],a[j])) {
        swap(a, j, j-1u);
        j--;
    }
}

static void insertion_sort(Team a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; i++) {
        insert(a, i);
    }
}

void sort(Team a[], unsigned int length) {
    insertion_sort(a, length);
}

