#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include "assert.h"

typedef struct _stack_t {
    stack_elem_t Value;
    stack_t Next;
} _stack_t;

stack_t stack_empty() {
    stack_t res;
    res = NULL;
    return (res);
}

stack_t stack_push(stack_t s, stack_elem_t elem) {
    stack_t new_node;
    new_node = malloc(sizeof(_stack_t));
    if (new_node == NULL) {
        printf("Se acabó la memoria");
        exit(1);
    }
    new_node->Value = elem;
    new_node->Next = s;
    return (new_node);
}

stack_t stack_pop(stack_t s) {
    assert(s != NULL);
    stack_t aux;
    aux = s;
    s = s->Next;
    free(aux);
    return (s);
}

unsigned int stack_size(stack_t s) {
    int size = 0u;
    while (s != NULL) {
        s = s->Next;
        size++;
    }
    return (size);
}

stack_elem_t stack_top(stack_t s) {
    assert(s != NULL);
    return (s->Value);
}

bool stack_is_empty(stack_t s) {
    return (s == NULL);
}

stack_elem_t *stack_to_array(stack_t s) {
    stack_elem_t *res;
    unsigned int elem_count = stack_size(s);
    res = calloc(elem_count, sizeof(stack_elem_t));
    if (res == NULL) {
        printf("Se acabó la memoria");
        exit(1);
    }
    if (elem_count != 0u) {
        for (unsigned int i = elem_count - 1u; i < elem_count; i--) {
            res[i] = s->Value;
            s = s->Next;
        }
    }
    return (res);
}

stack_t stack_destroy(stack_t s) {
    stack_t aux;
    while (s != NULL) {
        aux = s->Next;
        free(s);
        s = aux;
    }
    return (s);
}
