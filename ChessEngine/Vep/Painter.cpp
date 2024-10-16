#include "Painter.h"
#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <sstream>

const int Painter::BoardXOffset = 180;
const int Painter::BoardYOffset = 75;
const float Painter::SpaceSize = 60.f;

void Painter::DrawBoard(sf::RenderWindow& window, std::string fenString)
{
    std::array<std::string, 8> boardMatrix = GetBoardAsChars2D(fenString);

    sf::Color whiteColor = sf::Color(245, 222, 179);
    sf::Color blackColor = sf::Color(139, 69, 19);

    sf::Texture whitePawnTexture;
    whitePawnTexture.loadFromFile("whitePawn.png");

    sf::Texture whiteRookTexture;
    whiteRookTexture.loadFromFile("whiteRook.png");

    sf::Texture whiteKnightTexture;
    whiteKnightTexture.loadFromFile("whiteKnight.png");

    sf::Texture whiteBishopTexture;
    whiteBishopTexture.loadFromFile("whiteBishop.png");

    sf::Texture whiteKingTexture;
    whiteKingTexture.loadFromFile("whiteKing.png");

    sf::Texture whiteQueenTexture;
    whiteQueenTexture.loadFromFile("whiteQueen.png");

    sf::Texture blackPawnTexture;
    blackPawnTexture.loadFromFile("blackPawn.png");

    sf::Texture blackRookTexture;
    blackRookTexture.loadFromFile("blackRook.png");

    sf::Texture blackKnightTexture;
    blackKnightTexture.loadFromFile("blackKnight.png");

    sf::Texture blackBishopTexture;
    blackBishopTexture.loadFromFile("blackBishop.png");

    sf::Texture blackKingTexture;
    blackKingTexture.loadFromFile("blackKing.png");

    sf::Texture blackQueenTexture;
    blackQueenTexture.loadFromFile("blackQueen.png");

    window.clear(sf::Color(222, 184, 135));

    for (int column = 0; column <= 7; column++)
    {
        for (int row = 0; row <= 7; row++)
        {
            sf::RectangleShape space = sf::RectangleShape(sf::Vector2f(SpaceSize, SpaceSize));
            space.setPosition(BoardXOffset + (column * SpaceSize), BoardYOffset + (row * SpaceSize));
            (column + row) % 2 == 0 ? space.setFillColor(whiteColor) : space.setFillColor(blackColor);
            window.draw(space);

            sf::Sprite whitePawnSprite;
            sf::Sprite whiteRookSprite;
            sf::Sprite whiteKnightSprite;
            sf::Sprite whiteBishopSprite;
            sf::Sprite whiteKingSprite;
            sf::Sprite whiteQueenSprite;
            sf::Sprite blackPawnSprite;
            sf::Sprite blackRookSprite;
            sf::Sprite blackKnightSprite;
            sf::Sprite blackBishopSprite;
            sf::Sprite blackKingSprite;
            sf::Sprite blackQueenSprite;

            switch (boardMatrix[row][column])
            {
            case 'P':
                whitePawnSprite.setTexture(whitePawnTexture);
                whitePawnSprite.setPosition(BoardXOffset + (column * SpaceSize), (BoardYOffset + 5) + (row * SpaceSize));
                window.draw(whitePawnSprite);
                break;
            case 'R':
                whiteRookSprite.setTexture(whiteRookTexture);
                whiteRookSprite.setPosition(BoardXOffset + (column * SpaceSize), (BoardYOffset + 5) + (row * SpaceSize));
                window.draw(whiteRookSprite);
                break;
            case 'N':
                whiteKnightSprite.setTexture(whiteKnightTexture);
                whiteKnightSprite.setPosition(BoardXOffset + (column * SpaceSize), (BoardYOffset + 5) + (row * SpaceSize));
                window.draw(whiteKnightSprite);
                break;
            case 'B':
                whiteBishopSprite.setTexture(whiteBishopTexture);
                whiteBishopSprite.setPosition(BoardXOffset + (column * SpaceSize), (BoardYOffset + 5) + (row * SpaceSize));
                window.draw(whiteBishopSprite);
                break;
            case 'K':
                whiteKingSprite.setTexture(whiteKingTexture);
                whiteKingSprite.setPosition(BoardXOffset + (column * SpaceSize), (BoardYOffset + 5) + (row * SpaceSize));
                window.draw(whiteKingSprite);
                break;
            case 'Q':
                whiteQueenSprite.setTexture(whiteQueenTexture);
                whiteQueenSprite.setPosition(BoardXOffset + (column * SpaceSize), (BoardYOffset + 5) + (row * SpaceSize));
                window.draw(whiteQueenSprite);
                break;
            case 'p':
                blackPawnSprite.setTexture(blackPawnTexture);
                blackPawnSprite.setPosition(BoardXOffset + (column * SpaceSize), (BoardYOffset + 5) + (row * SpaceSize));
                window.draw(blackPawnSprite);
                break;
            case 'r':
                blackRookSprite.setTexture(blackRookTexture);
                blackRookSprite.setPosition(BoardXOffset + (column * SpaceSize), (BoardYOffset + 5) + (row * SpaceSize));
                window.draw(blackRookSprite);
                break;
            case 'n':
                blackKnightSprite.setTexture(blackKnightTexture);
                blackKnightSprite.setPosition(BoardXOffset + (column * SpaceSize), (BoardYOffset + 5) + (row * SpaceSize));
                window.draw(blackKnightSprite);
                break;
            case 'b':
                blackBishopSprite.setTexture(blackBishopTexture);
                blackBishopSprite.setPosition(BoardXOffset + (column * SpaceSize), (BoardYOffset + 5) + (row * SpaceSize));
                window.draw(blackBishopSprite);
                break;
            case 'k':
                blackKingSprite.setTexture(blackKingTexture);
                blackKingSprite.setPosition(BoardXOffset + (column * SpaceSize), (BoardYOffset + 5) + (row * SpaceSize));
                window.draw(blackKingSprite);
                break;
            case 'q':
                blackQueenSprite.setTexture(blackQueenTexture);
                blackQueenSprite.setPosition(BoardXOffset + (column * SpaceSize), (BoardYOffset + 5) + (row * SpaceSize));
                window.draw(blackQueenSprite);
                break;
            default:
                break;
            }



        }
    }

    

    window.display();
}

