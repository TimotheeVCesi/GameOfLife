class GameOfLife {
private:
    std::string filePath;

public:
    GameOfLife(std::string filePath) : filePath(filePath) {}

    void start() {
        grid.initializeGrid();
        for (int i = 0; i < generations; i++) {
            grid.renderGrid();
            grid.updateGrid();
            std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
        }
    }
};