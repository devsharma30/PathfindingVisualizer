#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class Pathfinding
{
public:
    void bfs(std::vector<std::vector<int>>& grid,
             int startRow, int startCol,
             int endRow, int endCol);
};