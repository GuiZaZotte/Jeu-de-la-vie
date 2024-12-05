#include "Grille.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

Grille::Grille() : matrice({}) {}

Grille::Grille(vector<vector<int>> matrice) {
    this->matrice = matrice;
}

// Méthode pour lire les valeurs depuis un fichier
void Grille::implementation_valeurs() {
    // Ouverture du fichier
    ifstream fichier("test.txt");
    if (!fichier) {
        cerr << "Erreur fichier" << endl;
        return;
    }

    // Lire la première ligne pour obtenir les dimensions
    int lignes, colonnes;
    fichier >> lignes >> colonnes;

    // Redimensionner la matrice selon les dimensions
    matrice.resize(lignes, vector<int>(colonnes));

    // Lire les valeurs de la matrice
    for (int i = 0; i < lignes; ++i) {
        for (int j = 0; j < colonnes; ++j) {
            fichier >> matrice[i][j];
        }
    }

    fichier.close();
}

vector<vector<int>> Grille::getMatrice() const {
    return matrice;
}

void Grille::setMatrice(const vector<vector<int>>& nouvelle_matrice) {
    matrice = nouvelle_matrice;
}

void Grille::affiche_grille() const {
    for (const auto& ligne : matrice) {
        for (const auto& cellule : ligne) {
            std::cout << (cellule == 1 ? "1" : "0") << " ";
        }
        std::cout << std::endl;
    }
}
