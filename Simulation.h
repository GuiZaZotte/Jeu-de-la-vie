#ifndef SIMULATION_H
#define SIMULATION_H

#include "Grille.h"
#include "Vue.h"

class Simulation {
private:
    Grille grille;
    Vue vue;
    int max_iterations;

    void interfaceConsole();
    void interfaceGraphique();

public:
    Simulation();
    void lancer();
};

#endif
