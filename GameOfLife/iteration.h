#ifndef ITER_H
#define ITER_H

#include "headers.h"

class IGrid;

class IIteration {
protected:
    int maxGenerations;
    int currentGeneration;

public :
    IIteration(int maxGenerations) : maxGenerations(maxGenerations), currentGeneration(0) {}
    virtual ~IIteration() = default;
    virtual void reset() = 0;
    virtual bool hasReachedLimit() const = 0;
    virtual bool isStable(const IGrid& grid) = 0;
    virtual bool canContinue(const IGrid& grid) = 0;
    virtual int getCurrentGeneration() const = 0;
};

class IterationClassic : public IIteration {
private:
    std::vector<std::vector<bool>> previousState;

public:
    IterationClassic(int maxGenerations) : IIteration(maxGenerations) {}

    void reset() override;

    bool hasReachedLimit() const override;

    bool isStable(const IGrid& grid) override;

    bool canContinue(const IGrid& grid) override;

    int getCurrentGeneration() const override;
};

#endif