#include "grid.h"

int GridClassic::getRows() const{
    return rows;
}

int GridClassic::getColumns() const {
    return columns; 
}

void GridClassic::setCellState(int x, int y, bool state){
    if (x >= 0 && x < rows && y >= 0 && y < columns) {
        grid[x][y].setAlive(state);
    }
}

bool GridClassic::getCellState(int x, int y) const{
    if (x >= 0 && x < rows && y >= 0 && y < columns) {
        return grid[x][y].isAlive();
    }
    return false;
}

void GridClassic::update(){
    auto nextState = grid;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            int neighbors = countAliveNeighbors(i, j);
            nextState[i][j].updateState(neighbors);
        }
    }
    grid = nextState;
}

int GridClassic::countAliveNeighbors(int x, int y) const {
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

void GridClassic::copyFrom(const IGrid& other){
    for (int i = 0; i < getRows(); ++i) {
        for (int j = 0; j < getColumns(); ++j) {
            this->grid[i][j] = other.getCellState(i, j) ? CellClassic(true) : CellClassic(false);
        }
    }
}

std::vector<std::vector<bool>> GridClassic::getGridState() const{
    std::vector<std::vector<bool>> gridState(rows, std::vector<bool>(columns));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            gridState[i][j] = getCellState(i, j);
        }
    }
    return gridState;
}

int GridToroidal::getRows() const{ 
    return rows;
}

int GridToroidal::getColumns() const {
    return columns;
}

void GridToroidal::setCellState(int x, int y, bool state){
    if (x >= 0 && x < rows && y >= 0 && y < columns) {
        grid[x][y].setAlive(state);
    }
}

bool GridToroidal::getCellState(int x, int y) const {
    if (x >= 0 && x < rows && y >= 0 && y < columns) {
        return grid[x][y].isAlive();
    }
    return false;
}

void GridToroidal::update(){
    auto nextState = grid;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            int neighbors = countAliveNeighbors(i, j);
            nextState[i][j].updateState(neighbors);
        }
    }
    grid = nextState;
}

int GridToroidal::countAliveNeighbors(int x, int y) const {
    int count = 0;
    for (int di = -1; di <= 1; ++di) {
        for (int dj = -1; dj <= 1; ++dj) {
            if (di == 0 && dj == 0) 
                continue;
            int ni = (x + di + rows) % rows;
            int nj = (y + dj + columns) % columns;
            count += grid[ni][nj].isAlive();
        }
    }
    return count;   
}

void GridToroidal::copyFrom(const IGrid& other){
    for (int i = 0; i < getRows(); ++i) {
        for (int j = 0; j < getColumns(); ++j) {
            this->grid[i][j] = other.getCellState(i, j) ? CellClassic(true) : CellClassic(false);
        }
    }
}

std::vector<std::vector<bool>> GridToroidal::getGridState() const{
    std::vector<std::vector<bool>> gridState(rows, std::vector<bool>(columns));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            gridState[i][j] = getCellState(i, j);
        }
    }
    return gridState;
}