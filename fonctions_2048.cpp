#include "2048.h"



/** Construit un tableau 2D 4x4 d'entiers dont les valeurs sont initialisées à 0
 * @return le tableau 2D 4x4 d'entiers
**/

Plateau plateauVide() {
    Plateau t = Plateau(4);             //Allocation
    for (int i = 0; i<t.size(); i++){
        t[i] = vector<int>(4,0);        //Allocation et initialisation
    }
    return t;
}



/** renvoie au hasard 2 ou 4
 * @return l'entier n contenant au hasard 2 ou 4
**/

int valeurCase () {
    int i = rand() % 10;                //prends un entier aléatoire entre 1 et 10
    if (i == 0){
        return 4;                       //renvoie 4 une fois sur dix
    }else{
        return 2;                       //renvoie 2 neuf fois sur dix
    }
}



/** Construit un tableau 2D 4x4 d'entiers dont les valeurs sont initialisées à 0 sauf une ou deux cases à 2 ou 4
 * @return le tableau 2D 4x4 d'entiers
**/

Plateau plateauInitial() {
    Plateau t = plateauVide();
    int abscisseInitiale1 = rand() % 4; //définit une abscisse initiale pour la première case entre 0 et 3
    int ordonneeInitiale1 = rand() % 4; //définit une ordonnée initiale pour la première case entre 0 et 3
    int abscisseInitiale2 = rand() % 4;
    int ordonneeInitiale2 = rand() % 4;
    int nombreDeCasesInitialisees = valeurCase();
    t[abscisseInitiale1][ordonneeInitiale1] = valeurCase(); //Assigne une valeur entre 2 et 4 à la case d'abscisse abscisseInitiale1 et d'ordonnee ordonneeInitiale1
    return t;
}



/** dessine le tableau dans le terminal
 * @param un tableau 2D 4x4 g
 * @return une chaine de caractères représentant la grille et les nombres dans les cases
**/

