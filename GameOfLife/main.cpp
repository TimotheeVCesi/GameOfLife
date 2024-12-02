#include "headers.h"

void config(std::string& fileName, std::string& mode, std::string& grid, int& generations, int& sleepTime) {
    std::cout << "Entrez le chemin d'accès au fichier d'entrée (/dossier/dossier/fichier.txt) :" << std::endl;
    std::cin >> fileName;

    std::cout << "Entrez le mode de fonctionnement ('console' ou 'graphique') :" << std::endl;
    std::cin >> mode;

    std::cout << "Entrez le type de grille ('classique' ou 'torique') :" << std::endl;
    std::cin >> grid;

    std::cout << "Entrez le nombre de générations maximum (entier non nul et non signé) :" << std::endl;
    std::cin >> generations;

    std::cout << "Entrez le temps de pause entre deux générations (entier non nul et non signé) :" << std::endl;
    std::cin >> sleepTime;
}

void inputFile(std::string fileName, int& rows, int& columns) {
    std::ifstream file(fileName);
    if (!file) {
        std::cerr << "Erreur: impossible d'ouvrir le fichier " << fileName << std::endl;
    }

    file >> rows >> columns;
    file.close();
}

int main() {
    std::string fileName, mode, grid;
    int generations, sleepTime, rows, columns;

    config(fileName, mode, grid, generations, sleepTime);
    inputFile(fileName, rows, columns);

    GameOfLife simulation;

    simulation.start(generations);

    return 0;
}