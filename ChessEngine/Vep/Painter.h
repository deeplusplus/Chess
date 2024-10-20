#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <Board.h>

class Painter
{
public:
	static void DrawBoard(sf::RenderWindow& window, Board board);
	static std::string TurnClickIntoBoardPosition(int x, int y);
private:
	static const float SpaceSize;
	static const int BoardXOffset;
	static const int BoardYOffset;
};

