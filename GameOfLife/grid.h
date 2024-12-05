 #ifndef GRID_H
 #define GRID_H

#include "cell.h"

class IGrid {
public:
    virtual ~IGrid() = default;
    virtual int getRows() const = 0;
    virtual int getColumns() const = 0;
    virtual void setCellState(int x, int y, bool state) = 0;
    virtual bool getCellState(int x, int y) const = 0;
    virtual void update() = 0;
    virtual int countAliveNeighbors(int x, int y) const = 0;
};

class GridClassic : public IGrid {
private:
    int rows, columns;
    std::vector<std::vector<CellClassic>> grid;

public:
    GridClassic(int rows, int columns) : rows(rows), columns(columns), grid(rows, std::vector<CellClassic>(columns)) {}

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

};

 #endif


// int Detection(int i,int j, int n,int m){            //ce sera surement dans une classe Grid
// // n = gridHeigth, m = gridWidth
//     //check si c'est premirère u denrière ligne et/ou colonne)
//     int cell_select = grid[i][j]; 
//     int compteur = 0;

//     if (i==0){
//         if (j==0){
//             compteur = grid[n-1][m-1] + grid[n-1][j] + grid[n-1][j+1] + grid[i][m-1] + grid[i][j+1] + grid[i+1][m-1] + grid[i+1][j] + grid[i+1][j+1];
//         }

//         else if (j==n-1)
//         {
//             compteur = grid[n-1][j-1] + grid[n-1][j] + grid[n-1][0] + grid[i][j-1] + grid[i][0] + grid[i+1][j-1] + grid[i+1][j] + grid[i+1][0];
//         }

//         else{
//             compteur = grid[n-1][j-1] + grid[n-1][j] + grid[n-1][j+1] + grid[i][j-1] + grid[i][j+1] + grid[i+1][j-1] + grid[i+1][j] + grid[i+1][j+1];
//         } 
//     }

//     else if (i==(n-1))
//     {
//         if (j==0){
//             compteur = grid[i-1][m-1] + grid[i-1][j] + grid[i-1][j+1] + grid[i][m-1] + grid[i][j+1] + grid[0][m-1] + grid[0][j] + grid[0][j+1];
//         }

//         else if (j==n-1)
//         {
//             compteur = grid[i-1][j-1] + grid[i-1][j] + grid[i-1][0] + grid[i][j-1] + grid[i][0] + grid[0][j-1] + grid[0][j] + grid[0][0];
//         }
//         else{
//             compteur = grid[i-1][j-1] + grid[i-1][j] + grid[i-1][j+1] + grid[i][j-1] + grid[i][j+1] + grid[0][j-1] + grid[0][j] + grid[0][j+1];
//         } 
//     }

//     else {
//         compteur = grid[i-1][j-1] + grid[i-1][j] + grid[i-1][j+1] + grid[i][j-1] + grid[i][j+1] + grid[i+1][j-1] + grid[i+1][j] + grid[i+1][j+1];
//     }
    
//     return compteur;    
// }