#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class Painter
{
public:
	static void DrawBoard(sf::RenderWindow& window, std::string fenString);
private:
	static std::array<std::string, 8> GetBoardAsChars2D(std::string fenString);
	static std::string ReplaceNumberWithBlanks(std::string fenRow);
};

