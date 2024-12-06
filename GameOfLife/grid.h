 #ifndef GRID_H
 #define GRID_H

#include "cell.h"

class IGrid {
protected:
    int rows, columns;
    std::vector<std::vector<ICell>> grid;

public:
    IGrid(int rows, int columns) : rows(rows), columns(columns), grid(rows, std::vector<ICell>(columns)) {}
    virtual ~IGrid() = default;

    virtual int getRows() const = 0;
    virtual int getColumns() const = 0;
    virtual void setCellState(int x, int y, bool state) = 0;
    virtual bool getCellState(int x, int y) const = 0;
    virtual void update() = 0;
    virtual int countAliveNeighbors(int x, int y) const = 0;
};

class GridClassic : public IGrid {
public:
    GridClassic(int rows, int columns) : IGrid(rows, columns) {}

    int getRows() const override { return rows; }
    int getColumns() const override { return columns; }

    void setCellState(int x, int y, bool state) override {
        if (x >= 0 && x < rows && y >= 0 && y < columns) {
            grid[x][y].setAlive(state);
        }
    }

    bool getCellState(int x, int y) const override {
        if (x >= 0 && x < rows && y >= 0 && y < columns) {
            return grid[x][y].isAlive();
        }
        return false;
    }

    void update() override {
        auto nextState = grid;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                int neighbors = countAliveNeighbors(i, j);
                nextState[i][j].updateState(neighbors);
            }
        }
        grid = nextState;
    }

    int countAliveNeighbors(int x, int y) const override {
        int count = 0;
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) continue;
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < rows && ny >= 0 && ny < columns) {
                    count += grid[nx][ny].isAlive();
                }
            }
        }
        return count;
    }
};

class GridToroidal : public IGrid {
public:
    GridToroidal(int rows, int columns) : IGrid(rows, columns) {}

    int getRows() const override { return rows; }
    int getColumns() const override { return columns; }

    void setCellState(int x, int y, bool state) override {
        if (x >= 0 && x < rows && y >= 0 && y < columns) {
            grid[x][y].setAlive(state);
        }
    }

    bool getCellState(int x, int y) const override {
        if (x >= 0 && x < rows && y >= 0 && y < columns) {
            return grid[x][y].isAlive();
        }
        return false;
    }

    void update() override {
        auto nextState = grid;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                int neighbors = countAliveNeighbors(i, j);
                nextState[i][j].updateState(neighbors);
            }
        }
        grid = nextState;
    }

    int countAliveNeighbors(int x, int y) const override {
        int n = rows;
        int m = columns;
        int compteur = 0;

        for (int di = -1; di <= 1; ++di) {
            for (int dj = -1; dj <= 1; ++dj) {
                if (di == 0 && dj == 0) 
                    continue;
                int ni = (x + di + n) % n;
                int nj = (y + dj + m) % m;
                compteur += grid[ni][nj].isAlive();
            }
        }
        return compteur;   
    }
};

 #endif