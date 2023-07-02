#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main()
{
    char command[BUFFER_SIZE];
    int status;

    while (1)
    {
        printf("Shell> ");
        fgets(command, BUFFER_SIZE, stdin);

        // Remove newline character from the end
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "exit") == 0)
        {
            break;
        }

        pid_t pid = fork();
        if (pid == 0)
        {
            // Child process
            char *arguments[] = {"/bin/sh", "-c", command, NULL};
            execve("/bin/sh", arguments, NULL);
            exit(0); // Exit child process if execve fails
        }
        else if (pid > 0)
        {
            // Parent process
            waitpid(pid, &status, 0);
        }
        else
        {
            // Fork failed
            perror("fork");
            exit(1);
        }
    }

    return 0;
}
