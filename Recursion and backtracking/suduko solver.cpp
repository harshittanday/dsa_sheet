bool isValid(int grid[N][N], int k, int row, int col)
{
    for (int i = 0; i < 9; i++)
    {
        if (grid[row][i] == k)
            return false;
        if (grid[i][col] == k)
            return false;
        if (grid[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == k)
            return false;
    }
    return true;
}
// Function to find a solved Sudoku.
bool SolveSudoku(int grid[N][N])
{
    // Your code here
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == 0)
            {
                for (int k = 1; k <= 9; k++)
                {
                    if (isValid(grid, k, i, j))
                    {
                        grid[i][j] = k;
                        if (SolveSudoku(grid) == true)
                        {
                            return true;
                        }
                        else
                        {
                            grid[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
}

// Function to print grids of the Sudoku.
void printGrid(int grid[N][N])
{
    // Your code here
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << grid[i][j] << " ";
        }
    }
}