#ifndef CELL_H
#define CELL_H

// ajout interface pour diff cell classique et cell obstacle

class Cell {
private:
    bool state;

public:
    Cell(bool alive = false) : state(alive) {}

    bool isAlive() const { return state; }
    void setAlive(bool alive) { state = alive; }

    void updateState(int aliveNeighbors) {
        if (isAlive) {
            state = (aliveNeighbors == 2 || aliveNeighbors == 3);
        } else {
            state = (aliveNeighbors == 3);
        }
    }
};

#endif