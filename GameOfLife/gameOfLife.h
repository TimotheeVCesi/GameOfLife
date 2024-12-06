#ifndef GOF_H
#define GOF_H

#include "grid.h"
#include "view.h"
#include "iteration.h"

class GameOfLife {
private:
    IGrid* grid;
    IView* view;
    IIteration* iterations;

public:
    GameOfLife(IGrid* grid, IView* view, IIteration* iterations) : grid(grid), view(view) {}

    void run(int sleepTime) {
        while (iterations->canContinue(*grid)) {
            view->display(*grid);
            grid->update();
            std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
        }
    }
};

#endif