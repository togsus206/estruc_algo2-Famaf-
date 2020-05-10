#include "knapsack.h"
#include <assert.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"
#include "item.h"
#include "string.h"

// Backtracking------------------------------------------------

static value_t max_value(value_t first, value_t second) {
    if (first >= second) {
        return first;
    } else {
        return second;
    }
}

value_t knapsack_bt_rec(item_t *items, unsigned int array_length,
                        weight_t max_weight) {
    if (max_weight == 0u) {
        return 0u;
    } else if (array_length == 0u) {
        return 0u;
    }

    weight_t current_weight = item_weight(items[array_length - 1]);
    value_t current_value = item_value(items[array_length - 1]);

    if (current_weight > max_weight) {
        return (knapsack_bt_rec(items, array_length - 1, max_weight));
    } else if (max_weight >= current_weight) {
        value_t using_it =
            current_value + knapsack_bt_rec(items, array_length - 1,
                                            max_weight - current_weight);
        value_t not_using_it =
            knapsack_bt_rec(items, array_length - 1, max_weight);

        return max_value(using_it, not_using_it);
    }
    exit(EXIT_FAILURE);
}

value_t knapsack_backtracking(item_t *items, unsigned int array_length,
                              weight_t max_weight) {
    return (knapsack_bt_rec(items, array_length, max_weight));
}

// Dynamic------------------------------------------------------------

value_t knapsack_dynamic(item_t *items, unsigned array_length,
                         weight_t max_weight) {
    value_t A[array_length + 1][max_weight + 1];

    for (unsigned i = 0; i <= array_length; i++) {
        A[i][0] = 0;
    }
    for (weight_t j = 1; j <= max_weight; j++) {
        A[0][j] = 0;
    }

    for (unsigned i = 1; i <= array_length; i++) {
        for (weight_t j = 1; j <= max_weight; j++) {
            weight_t current_weight = item_weight(items[i - 1]);
            value_t current_value = item_value(items[i - 1]);
            if (current_weight > j) {
                A[i][j] = A[i - 1][j];
            } else {
                value_t using_it = current_value + A[i - 1][j - current_weight];
                value_t not_using_it = A[i - 1][j];
                A[i][j] = max_value(using_it, not_using_it);
            }
        }
    }
    return (A[array_length][max_weight]);
}

value_t knapsack_dynamic_selection(item_t *items, bool *selected,
                                   unsigned int array_length,
                                   weight_t max_weight) {
    value_t A[array_length][max_weight];
    for (unsigned i = 0; i < array_length; i++) {
        A[i][0] = 0;
    }
    for (weight_t j = 1; j < max_weight; j++) {
        A[0][j] = 0;
    }
    for (unsigned i = 1; i < array_length; i++) {
        for (weight_t j = 1; j < max_weight; j++) {
            weight_t current_weight = item_weight(items[i]);
            value_t current_value = item_value(items[i]);
            if (current_weight > j) {
                A[i][j] = A[i - 1][j];
            } else {
                value_t not_using_it = A[i - 1][j];
                value_t using_it = current_value + A[i - 1][j - current_weight];
                A[i][j] = max_value(using_it, not_using_it);
            }
        }
    }

    unsigned r = array_length;
    weight_t s = max_weight;
    while (A[r][s] > 0) {
        if (A[r][s] == A[r - 1][s]) {
            selected[r] = false;
        } else {
            selected[r] = true;
            s = s - item_weight(items[r]);
        }
        r = r - 1;
    }

    return (A[array_length - 1][max_weight - 1]);
}
