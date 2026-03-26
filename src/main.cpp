#include <SFML/Graphics.hpp>

int main()
{
    const int ROWS = 20;
    const int COLS = 20;
    const int CELL_SIZE = 30;

    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(COLS * CELL_SIZE, ROWS * CELL_SIZE)), "Pathfinding Visualizer");

    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();

        // DRAW GRID
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                sf::RectangleShape cell(sf::Vector2f(CELL_SIZE - 1, CELL_SIZE - 1));

                cell.setPosition(sf::Vector2f(j * CELL_SIZE, i * CELL_SIZE));
                cell.setFillColor(sf::Color::White);

                window.draw(cell);
            }
        }

        window.display();
    }

    return 0;
}