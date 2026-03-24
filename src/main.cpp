#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    std::cout << "Program started\n";

    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(800, 600)), "Pathfinding Visualizer");

    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.display();
    }

    return 0;
}