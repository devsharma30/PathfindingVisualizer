#pragma once
#include <vector>
#include <queue>

class Pathfinding
{
public:
    void startBFS(std::vector<std::vector<int>>& grid,
                  int startRow, int startCol,
                  int endRow, int endCol);

    void stepBFS(std::vector<std::vector<int>>& grid);

private:
    std::queue<std::pair<int,int>> q;
    std::vector<std::vector<bool>> visited;

    int rows, cols;
    bool finished = false;
};