#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void *thread_function(void *arg);
char message[] = "Thread";
void *thread_function(void *arg)
{
    int ppid = fork();
    if (ppid > 0)
    {
        printf("parent_thread_function is running. Argument was %s\n", (char *)arg);
        pthread_exit((void *)"Parent Thread");
    }
    else
    {
        printf("child_thread_function is running. Argument was %s\n", (char *)arg);
        pthread_exit((void *)"Child Thread");
    }
}
int main()
{
    pthread_t a_thread;
    int res;
    pid_t pid;
    void *thread_result;

    pid = fork();
    if (pid > 0)
        sleep(1);
    pthread_create(&a_thread, NULL, thread_function, (void *)message);
    printf("Waiting for thread to finish...\n");
    sleep(1);
    pthread_join(a_thread, &thread_result);
    printf("Thread joined, it returned %s\n", (char *)thread_result);
}