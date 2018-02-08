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

	gWindow = SDL_CreateWindow("Entorns", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);


	SDL_Quit();

	return 0;
}