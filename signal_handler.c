/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT, the handler prints a message and then quits
 */

/**
 * Modified by: Christopher Martin
 * 
 * Brief summary of modifications: 
   Made program automacially terminate (n) seconds, printed out process id
   to enable termination from command line, chaned exit(1) within handle_signal() function to kill instead
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGINT - prints a message and exits
 */
void handle_signal() {
    printf("Received a signal\n");
    kill(getpid(), SIGKILL);
}

int main() {

    // Register for the signal
    signal(SIGINT, handle_signal);
    //signal(SIGKILL, handle_signal);


    printf("Main PID: %d\n", getpid());

    // Wait until a signal is received
    int count = 0;
    while(count <= 5) {
        printf("Sleeping\n");
        sleep(1);
        count++;
    }

    // will call SIGINT after 5 seconds or before if ctrl+c pressed
    kill(getpid(), SIGINT);

    printf("End of Program\n");
    return 0;
}