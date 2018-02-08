#include <SDL_image.h>
#include <SDL_mixer.h>
#include <string>
#include <iostream>
#include <vector>

#define SCREEN_WIDTH 1400
#define SCREEN_HEIGHT 800
#define FPS 60
SDL_Window* gWindow = NULL;
//The window renderer
SDL_Renderer* gRenderer = NULL;
//Current displayed texture
SDL_Texture* gTexture = NULL;

unsigned int lastTime = 0, currentTime, deltaTime;
float msFrame = 1 / (FPS / 1000.0f);

//Loads individual image as texture
SDL_Texture* loadTexture(std::string path);
bool loadMedia();
void close();





int main(int argc, char* args[]) {
	SDL_Rect rollito;
	rollito.h = 600/2;
	rollito.w = 800/2;
	rollito.x = 0;
	rollito.y = 0;
	SDL_Rect Voltereta;
	Voltereta.h = 600;
	Voltereta.w = 800;
	Voltereta.x = 500;
	Voltereta.y = 500;
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Surface* screenSurface = NULL;
	bool quit = false;
	bool success;
	int angle = 0;
	SDL_Event tecla;
	gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (gWindow == NULL)
	{
		printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create renderer for window
		gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (gRenderer == NULL)
		{
			printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Initialize renderer color
			SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
				success = false;
			}
		}
	}
	loadMedia();
		do
		{
			int	move = 0;
			int movey = 0;
			SDL_PollEvent(&tecla);
			switch (tecla.type) {
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_KEYDOWN:
				switch (tecla.key.keysym.sym) {
				case SDLK_ESCAPE:
					quit = true;
					break;
				}
			default:
				break;
			}

			angle++;
			////////FPS/////////
			currentTime = SDL_GetTicks();
			deltaTime = currentTime - lastTime;
			lastTime = SDL_GetTicks();
			////////////////////
			const Uint8 *keystate = SDL_GetKeyboardState(NULL);
			if (keystate[SDL_SCANCODE_LEFT]) {
				move = -2;
			}
			if (keystate[SDL_SCANCODE_RIGHT]) {
				move = 2;
			}
			if (keystate[SDL_SCANCODE_UP]) {
				movey = -2;
			}
			if (keystate[SDL_SCANCODE_DOWN]) {
				movey = 2;
			}
			//SDL_SCANCODE_A


			rollito.x += move;
			rollito.y += movey;
			//Clear screen
			SDL_RenderClear(gRenderer);

			//Render texture to screen
			SDL_RenderCopy(gRenderer, gTexture, NULL, &rollito);
			SDL_RenderCopyEx(gRenderer, gTexture, NULL, &Voltereta, angle, NULL, SDL_FLIP_VERTICAL);

			//Update screen
			SDL_RenderPresent(gRenderer);
		} while (!quit);

		close();
		return 0;
}

	SDL_Texture* loadTexture(std::string path){
		//The final texture
		SDL_Texture* newTexture = NULL;

		//Load image at specified path
		SDL_Surface* loadedSurface = IMG_Load(path.c_str());
		if (loadedSurface == NULL)
		{
			printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
		}
		else
		{
			//Create texture from surface pixels
			newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
			if (newTexture == NULL)
			{
				printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
			}

			//Get rid of old loaded surface
			SDL_FreeSurface(loadedSurface);
		}

		return newTexture;
	
	
	}
	bool loadMedia()
	{
		//Loading success flag
		bool success = true;

		//Load PNG texture
		gTexture = loadTexture("images/gato.jpg");
		if (gTexture == NULL)
		{
			printf("Failed to load texture image!\n");
			success = false;
		}


		return success;
	}

	void close(){
		//Free loaded image
		SDL_DestroyTexture(gTexture);
		gTexture = NULL;

		//Destroy window    
		SDL_DestroyRenderer(gRenderer);
		SDL_DestroyWindow(gWindow);
		gWindow = NULL;
		gRenderer = NULL;

		//Quit SDL subsystems
		IMG_Quit();
		SDL_Quit();
	}
