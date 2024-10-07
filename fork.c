#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>


int random_sleep(int i) {
    srand(time(NULL)+i);
    return (rand() % 8) + 1;
}


void pattern1(int n) {
    pid_t pid;
    for (int i = 0; i < n; i++) {
        pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            int sleep_time = random_sleep(i);
            printf("Process %d,PID:%d beginning.\nSleeping for %d seconds.\n", i + 1, getpid(), sleep_time);
            sleep(sleep_time);
            printf("Process %d,PID:%d exiting.\n", i + 1, getpid());
            exit(0);
        }
    }
    for (int i = 0; i < n; i++) {
        wait(NULL);
    }
}

void pattern2(int n){
    pid_t pid;
    for (int i = 0; i < n; i++) {
        pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            int sleep_time = random_sleep(i);
            printf("Process %d,PID:%d beginning.\nSleeping for %d seconds.\n", i + 1, getpid(), sleep_time);
            sleep(sleep_time);
            if(i < n - 1)if (i < n - 1) {
                printf("Process %d (PID: %d) creating process %d.\n", 
                       i + 1, getpid(), i + 2);
            }
        } else {
            wait(NULL); 
            printf("Process %d (PID: %d) exiting.\n", 
                   i + 1, getpid());
            exit(0);
        }
            
    }
}