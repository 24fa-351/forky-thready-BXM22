#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include "fork.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <number of things> <pattern number>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int n = atoi(argv[1]);
    int pattern = atoi(argv[2]);

    if (n < 1 || n > 256) {
        fprintf(stderr, "Number of things must be between 1 and 256.\n");
        return EXIT_FAILURE;
    }

    srand(time(NULL)); // Seed the random number generator

    switch (pattern) {
        case 1:
            pattern1(n);
            break;
        case 2:
            pattern2(n);
            break;
        

    return EXIT_SUCCESS;
    }

}