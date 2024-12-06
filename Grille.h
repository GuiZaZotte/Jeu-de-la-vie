#ifndef GRILLE_H
#define GRILLE_H

#include <vector>
#include <string>

using namespace std;

class Grille {
private:
    vector<vector<int>> matrice;  // Matrice principale
    string fichier_source;        // Nom du fichier source (nouvel attribut)

public:
    // Constructeurs
    Grille();
    Grille(vector<vector<int>> matrice);

    // Méthodes principales
    void implementation_valeurs();
    void affiche_grille() const;

    // Accesseurs
    vector<vector<int>> getMatrice() const;
    void setMatrice(const vector<vector<int>>& nouvelle_matrice);

    string getFichierSource() const;  // Nouveau : récupérer le nom du fichier source
};

#endif
