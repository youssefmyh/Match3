#include "Sdl.h"

#include <sdl/SDL.h>
#include <stdexcept>

namespace King {
	Sdl::Sdl(int flags) {
		if (SDL_Init(flags) != 0) {
			throw std::runtime_error("Failed to init SDL");
		}
	}
	Sdl::~Sdl() {
		SDL_Quit();
	}
}