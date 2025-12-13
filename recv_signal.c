/**
 * File: recv_signal.c
 * Modified by: Christopher Martin
 * 
 * Brief summary of program: 
 */
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void recieve_signal(int signal_int){ // may need to be pointer?
    printf("Data recieved: %d", signal_int);
    exit(1);
}

int main () {

   // Register Signal and Sig Handler
   struct sigaction sa;
   sa.sa_handler = handle_sigaction; // declare which method is called when signal is thrown
   sa.sa_flags = 0;                  // no special flags
   sigemptyset(&sa.sa_mask);         // no signal blocked during handler

   // declare signal
   sigaction(SIGUSR1, &sa, NULL);

   // Wait in infinite loop
   printf("Process ID: %d", getpid());
   while(1){
       
   }
   printf("Exiting Program\n");
   return 0;
}
