#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int y = 0;

void *threadBody(void *arg) {
    int x = 0;
    sleep(10);
    printf("x: %d, y: %d\n", ++x, ++y);
    pthread_exit(NULL);
}

int main() {
    pthread_t tA, tB, tC;

    pthread_create(&tA, NULL, threadBody, NULL);
    pthread_create(&tB, NULL, threadBody, NULL);

    sleep(1);
    pthread_join(tA, NULL);
    pthread_join(tB, NULL);

    sleep(1);
    pthread_create(&tC, NULL, threadBody, NULL);
    pthread_join(tC, NULL);

    return 0;
}
