#include "2048.h"

void ecranFinal(jeu game){
    clear();
    int bestscore = 0;
    ifstream file1("highscore.txt");
    file1 >> bestscore;
    if (game.s>bestscore){
    	bestscore = game.s;
    	ofstream file2("highscore.txt");
    	file2 << bestscore;
    }
    WINDOW *afficheTableau, *afficheScore;
    afficheTableau = subwin(stdscr, LINES/2, COLS, 0, 0);
    afficheScore = subwin(stdscr, LINES/2, COLS, LINES/2, 0);
    mvwprintw(afficheTableau, 0, 0, dessine(game.p).c_str());
    mvwprintw(afficheScore, 2, LINES/2, "score = %d", game.s);
    mvwprintw(afficheScore, 4, LINES/2, "Record = %d", bestscore);
    mvwprintw(afficheScore, 6, LINES/2, "Appuyez sur une ECHAP pour quitter !");
    wrefresh(afficheTableau);
    wrefresh(afficheScore);
    refresh();
    int ch = 0;
    while (ch!=27){
    	ch = getch();
	}
}

void dessineNcurses(Plateau plateau){
    
    vector<vector<const char *>> grilleChar(4);
    vector<vector<string>> grille(4);
    for (int i =0; i<grille.size(); i++){
        grille[i] = vector<string>(4);
        grilleChar[i] = vector<const    char *>(4);
        for (int j=0; j<grille[i].size(); j++){
            if (plateau[i][j] == 0){
                grille[i][j] = " ";
            } else {
                grille[i][j] = to_string(plateau[i][j]);   //convertit le tableau d'entiers en tableau de strings
            }
            int k = 0;
            while (grille[i][j].size() < 5){     //Donne une taille de 5 à chaque case de t en rajoutant des espaces a droite et a gauche
                k = k+1;
                if ( k%2 == 1 ){
                    grille[i][j] = grille[i][j] + " ";
                } else {
                    grille[i][j] = " " + grille[i][j];
                }

            }
            grilleChar[i][j] = grille[i][j].c_str();
        }
    }
    
    start_color();
    printw("*************************\n");
    for(int i=0; i<plateau.size(); i++){
        for(int j=0; j<plateau.size(); j++){
        	printw("*");
            colorie(plateau[i][j], grilleChar[i][j]);
        }
    printw("*\n*************************\n");
    }   


    refresh();
}

void colorie(int valeur, const char * tile){
	switch (valeur){
		case 0:
			printw(tile);
			break;
		case 2:
			attron(A_STANDOUT|COLOR_PAIR(2));
			printw(tile);
			attroff(A_STANDOUT|COLOR_PAIR(2));
			break;
		case 4:
			attron(A_STANDOUT|COLOR_PAIR(4));
			printw(tile);
			attroff(A_STANDOUT|COLOR_PAIR(4));
			break;
		case 8:
			attron(A_STANDOUT|COLOR_PAIR(8));
			printw(tile);
			attroff(A_STANDOUT|COLOR_PAIR(8));
			break;
		case 16:
			attron(A_STANDOUT|COLOR_PAIR(16));
			printw(tile);
			attroff(A_STANDOUT|COLOR_PAIR(16));
			break;
		case 32:
			attron(A_STANDOUT|COLOR_PAIR(32));
			printw(tile);
			attroff(A_STANDOUT|COLOR_PAIR(32));
			break;
		case 64:
			attron(A_STANDOUT|COLOR_PAIR(64));
			printw(tile);
			attroff(A_STANDOUT|COLOR_PAIR(64));
			break;
		case 128:
			attron(A_STANDOUT|COLOR_PAIR(128));
			printw(tile);
			attroff(A_STANDOUT|COLOR_PAIR(128));
			break;
		case 256:
			attron(A_STANDOUT|COLOR_PAIR(256));
			printw(tile);
			attroff(A_STANDOUT|COLOR_PAIR(256));
			break;
		case 512:
			attron(A_STANDOUT|COLOR_PAIR(512));
			printw(tile);
			attroff(A_STANDOUT|COLOR_PAIR(512));
			break;
		case 1024:
			attron(A_STANDOUT|COLOR_PAIR(1024));
			printw(tile);
			attroff(A_STANDOUT|COLOR_PAIR(1024));
			break;
		case 2048:
			attron(A_STANDOUT|COLOR_PAIR(2048));
			printw(tile);
			attroff(A_STANDOUT|COLOR_PAIR(2048));
			break;
	}
}	
