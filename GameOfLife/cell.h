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

    bool isAlive() const override;
    void setAlive(bool alive) override;
    void updateState(int aliveNeighbors) override;
};

class CellObstacle : public ICell {
    CellObstacle(bool alive = false) : ICell(alive) {}

    bool isAlive() const override;
    void setAlive(bool alive) override;
    void updateState(int aliveNeighbors) override{}
};

#endif