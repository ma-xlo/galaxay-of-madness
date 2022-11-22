#include <iostream>

const int MAX_AMMO = 7;

struct spaceCraft{
    std::string primaryWeapon;
    std::string secundaryWeapon;
    int totalAmmoPrimary = MAX_AMMO;
    int totalAmmoSecondary = MAX_AMMO;

    void fire(int shot){
        if(this->totalAmmoPrimary > 0)
            this->totalAmmoPrimary -= shot;
    }

    void recharge(){
            this->totalAmmoPrimary = MAX_AMMO;
    }

};
 int main(int argc, const char** argv) {
    
    FILE *lvl_1_intro = fopen("./lvl_2/intro.txt", "r");
    FILE *lvl_1_part_1 = fopen("./lvl_2/part_1.txt", "r");
    char line[100];

    spaceCraft maveric;
    char action;
    int shot=0, op, life = 24;
    std::string bossLife = "========================="; 

    system("clear");
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "                   [1] Start" << std::endl;
    std::cout << "                   [2] Exit" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "                   Option: ";
    std::cin >> op;
    while ( getchar() != '\n' );


    if(op == 1) {

        system("clear");
        while(fgets(line, 100, lvl_1_intro)) {
            std::cout << line;
        }
        std::cin;
        while ( getchar() != '\n' );
        
        system("clear");
        while(fgets(line, 100, lvl_1_part_1)) {
            std::cout << line;
        }

        for(;;) {
            action = getchar();
            if (action == '\n')
            {
                if(maveric.totalAmmoPrimary == 0) {

                    system("clear");
                    std::cout << std::endl;
                    std::cout << "      Life: " << bossLife << std::endl;
                    std::cout << "                  '               '    " << std::endl;
                    std::cout << "      '   /                   '    \\  " << std::endl;
                    std::cout << "        -(---------/-----\\---------)- " << std::endl;
                    std::cout << "     //( ()     (   )     (   )   () )" << std::endl;
                    std::cout << "    //  \\\\----------(||||)---------//" << std::endl;
                    std::cout << "    \\\\     _____/_____           ///    " << std::endl;
                    std::cout << "     \\\\   | Pathetic! |        ╭∩╮//    " << std::endl;
                    std::cout << "      \\\\   ¨¨¨¨¨¨¨¨¨¨¨         ¨¨¨¨     " << std::endl;
                    std::cout << "      ( )                                 " << std::endl;
                    std::cout << "                                         " << std::endl;
                    std::cout << "           '     Out of ammo!      '  " << std::endl;
                    std::cout << "              press 'r' to reload      " << std::endl;
                    std::cout << "        '                       '      " << std::endl;
                    std::cout << "            '        '   _______       " << std::endl;
                    std::cout << "                        | glup! |      " << std::endl;
                    std::cout << "        '              / ¨¨¨¨¨¨¨       " << std::endl;
                    std::cout << "          '           Δ       '        " << std::endl;
                    std::cout << std::endl;
                    
                }
                else {
                    bossLife[life] = ' '; 
                    life -= 1;
                    maveric.fire(1);
                    system("clear");
                    std::cout << std::endl;
                    std::cout << "      Life: " << bossLife << std::endl;
                    std::cout << "                  '               '    " << std::endl;
                    std::cout << "      '   /                   '    \\  " << std::endl;
                    std::cout << "        -(---------/-----\\---------)- " << std::endl;
                    std::cout << "       ( ()     (   )     (   )   () )" << std::endl;
                    std::cout << "      ' \\\\----------(||||)---------//" << std::endl;

                    
                    if(life >= 17 && life <= 25) {
                        std::cout << "           //                 //     " << std::endl;
                        std::cout << "           \\\\(_)              //       " << std::endl;
                        std::cout << "                            ( )      " << std::endl;
                        std::cout << "                            /         " << std::endl;
                        std::cout << "                           /           " << std::endl;
                        std::cout << "           '              /        '   " << std::endl;
                        std::cout << "                                       " << std::endl;
                        std::cout << "        '                       '      " << std::endl;
                    }
                    // } else {
                    //     std::cout << "                                   " << std::endl;
                    //     std::cout << "                                   " << std::endl;
                    //     std::cout << "                                   " << std::endl;
                    // }

                    else if(life >= 10 && life <= 16) {
                        std::cout << "            \\\\              \\\\      " << std::endl;
                        std::cout << "             \\\\           (_)//      " << std::endl;
                        std::cout << "               ( )                     " << std::endl;
                        std::cout << "                \\                     " << std::endl;
                        std::cout << "                 \\                    " << std::endl;
                        std::cout << "           '      \\               '   " << std::endl;
                        std::cout << "                                       " << std::endl;
                        std::cout << "        '                       '      " << std::endl;
                    } 
                    else {
                        std::cout << "             /|\\            /|\\      " << std::endl;
                        std::cout << "            * * *          * * *       " << std::endl;
                        std::cout << "          *   *   *      *   *   *     " << std::endl;
                        std::cout << "        *     *    *   *     *     *   " << std::endl;
                        std::cout << "                                       " << std::endl;
                        std::cout << "           '                       '   " << std::endl;
                        std::cout << "                                       " << std::endl;
                        std::cout << "        '                       '      " << std::endl;

                    }

                    if(shot % 2 != 0) {
                        std::cout << "            '        '   ______         " << std::endl;
                        std::cout << "                        | pew! |        " << std::endl;
                        std::cout << "        '              / ¨¨¨¨¨¨         " << std::endl;
                        std::cout << "          '           Δ       '         " << std::endl;
                        shot += 1;
                    } else  {
                        std::cout << "            ' ______ '                  " << std::endl;
                        std::cout << "             | pew! |                   " << std::endl;
                        std::cout << "        '     ¨¨¨¨¨¨ \\                 " << std::endl;
                        std::cout << "          '           Δ       '         " << std::endl;
                        shot += 1;

                    }

                    //std::cout << life << std::endl;
                    if(life == -1) {
                        system("clear");
                            std::cout << std::endl;
                            std::cout << "                                  " << std::endl;
                            std::cout << "              +-------------+         " << std::endl;
                            std::cout << "              |   You win!  |         " << std::endl;
                            std::cout << "              +-------------+         " << std::endl;
                            std::cout << "                                  " << std::endl;

                            return 0;
                        }
                    }


            } else if(action == 'r'){
                if(maveric.totalAmmoPrimary == MAX_AMMO) {
    
                    std::cout << "Ammo is full!" << std::endl;

                } else {
                    maveric.recharge();
                    std::cout << "\nWeapon is loaded! " << maveric.totalAmmoPrimary << "%"<< std::endl;
                }
            } else 
                break;
            
        }
    }

    return 0;
 }