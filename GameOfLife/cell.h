#ifndef CELL_H
#define CELL_H

class ICell {
protected:
    bool state;

public:
    ICell(bool alive = false) : state(alive) {}
    virtual ~ICell() = default;

    virtual bool isAlive() const = 0;
    virtual void setAlive(bool alive) = 0;
    virtual void updateState(int aliveNeighbors) = 0;
};

class CellClassic : public ICell {
public:
    CellClassic(bool alive = false) : ICell(alive) {}

    bool isAlive() const override { return state; }
    void setAlive(bool alive) override { state = alive; }
    void updateState(int aliveNeighbors) override {
        state = isAlive() ? (aliveNeighbors == 2 || aliveNeighbors == 3) : (aliveNeighbors == 3);
    }
};

class CellObstacle : public ICell {

};

#endif