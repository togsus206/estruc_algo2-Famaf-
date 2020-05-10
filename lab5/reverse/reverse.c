#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../stack.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./reverse <string-to-reverse>\n");
        exit(EXIT_FAILURE);
    }
    char *str = argv[1];

    stack_t stack;
    stack = stack_empty();
    int length = strlen(str);
    
    for(int i = 0; i < length; i++) {
        stack = stack_push(stack, str[i]);
    }
    for(int i = 0; i < length; i++)
    {
        str[i] = stack_top(stack);
        stack = stack_pop(stack);
    }
    
    printf("%s\n", str);
}
