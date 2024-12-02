class GameOfLife {
private:
    Grid grid;

public:
    GameOfLife(int rows, int columns, int generations) : grid(rows, columns) {}

    void start(int generations) {
        grid.initializeGrid();
        for (int i = 0; i < generations; i++) {
            grid.renderGrid();
            grid.updateGrid();
            std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
        }
    }
};