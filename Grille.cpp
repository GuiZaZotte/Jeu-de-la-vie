
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


void Grille::implementation_valeurs() { // permet de remplir la matrice avec les valeurs du fichier txt.
    
    string nom_fichier;
    cout<<"Entrée le nom de votre fichier d'entrée avec l'extension : ";
    cin>>nom_fichier;
    // permet d'ouvrir le fichier, si cela ne marche alors la méthode renvoie une erreur
    ifstream fichier(nom_fichier);
    if (!fichier) {
        cerr << "Erreur fichier" << endl;
        return;
    }

    // permet de lire les deux premier éléments du fichier txt, qui indique les dimensions de la matrices.
    int lignes, colonnes;
    fichier >> lignes >> colonnes;

    // permet de redimensionner la matrice par défaut par les dimensions du fichier txt
    matrice.resize(lignes, vector<int>(colonnes));

    // permet de remplir la matrice par les valeurs du fichier
    for (int i = 0; i < lignes; ++i) {
        for (int j = 0; j < colonnes; ++j) {
            fichier >> matrice[i][j];
        }
    }

    // parmet de fermer le fichier car la matrice est remplie
    fichier.close();
}

// permet d'afficher la matrice dans la console.

void Grille::affiche_grille() const {
    // On parcourt chaque ligne de la matrice.
    for (std::vector<std::vector<int>>::size_type i = 0; i < matrice.size(); ++i) {
        // On parcourt chaque cellule dans la ligne i.
        for (std::vector<int>::size_type j = 0; j < matrice[i].size(); ++j) {
            // Si la cellule contient 1, on affiche "1", sinon "0".
            if (matrice[i][j] == 1) {
                std::cout << "1 ";
            } else {
                std::cout << "0 ";
            }
        }
        // Après avoir affiché toutes les cellules de la ligne, on passe à la ligne suivante.
        std::cout << std::endl;
    }
}



// Les accesseurs :

// permet de récupérer la matrice, utilisation de const pour pas la modifier.
vector<vector<int>> Grille::getMatrice() const {
    return matrice;
}

// permet de modifier la matrice avec la nouvelle matrice, elle prend en paramètre la nouvelle matrice vectorielle en référence pour éviter la duplication.
void Grille::setMatrice(const vector<vector<int>>& nouvelle_matrice) {
    matrice = nouvelle_matrice;
}


