#include <vector>
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <cstdio>
#include <thread>
#include <chrono>
#include "2048.h"
using namespace std;


int main(){
    srand(time(NULL));
    int direction;
    Plateau stockageTableau;
    Plateau plateauDeJeu = plateauInitial();
    cout << dessine(plateauDeJeu) << endl;
    while (estGagnant(plateauDeJeu) != true and estTermine(plateauDeJeu)!= true){
        stockageTableau = plateauDeJeu;
        direction = 0;
        while (direction != 2 and direction != 4 and direction != 6 and direction != 8){
            cout << "Entrez le déplacement : ";
            cin >> direction;
        }
        plateauDeJeu = deplacement(plateauDeJeu, direction);
        if (plateauDeJeu != stockageTableau){
            plateauDeJeu = creationCase(plateauDeJeu);
        }
        cout << dessine(plateauDeJeu) << endl;
    }
    return 0;

}

