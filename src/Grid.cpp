#include "Grid.h"

Grid::Grid(int rows, int cols, int cellSize)
{
    this->rows = rows;
    this->cols = cols;
    this->cellSize = cellSize;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            grid[i][j] = 0;
}

void Grid::handleMouse(sf::RenderWindow& window)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        auto pos = sf::Mouse::getPosition(window);

        int col = pos.x / cellSize;
        int row = pos.y / cellSize;

        if (row >= 0 && row < rows && col >= 0 && col < cols)
        {
            grid[row][col] = 1;
        }
    }
}

void Grid::draw(sf::RenderWindow& window)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sf::RectangleShape cell(sf::Vector2f(cellSize - 1, cellSize - 1));
            cell.setPosition(sf::Vector2f(j * cellSize, i * cellSize));

            if (grid[i][j] == 1)
                cell.setFillColor(sf::Color::Black);
            else
                cell.setFillColor(sf::Color::White);

            window.draw(cell);
        }
    }
}