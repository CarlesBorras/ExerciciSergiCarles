#include <SDL.h>
#include <iostream>
#include <vector>

using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* gWindow = NULL;
//The window renderer
SDL_Renderer* gRenderer = NULL;
//Current displayed texture
SDL_Texture* gTexture = NULL;


int main(int argc, char* args[]) {

	SDL_Init(SDL_INIT_EVERYTHING);

	//variables
	
	bool exit = false;

	//
	gWindow = SDL_CreateWindow("Entorns", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	gRenderer = SDL_CreateRenderer(gWindow, -1, 0);

	SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 0);

	SDL_RenderClear(gRenderer);
	
	SDL_RenderPresent(gRenderer);

	while (!exit)
	{

		SDL_Event test_event;
		SDL_Scancode tecla;

		while (SDL_PollEvent(&test_event)) {
			switch (test_event.type) {
			case SDL_KEYDOWN:
				
				tecla = test_event.key.keysym.scancode;
				
				if (tecla == SDL_SCANCODE_1) {
					//funcio
				}

				if (tecla == SDL_SCANCODE_2) {
					//funcio
				}

				if (tecla == SDL_SCANCODE_ESCAPE) {
					exit = true;
				}

				break;

			case SDL_QUIT:
				exit = true;
				break;
			}
		}


	}


	SDL_Quit();

	system("pause");

	

	return 0;
}