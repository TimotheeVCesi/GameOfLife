#ifndef VIEW_H
#define VIEW_H

#include "headers.h"

class IGrid;

class IView {
public:
    virtual ~IView() = default;
    virtual void display(const IGrid& grid, sf::RenderWindow& window, int cellSize) const = 0;
};

class ViewGraphic : public IView {
public:
    void display(const IGrid& grid, sf::RenderWindow& window, int cellSize) const override;
};

#endif