/**
 * File: signal_sigaction.c
 * Modified by: Christopher Martin
 * 
 * Brief summary of program: the command "kill -SIGUSR1" can be called form a different terminal,
 * this should call the handle_sigaction() method, print out the current process ID, and exit the program
 */
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void handle_sigaction() {
    printf("Process ID: %d\n", getpid());
    exit(1);
}
int main (){

    // Register Signal and Sig Handler
    struct sigaction sa;
    sa.sa_handler = handle_sigaction; // declare which method is called when signal is thrown
    sa.sa_flags = 0; // no special flags
    sigemptyset(&sa.sa_mask); // no signal blocked during handler

    // declare signal
    sigaction(SIGUSR1, &sa, NULL);

    // Wait in infinite loop
    printf("Process ID: %d", getpid());
    while(1){
        printf("Waiting for SIGUSR1...\n");
        sleep(1);
    }
    printf("Exiting Program\n");

    return 0;
}


