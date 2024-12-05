#include "Simulation.h"

Simulation::Simulation() : max_iterations(0) {}

void Simulation::lancer() {
    // Charger la grille
    grille.implementation_valeurs();
    if (grille.getMatrice().empty()) {
        std::cerr << "Erreur : La matrice est vide !" << std::endl;
        return;
    }

    // Menu principal
    std::cout << "Choisissez l'interface :\n";
    std::cout << "1. Interface console\n";
    std::cout << "2. Interface graphique\n";
    std::cout << "Votre choix : ";
    int choix;
    std::cin >> choix;

    std::cout << "Entrez le nombre d'iterations : ";
    std::cin >> max_iterations;

    if (choix == 1) {
        interfaceConsole();
    } else if (choix == 2) {
        interfaceGraphique();
    } else {
        std::cerr << "Erreur : Choix invalide !" << std::endl;
    }
}

void Simulation::interfaceConsole() {
    for (int iteration = 0; iteration < max_iterations; ++iteration) {
        grille.affiche_grille();  // Affiche la grille
        Cellule cellule;
        auto nouvelleMatrice = cellule.Cellule_changement_etat(grille.getMatrice());
        grille.setMatrice(nouvelleMatrice);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));  // Pause d'une seconde
    }
}

void Simulation::interfaceGraphique() {
    int lignes = grille.getMatrice().size();
    int colonnes = grille.getMatrice()[0].size();
    int taille_case = 50;  // Taille de chaque case
    sf::RenderWindow window(sf::VideoMode(colonnes * taille_case, lignes * taille_case), "Simulation de la grille");

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
        std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause entre les itérations
        iteration++;
    }
}
