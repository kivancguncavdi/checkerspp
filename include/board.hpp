#ifndef BOARD_HPP_
#define BOARD_HPP_

#include "SDL.h"
#include "color.hpp"
#include "tile.hpp"

class Board
{
public:
	Board();
	SDL_Rect getTile(int x, int y) const { return m_tiles[x][y]; };
	Color getTileColor(int x, int y) const { return m_tiles[x][y].getColor(); }
	void getTileStatus(SDL_Event event);
private:
	Tile m_tiles[8][8];
};

#endif