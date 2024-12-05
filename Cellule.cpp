#include "Cellule.h"
#include <iostream>

using namespace std;

vector<vector<int>> Cellule::Cellule_changement_etat(const vector<vector<int>>& matrice) {
    int compteur = 0;
    vector<vector<int>> temp = matrice;

    for (size_t i = 0; i < matrice.size(); i++) {  // Utilisation de size_t
        for (size_t j = 0; j < matrice[i].size(); j++) {  // Utilisation de size_t
            compteur = 0;

            // Vérifie les cellules adjacentes
            if (i + 1 < matrice.size() && matrice[i + 1][j] == 1) compteur++;
            if (i > 0 && matrice[i - 1][j] == 1) compteur++;  // Vérification que i > 0 avant de soustraire
            if (j + 1 < matrice[0].size() && matrice[i][j + 1] == 1) compteur++;
            if (j > 0 && matrice[i][j - 1] == 1) compteur++;  // Vérification que j > 0 avant de soustraire
            if (i + 1 < matrice.size() && j > 0 && matrice[i + 1][j - 1] == 1) compteur++;  // i + 1 < matrice.size() et j > 0
            if (i + 1 < matrice.size() && j + 1 < matrice[0].size() && matrice[i + 1][j + 1] == 1) compteur++;
            if (i > 0 && j > 0 && matrice[i - 1][j - 1] == 1) compteur++;  // i > 0 et j > 0
            if (i > 0 && j + 1 < matrice[0].size() && matrice[i - 1][j + 1] == 1) compteur++;  // i > 0 et j + 1 < matrice[0].size()

            // Règles de changement d'état
            if (matrice[i][j] == 0) {
                if (compteur >= 3) {
                    temp[i][j] = 1;
                }
            } else {
                if (compteur < 2 || compteur > 3) {
                    temp[i][j] = 0;
                }
            }
        }
    }

    return temp;
}
