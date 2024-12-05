#ifndef ITER_H
#define ITER_H

class IIteration {
public :
    virtual ~IIteration() = default;

    virtual void reset() = 0;
    virtual bool hasReachedLimit() const = 0;
    virtual bool isStable(const IGrid& grid) = 0;
    virtual bool canContinue(const IGrid& grid) = 0;
    virtual int getCurrentGeneration() const = 0;
};

class IterationClassic : public IIteration {
private:
    int maxGenerations;
    int currentGeneration;
    std::vector<std::vector<bool>> previousState;

public:
    IterationClassic(int maxGenerations) : maxGenerations(maxGenerations), currentGeneration(0) {}

    void reset() override {
        currentGeneration = 0;
        previousState.clear();
    }

    bool hasReachedLimit() const override {
        return currentGeneration >= maxGenerations;
    }

    bool isStable(const IGrid& grid) override {
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

    bool canContinue(const IGrid& grid) override {
        currentGeneration++;
        return !hasReachedLimit() && !isStable(grid);
    }

    int getCurrentGeneration() const override {
        return currentGeneration;
    }
};

#endif