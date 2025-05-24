#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAX_FORKS 10  // Define um limite seguro

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <numero_de_forks>\n", argv[0]);
        return 1;
    }

    pid_t pid[MAX_FORKS];
    int i;
    int N = atoi(argv[1]);

    // Garante que N não exceda MAX_FORKS
    if (N > MAX_FORKS) {
        fprintf(stderr, "Erro: Número máximo de forks é %d\n", MAX_FORKS);
        return 1;
    }

    // Garante que N não é negativo
    if (N <= 0) {
        fprintf(stderr, "Erro: N deve ser positivo\n");
        return 1;
    }

    // Código executado apenas pelo pai
    printf("[Pai] PID %d criou %d filhos\n", getpid(), N);

    for (i = 0; i < N; i++) {
        pid[i] = fork();
        
        if (pid[i] < 0) {
            perror("fork falhou");
            exit(1);
        }
        
        if (pid[i] == 0) {
            // Código executado apenas pelos filhos
            printf("[Filho %d] PID %d criado\n", i+1, getpid());
            exit(0);  // Filhos terminam aqui
        }
    }
    
    // Espera todos os filhos terminarem
    for (i = 0; i < N; i++) {
        wait(NULL);
    }

    return 0;
}