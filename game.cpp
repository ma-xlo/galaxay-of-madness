#include <iostream>
#include <string.h>
#include <time.h>
#include <ncurses.h>

#define x 11
#define y 11
#define SHIP_POSIX 10
#define BLANK_SPACE ' '
#define FRAME_RATE 0.15
#define SHOT '|'
#define SHIP '^'

void showLogo(FILE *logo){
    // system("clear");
    char line[100];
    printf("\n");
    while(fgets(line, 100, logo)){
        printf("%s", line);
    }
    printf("\n");
}

void refreshState(char matrix[y][x], char *boss, int score, int bossSize) {

    system("clear");
    printf("\t\t\t   SCORE: %4d", score);
    printf("\n\n");

    //Boss frame
    for(int j = 3, k = 0; j < bossSize + 3; j++, k++) 
            matrix[1][j] = boss[k];
    // strcpy(matrix[1], boss);
    
    
    for(int i = 0; i < y; i++) {
        printf("\t ");
        for(int j = 0; j < x; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
    // printf("\e[?25h");
}

int bossState(char *boss) {
    int state = 5;

    for(int i = 0; i < 5; i++) 
        if(boss[i] == BLANK_SPACE)
            state -= 1;
    //printf("%s", boss);
    //printf("%d", state);
    return state;    
}

void startScreen () {
    for(int i = 0; i < 7; i++) {

            system("clear");
            printf("\n\n\n\n\n\n\n\n");
            std::cout << "               S T A R T !      \n\n" << std::endl;
            printf("\n\n\n\n\n\n");
            system("sleep 0.1");

            system("clear");
            system("sleep 0.1");
    }
}

int main(){
    
    FILE *logo = fopen("logo.txt", "r");
    char matrix[y][x];
    int x_axis = x/2;
    int inGame = 1;
    int stage = 1;
    char input = '8';
    char boss[15] = {'x', '0', 'X', '0', 'x'};
    int score = 0;
    int bossSize= strlen(boss);
    
    // Game scenario
    for(int i = 0; i < y; i++) 
        for(int j = 0; j < x; j++) 
            matrix[i][j] = BLANK_SPACE;
    
    matrix[SHIP_POSIX][x/2] = SHIP;
    // strcpy(boss, "x0X0x");
    
    //Hide the cursor
    printf("\e[?25l");

    int option = 1;
    while(input != 32) 
    {
        if(input == '8') {
            system("clear");
            // showLogo(logo);
            std::cout << "         __                           " << std::endl;
            std::cout << "        / _` /\\ |    /\\ \\_/\\ /        " << std::endl;
            std::cout << "        \\__>/--\\|___/--\\/ \\ |         " << std::endl;
            std::cout << "              __  of  ___ __  __      " << std::endl;
            std::cout << "     |\\/| /\\ |  \\|\\ ||__ /__`/__`     " << std::endl;
            std::cout << "     |  |/--\\|__/| \\||___.__/.__/     " << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "              -> Start" << std::endl;
            std::cout << "                 Exit" << std::endl;
            system("stty raw"); 
            input = getchar();                                                       
            system("stty cooked");
            option = 1;
        }
        else if(input == '2') {   
            system("clear");
            std::cout << "         __                           " << std::endl;
            std::cout << "        / _` /\\ |    /\\ \\_/\\ /        " << std::endl;
            std::cout << "        \\__>/--\\|___/--\\/ \\ |         " << std::endl;
            std::cout << "              __  of  ___ __  __      " << std::endl;
            std::cout << "     |\\/| /\\ |  \\|\\ ||__ /__`/__`     " << std::endl;
            std::cout << "     |  |/--\\|__/| \\||___.__/.__/     " << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "                 Start" << std::endl;
            std::cout << "              -> Exit" << std::endl;
            system("stty raw"); 
            input = getchar();                                                       
            system("stty cooked");
            option = 2;
        }
        else if(input == 32 && option == 2)
            return 0;
        else 
            continue;
    }
    startScreen ();
    
    while(inGame) {

        refreshState(matrix, boss, score, bossSize);
        system("stty raw"); 
        input = getchar();                                                       
        system("stty cooked");
        
        if(input == 68) {
            
            //Left arrow
            if(x_axis > 0) {
                matrix[SHIP_POSIX][x_axis] = BLANK_SPACE;
                x_axis -=1;
                matrix[SHIP_POSIX][x_axis] = SHIP;
            }
            refreshState(matrix, boss, score, bossSize);

        }
        
        else if(input == 67) {
            
            //Left arrow
            if(x_axis < x - 1) {
                matrix[SHIP_POSIX][x_axis] = BLANK_SPACE;
                x_axis +=1;
                matrix[SHIP_POSIX][x_axis] = SHIP;
            }
            refreshState(matrix, boss, score, bossSize);
        }

        else if(input == 32) {
            
            //Shot triggered
            for(int i = y - 2; i >= 0; i--) {
                
                matrix[i][x_axis] = SHOT;
                refreshState(matrix, boss, score, bossSize);
                system("sleep 0.02");
                //After every shot frame
                matrix[i][x_axis] = BLANK_SPACE;
                refreshState(matrix, boss, score, bossSize);
                
                //Check if boss was hited
                if(matrix[i][x_axis] != BLANK_SPACE) {
                    boss[x_axis-3] = BLANK_SPACE; //-> -3?????????????????????????????
                    score += 100;
                    //Explosion
                } 
                else if (i == 1 && matrix[i][x_axis] == BLANK_SPACE) {
                    printf("\n\n\n\n\n\n");
                    for(int i = 0; i < 7; i++) {
                            system("clear");
                            printf("\n\n\n\n\n\n");
                            std::cout << "             \\     |     /      \n" << std::endl;
                            std::cout << "            -- GAME OVER! --     \n" << std::endl;
                            std::cout << "             /     |     \\      \n" << std::endl;
                            printf("\n\n\n\n\n\n");
                            system("sleep 0.2");

                            system("clear");
                            system("sleep 0.2");
                    }
                    printf("\e[?25h");
                    system("stty cooked");
                    return 0;
                }

            }
            if(bossState(boss) == 0) {
                if(stage == 1)
                    // strcpy(boss, "-U_U-");
                    strcpy(boss, "-U_Uz-");
                else if(stage == 2)
                    strcpy(boss, "|A=A|");
                else if(stage == 3)
                    strcpy(boss, "^~v~^");
                else if(stage == 4)
                    strcpy(boss, "~O.O~");
                else if(stage == 5)
                    strcpy(boss, "A|-|A");
                else if(stage == 6)
                    strcpy(boss, "ZZ*ZZ");
                else if(stage == 7)
                    strcpy(boss, "KK-KK");
                stage += 1;

            }
            if(stage == 9) {

                printf("\n\n\n\n\n\n");
                for(int i = 0; i < 7; i++) {
                        system("clear");
                        printf("\n\n\n\n\n\n");
                        std::cout << "             \\     |     /      \n" << std::endl;
                        std::cout << "            -- You  Win ! --     \n" << std::endl;
                        std::cout << "             /     |     \\      \n" << std::endl;
                        printf("\n\n\n\n\n\n");
                        system("sleep 0.1");

                        system("clear");
                        system("sleep 0.1");
                }
                printf("\e[?25h");

                system("stty cooked");
                break; 
            }
        }

        else if(input == 'q') {
            system("clear");
            printf("\e[?25h");
            inGame = 0;
            system("stty cooked");

        }
        else {
            refreshState(matrix, boss, score, bossSize);
        }
    }   

    system("stty cooked");
    return 0;
}

