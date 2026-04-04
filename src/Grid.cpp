#include "Grid.h"

Grid::Grid(int rows, int cols, int cellSize)
{
    this->rows = rows;
    this->cols = cols;
    this->cellSize = cellSize;

    visited = std::vector<std::vector<bool>>(rows, std::vector<bool>(cols, false));
    grid = std::vector<std::vector<int>>(rows, std::vector<int>(cols, 0));
}


// we change it to give function or instruction to add start node and end node using some functions.
void Grid::handleMouse(sf::RenderWindow& window)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        auto pos = sf::Mouse::getPosition(window);

        int col = pos.x / cellSize;
        int row = pos.y / cellSize;

        // Check inside grid
        if (row >= 0 && row < rows && col >= 0 && col < cols)
        {
            // 🟢 START NODE (Press S)
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            {
                // Remove old start
                if (startRow != -1)
                {
                    grid[startRow][startCol] = 0;
                }

                startRow = row;
                startCol = col;
                grid[row][col] = 2;
            }

            // 🔴 END NODE (Press E)
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E))
            {
                if (endRow != -1)
                {
                    grid[endRow][endCol] = 0;
                }

                endRow = row;
                endCol = col;
                grid[row][col] = 3;
            }

            // ⬛ WALL
            else
            {
                if (grid[row][col] == 0)
                {
                    grid[row][col] = 1;
                }
            }
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
            else if (grid[i][j] == 2)
                cell.setFillColor(sf::Color::Green);
            else if (grid[i][j] == 3)
                cell.setFillColor(sf::Color::Red);

            else if (grid[i][j] == 4)
                cell.setFillColor(sf::Color::Blue);

            else if (grid[i][j] == 5)
                cell.setFillColor(sf::Color::Yellow);    

            else
                cell.setFillColor(sf::Color::White);

            window.draw(cell);
        }
    }
}

std::vector<std::vector<int>>& Grid::getGrid()
{
    return grid;
}

int Grid::getStartRow()
{
    return startRow;
}

int Grid::getStartCol()
{
    return startCol;
}

int Grid::getEndRow()
{
    return endRow;
}

int Grid::getEndCol()
{
    return endCol;
}





void Grid::reset()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            grid[i][j] = 0; // empty
        }
    }

    startRow = startCol = -1;
    endRow = endCol = -1;
}