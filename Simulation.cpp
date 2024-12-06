#include "Simulation.h"
#include "Cellule.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <chrono>
#include <thread>

using namespace std;

Simulation::Simulation() : max_iterations(0) {}

void Simulation::lancer() {
    grille.implementation_valeurs();
    if (grille.getMatrice().empty()) {
        cerr << "Erreur : La matrice est vide !" << endl;
        return;
    }

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

    // Récupérer le nom du fichier source
    string fichier_source = grille.getFichierSource();

    // Créer le dossier de sortie
    string dossier_sortie = fichier_source.substr(0, fichier_source.find('.')) + "_out";
    if (!filesystem::exists(dossier_sortie)) {
        filesystem::create_directory(dossier_sortie);
    }


    for (int iteration = 0; iteration < max_iterations; ++iteration) {
        vue.afficheGrilleConsole(grille, iteration);

        // Sauvegarde de l'état dans un fichier
        string nom_fichier_sortie = dossier_sortie + "/iteration_" + to_string(iteration + 1) + ".txt";
        ofstream fichier_sortie(nom_fichier_sortie);
        if (fichier_sortie) {
            for (const auto& ligne : grille.getMatrice()) {
                for (int valeur : ligne) {
                    fichier_sortie << valeur << " ";
                }
                fichier_sortie << endl;
            }
        }
        fichier_sortie.close();


        // Calcul de l'état suivant
        Cellule cellule;
        auto nouvelleMatrice = cellule.Cellule_changement_etat(grille.getMatrice());
        grille.setMatrice(nouvelleMatrice);

        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

void Simulation::interfaceGraphique() {
    int temps;
    cout << "Entrez le temps entre deux itérations en millisecondes : ";
    cin >> temps;

    vue.afficheGrilleGraphique(grille, max_iterations, temps);
}
