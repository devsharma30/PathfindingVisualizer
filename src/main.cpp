#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "Pathfinding.h"

int main()
{ 
    Pathfinding pathfinder;
    const int ROWS = 20;
    const int COLS = 20;
    const int CELL_SIZE = 30;

    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(COLS * CELL_SIZE, ROWS * CELL_SIZE)), "Pathfinding Visualizer");

    Grid grid(ROWS, COLS, CELL_SIZE);

    bool bfsStarted = false;

    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        grid.handleMouse(window);
        if (bfsStarted)
{
    pathfinder.stepBFS(grid.getGrid());
}

if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
{
    if (!bfsStarted)
    {
        int sr = grid.getStartRow();
        int sc = grid.getStartCol();
        int er = grid.getEndRow();
        int ec = grid.getEndCol();

        if (sr >= 0 && sc >= 0 && er >= 0 && ec >= 0)
        {
            pathfinder.startBFS(grid.getGrid(), sr, sc, er, ec);
            bfsStarted = true;
        }
    }
}

        window.clear();
        grid.draw(window);
        window.display();
    }

    return 0;
}
