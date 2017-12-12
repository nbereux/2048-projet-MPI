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


Plateau plateauVide();
Plateau plateauInitial();

Plateau suppression0Haut(Plateau plateau);
Plateau suppression0Bas(Plateau plateau);
Plateau suppression0Gauche(Plateau plateau);
Plateau suppression0Droite(Plateau plateau);

Plateau additionHaut(Plateau plateau);
Plateau additionBas(Plateau plateau);
Plateau additionGauche(Plateau plateau);
Plateau additionDroite(Plateau plateau);

Plateau deplacementHaut(Plateau plateau);
Plateau deplacementBas(Plateau plateau);
Plateau deplacementGauche(Plateau plateau);
Plateau deplacementDroite(Plateau plateau);
Plateau deplacement(Plateau plateau, int direction);

string dessine(Plateau g);
bool estTermine(Plateau plateau);
bool estGagnant(Plateau plateau);
int score(Plateau plateau);

int valeurCase();
Plateau creationCase(Plateau t);
