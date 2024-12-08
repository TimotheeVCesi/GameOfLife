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

    IGrid* newGrid = nullptr;
    switch (gridType) {
        case 1:
            newGrid = new GridClassic(rows, columns);
            break;
        case 2:
            newGrid = new GridToroidal(rows, columns);
            break;
        default:
            std::cerr << "Erreur: entrée inconnue (type de la grille). Grille classique utilisée par défaut." << std::endl;
            newGrid = new GridClassic(rows, columns);
            break;
    }

    if (grid) {
        newGrid->copyFrom(*grid);
        delete grid;
    }
    grid = newGrid;
}

void configViewType(IView*& view, int& viewType) {
    std::cout << "Entrez le type de vue ('1' pour console, '2' pour graphique) :" << std::endl;
    std::cin >> viewType;

    view = new ViewGraphic();
}

void configVar(IIteration*& iterations, int& generations, int& sleepTime, int& viewType) {
    std::cout << "Entrez le nombre de générations maximum :" << std::endl;
    std::cin >> generations;
    iterations = new IterationClassic(generations);

    std::cout << "Entrez le temps de pause entre deux itérations (en ms) :" << std::endl;
    std::cin >> sleepTime;
}

void testGrid(IGrid*& initialGrid, IGrid*& grid, int generations, int viewType) {
    std::cout << "Test de validation de la grille :" << std::endl;
    std::vector<std::vector<bool>> testGridState = initialGrid->getGridState();
    std::vector<std::vector<bool>> finalGridState = grid->getGridState();
    int rows = initialGrid->getRows();
    int columns = initialGrid->getColumns();

    for (int i = 0; i < generations; i++) {
        std::vector<std::vector<bool>> nextState = testGridState;

        for (int x = 0; x < rows; x++) {
            for (int y = 0; y < columns; y++) {
                int neighbors = 0;
                if (viewType == 1) {
                    for (int dx = -1; dx <= 1; ++dx) {
                        for (int dy = -1; dy <= 1; ++dy) {
                            if (dx == 0 && dy == 0) continue;
                            int nx = x + dx, ny = y + dy;
                            if (nx >= 0 && nx < rows && ny >= 0 && ny < columns) {
                                neighbors += testGridState[nx][ny];
                            }
                        }
                    }
                } else if (viewType == 2) {
                    for (int di = -1; di <= 1; ++di) {
                        for (int dj = -1; dj <= 1; ++dj) {
                            if (di == 0 && dj == 0) 
                                continue;
                            int ni = (x + di + rows) % rows;
                            int nj = (y + dj + columns) % columns;
                            neighbors += testGridState[ni][nj];
                        }
                    }
                } else {
                    throw std::runtime_error("Test unitaire: erreur: la vue spécifiée est invalide");
                }
                
                nextState[x][y] = (testGridState[x][y]) ? (neighbors == 2 || neighbors == 3) : (neighbors == 3);
            }
        }
        testGridState = nextState;
    }

    for (size_t i = 0; i < testGridState.size(); ++i)
        for (size_t j = 0; j < testGridState[i].size(); ++j)
            if (testGridState[i][j] != finalGridState[i][j])
                throw std::runtime_error("Test unitaire: la grille n'est pas valide");
    std::cout << "Test unitaire: la grille est valide" << std::endl;
}

int main() {
    IFileHandler* fileHandler = nullptr;
    inputFile(fileHandler);

    IGrid* grid = fileHandler->load();
    configGridType(grid, grid->getRows(), grid->getColumns());
    auto* initialGrid = grid;

    IView* view = nullptr;
    int viewType;
    configViewType(view, viewType);

    IIteration* iterations = nullptr;
    int generations, sleepTime;
    configVar(iterations, generations, sleepTime, viewType);

    GameOfLife game(fileHandler, grid, view, iterations, viewType);
    game.run(sleepTime);

    testGrid(initialGrid, grid, generations, viewType);

    delete fileHandler;
    delete grid;
    delete view;
    delete iterations;

    return 0;
}