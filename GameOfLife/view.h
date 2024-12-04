#ifndef VIEW_H
#define VIEW_H

class IView {
public:
    virtual ~IView() = default;
    virtual void display(const Grid& grid) const = 0;
};

class ViewGraphic : public IView {
private:
    sf::RenderWindow& window;
    float cellSize;           

public:
    ViewGraphic(sf::RenderWindow& win) : window(win), cellSize(10) {}

    void display(const Grid& grid) const override {
        window.clear();
        sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));

        for (int x = 0; x < grid.getRows(); x++) {
            for (int y = 0; y < grid.getColumns(); y++) {
                if (grid[x][y] == 1) {
                    cell.setPosition(x * cellSize, y * cellSize);
                    window.draw(cell);
                }
            }
        }
        window.display();
    }
};

#endif