#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_PARAMETERS 10

void type_prompt()
{
    printf("정욱$ ");
}

void read_command(char *command, char *parameters[])
{
    char input[MAX_COMMAND_LENGTH];
    fgets(input, sizeof(input), stdin);

    // Remove the newline character from the end of the input
    input[strcspn(input, "\n")] = '\0';
    printf("");

    char *token = strtok(input, " ");
    int paramIndex = 0;

    while (token != NULL && paramIndex < MAX_PARAMETERS)
    {
        parameters[paramIndex] = token;
        token = strtok(NULL, " ");
        paramIndex++;
    }

    parameters[paramIndex] = NULL;

    strncpy(command, parameters[0], MAX_COMMAND_LENGTH);
}

int main()
{
    char command[MAX_COMMAND_LENGTH];
    char *parameters[MAX_PARAMETERS + 1];
    int status;

    while (1)
    {
        type_prompt();
        read_command(command, parameters);

        if (strcmp(command, "exit") == 0)
        {
            break; // Exit the shell if the command is "exit"
        }

        if (fork() != 0)
        {
            waitpid(-1, &status, 0);
        }
        else
        {
            execve(command, parameters, 0);
        }
    }

    return 0;
}
