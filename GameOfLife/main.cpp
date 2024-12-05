#include "headers.h"

int main() {
    FileHandler fileHandler;

    std::string filePath;
    std::cout << "Entrez le chemin d'accès au fichier d'entrée :" << std::endl;
    std::cin >> filePath;

    IGrid* grid = fileHandler.load(filePath);

    // sf::RenderWindow window(sf::VideoMode(gridWidth * cellSize, gridHeight * cellSize), "Game of Life");
    sf::RenderWindow window(sf::VideoMode(800, 800), "Game of Life");
    ViewGraphic view(window, 10);

    GameOfLife game(grid, &view);
    game.run(100, 100);

    delete grid;
    return 0;
}