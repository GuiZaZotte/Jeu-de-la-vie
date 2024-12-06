
#include "Cellule.h"
#include <iostream>

using namespace std;

vector<vector<int>> Cellule::Cellule_changement_etat(const vector<vector<int>>& matrice) {
    int compteur = 0;
    vector<vector<int>> temp = matrice;  // Copie de la matrice pour ne pas modifier l'état pendant les itérations

    for (size_t i = 0; i < matrice.size(); i++) {  // Utilisation de size_t
        for (size_t j = 0; j < matrice[i].size(); j++) {  // Utilisation de size_t
            compteur = 0;

            // Vérifie les cellules adjacentes avec gestion torique
            // Ligne suivante (en bas) : Si i est au bas de la grille, on revient au haut
            if (matrice[(i + 1) % matrice.size()][j] == 1) compteur++;  // Torique : (i + 1) % matrice.size() revient au début si i est à la fin

            // Ligne précédente (en haut) : Si i est au début, on revient en bas
            if (matrice[(i - 1 + matrice.size()) % matrice.size()][j] == 1) compteur++;  // Torique : (i - 1 + matrice.size()) % matrice.size() revient en bas si i est au début

            // Colonne suivante (à droite) : Si j est au bord droit, on revient au bord gauche
            if (matrice[i][(j + 1) % matrice[i].size()] == 1) compteur++;  // Torique : (j + 1) % matrice[i].size() revient au début si j est à la fin

            // Colonne précédente (à gauche) : Si j est au début, on revient à droite
            if (matrice[i][(j - 1 + matrice[i].size()) % matrice[i].size()] == 1) compteur++;  // Torique : (j - 1 + matrice[i].size()) % matrice[i].size() revient à droite si j est au début

            // Diagonales
            if (matrice[(i + 1) % matrice.size()][(j - 1 + matrice[i].size()) % matrice[i].size()] == 1) compteur++;  // Diagonale bas-gauche
            if (matrice[(i + 1) % matrice.size()][(j + 1) % matrice[i].size()] == 1) compteur++;  // Diagonale bas-droite
            if (matrice[(i - 1 + matrice.size()) % matrice.size()][(j - 1 + matrice[i].size()) % matrice[i].size()] == 1) compteur++;  // Diagonale haut-gauche
            if (matrice[(i - 1 + matrice.size()) % matrice.size()][(j + 1) % matrice[i].size()] == 1) compteur++;  // Diagonale haut-droite

            // Règles de changement d'état
            if (matrice[i][j] == 0) {
                if (compteur == 3) {  // Cellule morte devient vivante si elle a exactement 3 voisins vivants
                    temp[i][j] = 1;
                }
            } else {
                if (compteur < 2 || compteur > 3) {  // Cellule vivante meurt si elle a moins de 2 ou plus de 3 voisins vivants
                    temp[i][j] = 0;
                }
            }
        }
    }

    return temp;  // Retourne la nouvelle matrice mise à jour
}