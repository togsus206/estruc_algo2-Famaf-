#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void print_stack(stack_t s) {
    printf("\n");
    unsigned int size = stack_size(s);
    if (size == 0u) {
        printf("Empty stack\n\n");
    } else {
        printf("[");
        for (unsigned int i = 0; i < size - 1; i++) {
            printf("%d, ", ((stack_to_array(s))[i]));
        }
        printf("%d]\n\n", ((stack_to_array(s))[size - 1]));
    }
}

int main() {
    stack_t stack;
    stack = stack_empty();
    unsigned int size;
    printf("Cuántos elementos para el stack?:\n");
    scanf("%u", &size);
    for (unsigned int i = 0; i < size; i++) {
        int aux;
        printf("Elemento %u:\n", i);
        scanf("%d", &aux);
        stack = stack_push(stack, aux);
    }

    print_stack(stack);
    stack = stack_pop(stack);
    print_stack(stack);
}
