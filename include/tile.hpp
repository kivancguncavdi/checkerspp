#ifndef TILE_HPP_
#define TILE_HPP_

#include "common.hpp"
#include "SDL.h"
#include "SDL_Handler.hpp"

class Tile : public SDL_Rect
{
public:
	Color getColor() const { return m_tileColor; }
	void setColor(Color tileColor) { m_tileColor = tileColor; }
	bool isClicked() const { return m_status; }
	void Clicked(int x, int y, Renderer& renderer);
	static int prevX;
	static int prevY;
	static Color prevTileColor;
private:
	Color m_tileColor;
	bool m_status;
};

#endif