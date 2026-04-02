#include "Pathfinding.h"
#include <queue>
#include <vector>

void Pathfinding::bfs(std::vector<std::vector<int>>& grid,
                      int startRow, int startCol,
                      int endRow, int endCol)
{
    int rows = grid.size();
    int cols = grid[0].size();

    // visited array
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));

    std::queue<std::pair<int, int>> q;

    // start from starting node
    q.push({startRow, startCol});
    visited[startRow][startCol] = true;

    // directions (UP, DOWN, LEFT, RIGHT)
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty())
    {
        auto current = q.front();
        q.pop();

        int r = current.first;
        int c = current.second;

        // if reached end → stop
        if (r == endRow && c == endCol)
        {
            return;
        }

        // explore neighbors
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            // ✅ VERY IMPORTANT: boundary check
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols)
            {
                // if not visited and not a wall
                if (!visited[nr][nc] && grid[nr][nc] != 1)
                {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }
}