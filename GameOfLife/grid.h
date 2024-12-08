#ifndef GRID_H
#define GRID_H

#include "cell.h"
#include "headers.h"

class IGrid {
protected:
    int rows, columns;
    std::vector<std::vector<CellClassic>> grid;

public:
    IGrid(int rows, int columns) : rows(rows), columns(columns), grid(rows, std::vector<CellClassic>(columns)) {}
    virtual ~IGrid() = default;

    virtual int getRows() const = 0;
    virtual int getColumns() const = 0;
    virtual void setCellState(int x, int y, bool state) = 0;
    virtual bool getCellState(int x, int y) const = 0;
    virtual void update() = 0;
    virtual int countAliveNeighbors(int x, int y) const = 0;
    virtual void copyFrom(const IGrid& other) = 0;
    virtual std::vector<std::vector<bool>> getGridState() const = 0;
};

class GridClassic : public IGrid {
public:
    GridClassic(int rows, int columns) : IGrid(rows, columns) {}

    int getRows() const override;
    int getColumns() const override;

    void setCellState(int x, int y, bool state) override;
    bool getCellState(int x, int y) const override;

    void update() override;
    int countAliveNeighbors(int x, int y) const override;

    void copyFrom(const IGrid& other) override;
    std::vector<std::vector<bool>> getGridState() const override;
};


class GridToroidal : public IGrid {
public:
    GridToroidal(int rows, int columns) : IGrid(rows, columns) {}

    int getRows() const override;
    int getColumns() const override;

    void setCellState(int x, int y, bool state) override;
    bool getCellState(int x, int y) const override;

    void update() override;
    int countAliveNeighbors(int x, int y) const override;

    void copyFrom(const IGrid& other) override;
    std::vector<std::vector<bool>> getGridState() const override;
};

#endif