#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    int i, children_number = 5;
    pid_t fork_pid;
    printf("Moj PID = %d\n", getpid());

    for (i = 0; i < children_number; i++)
    {
        fork_pid = fork();
        if (fork_pid == -1)
        {
            fprintf(stderr, "Blad w fork\n");
            return EXIT_FAILURE;
        }
        else if (fork_pid == 0)
        {
            printf("Jestem procesem potomnym. PID = %d fork() = %d\n",
                   getpid(), fork_pid);
            break;
        }
        else
        {
            printf("Jestem procesem macierzystym. PID = %d fork() = %d\n",
                   getpid(), fork_pid);
        }
    }

    if (fork_pid != 0 && wait(0) == -1)
    {
        fprintf(stderr, "Blad w wait\n");
        return EXIT_FAILURE;
    }

    if (fork_pid == 0)
    {
        sleep(60);
    }

    return EXIT_SUCCESS;
}
