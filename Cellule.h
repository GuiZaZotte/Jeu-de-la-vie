#ifndef CELLULE_H
#define CELLULE_H

#include <vector>
#include "Grille.h" 

using namespace std;

class Cellule {
public:
    vector<vector<int>> Cellule_changement_etat(const vector<vector<int>>& matrice);
};

#endif
