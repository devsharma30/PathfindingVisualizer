#include "Pathfinding.h"

void Pathfinding::startBFS(std::vector<std::vector<int>>& grid,
                           int startRow, int startCol,
                           int endRow, int endCol)
{
    rows = grid.size();
    cols = grid[0].size();

    visited = std::vector<std::vector<bool>>(rows, std::vector<bool>(cols, false));

    while (!q.empty()) q.pop();

    q.push({startRow, startCol});
    visited[startRow][startCol] = true;

    finished = false;
}

void Pathfinding::stepBFS(std::vector<std::vector<int>>& grid)
{
    if (q.empty() || finished) return;

    auto current = q.front();
    q.pop();

    int r = current.first;
    int c = current.second;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols)
        {
            if (!visited[nr][nc] && grid[nr][nc] != 1)
            {
                visited[nr][nc] = true;

                if (grid[nr][nc] != 3) // don't overwrite end
                    grid[nr][nc] = 4;

                q.push({nr, nc});
            }
        }
    }
}