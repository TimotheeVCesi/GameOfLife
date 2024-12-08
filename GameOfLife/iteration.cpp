#include "iteration.h"

void IterationClassic::reset() {
    currentGeneration = 0;
    previousState.clear();
}

bool IterationClassic::hasReachedLimit()const{
    return currentGeneration > maxGenerations;
};

bool IterationClassic::isStable(const IGrid& grid){
    std::vector<std::vector<bool>> currentState(grid.getRows(), std::vector<bool>(grid.getColumns()));

    for (int i = 0; i < grid.getRows(); ++i) {
        for (int j = 0; j < grid.getColumns(); ++j) {
            currentState[i][j] = grid.getCellState(i, j);
        }
    }

    bool stable = (currentState == previousState);
    previousState = std::move(currentState);
    return stable;
}

bool IterationClassic::canContinue(const IGrid& grid){
    currentGeneration++;
    return !hasReachedLimit() && !isStable(grid);
}

int IterationClassic::getCurrentGeneration() const {
    return currentGeneration;
}