#ifndef CELL_H
#define CELL_H

class ICell {
public:
    virtual ~ICell() = default;
    virtual bool isAlive() const = 0;
    virtual void setAlive(bool alive) = 0;
    virtual void updateState(int aliveNeighbors) = 0;
};

class CellClassic : public ICell {
private:
    bool state;

public:
    CellClassic(bool alive = false) : state(alive) {}

    bool isAlive() const override { return state; }
    void setAlive(bool alive) override { state = alive; }
    void updateState(int aliveNeighbors) override {
        state = isAlive() ? (aliveNeighbors == 2 || aliveNeighbors == 3) : (aliveNeighbors == 3);
    }
};

class CellObstacle : public ICell {

};

#endif