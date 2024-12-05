#ifndef SIMULATION_H
#define SIMULATION_H

#include "Grille.h"
#include "Cellule.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <chrono>

class Simulation {
private:
    Grille grille;
    int max_iterations;

    // Méthodes privées pour gérer les interfaces
    void interfaceConsole();
    void interfaceGraphique();

public:
    Simulation();
    void lancer();
};

#endif
