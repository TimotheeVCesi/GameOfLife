#ifndef CELL_H
#define CELL_H

// ajout interface pour diff cell classique et cell obstacle

class Cell {
private:
    bool isAlive;

public:
    Cell(bool alive = false) : isAlive(alive) {}

    bool isAlive() const { return isAlive; }
    void setAlive(bool alive) { isAlive = alive; }

    void updateState(int aliveNeighbors) {
        if (isAlive) {
            isAlive = (aliveNeighbors == 2 || aliveNeighbors == 3);
        } else {
            isAlive = (aliveNeighbors == 3);
        }
    }
};

#endif