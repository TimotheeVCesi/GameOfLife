#include "headers.h"

void config(std::string& fileName, std::string& mode, std::string& gridType, int& generations, int& sleepTime) {
    std::cout << "Entrez le chemin d'accès au fichier d'entrée (/dossier/dossier/fichier.txt) :" << std::endl;
    std::cin >> fileName;

    std::cout << "Entrez le mode de fonctionnement ('console' ou 'graphique') :" << std::endl;
    std::cin >> mode;

    std::cout << "Entrez le type de grille ('classique' ou 'torique') :" << std::endl;
    std::cin >> gridType;

    std::cout << "Entrez le nombre de générations maximum (entier non nul et non signé) :" << std::endl;
    std::cin >> generations;

    std::cout << "Entrez le temps de pause entre deux générations (entier non nul et non signé) :" << std::endl;
    std::cin >> sleepTime;
}

int main() {
    std::string fileName, mode, gridType;
    int generations, sleepTime;

    config(fileName, mode, gridType, generations, sleepTime);

    GameOfLife simulation(fileName, mode, gridType, generations, sleepTime);

    simulation.start();

    return 0;
}