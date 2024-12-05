#ifndef GRILLE_H
#define GRILLE_H

#include <vector>
using namespace std;

class Grille {
private:
    vector<vector<int>> matrice; // Matrice de la grille

public:
    // Constructeurs
    Grille(); 
    Grille(vector<vector<int>> matrice); 

    // Accesseurs
    vector<vector<int>> getMatrice() const; // Ajout de `const` ici pour correspondre à l'implémentation
    void setMatrice(const vector<vector<int>>& nouvelle_matrice); // Met à jour la matrice avec une nouvelle

    // Méthodes principales
    void implementation_valeurs(); // Remplit la matrice avec les valeurs d'un fichier
    void affiche_grille() const;         // Affiche la matrice
};

#endif
