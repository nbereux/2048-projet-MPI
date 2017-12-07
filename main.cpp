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
    jeu jeuActuel; 
    srand(time(NULL));  //donne une seed égale au nombre de secondes depuis le 1er janvier 1970 minuit à la fonction rand
    int direction;
    Plateau stockageTableau; 
    jeuActuel.p = plateauInitial();
    jeuActuel.s=0;
    cout << dessine(jeuActuel.p) << endl;
    while (estGagnant(jeuActuel.p) != true and estTermine(jeuActuel)!= true){
        stockageTableau = jeuActuel.p;
        direction = 0;
        while (direction != 2 and direction != 4 and direction != 6 and direction != 8){
            cout << "Entrez le déplacement : ";
            cin >> direction;
        }
        jeuActuel = deplacement(jeuActuel, direction);
        if (jeuActuel.p != stockageTableau){    //vérifie que le tableau après le déplacement est différent du tableau avant déplacement
            jeuActuel.p = creationCase(jeuActuel.p);
        }
        cout << "score : " << jeuActuel.s << endl;
        cout << dessine(jeuActuel.p) << endl;
    }
    return 0;
}

