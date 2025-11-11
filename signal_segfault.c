/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Christopher Martin
 * 
 * Brief summary of modifications: created handle_segv() function to print out segmentation fault recieved
 * WILL continuously print out that segfault was recieved and will NOT stop program
 */


#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handle_segv(){
    printf("Recieved segfault\n");
    //exit(1);
    return;
}

int main (int argc, char* argv[]) {

    // Register signal
    signal(SIGSEGV, handle_segv);

    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}