string dessine(Plateau g) {
    vector<vector<string>> t(4);            //crée un tableau 2D de string
    for (int i = 0; i<t.size(); i++){
        t[i] = vector<string>(4);           //Allocation
        for (int j = 0; j<t[i].size(); j++){
            if (g[i][j] == 0){
                t[i][j] = " ";
            } else {
                t[i][j] = to_string(g[i][j]);   //convertit le tableau d'entiers en tableau de strings
            }   //convertit le tableau d'entiers en tableau de strings
            int k = 0;
            while (t[i][j].size() < 5){     //Donne une taille de 5 à chaque case de t en rajoutant des espaces a droite et a gauche
                k = k+1;
                if ( k%2 == 1 ){
                    t[i][j] = t[i][j] + " ";
                } else {
                    t[i][j] = " " + t[i][j];
                }

            }
        }
    }
    string grille = "*************************\n*" + t[0][0] + "*" + t[0][1] + "*" + t[0][2] + "*" + t[0][3] +"*\n*************************\n*" + t[1][0] + "*" + t[1][1] + "*" + t[1][2] + "*" + t[1][3] +"*\n*************************\n*" + t[2][0] + "*" + t[2][1] + "*" + t[2][2] + "*" + t[2][3] +"*\n*************************\n*" + t[3][0] + "*" + t[3][1] + "*" + t[3][2] + "*" + t[3][3] +"*\n*************************\n";  //Cree une chaine de caractere formant la grille ainsi que les cases avec la bonne mise en forme
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

bool estTermine (jeu game){
    jeu game1 = game;
    jeu game2 = game;
    jeu game3 = game;
    jeu game4 = game;
    if (estGagnant(game.p) == true ){   //vérifie si la grille est gagnante
        return true;
    } else {
        game1 = deplacementBas(game);
        game2 = deplacementDroite(game);
        game3 = deplacementGauche(game);
        game4 = deplacementGauche(game);
        if ((game1.p == game.p) and (game2.p == game.p) and (game3.p == game.p) and (game4.p == game.p)){   //vérifie si plus aucun déplacement n'est possible
            return true;
    }
    return false;
}
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

jeu additionHaut(jeu game){
    Plateau plateau = game.p;
    for (int i = 0; i<plateau.size(); i++){
        if (plateau[0][i] == plateau[1][i]){
            game.s = game.s+2*plateau[0][i];    //rajoute la valeur de la case additionnée au score
            plateau[0][i] = 2*plateau[0][i];
            plateau[1][i] = 0;
            if (plateau[2][i] == plateau[3][i]){
                game.s = game.s+2*plateau[2][i];    //rajoute la valeur de la case additionnée au score
                plateau[2][i] = 2*plateau[2][i];
                plateau[3][i] = 0;
            }
        } else if (plateau[1][i] == plateau[2][i]){
            game.s = game.s+2*plateau[1][i];    //rajoute la valeur de la case additionnée au score
            plateau[1][i] = 2*plateau[1][i];
            plateau[2][i] = 0;
        } else if (plateau[2][i] == plateau[3][i]){
            game.s = game.s+2*plateau[2][i];    //rajoute la valeur de la case additionnée au score
            plateau[2][i] = 2*plateau[2][i];
            plateau[3][i] = 0;
        }
    }
    game.p = plateau;
    return game;
}



/** Additionne les tuiles vers le bas
 * @param un plateau plateau
 * @return le plateau après les additions
**/

jeu additionBas(jeu game){
    Plateau plateau = game.p;
    for (int i = 0; i<plateau.size(); i++){
        if (plateau[3][i] == plateau[2][i]){
            game.s = game.s+2*plateau[3][i];    //rajoute la valeur de la case additionnée au score
            plateau[3][i] = 2*plateau[3][i];
            plateau[2][i] = 0;
            if (plateau[1][i] == plateau[0][i]){
                game.s = game.s+2*plateau[1][i];    //rajoute la valeur de la case additionnée au score
                plateau[1][i] = 2*plateau[1][i];
                plateau[0][i] = 0;
            }
        } else if (plateau[2][i] == plateau[1][i]){
            game.s = game.s+2*plateau[2][i];    //rajoute la valeur de la case additionnée au score
            plateau[2][i] = 2*plateau[2][i];
            plateau[1][i] = 0;
        } else if (plateau[1][i] == plateau[0][i]){
            game.s = game.s+2*plateau[1][i];    //rajoute la valeur de la case additionnée au score
            plateau[1][i] = 2*plateau[1][i];
            plateau[0][i] = 0;
        }
}
    game.p = plateau;
    return game;
}



/** Additionne les tuiles vers la gauche
 * @param un plateau plateau
 * @return le plateau après les additions
**/

jeu additionGauche(jeu game){
    Plateau plateau = game.p;
    for (int i = 0; i<plateau.size(); i++){
        if (plateau[i][0] == plateau[i][1]){
            game.s = game.s+2*plateau[i][0];    //rajoute la valeur de la case additionnée au score
            plateau[i][0] = 2*plateau[i][0];
            plateau[i][1] = 0;
            if (plateau[i][2] == plateau[i][3]){
                game.s = game.s+2*plateau[i][2];    //rajoute la valeur de la case additionnée au score
                plateau[i][2] = 2*plateau[i][2];
                plateau[i][3] = 0;
            }
        } else if (plateau[i][1] == plateau[i][2]){
            game.s = game.s+2*plateau[i][2];    //rajoute la valeur de la case additionnée au score
            plateau[i][1] = 2*plateau[i][1];
            plateau[i][2] = 0;
        } else if (plateau[i][2] == plateau[i][3]){
            game.s = game.s+2*plateau[i][2];    //rajoute la valeur de la case additionnée au score
            plateau[i][2] = 2*plateau[i][2];
            plateau[i][3] = 0;
        }
    }
    game.p = plateau;
    return game;
}



/** Additionne les tuiles vers la droite
 * @param un plateau plateau
 * @return le plateau après les additions
**/

jeu additionDroite(jeu game){
    Plateau plateau = game.p;
    for (int i = 0; i<plateau.size(); i++){
        if (plateau[i][3] == plateau[i][2]){
            game.s = game.s+2*plateau[i][3];    //rajoute la valeur de la case additionnée au score
            plateau[i][3] = 2*plateau[i][3];
            plateau[i][2] = 0;
            if (plateau[i][1] == plateau[i][0]){
                game.s = game.s+2*plateau[i][1];    //rajoute la valeur de la case additionnée au score
                plateau[i][1] = 2*plateau[i][1];
                plateau[i][0] = 0;
            }
        } else if (plateau[i][2] == plateau[i][1]){
            game.s = game.s+2*plateau[i][2];    //rajoute la valeur de la case additionnée au score
            plateau[i][2] = 2*plateau[i][2];
            plateau[i][1] = 0;
        } else if (plateau[i][1] == plateau[i][0]){
            game.s = game.s+2*plateau[i][1];    //rajoute la valeur de la case additionnée au score
            plateau[i][1] = 2*plateau[i][1];
            plateau[i][0] = 0;
        }
}
    game.p = plateau;
    return game;
}



/** Déplace les tuiles vers le haut et fusionne les tuiles selon les règles
 * @param un plateau plateau
 * @return le nouveau plateau après les déplacements
**/

jeu deplacementHaut(jeu game){
    game.p = suppression0Haut(game.p);
    game = additionHaut(game);
    game.p = suppression0Haut(game.p);
    return game;
}



/** Déplace les tuiles vers le bas et fusionne les tuiles selon les règles
 * @param un plateau plateau
 * @return le nouveau plateau après les déplacements
**/

jeu deplacementBas(jeu game){
    game.p = suppression0Bas(game.p);
    game = additionBas(game);
    game.p = suppression0Bas(game.p);
    return game;
}



/** Déplace les tuiles vers la gauche et fusionne les tuiles selon les règles
 * @param un plateau plateau
 * @return le nouveau plateau après les déplacements
**/

jeu deplacementGauche(jeu game){
    game.p = suppression0Gauche(game.p);
    game = additionGauche(game);
    game.p = suppression0Gauche(game.p);
    return game;
}



/** Déplace les tuiles vers la droite et fusionne les tuiles selon les règles
 * @param un plateau plateau
 * @return le nouveau plateau après les déplacements
**/

jeu deplacementDroite(jeu game){
    game.p = suppression0Droite(game.p);
    game = additionDroite(game);
    game.p = suppression0Droite(game.p);
    return game;
}



/** Demande une touche au joueur et exécute le déplacement correspondant
 * @param une grille plateau
 * @param un int direction
 * @return le nouveau plateau après les déplacements
**/

jeu deplacement(jeu game, int direction){
    if (direction == GAUCHE){
        return deplacementGauche(game);
    } else if ( direction == HAUT){
        return deplacementHaut(game);
    } else if (direction == BAS){
        return deplacementBas(game);
    } else if (direction == DROITE){
        return deplacementDroite(game);
    }
}



/** Ajoute une nouvelle case initialisée à 2 ou 4 selon les probabilités du 2048
 * @param un plateau t
 * @return le plateau t avec une nouvelle case
**/

Plateau creationCase (Plateau t){
    int abscisse = rand() % 4;  //donne une valeur a abscisse entre 0 et 3
    int ordonnee = rand() % 4;
    while (t[abscisse][ordonnee] != 0){     //réitère l'opération tant que la case donnée n'est pas vide
        abscisse = rand() % 4;
        ordonnee = rand() % 4;
    }
    t[abscisse][ordonnee] = valeurCase();
    return t;
}
