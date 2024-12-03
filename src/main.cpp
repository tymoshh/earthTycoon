#include <bits/stdc++.h>

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"

#include "filemgr.hpp"

#include "mineHeader.hpp"

using namespace std;

int main(int argc, char *argv[]) {

    // load config
    filemgr::loadConfig("config.toml");

    // window parameters
    const string WINDOW_TITLE = filemgr::getStr({"window", "title"});
    const int WINDOW_WIDTH = filemgr::getInt({"window", "width"});
    const int WINDOW_HEIGHT = filemgr::getInt({"window", "height"});

    // fps cap stuff
    const int MAX_FPS = filemgr::getInt({"window", "fps"});
    const int FRAME_DELAY = 1000 / MAX_FPS;
    Uint32 FRAME_START;
    int FRAME_TIME;

    // init
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    Mix_Init(MIX_INIT_MP3); Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096);

    // create window
    SDL_Window* myWindow = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    // create renderer
    SDL_Renderer* myRenderer = SDL_CreateRenderer(myWindow, -1, 0);
    // event manager
    SDL_Event myEvent;

    // loading textures
    vector<int> x = filemgr::getIntVec({"textures", "mine"});

    cout << WINDOW_TITLE << endl;
    cout << WINDOW_WIDTH  << "x" << WINDOW_HEIGHT << endl;

    return 0;

}
