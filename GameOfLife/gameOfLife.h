#ifndef GOF_H
#define GOF_H

#include "file.h"
#include "grid.h"
#include "view.h"
#include "iteration.h"

class IFileHandler;
class IView;
class IIteration;

class GameOfLife {
private:
    IFileHandler* fileHandler;
    IGrid* grid;
    IView* view;
    IIteration* iterations;
    int viewType;

public:
    GameOfLife(IFileHandler* fileHandler, IGrid* grid, IView* view, IIteration* iterations, int viewType)
                : fileHandler(fileHandler), grid(grid), view(view), iterations(iterations), viewType(viewType) {}

    void run(int sleepTime);
};

#endif