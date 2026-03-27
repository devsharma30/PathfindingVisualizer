#include <SFML/Graphics.hpp>
#include "Grid.h"

int main()
{
    const int ROWS = 20;
    const int COLS = 20;
    const int CELL_SIZE = 30;

    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(COLS * CELL_SIZE, ROWS * CELL_SIZE)), "Pathfinding Visualizer");

    Grid grid(ROWS, COLS, CELL_SIZE);

    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        grid.handleMouse(window);

        window.clear();
        grid.draw(window);
        window.display();
    }

    return 0;
}