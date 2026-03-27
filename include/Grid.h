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
};