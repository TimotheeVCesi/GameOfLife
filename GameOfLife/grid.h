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

    void initializeGrid();
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

    void renderGrid();
};


// int Detection(int i,int j, int n,int m){            //ce sera surement dans une classe Grid
// // n = gridHeigth, m = gridWidth
//     //check si c'est premirère u denrière ligne et/ou colonne)
//     int cell_select = grid[i][j]; 
//     int compteur = 0;

//     if (i==0){
//         if (j==0){
//             compteur = grid[n-1][m-1] + grid[n-1][j] + grid[n-1][j+1] + grid[i][m-1] + grid[i][j+1] + grid[i+1][m-1] + grid[i+1][j] + grid[i+1][j+1];
//         }

//         else if (j==n-1)
//         {
//             compteur = grid[n-1][j-1] + grid[n-1][j] + grid[n-1][0] + grid[i][j-1] + grid[i][0] + grid[i+1][j-1] + grid[i+1][j] + grid[i+1][0];
//         }

//         else{
//             compteur = grid[n-1][j-1] + grid[n-1][j] + grid[n-1][j+1] + grid[i][j-1] + grid[i][j+1] + grid[i+1][j-1] + grid[i+1][j] + grid[i+1][j+1];
//         } 
//     }

//     else if (i==(n-1))
//     {
//         if (j==0){
//             compteur = grid[i-1][m-1] + grid[i-1][j] + grid[i-1][j+1] + grid[i][m-1] + grid[i][j+1] + grid[0][m-1] + grid[0][j] + grid[0][j+1];
//         }

//         else if (j==n-1)
//         {
//             compteur = grid[i-1][j-1] + grid[i-1][j] + grid[i-1][0] + grid[i][j-1] + grid[i][0] + grid[0][j-1] + grid[0][j] + grid[0][0];
//         }
//         else{
//             compteur = grid[i-1][j-1] + grid[i-1][j] + grid[i-1][j+1] + grid[i][j-1] + grid[i][j+1] + grid[0][j-1] + grid[0][j] + grid[0][j+1];
//         } 
//     }

//     else {
//         compteur = grid[i-1][j-1] + grid[i-1][j] + grid[i-1][j+1] + grid[i][j-1] + grid[i][j+1] + grid[i+1][j-1] + grid[i+1][j] + grid[i+1][j+1];
//     }
    
//     return compteur;    
// }