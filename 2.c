#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h> /*deklaracje standardowych funkcji uniksowych (fork(), write() itd.)*/

int main()
{
    int max = 5;
    pid_t pid = 0;
    printf("Moj PID = %d\n", getpid());

    while (pid == 0 && max > 0) {
        max -= 1;
        switch(pid = fork()){
            case -1:
                fprintf(stderr, "Blad w fork\n");
                return EXIT_FAILURE;
            case 0: /*proces potomny*/
                printf("Jestem procesem potomnym. PID = %d\n \
                    Wartosc przekazana przez fork() = %d\n", getpid(), pid);
            default:
                printf("Jestem procesem macierzystym. PID = %d\n \
                    Wartosc przekazana przez fork() = %d\n", getpid(), pid);
                break;
        }
    }

    if(wait(0) == -1)
    {
        fprintf(stderr, "Blad w wait\n");
        return EXIT_FAILURE;

    }
    return EXIT_SUCCESS;
}
