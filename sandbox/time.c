#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int timer(int *sec){
    while(*sec < 10){

        *sec += 1;
        system("sleep 1");
        //printf("%d\n", *sec);

        if(*sec == 5) {
            printf("TIME'S UP!\n");
            break;
        }
    }
}

int timeStamp(int *sec){
    char guess[5];
    printf("Guess: ");
    scanf("%s", guess);

    printf("Your guess: %s\n", guess);
}


int main() {
    pthread_t t1, t2;
    int sec = 0;
    pthread_create(&t1, NULL, &timer, &sec);
    pthread_create(&t2, NULL, &timeStamp, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    

    return 0;
}