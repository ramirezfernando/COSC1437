#include "Game.h"
#include "Textures.h"
#include "Character.h"
#include "Background.h"

Character* player;
//Character* enemy;
Background* forest;

// we haven't initialized SDL yet
SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;


Game::Game()
{

}
Game::~Game()
{

}
void Game::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen == true)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) 
    {
        cout << "Initializing" << endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags); 
        if (window)
        {
            cout << "Window created" << endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            cout << "Renderer created" << endl;
        }
        isRunning = true;
    } 
    else 
    {
        isRunning = false;
    }
    // Choose your character screen

    // Duel screen
        // run forest background
    forest = new Background("assets/forest.png", 0, 0);
        // run players
    //player = new Character("assets/player.png", -80, 20);

    player = new Character("assets/GroundMonk/4_sp_atk", 25, 100, -80, 20);
    //enemy = new Character("assets/player.png", 340, 20);
}
void Game::HandleEvents()
{
    SDL_PollEvent(&event);

    switch (event.type)
    {
        case SDL_QUIT:
            isRunning = false;        
            break;
        case SDL_MOUSEBUTTONDOWN: // && click in a certain box, testing right now
            isRunning = false;
            break;
        default:
            break;
    }

}
void Game::Update()
{
    forest->Update();
    player->Update();
    //enemy->Update();
}
void Game::Render()
{
    SDL_RenderClear(renderer);
    // This is where to add stuff to render, 
    forest->Render();
    player->Render();
    //enemy->Render();
    //
    SDL_RenderPresent(renderer);
}
void Game::Clean()
{
    // add destructors for character and background


    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Game cleaned" << endl;
}
bool Game::Running()
{
    return isRunning;
}