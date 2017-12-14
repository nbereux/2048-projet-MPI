		#include "2048.h"
using namespace std;


int main(){
    initscr();
    noecho();
    cbreak();
    start_color();
    keypad(stdscr,TRUE);
    timeout(0);
    

	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(8, COLOR_YELLOW, COLOR_BLACK);
	init_pair(16, COLOR_BLUE, COLOR_BLACK);
	init_pair(32, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(64, COLOR_CYAN, COLOR_BLACK);
	init_pair(128, COLOR_WHITE, COLOR_BLACK);
	init_pair(256, COLOR_CYAN, COLOR_BLACK);
	init_pair(512, COLOR_BLACK, COLOR_BLACK);
	init_pair(1024, COLOR_GREEN, COLOR_BLACK);
	init_pair(2048, COLOR_BLACK, COLOR_BLACK);
    
    jeu jeuActuel;
    srand(time(NULL));  //donne une seed égale au nombre de secondes depuis le 1er janvier 1970 minuit à la fonction rand
    int direction;
    Plateau stockageTableau;
    jeuActuel.p = plateauInitial();
    jeuActuel.s=0;
    printw(dessine(jeuActuel.p).c_str());
    while (estGagnant(jeuActuel.p) != true and estTermine(jeuActuel)!= true){
        stockageTableau = jeuActuel.p;
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
        jeuActuel = deplacement(jeuActuel, direction);
        if (jeuActuel.p != stockageTableau){    //vérifie que le tableau après le déplacement est différent du tableau avant déplacement
            jeuActuel.p = creationCase(jeuActuel.p);
        }
        clear();
		dessineNcurses(jeuActuel.p);
        printw("score = %d", jeuActuel.s);
        refresh();
    }
    ecranFinal(jeuActuel);
    return 0;
}

