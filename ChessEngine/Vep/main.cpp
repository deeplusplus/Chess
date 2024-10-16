#include <SFML/Graphics.hpp>
#include <Painter.h>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "VEO", sf::Style::Close | sf::Style::Close);
 
    window.setVerticalSyncEnabled(true);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    Painter::TurnClickIntoBoardPosition(event.mouseButton.x, event.mouseButton.y);
                    //std::cout << "the left button was pressed" << std::endl;
                    //std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    //std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                }
                break;
            case sf::Event::MouseMoved:
                //std::cout << "new mouse x: " << event.mouseMove.x << std::endl;
                //std::cout << "new mouse y: " << event.mouseMove.y << std::endl;
                break;
            case sf::Event::MouseLeft:
                std::cout << "Mouse left" << std::endl;
                break;
            case sf::Event::MouseEntered:
                std::cout << "Mouse entered" << std::endl;
                break;
            case sf::Event::KeyPressed:
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    window.close();
                }
                break;
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
            }
        }

        Painter::DrawBoard(window, "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    }
    return 0;
}