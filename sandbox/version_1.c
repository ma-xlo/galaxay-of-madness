#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include <unistd.h>
#include <termios.h>


#define BLANK_SPACE ' '
#define X_SIZE 11
#define Y_SIZE 11

void* bossThread(char matrix[Y_SIZE][X_SIZE]){
    int p = X_SIZE/2, init, initF;

    for(; ;) {

        if(p < X_SIZE && init == 0) { 
            matrix[0][p] = 'v';
            matrix[0][p-1] = BLANK_SPACE;

            if(p == X_SIZE - 1)
                init = 1;
            p++;
        }

        else if (p > 0 && init == 1){
            matrix[0][p-1] = 'v';
            matrix[0][p] = BLANK_SPACE;

            if(p == 1)
                init = 0;
            p--;
        }
        for(int i = 1; i < Y_SIZE; i++) {

            if(p <= X_SIZE - 1 && init == 1) { 



                matrix[i][p] = '*';
                system("sleep 0.1");
                matrix[i][p] = BLANK_SPACE;
                if(p == X_SIZE - 1) {
                    initF = 0;
                    if(matrix[Y_SIZE-1][p] == '^') {
                        printf("Game Over");
                        system("sleep 2");
                    }
                }
            }
            else if (p > 0 && init == 0){

                matrix[i][p-1] = '*';
                system("sleep 0.1");
                matrix[i][p-1] = BLANK_SPACE;
                if(p == 1)
                    initF = 1;

                if(matrix[Y_SIZE-1][p] == '^') {
                    printf("Game Over");
                    system("sleep 2");
                }
            }
        }
    }

}

void *playerThread(char matrix[Y_SIZE][X_SIZE]) {
    
    // // initialization
    int x_axis = X_SIZE / 2;
	struct termios old_tio, new_tio;
	unsigned char ch;

	/* get the terminal settings for stdin */
	tcgetattr(STDIN_FILENO,&old_tio);

	/* we want to keep the old setting to restore them a the end */
	new_tio=old_tio;

	/* disable canonical mode (buffered i/o) and local echo */
	new_tio.c_lflag &=(~ICANON & ~ECHO);

	/* set the new settings immediately */
	tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);

    matrix[Y_SIZE - 1][X_SIZE/2] = '^';

    for(; ;) {  

        ch=getchar();
        
        switch (ch) {
            case 67:
                if(x_axis < Y_SIZE - 1) {
                    matrix[Y_SIZE - 1][x_axis] = BLANK_SPACE;
                    x_axis += 1;
                    matrix[Y_SIZE - 1][x_axis] = '^';
                }
                break;
            case 68:
                if(x_axis > 0) {
                    matrix[Y_SIZE - 1][x_axis] = BLANK_SPACE;
                    x_axis -= 1;
                    matrix[Y_SIZE - 1][x_axis] = '^';
                }
                break;
            case 32:
                // system("play -q pew.mp3");
                for(int i = Y_SIZE - 2; i >= 0; i--) {


                    matrix[i][x_axis] = '|';
                    system("sleep 0.03");
                    matrix[i][x_axis] = BLANK_SPACE;

                    if(i == 0)
                        break;
                }
                break;
            case 'q':
                /* restore the former settings */
                tcsetattr(STDIN_FILENO,TCSANOW,&old_tio);
                printf("\e[?25h");
                exit(0);   
                break;
        }
    }
}

void* refreshState(char matrix[Y_SIZE][Y_SIZE]) {
    
    for( ; ; ) {
        printf("\e[?25l");
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
    }
}


int main(void) {

    printf("\e[?25l");

    char matrix[Y_SIZE][X_SIZE];

    for(int i = 0; i < Y_SIZE; i++) 
        for(int j = 0; j < X_SIZE; j++) 
            matrix[i][j] = BLANK_SPACE;

    pthread_t t1, t2, t3;

    pthread_create(&t1, NULL, &bossThread, (void*)matrix);
    pthread_create(&t2, NULL, &refreshState, matrix);
    pthread_create(&t3, NULL, &playerThread, (void*)matrix);
    // pthread_create(&t4, NULL, &shotsThread, (void*)matrix);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    // pthread_join(t4, NULL);



    printf("\e[?25h");
    return EXIT_SUCCESS;
}