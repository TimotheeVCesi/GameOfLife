#include <iostream>
#include <vector>

class Cell {
private:
    bool alive;

public:
    Cell(bool state = false) : alive(state) {}

    bool isAlive() const { return alive; }

    void setAlive(bool state) { alive = state; }
};

class Grid {
private:
    int rows, columns;
    std::vector<std::vector<Cell>> grid;

public:
    Grid(int r, int c) : rows(r), columns(c), grid(r, std::vector<Cell>(c)) {}

    void initializeGrid();

    void display() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                std::cout << (grid[i][j].isAlive() ? "1 " : "0 ");
            }
            std::cout << "\n";
        }
    }

    void update() {
        std::vector<std::vector<Cell>> newGrid = grid;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                int aliveNeighbors = countAliveNeighbors(i, j);

                if (grid[i][j].isAlive()) {
                    newGrid[i][j].setAlive(aliveNeighbors == 2 || aliveNeighbors == 3);
                } else {
                    newGrid[i][j].setAlive(aliveNeighbors == 3);
                }
            }
        }

        grid = newGrid;
    }    
};

class GameOfLife {
private:
    Grid grid;

public:
    GameOfLife(int rows, int columns) : grid(rows, columns) {}

    void start(int generations) {
        for (int i = 0; i < generations; i++) {

        }
    }
};

int mainTest() {
    int rows, columns, generations;

    GameOfLife game(rows, columns);
    game.start(generations);

    return 0;
}