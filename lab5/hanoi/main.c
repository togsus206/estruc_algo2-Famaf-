#include <stdio.h>
#include <stdlib.h>
#include "hanoi.h"
#include <time.h> 


int main(int argc, char *argv[]) {
    extern unsigned int counter;
    if (argc < 2) {
        printf("Usage: ./solve-hanoi <disk-count>\n");
        exit(EXIT_FAILURE);
    }
    int count = atoi(argv[1]);
    if (count < 0) {
        printf("Negative disk-count is not allowed\n");
        exit(EXIT_FAILURE);
    }
    if (count > 20) {
        printf("> 20 is too slow!\n");
        exit(EXIT_FAILURE);
    }
    counter = 0;
    hanoi_t hanoi = hanoi_init(count);
    hanoi_print(hanoi);
    hanoi_solve(hanoi);
    printf("\033[2J");
    hanoi_print(hanoi);
    hanoi = hanoi_destroy(hanoi);
    printf("Movimientos: %u\n", counter);
    return 0;
}
