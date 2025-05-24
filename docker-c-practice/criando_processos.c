#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]) {
    int pid;

    pid = fork(); // cria novo processo

    if (pid < 0) {
        perror("Erro no fork");
        exit(-1);
    }
    else if (pid > 0) {
        // processo pai
        wait(0); // espera o filho
    }
    else {
        // processo filho
        execve("/bin/date", argv, envp); // substitui por outro programa
        perror("Erro no execve"); // se execve falhar
    }

    printf("Tchau!\n");
    return 0;
}