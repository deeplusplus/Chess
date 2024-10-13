#include "Painter.h"


void Painter::DrawBoard(sf::RenderWindow& window)
{
    int boardUpperLeftOffsetX = 180;
    int boardUpperLeftOffsetY = 75;
    float spaceSize = 50.f;
    sf::Color whiteColor = sf::Color(255, 255, 255);
    sf::Color blackColor = sf::Color(0, 0, 0);


    window.clear(sf::Color(222, 184, 135));

    for (int row = 0; row <= 8; row++)
    {
        for (int column = 0; column <= 8; column++)
        {
            sf::RectangleShape space = sf::RectangleShape(sf::Vector2f(spaceSize, spaceSize));
            (row + column) % 2 == 0 ? space.setFillColor(whiteColor) : space.setFillColor(blackColor);
            space.setPosition(boardUpperLeftOffsetX + (row * spaceSize), boardUpperLeftOffsetY + (column * spaceSize));

            window.draw(space);
        }
    }

    window.display();
};