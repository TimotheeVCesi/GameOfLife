#ifndef GOF_H
#define GOF_H

class GameOfLife {
private:
    std::string filePath;
    IFileHandler* file;
    IView* view;

public:
    GameOfLife(std::string filePath) : filePath(filePath) {}

    void start() {
        file = new FileHandler();
        Grid grid = file->load(filePath);

        int mode;
        std::cout << "Entrez la vue à utiliser (1 pour console ou 2 pour graphique) :" << std::endl;
        std::cin >> mode;

        switch (mode) {
            case 1:
                view = new ViewConsole();
                break;
            case 2:
                sf::RenderWindow window(sf::VideoMode(gridWidth * cellSize, gridHeight * cellSize), "Game of Life");
                view = new ViewGraphic(window);
                break;
            default:
                throw std::runtime_error("Erreur: mode non défini");
                break;
        }

        view->display();

        





        // for (int i = 0; i < generations; i++) {
        //     grid.renderGrid();
        //     grid.updateGrid();
        //     std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
        // }
    }
};

#endif