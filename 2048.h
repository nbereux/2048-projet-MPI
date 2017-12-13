#include <vector>
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <cstdio>
#include <thread>
#include <chrono>
#include <ncurses.h>
using namespace std;

const int GAUCHE = 4, DROITE = 6, HAUT = 8, BAS = 2;
typedef vector<vector<int>> Plateau;

struct jeu {    //définit une structure jeu contenant un plateau ainsi qu'un score
    Plateau p;
    int s;
};

Plateau plateauVide();
Plateau plateauInitial();

Plateau suppression0Haut(Plateau plateau);
Plateau suppression0Bas(Plateau plateau);
Plateau suppression0Gauche(Plateau plateau);
Plateau suppression0Droite(Plateau plateau);

jeu additionHaut(jeu game);
jeu additionBas(jeu game);
jeu additionGauche(jeu game);
jeu additionDroite(jeu game);

jeu deplacementHaut(jeu game);
jeu deplacementBas(jeu game);
jeu deplacementGauche(jeu game);
jeu deplacementDroite(jeu game);
jeu deplacement(jeu game, int direction);

string dessine(Plateau g);
bool estTermine(jeu game);
bool estGagnant(Plateau plateau);
int score(Plateau plateau);

int valeurCase();
Plateau creationCase(Plateau t);
