#ifndef VIEW_H
#define VIEW_H

class IView {
public:
    virtual ~IView() = default;
    virtual void display(const IGrid& grid, sf::RenderWindow& window, int cellSize) const = 0;
};

class ViewGraphic : public IView {
public:
    void display(const IGrid& grid, sf::RenderWindow& window, int cellSize) const override {
        window.clear();
        sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));

        for (int x = 0; x < grid.getRows(); x++) {
            for (int y = 0; y < grid.getColumns(); y++) {
                if (grid.getCellState(x, y)) {
                    cell.setPosition(y * cellSize, x * cellSize);
                    window.draw(cell);
                }
            }
        }
        window.display();
    }
};

#endif