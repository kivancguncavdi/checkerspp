#include <iostream>
#include "SDL_Handler.hpp"
#include "common.hpp"

using namespace std;

Window::Window()
{
	if (m_fullscreen) {
		m_flags = m_flags | SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) != R_OK)
	{
		cout << "SDL initialization failed: " << SDL_GetError() << endl;
	}
	else
	{
		std::cout << "Subsystems Initialized!\n";

		m_window = SDL_CreateWindow("Checkers++", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, m_flags);
		if (m_window) {
			std::cout << "Window Created!\n";
			SDL_SetWindowMinimumSize(m_window, MINIMUM_WINDOW_WIDTH, MINIMUM_HEIGHT_WIDTH);
		}
	}
}

Renderer::Renderer(SDL_Window* window)
{
	m_renderer = SDL_CreateRenderer(window, -1, 0);
	if (m_renderer) {
		SDL_SetRenderDrawColor(m_renderer, 1, 1, 1, 255);
		std::cout << "Renderer created!\n";
		SDL_SetRenderDrawBlendMode(m_renderer, SDL_BLENDMODE_BLEND);
		//m_isRunning = true;
	}
}

Window::~Window()
{
	SDL_DestroyWindow(m_window);	//error here
	SDL_Quit();
}

Renderer::~Renderer()
{
	//frees memory associated with renderer and window
	SDL_DestroyRenderer(m_renderer);
}