#include "Simulation.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

Simulation::Simulation() {
    max_iterations = 0;
} 

void Simulation::lancer() {
    // Charger la grille
    grille.implementation_valeurs();
    if (grille.getMatrice().empty()) {
        cerr << "Erreur : La matrice est vide !" << endl;
        return;
    }

    // Menu principal
    cout << "Choisissez l'interface :\n";
    cout << "1. Interface console\n";
    cout << "2. Interface graphique\n";
    cout << "Votre choix : ";
    int choix;
    cin >> choix;

    cout << "Entrez le nombre d'iterations : ";
    cin >> max_iterations;

    if (choix == 1) {
        interfaceConsole();
    } else if (choix == 2) {
        interfaceGraphique();
    } else {
        cerr << "Erreur : Choix invalide !" << endl;
    }
}

void Simulation::interfaceConsole() {
    for (int iteration = 0; iteration < max_iterations; ++iteration) {
        grille.affiche_grille();  // Affiche la grille
        Cellule cellule;
        auto nouvelleMatrice = cellule.Cellule_changement_etat(grille.getMatrice());
        grille.setMatrice(nouvelleMatrice);
        this_thread::sleep_for(chrono::milliseconds(1000));  // Pause d'une seconde
    }
}

void Simulation::interfaceGraphique() {
    int temps;
    cout << "Entrez le temps entre deux itérations en millisecondes (idéal : 200) : ";
    cin >> temps;
    
    int lignes = grille.getMatrice().size();
    int colonnes = grille.getMatrice()[0].size();
    int taille_case = 50;  // Taille de chaque case (ajustez pour rendre plus petit ou grand)
    
    // Limiter la taille de la fenêtre
    int max_largeur = 800; // Largeur maximale de la fenêtre
    int max_hauteur = 600; // Hauteur maximale de la fenêtre
    
    // Calculer la taille de la fenêtre en fonction de la grille
    int largeur_fenetre = min(colonnes * taille_case, max_largeur);
    int hauteur_fenetre = min(lignes * taille_case, max_hauteur);

    // Créer la fenêtre avec la taille ajustée
    sf::RenderWindow window(sf::VideoMode(largeur_fenetre, hauteur_fenetre), "Simulation de la grille", sf::Style::Resize);
    
    sf::Color couleur_vivante = sf::Color::White;
    sf::Color couleur_morte = sf::Color::Black;

    int iteration = 0;
    while (window.isOpen() && iteration < max_iterations) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Mettre à jour la grille
        Cellule cellule;
        auto nouvelleMatrice = cellule.Cellule_changement_etat(grille.getMatrice());
        grille.setMatrice(nouvelleMatrice);

        // Affichage
        window.clear();
        for (int i = 0; i < lignes; ++i) {
            for (int j = 0; j < colonnes; ++j) {
                sf::RectangleShape case_rect(sf::Vector2f(taille_case - 1, taille_case - 1));
                case_rect.setPosition(j * taille_case, i * taille_case);
                case_rect.setFillColor(grille.getMatrice()[i][j] == 1 ? couleur_vivante : couleur_morte);
                window.draw(case_rect);
            }
        }
        window.display();
        this_thread::sleep_for(chrono::milliseconds(temps));  // Pause entre les itérations
        iteration++;
    }
}
