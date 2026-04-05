#include "Pathfinding.h"

void Pathfinding::startBFS(std::vector<std::vector<int>>& grid,
                           int startRow, int startCol,
                           int endRow, int endCol)
{
    rows = grid.size();
    cols = grid[0].size();

    visited = std::vector<std::vector<bool>>(rows, std::vector<bool>(cols, false));
    parent = std::vector<std::vector<std::pair<int,int>>>(
                rows, std::vector<std::pair<int,int>>(cols, {-1, -1}));

    while (!q.empty()) q.pop();

    q.push({startRow, startCol});
    visited[startRow][startCol] = true;

    this->endRow = endRow;
    this->endCol = endCol;

    pathFound = false;
    finished = false;
}

void Pathfinding::stepBFS(std::vector<std::vector<int>>& grid)
{
    if (q.empty() || finished) return;

    auto current = q.front();
    q.pop();

    int r = current.first;
    int c = current.second;

    int dr[] = {0, 1, 0, -1};
    int dc[] = {1, 0, -1, 0};


    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols)
        {
            if (!visited[nr][nc] && grid[nr][nc] != 1)
          {
               visited[nr][nc] = true;
               parent[nr][nc] = {r, c};  // 🔥 TRACK PATH

                if (nr == endRow && nc == endCol)
                 {
                     pathFound = true;
                     finished = true;
                     return;
                 }

                if (grid[nr][nc] != 3)
                     grid[nr][nc] = 4;

                q.push({nr, nc});
         }
        }
    }
}


void Pathfinding::drawPath(std::vector<std::vector<int>>& grid)
{
    if (!pathFound) return;

    int r = endRow;
    int c = endCol;

    while (true)
    {
        auto p = parent[r][c];

        if (p.first == -1 && p.second == -1)
            break;

        r = p.first;
        c = p.second;

        if (grid[r][c] != 2) // don't overwrite start
            grid[r][c] = 5;
    }
}

bool Pathfinding::isFinished()
{
    return finished;
}