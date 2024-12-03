#pragma once

#include <bits/stdc++.h>

#include "SDL.h"
#include "SDL_image.h"

namespace mineNs {

    std::vector<SDL_Texture*> mineTextures;
    void loadTextures(SDL_Renderer** targetRenderer, std::vector<std::string> texturePaths) {
        for (std::string &texturePath : texturePaths) {
            texturePath = "res/" + texturePath;
            mineTextures.push_back(IMG_LoadTexture(*targetRenderer, texturePath.c_str()));
        }
    }

}