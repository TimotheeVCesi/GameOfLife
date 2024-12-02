class Grid {
private:
    int rows, columns;
    std::vector<std::vector<Cell>> grid;

    // méthode à modifier pour grille torique
    int countAliveNeighbors(int x, int y) const {
        int count = 0;
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) continue;

                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < rows && ny >= 0 && ny < columns) {
                    if (grid[nx][ny].isAlive()) {
                        ++count;
                    }
                }
            }
        }
        return count;
    }

public:
    Grid(int r, int c) : rows(r), columns(c), grid(r, std::vector<Cell>(c)) {}

    void initializeGrid() {
        std::srand(std::time(0));
        for (int x = 0; x < gridWidth; ++x) {
            for (int y = 0; y < gridHeight; ++y) {
                grid[x][y] = std::rand() % 2;  // Randomly initialize cells as alive or dead
            }
        }
    }

    void renderGrid(sf::RenderWindow &window) {
        int x, y;
        
        window.clear();
        sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
        for (x = 0; x < gridWidth; ++x) {
            for (y = 0; y < gridHeight; ++y) {
                if (grid[x][y] == 1) {
                    cell.setPosition(x * cellSize, y * cellSize);
                    window.draw(cell);
                }
            }
        }
        window.display();
    }

    void update() {
        std::vector<std::vector<Cell>> newGrid = grid;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                int aliveNeighbors = countAliveNeighbors(i, j);

                if (grid[i][j].isAlive()) {
                    newGrid[i][j].setAlive(aliveNeighbors == 2 || aliveNeighbors == 3);
                } else {
                    newGrid[i][j].setAlive(aliveNeighbors == 3);
                }
            }
        }

        grid = newGrid;
    }    
};

class Grid {
protected:
    const int rows, columns;
    int generations;
    std::string fileName;
    std::vector<std::vector<Cell>> grid(rows, std::vector<Cell>(columns));

    int countAliveNeighbors();
    int countAliveNeighborsToroidal();

public:
    Grid();
    ~Grid();

    void inputFile() {
        std::ifstream file(fileName);
        if (!file) {
            std::cerr << "Erreur: impossible d'ouvrir le fichier " << fileName << std::endl;
        }

        file >> rows >> columns;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                file >> grid[i][j];
            }
        }

        file.close();
    }

    void initializeGrid();
    void renderGrid();
    void updateGrid();
};

class GridConsole : public Grid {
private:

public:
    GridConsole();
    ~GridConsole();

    void outputFile();
};

class GridGraphic : public Grid {
private:
    const int cellSize;
    int sleepTime;
    std::vector<std::vector<int>> grid(gridWidth, std::vector<int>(gridHeight));

public:
    GridGraphic();
    ~GridGraphic();


};