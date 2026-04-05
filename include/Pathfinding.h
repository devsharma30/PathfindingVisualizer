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


    /// using something like f=g+h formula for good moving in grid instead of random moving


    void startAStar(std::vector<std::vector<int>>& grid,
                int startRow, int startCol,
                int endRow, int endCol);

void stepAStar(std::vector<std::vector<int>>& grid);

    void drawPath(std::vector<std::vector<int>>& grid);
    bool isFinished();

private:
    std::queue<std::pair<int,int>> q;
    std::vector<std::vector<bool>> visited;

    int rows, cols;
    bool finished = false;


    std::vector<std::vector<std::pair<int,int>>> parent;
    int heuristic(int r, int c);


   std::priority_queue<
    std::pair<int, std::pair<int,int>>,
    std::vector<std::pair<int, std::pair<int,int>>>,
    std::greater<>
> pq;

std::vector<std::vector<int>> gCost; 

int endRow, endCol;
bool pathFound = false;
};







