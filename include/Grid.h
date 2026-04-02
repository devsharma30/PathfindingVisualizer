#pragma once
#include <SFML/Graphics.hpp>

class Grid
{
public:
    Grid(int rows, int cols, int cellSize);

    void handleMouse(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);

private:
    int rows, cols, cellSize;
    int grid[50][50]; // max size
    // to remember start and end node
    int startRow = -1, startCol = -1;
    int endRow = -1, endCol = -1;

};