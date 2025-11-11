/**
 * File: signal_alarm.c
 * Modified by: Christopher Martin
 * 
 * Brief summary of program: Schedules a alarm to send to the operating system after 5 seconds
 */
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void handle_signal(){
    // print that process recieved alarm from OS
    printf("Alarm recieved\n");
    exit(1);
}

int main (void) {
    
    // register signal 
    signal(SIGALRM, handle_signal);

    alarm(5); // sound alarm after 5 seconds

    while(1){
        printf("Sleeping..\n");
        sleep(1);
    }

    return 0;
}