std::string Painter::TurnClickIntoBoardPosition(int x, int y)
{
    std::array<char, 8> rows = { '8', '7', '6', '5', '4', '3', '2', '1'};
    std::array<char, 8> columns = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
    std::string clickedRow;
    std::string clickedColumn;

    for (int row = 0; row <= 7; row++)
    {
        if (x >( BoardXOffset + (row * SpaceSize))) {
            clickedRow = rows[row];
        }
    }

    for (int column = 0; column <= 7; column++)
    {
        if (y > (BoardYOffset + (column * SpaceSize))) {
            clickedColumn = columns[column];
        }
    }

    std::string result = clickedColumn + clickedRow;
    std::cout << result << std::endl;
    return result;
};

std::array<std::string, 8> Painter::GetBoardAsChars2D(std::string fenString)
{
    std::array<std::string, 8> board;

    std::stringstream stringStream(fenString);
    std::string segment;
    std::vector<std::string> seglist;

    while (std::getline(stringStream, segment, '/'))
    {
        seglist.push_back(segment);
    }

    for (int row = 0; row <= 7; row++)
    {
        std::string fenRow = seglist[row];
        board[row] = ReplaceNumberWithBlanks(fenRow);
    }

    return board;
};

std::string Painter::ReplaceNumberWithBlanks(std::string fenRow)
{
    std::string newFenRow;

    for (size_t character = 0; character < fenRow.size(); character++)
    {
        switch (fenRow[character])
        {
        case('1'):
            newFenRow += "_";
            break;
        case('2'):
            newFenRow += "__";
            break;
        case('3'):
            newFenRow += "___";
            break;
        case('4'):
            newFenRow += "____";
            break;
        case('5'):
            newFenRow += "_____";
            break;
        case('6'):
            newFenRow += "_______";
            break;
        case('7'):
            newFenRow += "_______";
            break;
        case('8'):
            newFenRow += "________";
            break;
        default:
            newFenRow += fenRow[character];
        }
    }

    return newFenRow;
}