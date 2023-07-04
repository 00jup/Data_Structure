#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void *thread_function(void)
{
    printf("thread_function is running. Argument was %s\n", (char *)arg);
    sleep(3);
    printf("Second thread setting finished flag, and exiting now\n");
    thread_finished = 1;
    pthread_exit(NULL);
}
int main()
{
    pthread_t a_thread;
    int res;

    res = pthread_creation(&a_thread, NULL, thread_function, NULL);
}