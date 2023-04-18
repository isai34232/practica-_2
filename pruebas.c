#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()int argc, char *argv[]) {
	int pid;
    while(1) {
        printf("$ ");
        char input[100];
        scanf("%s", input);
        if (strcmp(input, "EXIT") == 0) {
            break;
        }
        pid = fork();
        if (pid == -1) {
            printf("Error: failed to create new process\n");
        } else if (pid == 0) {
            if (execlp(input, input, (char *) NULL) == -1) {
                printf("Error: failed to execute %s\n", input);
                exit(EXIT_FAILURE);
            }
        } else {
            int status;
            waitpid(pid, &status, 0);
            if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_SUCCESS) {
                printf("Execution of %s was successful\n", input);
            } else {
                printf("Error: failed to execute %s\n", input);
            }
        }
    }
    return 0;
}