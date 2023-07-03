#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void *thread_function(void *arg);
char message[] = "Thread";

void *thread_function(void *arg)
{
    if (arg == NULL)
    {
        printf("child_thread_function is running.\n");
        pthread_exit((void *)"Child Thread");
    }
    else
    {
        printf("parent_thread_function is running. Argument was %s\n", (char *)arg);
        pthread_exit((void *)"Parent Thread");
    }
}

int main()
{
    pthread_t a_thread;
    int res;
    void *thread_result;

    res = pthread_create(&a_thread, NULL, thread_function, (void *)message);
    if (res != 0)
    {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for thread to finish...\n");
    res = pthread_join(a_thread, &thread_result);
    if (res != 0)
    {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }

    printf("Thread joined, it returned %s\n", (char *)thread_result);

    return 0;
}
