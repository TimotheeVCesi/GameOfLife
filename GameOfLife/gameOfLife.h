#ifndef GOF_H
#define GOF_H

#include "file.h"
#include "grid.h"
#include "view.h"

class GameOfLife {
private:
    IGrid* grid;
    IView* view;

public:
    GameOfLife(IGrid* grid, IView* view) : grid(grid), view(view) {}

    void run(int iterations, int delayMs) {
        for (int i = 0; i < iterations; ++i) {
            view->display(*grid);
            grid->update();
            std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
        }
    }
};

#endif