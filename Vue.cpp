#include "Vue.h"
#include "Grille.h"
#include "Cellule.h"
#include <iostream>
#include <thread>
#include <chrono>


using namespace std;

void Vue::afficheGrilleConsole(const Grille& grille, int iteration) {
    cout << "Iteration " << iteration << ":" << endl;
    grille.affiche_grille();
}

void Vue::afficheGrilleGraphique(Grille& grille, int iterationsMax, int tempsEntreIterations) {
    int lignes = grille.getMatrice().size();
    int colonnes = grille.getMatrice()[0].size();
    int taille_case = 10;

    sf::RenderWindow window(sf::VideoMode(colonnes * taille_case, lignes * taille_case), "Simulation de la grille");
    sf::Color couleur_vivante = sf::Color::White;
    sf::Color couleur_morte = sf::Color::Black;

    for (int iteration = 0; iteration < iterationsMax; ++iteration) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Mise à jour et affichage
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

        // Calcul de l'état suivant
        Cellule cellule;
        auto nouvelleMatrice = cellule.Cellule_changement_etat(grille.getMatrice());
        grille.setMatrice(nouvelleMatrice);

        this_thread::sleep_for(chrono::milliseconds(tempsEntreIterations));
    }
}
