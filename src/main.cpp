#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "Pathfinding.h"
#include <iostream>

int main()
{ 
    Pathfinding pathfinder;
    const int ROWS = 20;
    const int COLS = 20;
    const int CELL_SIZE = 30;

    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(COLS * CELL_SIZE, ROWS * CELL_SIZE)), "Pathfinding Visualizer");

    Grid grid(ROWS, COLS, CELL_SIZE);  // shift grid down

 // ================= FONT =================
    sf::Font font;
    if (!font.openFromFile("C:/Windows/Fonts/arial.ttf"))
    {
        std::cout << "Font failed\n";
        return -1;
    }

    // ================= TEXT =================
    sf::Text instructions(font);
    instructions.setCharacterSize(18);
    instructions.setFillColor(sf::Color::Green);
    instructions.setPosition(sf::Vector2f(460.f, 20.f));

    instructions.setString(
        "S + Click: Start\n"
        "E + Click: End\n"
        "Left Click: Wall\n"
        "Space: BFS/A*\n"
        "R: Reset"
    );

    // ================= PANEL =================
    sf::RectangleShape panel;
    panel.setSize(sf::Vector2f(230.f, 140.f));
    panel.setFillColor(sf::Color(0, 0, 0, 200));
    panel.setPosition(sf::Vector2f(450.f, 10.f));

    panel.setOutlineThickness(2);
    panel.setOutlineColor(sf::Color::White);

    

    bool bfsStarted = false;

    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        grid.handleMouse(window);


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
           pathfinder.stepAStar(grid.getGrid());

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
            pathfinder.startAStar(grid.getGrid(), sr, sc, er, ec);
            bfsStarted = true;
        }
    }
}

       window.clear();

grid.draw(window);

window.draw(panel);         // 🔥 ADD THIS
window.draw(instructions);  // already there

window.display();
    }

    return 0;
}




