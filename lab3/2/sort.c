/*
  @file sort.c
  @brief sort functions implementation
*/

#include "sort.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"
#include "player.h"

bool goes_before(player_t x, player_t y) {
    if (x.rank <= y.rank) {
        return true;
    } else {
        return false;
    }
}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}

void swap(player_t a[], unsigned int i, unsigned int j) {
    player_t temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partition(player_t a[], unsigned int lft, unsigned int rgt) {
    int random_position = (rand() % (rgt + 1 - lft)) + lft;
    swap(a, lft, random_position);
    unsigned int i;
    unsigned int j;
    unsigned int ppiv = lft;
    i = lft + 1;
    j = rgt;
    while (i <= j) {
        if (a[i].rank <= a[ppiv].rank) {
            i = i + 1;
        } else if (a[j].rank >= a[ppiv].rank) {
            j = j - 1;
        } else if ((a[i].rank > a[ppiv].rank) && (a[j].rank < a[ppiv].rank)) {
            swap(a, i, j);
            i = i + 1;
            j = j - 1;
        }
    }
    swap(a, ppiv, j);  // setting the pivot in a more central position
    ppiv = j;
    return (ppiv);
}

void quick_sort_rec(player_t a[], int lft, int rgt) {
    int ppiv;
    if (rgt > lft) {
        ppiv = partition(a, lft, rgt);
        quick_sort_rec(a, lft, ppiv - 1);
        quick_sort_rec(a, ppiv + 1, rgt);
    }
}

void sort(player_t a[], unsigned int length) {
    quick_sort_rec(a, 0, (length - 1));
}
