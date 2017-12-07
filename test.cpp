#include "2048.h"


/** Infrastructutr minimale de test **/
#define ASSERT(C) if ( !(C) ) { std::cerr << "Test failed: "#C << std::endl; }

Plateau pVide = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
Plateau plateauGagnant = {{0,0,0,0},{0,0,2048,128},{128,64,32,16},{2,4,8,256}};
Plateau deux2048 = {{0,2048,0,0},{0,0,2048,128},{128,64,32,16},{2,4,8,256}};
Plateau pPlein = {{16,32,64,128},{256,512,1024,512},{256,128,64,32},{16,8,4,2}};
Plateau p1 = {{16,2,8,0},{2,16,0,2},{0,0,0,0},{2,0,0,0}};
Plateau p1Gauche = {{16,2,8,2},{4,16,0,0},{0,0,0,0},{0,0,0,0}};
Plateau p1Droite = {{0,0,0,0},{0,0,0,0},{16,2,0,0},{4,16,8,2}};
Plateau p1Haut = {{16,2,8,0},{2,16,2,0},{0,0,0,0},{2,0,0,0}};
Plateau p1Bas = {{0,16,2,8},{0,2,16,2},{0,0,0,0},{0,0,0,2}};
Plateau p2 = {{2,2,2,2},{2,2,2,2},{2,2,2,2},{2,2,2,2}};
Plateau p2Haut = {{4,4,4,4},{4,4,4,4},{0,0,0,0},{0,0,0,0}};
Plateau p2Bas = {{0,0,0,0},{0,0,0,0},{4,4,4,4},{4,4,4,4}};
Plateau p2Gauche = {{4,4,0,0},{4,4,0,0},{4,4,0,0},{4,4,0,0}};
Plateau p2Droite = {{0,0,4,4},{0,0,4,4},{0,0,4,4},{0,0,4,4}};

void plateauVideTest(){
    for (int i = 0; i<=10000; i++){
        ASSERT (plateauVide() == pVide);
    }
}

void valeurCaseTest(){
    for (int i = 0; i<=10000; i++){
        int x = valeurCase();
        ASSERT ((x==2) or (x==4));
    }
}

void plateauInitialTest(){
    int compteurErreur1 = 0;
    int compteurErreur2 = 0;
    for (int i = 0; i<=10000; i++){
        Plateau t = plateauInitial();
        int sommeCase = 0;
        int nombreCaseInit = 0;
        for (int j = 0; j<t.size(); j++){
            for (int k = 0; k<t[j].size(); k++){
                sommeCase = sommeCase +t[j][k];
                if (t[j][k] != 0){
                    nombreCaseInit++;
                    if ((t[j][k] != 2) and (t[j][k]!=4)){
                        compteurErreur2++;
                    }
                }
            }
        }
        if (nombreCaseInit!=2 and nombreCaseInit!=1){
            compteurErreur1++;
        }
    }
    cout << compteurErreur1 << " fois où le tableau n'avait pas le bon nombre de cases initialisées" << endl;
    cout << compteurErreur2 << " fois où le tableau n'avait pas les bonnes valeurs dans les cases initialisées" << endl;
}

void estGagnantTest(){
    ASSERT(estGagnant(plateauGagnant) == true );
    ASSERT(estGagnant(pVide) == false);
    ASSERT(estGagnant(deux2048) == true);
    ASSERT(estGagnant(pPlein) == false);
    ASSERT(estGagnant(p1) == false);
    ASSERT(estGagnant(p1Haut) == false);
    ASSERT(estGagnant(p1Bas) == false);
    ASSERT(estGagnant(p1Gauche) == false);
    ASSERT(estGagnant(p1Droite) == false);
}

void estTermineTest(){
    ASSERT(estTermine(pPlein) == false);
    ASSERT(estTermine(plateauGagnant) == true);
    ASSERT(estTermine(deux2048) == true);
    ASSERT(estTermine(p1) == false);
    ASSERT(estTermine(p1Haut) == false);
    ASSERT(estTermine(p1Bas) == false);
    ASSERT(estTermine(p1Gauche) == false);
    ASSERT(estTermine(p1Droite) == false);
    ASSERT(estTermine(p2) == false);
    ASSERT(estTermine(p2Haut) == false);
    ASSERT(estTermine(p2Bas) == false);
    ASSERT(estTermine(p2Gauche) == false);
    ASSERT(estTermine(p2Droite) == false);
}

void deplacementHautTest(){
    ASSERT(deplacementHaut(p1) == p1Haut);
    ASSERT(deplacementHaut(p2) == p2Haut);
}

void deplacementBasTest(){
    ASSERT(deplacementBas(p1) == p1Bas);
    ASSERT(deplacementBas(p2) == p2Bas);
}
void deplacementGaucheTest(){
    ASSERT(deplacementGauche(p1) == p1Gauche);
    ASSERT(deplacementGauche(p2) == p2Gauche);
}

void deplacementDroiteTest(){
    ASSERT(deplacementDroite(p1) == p1Droite);
    ASSERT(deplacementDroite(p2) == p2Droite);
}

int main(){
    plateauVideTest();
    valeurCaseTest();
    plateauInitialTest();
    estGagnantTest();
    estTermineTest();
    return 0;
}
    )
