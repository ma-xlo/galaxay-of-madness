#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BLANK_SPACE ' '
#define X_SIZE 11
#define Y_SIZE 11

void* bossThread(char matrix[Y_SIZE][X_SIZE]){
    matrix[0][X_SIZE/2] = 'v';

    for(; ;) {
        for(int i = 1; i < Y_SIZE; i++) {
            matrix[i][5] = '*';
            system("sleep 0.2");
            matrix[i][5] = BLANK_SPACE;

            if(i == X_SIZE-2)
                break;
        }
    }

}

void playerThread(char matrix[Y_SIZE][Y_SIZE]) {
    char input;
    matrix[Y_SIZE-1][X_SIZE/2] = '^';

    for(; ;) {
        for(int i = Y_SIZE - 2; i >= 1; i--) {
            matrix[i][5] = '|';
            system("sleep 0.05");
            matrix[i][5] = BLANK_SPACE;

            if(i == 1)
                break;
        }
    }

}

void playerMove(char matrix[Y_SIZE][Y_SIZE]){
        char input = 5;

        // system("stty raw"); 
        // input = getchar();                                                       
        // system("stty cooked");

        if(input == 5) {
            matrix[0][0] = 'O';
            matrix[0][1] = 'K';
            system("sleep 0.05");
            matrix[0][0] = BLANK_SPACE;
            matrix[0][1] = BLANK_SPACE;
        }


}

void refreshState(char matrix[Y_SIZE][Y_SIZE]) {

    for(int k = 0; k < 50000; k++) {
        system("clear");
        printf("\n\n\n");
        for(int i = 0; i < Y_SIZE; i++) {
            printf("\t ");
            for(int j = 0; j < X_SIZE; j++) {
                printf("%c ", matrix[i][j]);
            }
            printf("\n");
        }
        system("sleep 0.05");
        // system("clear");
        // system("sleep 0.05");

    }
    printf("\e[?25h");

}



int main() {
    printf("\e[?25l");

    char matrix[Y_SIZE][X_SIZE];

    for(int i = 0; i < Y_SIZE; i++) 
        for(int j = 0; j < X_SIZE; j++) 
            matrix[i][j] = BLANK_SPACE;

    pthread_t t1, t2, t3, t4;
    pthread_create(&t1, NULL, &bossThread, (void**)matrix);
    pthread_create(&t2, NULL, &refreshState, (void**)matrix);
    pthread_create(&t3, NULL, &playerThread, (void**)matrix);
    pthread_create(&t4, NULL, &playerMove, (void**)matrix);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

  



    printf("\e[?25h");
    return 0;
}