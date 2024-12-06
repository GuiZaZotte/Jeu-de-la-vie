#ifndef VUE_H
#define VUE_H

#include <SFML/Graphics.hpp>
#include "Grille.h"

class Vue {
public:
    void afficheGrilleConsole(const Grille& grille, int iteration);
    void afficheGrilleGraphique(Grille& grille, int iterationsMax, int tempsEntreIterations);
};

#endif
