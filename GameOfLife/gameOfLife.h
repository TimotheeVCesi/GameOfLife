class GameOfLife {
private:
    std::string fileName, mode, gridType;
    int generations, sleepTime;
    Grid grid;

public:
    GameOfLife(std::string fileName, std::string mode, std::string gridType, int generations, int sleepTime) :
                fileName(fileName), mode(mode), gridType(gridType), generations(generations), sleepTime(sleepTime) {}

    void start() {
        grid.initializeGrid();
        for (int i = 0; i < generations; i++) {
            grid.renderGrid();
            grid.updateGrid();
            std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
        }
    }
};