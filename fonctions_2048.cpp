	#include "2048.h"

/** Construit un tableau 2D 4x4 d'entiers dont les valeurs sont initialisées à 0
 * @return le tableau 2D 4x4 d'entiers
**/



Plateau plateauVide() {
    Plateau t = Plateau(4);
    for (int i = 0; i<t.size(); i++){
        t[i] = vector<int>(4,0);
    }
    return t;
}



/** renvoie au hasard 2 ou 4
 * @return l'entier n contenant au hasard 2 ou 4
**/



int valeurCase () {
    int i = rand() % 10;
    if (i == 0){
        return 4;
    }else{
        return 2;
    }
}



/** Construit un tableau 2D 4x4 d'entiers dont les valeurs sont initialisées à 0 sauf une ou deux cases à 2 ou 4
 * @return le tableau 2D 4x4 d'entiers
**/



Plateau plateauInitial() {
    Plateau t = plateauVide();
    vector<int> testRandom(5);
    int abscisseInitiale1 = rand() % 4;
    int ordonneeInitiale1 = rand() % 4;
    int abscisseInitiale2 = rand() % 4;
    int ordonneeInitiale2 = rand() % 4;
    int nombreDeCasesInitialisees = valeurCase();
    if (nombreDeCasesInitialisees == 4){
        t[abscisseInitiale1][ordonneeInitiale1] = valeurCase();
    } else {
        t[abscisseInitiale1][ordonneeInitiale1] = valeurCase();
        t[abscisseInitiale2][ordonneeInitiale2] = valeurCase();
    }
    return t;
}



/** dessine le tableau dans le terminal
 * @param un tableau 2D 4x4 g
 * @return une chaine de caractères représentant la grille et les nombres dans les cases
**/



string dessine(Plateau g) {
    vector<vector<string>> t = vector<vector<string>>(4);
    for (int i = 0; i<t.size(); i++){
        t[i] = vector<string>(4);
        for (int j = 0; j<t[i].size(); j++){
            t[i][j] = to_string(g[i][j]);
            int k = 0;
            while (t[i][j].size() < 5){
                k = k+1;
                if ( k%2 == 1 ){
                    t[i][j] = t[i][j] + " ";
                } else {
                    t[i][j] = " " + t[i][j];
                }

            }
        }
    }
    string grille = "*************************\n*" + t[0][0] + "*" + t[0][1] + "*" + t[0][2] + "*" + t[0][3] +"*\n*************************\n*" + t[1][0] + "*" + t[1][1] + "*" + t[1][2] + "*" + t[1][3] +"*\n*************************\n*" + t[2][0] + "*" + t[2][1] + "*" + t[2][2] + "*" + t[2][3] +"*\n*************************\n*" + t[3][0] + "*" + t[3][1] + "*" + t[3][2] + "*" + t[3][3] +"*\n*************************\n";
    return grille;
}



/** Détermine si la grille est gagnante
 * @param un plateau plateau
 * @return un booleen vrai si la grille contient une case 2048 et faux sinon
**/



bool estGagnant(Plateau plateau) {
    for (int i = 0; i<plateau.size(); i++){
        for (int j = 0; j<plateau[i].size(); j++){
            if (plateau[i][j] == 2048) {
                return true;
            }
        }
    }
    return false;
}



/** Détermine si une grille est finie
 * @param un plateau plateau
 * @return un booleen vrai si la grille est pleine et faux sinon
**/



bool estTermine (Plateau plateau){
    if (estGagnant(plateau) == true ){
        return true;
    } else if ((deplacementGauche(plateau) == plateau) and (deplacementDroite(plateau) == plateau) and (deplacementHaut(plateau) == plateau) and (deplacementBas(plateau) == plateau)){
        return true;
    }
    return false;
}

/** Déplace les tuiles vers le haut sans les additionner
 * @param un plateau plateau
 * @return un plateau après avoir deplacé les tuiles
**/

Plateau suppression0Haut(Plateau plateau){
    for (int i = 0; i<plateau.size(); i++){
        for (int j=1; j<plateau[i].size(); j++){
        int k = j;
            while (k!=0 and plateau[k-1][i] == 0){
                plateau[k-1][i] = plateau[k][i];
                plateau[k][i] = 0;
                k--;
            }
        }
    }
    return plateau;
}

