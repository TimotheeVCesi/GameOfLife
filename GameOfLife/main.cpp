#include "headers.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(gridWidth * cellSize, gridHeight * cellSize), "Game of Life");
    
    grid.initializeGrid();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        grid.renderGrid(window);

        sf::sleep(sf::milliseconds(100));
    }

    return 0;
}

int main() {
    GameOfLife simulation;

    simulation.start();

    return 0;
}