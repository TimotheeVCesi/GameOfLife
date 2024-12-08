#ifndef GOF_H
#define GOF_H

#include "headers.h"
#include "file.h"
#include "grid.h"
#include "view.h"
#include "iteration.h"

class GameOfLife {
private:
    IFileHandler* fileHandler;
    IGrid* grid;
    IView* view;
    IIteration* iterations;
    int viewType;

public:
    GameOfLife(IFileHandler* fileHandler, IGrid* grid, IView* view, IIteration* iterations, int viewType)
                : fileHandler(fileHandler), grid(grid), view(view), iterations(iterations), viewType(viewType) {}

    void run(int sleepTime) {
        while (iterations->canContinue(*grid)) {
            if (viewType == 1) {
                fileHandler->save(*grid);
                std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
            } else if (viewType == 2) {
                int cellSize = 10;
                sf::RenderWindow window(sf::VideoMode(grid->getColumns() * cellSize, grid->getRows() * cellSize), "Game of Life");

                view->display(*grid, window, cellSize);
                sf::sleep(sf::milliseconds(sleepTime));
            }
            grid->update();
        }
    }
};

#endif