#ifndef TITLE_H
#define TITLE_H
#include <SDL_image.h>
#include "SDL_FontCache.h"


class title
{
    public:
        title();
        int height;
        int vert;
        void init(SDL_Renderer *fromMain);
        void spawnText(SDL_Renderer *fromMain);
        void spawnImages(SDL_Renderer *fromMain);
        void destroyTitleTxt();
        void destroyInstructions();
        void spawnInstructions(SDL_Renderer *fromMain);
        void destroyImages();
        virtual ~title();

    private:
        FC_Font* titleTxt;
        FC_Font* instructionTxt;
        SDL_Texture* bellImg;
        SDL_Texture* guyImg;
        SDL_Texture* memeImg;
        SDL_Rect imageCasts[3];
        int blendR=0;
        int blendG=0;
        int blendB=255;
};

#endif // TITLE_H
