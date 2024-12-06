
// Implementation des bibliothèques :

#include "Grille.h" // permet d'inclure le fichier d'en tête pour définir les méthodes de la classe.
#include <fstream> // permet de lire un fichier et dans notre cas de transformer les données en matrice.
#include <sstream> // permet de diviser la ligne du fichier en élément pour dans notre cas transformer les données en matrice.
#include <iostream> // permet d'afficher du texte dans la console.

using namespace std; // permet d'éviter de réécrite std à chaque utilisation de la bibliothèque standard dans notre cas.


// Constructeurs :

Grille::Grille(){ // permet creer une instance avec une matrice par défaut 
    matrice = {};  // initialise une matrice vide
}

Grille::Grille(vector<vector<int>> matrice) { // permet de creer une instance avec une matrice personnalisé.
    this->matrice = matrice;  // permet de remplacer la matrice par défaut par la nouvelle matrice, utilisation de this pour différencier les deux matrices.
}


// Méthodes principales : 


void Grille::implementation_valeurs() {
    cout << "Entrez le nom de votre fichier d'entrée avec l'extension : ";
    cin >> fichier_source;  // Stocke le nom du fichier dans l'attribut fichier_source

    ifstream fichier(fichier_source);
    if (!fichier) {
        cerr << "Erreur : Impossible d'ouvrir le fichier " << fichier_source << endl;
        return;
    }

    int lignes, colonnes;
    fichier >> lignes >> colonnes;

    matrice.resize(lignes, vector<int>(colonnes));

    for (int i = 0; i < lignes; ++i) {
        for (int j = 0; j < colonnes; ++j) {
            fichier >> matrice[i][j];
        }
    }

    fichier.close();
}

string Grille::getFichierSource() const {
    return fichier_source;  // Retourne le nom du fichier source
}

// Méthode pour afficher la grille
void Grille::affiche_grille() const {
    for (const auto& ligne : matrice) {
        for (int cell : ligne) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

// Accesseurs
vector<vector<int>> Grille::getMatrice() const {
    return matrice;
}

void Grille::setMatrice(const vector<vector<int>>& nouvelle_matrice) {
    matrice = nouvelle_matrice;
}