#ifndef VIEW_H
#define VIEW_H

class IView {
public:
    virtual ~IView() = default;
    virtual void display(const Grid& grid) const = 0;
    virtual void update(const Grid& grid) const = 0;
};

class ViewConsole : public IView {
public:
    void display(const Grid& grid) const override {

    }

    void update(const Grid& grid) const override {

    }
};

class ViewGraphic : public IView {
public:
    void display(const Grid& grid) const override {    
        window.clear();
        sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
        for (int x = 0; x < gridWidth; ++x) {
            for (int y = 0; y < gridHeight; ++y) {
                if (grid[x][y] == 1) {
                    cell.setPosition(x * cellSize, y * cellSize);
                    window.draw(cell);
                }
            }
        }
        window.display();
    }

    void update(const Grid& grid) const override {

    }
};

#endif