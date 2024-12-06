#include "headers.h"

void inputFile(std::string& filePath) {
    std::cout << "Entrez le chemin d'accès au fichier d'entrée :" << std::endl;
    std::cin >> filePath;
}

void configGridType(IGrid*& grid, int& gridType, int rows, int columns) {
    std::cout << "Entrez le type de la grille ('1' pour classique, '2' pour torique) :" << std::endl;
    std::cin >> gridType;

    switch (gridType) {
        case 1:
            grid = new GridClassic(rows, columns);
            break;
        case 2:
            grid = new GridToroidal(rows, columns);
            break;
        default:
            std::cerr << "Erreur: entrée inconnue (type de la grille). Grille classique utilisée par défaut." << std::endl;
            grid = new GridClassic(rows, columns);
            break;
    }
}

int main() {
    IFileHandler* fileHandler = new FileHandler();

    std::string filePath;
    inputFile(filePath);

    IGrid* initialGrid = fileHandler->load(filePath);

    int gridType;
    IGrid* grid = nullptr;
    configGridType(grid, gridType, initialGrid->getRows(), initialGrid->getColumns());

    int cellSize = 10;
    sf::RenderWindow window(sf::VideoMode(grid->getColumns() * cellSize, grid->getRows() * cellSize), "Game of Life");

    IView* view = new ViewGraphic(window, cellSize);

    int generations;
    std::cout << "Entrez le nombre de générations maximum :" << std::endl;
    std::cin >> generations;
    IIteration* iterations = new IterationClassic(generations);

    int sleepTime;
    std::cout << "Entrez le temps de pause entre deux itérations (en ms) :" << std::endl;
    std::cin >> sleepTime;

    GameOfLife game(grid, view, iterations);
    game.run(sleepTime);

    delete grid;
    delete view;
    delete fileHandler;

    return 0;
}
