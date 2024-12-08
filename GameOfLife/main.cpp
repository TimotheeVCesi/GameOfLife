#include "headers.h"

void inputFile(IFileHandler*& fileHandler) {
    std::string filePath;
    std::cout << "Entrez le chemin d'accès au fichier d'entrée :" << std::endl;
    std::cin >> filePath;
    fileHandler = new FileHandler(filePath);
}

void configGridType(IGrid*& grid, int rows, int columns) {
    int gridType;
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

void configViewType(IView*& view, int& viewType) {
    std::cout << "Entrez le type de vue ('1' pour console, '2' pour graphique) :" << std::endl;
    std::cin >> viewType;

    view = new ViewGraphic();
}

void configVar(IIteration*& iterations, int& sleepTime, int& viewType) {
    int generations;
    std::cout << "Entrez le nombre de générations maximum :" << std::endl;
    std::cin >> generations;
    iterations = new IterationClassic(generations);

    std::cout << "Entrez le temps de pause entre deux itérations (en ms) :" << std::endl;
    std::cin >> sleepTime;
}

int main() {
    IFileHandler* fileHandler = nullptr;
    inputFile(fileHandler);

    IGrid* initialGrid = fileHandler->load();
    
    IGrid* grid = nullptr;
    configGridType(grid, initialGrid->getRows(), initialGrid->getColumns());

    IView* view = nullptr;
    int viewType;
    configViewType(view, viewType);

    IIteration* iterations = nullptr;
    int sleepTime;
    configVar(iterations, sleepTime, viewType);

    GameOfLife game(fileHandler, grid, view, iterations, viewType);
    game.run(sleepTime);

    delete fileHandler;
    delete initialGrid;
    delete grid;
    delete view;
    delete iterations;

    return 0;
}