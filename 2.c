#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    int children_number = 4;
    pid_t fork_pid;
    printf("Moj PID = %d\n", getpid());

    while (children_number > 0)
    {
        children_number -= 1;
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
        }
        else
        {
            printf("Jestem procesem macierzystym. PID = %d fork() = %d\n",
                   getpid(), fork_pid);
            break;
        }
    }

    if (children_number > 0 && wait(0) == -1)
    {
        fprintf(stderr, "Blad w wait\n");
        return EXIT_FAILURE;
    }

    if (children_number == 0)
    {
        sleep(60);
    }

    return EXIT_SUCCESS;
}
