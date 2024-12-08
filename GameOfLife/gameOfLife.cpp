#include "gameOfLife.h"

void GameOfLife::run(int sleepTime) {
    while (iterations->canContinue(*grid)) {
        if (viewType == 1) {
            fileHandler->save(*grid);
            std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
        } else if (viewType == 2) {
            int cellSize = 20;
            sf::RenderWindow window(sf::VideoMode(grid->getColumns() * cellSize, grid->getRows() * cellSize), "Game of Life");

            view->display(*grid, window, cellSize);
            sf::sleep(sf::milliseconds(sleepTime));
        }
        grid->update();
    }
}