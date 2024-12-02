class Cell {
private:
    bool alive;

public:
    Cell(bool state = false) : alive(state) {}

    bool isAlive() const { return alive; }

    void setAlive(bool state) { alive = state; }
};

class CellObstacle {

};