#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class Grid
{
public:
    Grid(int rows, int cols, int cellSize);

    void handleMouse(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);

    std::vector<std::vector<int>>& getGrid();
    int getStartRow();
    int getStartCol();
    int getEndRow();
    int getEndCol();

private:
    int rows, cols, cellSize;
    std::vector<std::vector<int>> grid;
    // to remember start and end node
    int startRow = -1, startCol = -1;
    int endRow = -1, endCol = -1;

};