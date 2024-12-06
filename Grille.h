#ifndef GRILLE_H
#define GRILLE_H

// Implementation des bibliothèques :
#include <vector> // permet d'utilser le conteneur vector dans notre cas.
using namespace std; // permet d'éviter de réécrite std à chaque utilisation de la bibliothèque standard dans notre cas.

class Grille {
private:
    vector<vector<int>> matrice; // permet de déclarer la matrice sous forme de vecteur de vecteurs d'entiers
public:
    // Constructeurs : 
    Grille(); // permer de creer une instance avec une matrice par défaut.
    Grille(vector<vector<int>> matrice); // permet de creer une instance avec une matrice personnalisé.

    // Les deux accesseurs get,set : 
    vector<vector<int>> getMatrice() const; // permet de récupérer la matrice, utilisation de const pour pas la modifier.
    void setMatrice(const vector<vector<int>>& nouvelle_matrice); // permet de modifier la matrice avec la nouvelle matrice, elle prend en paramètre la nouvelle matrice vectorielle en référence pour éviter la duplication.

    // Les méthodes principales : 
    void implementation_valeurs(); // permet de remplir la matrice avec les valeurs du fichier txt.
    void affiche_grille() const;  // permet d'afficher la matrice dans la console.


    
};

#endif