/** Déplace les tuiles vers le bas sans les additionner
 * @param un plateau plateau
 * @return un plateau après avoir deplacé les tuiles
**/

Plateau suppression0Bas(Plateau plateau){
    for (int i = 0; i<plateau.size(); i++){
        for (int j=plateau.size()-2; j>=0; j--){
        int k = j;
            while (k!=3 and plateau[k+1][i] == 0){
                plateau[k+1][i] = plateau[k][i];
                plateau[k][i] = 0;
                k++;
            }
        }
    }
    return plateau;
}

/** Déplace les tuiles vers la gauche sans les additionner
 * @param un plateau plateau
 * @return un plateau après avoir deplacé les tuiles
**/

Plateau suppression0Gauche(Plateau plateau){
    for (int i = 0; i<plateau.size(); i++){
        for (int j=1; j<plateau[i].size(); j++){
        int k = j;
            while (plateau[i][k-1] == 0 and k!=0){
                plateau[i][k-1] = plateau[i][k];
                plateau[i][k] = 0;
                k--;
            }
        }
    }
    return plateau;
}

/** Déplace les tuiles vers la droite sans les additionner
 * @param un plateau plateau
 * @return un plateau après avoir deplacé les tuiles
**/

Plateau suppression0Droite(Plateau plateau){
    for (int i = 0; i<plateau.size(); i++){
        for (int j=plateau.size()-2; j>=0; j--){
        int k = j;
            while (plateau[i][k+1] == 0 and k!= 3){
                plateau[i][k+1] = plateau[i][k];
                plateau[i][k] = 0;
                k++;
            }
        }
    }
    return plateau;
}

/** Additionne les tuiles vers le haut
 * @param un plateau plateau
 * @return le plateau après les additions
**/

Plateau additionHaut(Plateau plateau){
    for (int i = 0; i<plateau.size(); i++){
        if (plateau[0][i] == plateau[1][i]){
            plateau[0][i] = 2*plateau[0][i];
            plateau[1][i] = 0;
            if (plateau[2][i] == plateau[3][i]){
                plateau[2][i] = 2*plateau[2][i];
                plateau[3][i] = 0;
            }
        } else if (plateau[1][i] == plateau[2][i]){
            plateau[2][i] = 2*plateau[2][i];
            plateau[1][i] = 0;
        } else if (plateau[2][i] == plateau[3][i]){
            plateau[2][i] = 2*plateau[2][i];
            plateau[3][i] = 0;
        }
    }
    return plateau;
}

/** Additionne les tuiles vers le bas
 * @param un plateau plateau
 * @return le plateau après les additions
**/

Plateau additionBas(Plateau plateau){
    for (int i = 0; i<plateau.size(); i++){
        if (plateau[3][i] == plateau[2][i]){
            plateau[3][i] = 2*plateau[3][i];
            plateau[2][i] = 0;
            if (plateau[1][i] == plateau[0][i]){
                plateau[1][i] = 2*plateau[1][i];
                plateau[0][i] = 0;
            }
        } else if (plateau[2][i] == plateau[1][i]){
            plateau[1][i] = 2*plateau[1][i];
            plateau[2][i] = 0;
        } else if (plateau[1][i] == plateau[0][i]){
            plateau[1][i] = 2*plateau[1][i];
            plateau[0][i] = 0;
        }
    }
    return plateau;
}

/** Additionne les tuiles vers la gauche
 * @param un plateau plateau
 * @return le plateau après les additions
**/

Plateau additionGauche(Plateau plateau){
    for (int i = 0; i<plateau.size(); i++){
        if (plateau[i][0] == plateau[i][1]){
            plateau[i][0] = 2*plateau[i][0];
            plateau[i][1] = 0;
            if (plateau[i][2] == plateau[i][3]){
                plateau[i][2] = 2*plateau[i][2];
                plateau[i][3] = 0;
            }
        } else if (plateau[i][1] == plateau[i][2]){
            plateau[i][1] = 2*plateau[i][1];
            plateau[i][2] = 0;
        } else if (plateau[i][2] == plateau[i][3]){
            plateau[i][2] = 2*plateau[i][2];
            plateau[i][3] = 0;
        }
    }
    return plateau;
}

