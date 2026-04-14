#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "Pathfinding.h"
#include <iostream>
#include <sstream>
#include <iomanip>
bool keyPressedToggle = false;

int main()
{ 
    Pathfinding pathfinder;
    const int ROWS = 20;
    const int COLS = 20;
    const int CELL_SIZE = 30;

    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(COLS * CELL_SIZE, ROWS * CELL_SIZE)), "Pathfinding Visualizer");

    Grid grid(ROWS, COLS, CELL_SIZE);  // shift grid down
    float delay = 0.05f;
sf::Clock clock;

 // ================= FONT =================
    sf::Font font;
    if (!font.openFromFile("C:/Windows/Fonts/arial.ttf"))
    {
        std::cout << "Font failed\n";
        return -1;
    }

    // ================= TEXT =================
    sf::Text instructions(font);
    sf::Text statusText(font);
statusText.setCharacterSize(16);
statusText.setFillColor(sf::Color::Green);
statusText.setPosition(sf::Vector2f(460.f, 160.f));
    instructions.setCharacterSize(18);
    instructions.setFillColor(sf::Color::Green);
    instructions.setPosition(sf::Vector2f(460.f, 20.f));

    instructions.setString(
        "S + Click: Start\n"
        "E + Click: End\n"
        "Left Click: Wall\n"
        "Space: Run\n"
        "1:BFS | 2: A*\n"
        "UP/DOWN: speed\n"
        "R: Reset"
    );

    // ================= PANEL =================
    sf::RectangleShape panel;
    panel.setSize(sf::Vector2f(230.f, 195.f));
    panel.setFillColor(sf::Color(0, 0, 0, 200));
    panel.setPosition(sf::Vector2f(450.f, 10.f));

    panel.setOutlineThickness(2);
    panel.setOutlineColor(sf::Color::White);

    

    bool bfsStarted = false;
    bool useAStar = true;  // true = A*, false = BFS

    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1))
{
    if (!keyPressedToggle)
    {
        useAStar = false;
        grid.clearPath();
        bfsStarted = false;  // reset algorithm
        keyPressedToggle = true;
    }
}
else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2))
{
    if (!keyPressedToggle)
    {
        useAStar = true;
        grid.clearPath();
        bfsStarted = false;
        keyPressedToggle = true;
    }
}
else
{
    keyPressedToggle = false;
}
 

if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
{
    delay -= 0.001f;
    if (delay < 0.001f) delay = 0.001f;
}

if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
{
    delay += 0.001f;
    if (delay > 0.3f) delay = 0.3f;
}


        grid.handleMouse(window);
        std::string mode = useAStar ? "A*" : "BFS";

statusText.setString(
    "Mode: " + mode + "\n" +
    "Speed: " + std::to_string((int)(delay * 1000))
);


        static bool keyPressed = false;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
                  {
                      if (!keyPressed)
                        {
                            grid.reset();
                            bfsStarted = false;
                            keyPressed = true;
                        }
                 
                    else
                        {
                           keyPressed = false;
                        } 

                    }
      if (bfsStarted)
{
    if (clock.getElapsedTime().asSeconds() > delay)
    {
        if (useAStar)
            pathfinder.stepAStar(grid.getGrid());
        else
            pathfinder.stepBFS(grid.getGrid());

        clock.restart();
    }

    if (pathfinder.isFinished())
    {
        pathfinder.drawPath(grid.getGrid());
        bfsStarted = false;
    }
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
            if (useAStar)
{
    pathfinder.startAStar(grid.getGrid(), sr, sc, er, ec);
}
else
{
    pathfinder.startBFS(grid.getGrid(), sr, sc, er, ec);
}
            bfsStarted = true;
        }
    }
}

       window.clear();

grid.draw(window);

window.draw(panel);        
window.draw(instructions);
window.draw(statusText);  

window.display();
    }

    return 0;
}




