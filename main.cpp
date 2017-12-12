#include "2048.h"
using namespace std;


int main(){
    initscr();
    noecho();
    cbreak();
    keypad(stdscr,TRUE);
    timeout(0);
    srand(time(NULL));
    int direction;
    Plateau stockageTableau;
    Plateau plateauDeJeu = plateauInitial();
    printw(dessine(plateauDeJeu).c_str());
    while (estGagnant(plateauDeJeu) != true and estTermine(plateauDeJeu)!= true){
        stockageTableau = plateauDeJeu;
        direction = 0;
        while (direction != 2 and direction != 4 and direction != 6 and direction != 8){
            int touche = getch();
            if(touche!=ERR){
                switch(touche){
                    case KEY_UP:
                        direction = 8;
                        break;
                    case KEY_DOWN:
                        direction = 2;
                        break;
                    case KEY_LEFT:
                        direction = 4;
                        break;
                    case KEY_RIGHT:
                        direction = 6;
                        break;
                }
            }
        }
        plateauDeJeu = deplacement(plateauDeJeu, direction);
        if (plateauDeJeu != stockageTableau){
            plateauDeJeu = creationCase(plateauDeJeu);
        }
        clear();
        printw(dessine(plateauDeJeu).c_str());
        printw("score = ", plateauDeJeu);
        refresh();
    }
    return 0;

}

