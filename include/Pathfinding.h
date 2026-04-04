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

    void drawPath(std::vector<std::vector<int>>& grid);
    bool isFinished();

private:
    std::queue<std::pair<int,int>> q;
    std::vector<std::vector<bool>> visited;

    int rows, cols;
    bool finished = false;


    std::vector<std::vector<std::pair<int,int>>> parent;

int endRow, endCol;
bool pathFound = false;
};