/** Additionne les tuiles vers la droite
 * @param un plateau plateau
 * @return le plateau après les additions
**/

Plateau additionDroite(Plateau plateau){
    for (int i = 0; i<plateau.size(); i++){
        if (plateau[i][3] == plateau[i][2]){
            plateau[i][3] = 2*plateau[i][3];
            plateau[i][2] = 0;
            if (plateau[i][1] == plateau[i][0]){
                plateau[i][1] = 2*plateau[i][1];
                plateau[i][0] = 0;
            }
        } else if (plateau[i][2] == plateau[i][1]){
            plateau[i][1] = 2*plateau[i][1];
            plateau[i][2] = 0;
        } else if (plateau[i][1] == plateau[i][0]){
            plateau[i][1] = 2*plateau[i][1];
            plateau[i][0] = 0;
        }
    }
    return plateau;
}

/** Déplace les tuiles vers le haut et fusionne les tuiles selon les règles
 * @param un plateau plateau
 * @return le nouveau plateau après les déplacements
**/

Plateau deplacementHaut(Plateau plateau){
    plateau = suppression0Haut(plateau);
    plateau = additionHaut(plateau);
    plateau = suppression0Haut(plateau);
    return plateau;
}

/** Déplace les tuiles vers le bas et fusionne les tuiles selon les règles
 * @param un plateau plateau
 * @return le nouveau plateau après les déplacements
**/

Plateau deplacementBas(Plateau plateau){
    plateau = suppression0Bas(plateau);
    plateau = additionBas(plateau);
    plateau = suppression0Bas(plateau);
    return plateau;
}

/** Déplace les tuiles vers la gauche et fusionne les tuiles selon les règles
 * @param un plateau plateau
 * @return le nouveau plateau après les déplacements
**/

Plateau deplacementGauche(Plateau plateau){
    plateau = suppression0Gauche(plateau);
    plateau = additionGauche(plateau);
    plateau = suppression0Gauche(plateau);
    return plateau;
}

/** Déplace les tuiles vers la droite et fusionne les tuiles selon les règles
 * @param un plateau plateau
 * @return le nouveau plateau après les déplacements
**/

Plateau deplacementDroite(Plateau plateau){
    plateau = suppression0Droite(plateau);
    plateau = additionDroite(plateau);
    plateau = suppression0Droite(plateau);
    return plateau;
}

/** Demande une touche au joueur et exécute le déplacement correspondant
 * @param une grille plateau
 * @param un int direction
 * @return le nouveau plateau après les déplacements
**/

Plateau deplacement(Plateau plateau, int direction){
    if (direction == GAUCHE){
        return deplacementGauche(plateau);
    } else if ( direction == HAUT){
        return deplacementHaut(plateau);
    } else if (direction == BAS){
        return deplacementBas(plateau);
    } else if (direction == DROITE){
        return deplacementDroite(plateau);
    }
}

/** Ajoute une nouvelle case initialisée à 2 ou 4 selon les probabilités du 2048
 * @param un plateau t
 * @return le plateau t avec une nouvelle case
**/

Plateau creationCase (Plateau t){
    int abscisse = rand() % 4;
    int ordonnee = rand() % 4;
    while (t[abscisse][ordonnee] != 0){
        abscisse = rand() % 4;
        ordonnee = rand() % 4;
    }
    t[abscisse][ordonnee] = valeurCase();
    return t;
}


void test(){
    srand(time(NULL));
    int compteur = 0;
    for (int test = 0; test < 120; test++){
        Plateau t = plateauInitial();
        cout << dessine(t);
        int somme = 0;
        for (int test2 = 0; test2 < t.size(); test2++){
            for (int test3 = 0; test3 < t[test2].size(); test3++){
                somme = somme +t[test2][test3];
            }
        }
        if ( not(somme == 2) and not(somme == 4) and not(somme==6) and not (somme == 8)){
            compteur++;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    cout << compteur << endl;
}




