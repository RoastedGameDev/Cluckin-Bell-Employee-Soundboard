#include "title.h"

title::title()
{
    //ctor
}

title::~title()
{
    //dtor
}

void title::init(SDL_Renderer *fromMain)
{
    titleTxt=FC_CreateFont();
    instructionTxt=FC_CreateFont();
    FC_LoadFont(titleTxt,fromMain,"Walkway_Oblique.ttf",((height*0.022)+(vert*0.04)),FC_MakeColor(255,255,0,255),TTF_STYLE_NORMAL);
    FC_LoadFont(instructionTxt,fromMain,"Walkway_SemiBold.ttf",((height*0.013)+(vert*0.023)),FC_MakeColor(blendR,blendG,blendB,255),TTF_STYLE_NORMAL);
    SDL_Surface* intermediate=IMG_Load("Bell.png");
    bellImg=SDL_CreateTextureFromSurface(fromMain,intermediate);
    intermediate=IMG_Load("meme.png");
    memeImg=SDL_CreateTextureFromSurface(fromMain,intermediate);
    intermediate=IMG_Load("SadGuy.jpg");
    guyImg=SDL_CreateTextureFromSurface(fromMain,intermediate);
    SDL_FreeSurface(intermediate);
    imageCasts[0].x=height*0.005;
    imageCasts[0].y=vert*0.05;
    imageCasts[0].w=height*0.21;
    imageCasts[0].h=vert*0.37;
    imageCasts[1].x=height*0.80;
    imageCasts[1].y=vert*0.05;
    imageCasts[1].w=height*0.21;
    imageCasts[1].h=vert*0.37;
    imageCasts[2].x=height*0.80;
    imageCasts[2].y=vert*0.43;
    imageCasts[2].w=height*0.21;
    imageCasts[2].h=vert*0.37;
}

void title::spawnText(SDL_Renderer *fromMain)
{
    FC_Draw(titleTxt,fromMain,height*0.21,vert*0.03,"Cluckin' Bell Wage Slave");
}

void title::spawnImages(SDL_Renderer *fromMain)
{
    SDL_RenderCopy(fromMain,bellImg,NULL,&imageCasts[0]);
    SDL_RenderCopy(fromMain,guyImg,NULL,&imageCasts[1]);
    SDL_RenderCopy(fromMain,memeImg,NULL,&imageCasts[2]);
}

void title::destroyTitleTxt()
{
    FC_FreeFont(titleTxt);
}

void title::destroyInstructions()
{
    FC_FreeFont(instructionTxt);
}

void title::spawnInstructions(SDL_Renderer *fromMain)
{
    FC_LoadFont(instructionTxt,fromMain,"Walkway_SemiBold.ttf",((height*0.013)+(vert*0.023)),FC_MakeColor(blendR,blendG,blendB,255),TTF_STYLE_NORMAL);
    FC_Draw(instructionTxt,fromMain,height*0.214,vert*0.15,"Press space to stop lines");
    if(blendG>255)
        blendG=255;
    if(blendR>255)
        blendR=255;
    if(blendB>255)
        blendB=255;
    if(blendB==255&&blendR==0)
        blendG++;
    if(blendG==255)
    {
        blendB--;
        blendR++;
    }
    if(blendR==255)
    {
        if(blendG==0)
            blendG=1;
        blendG--;
    }
    if(blendG==0&&blendR==255)
        blendB++;
    if(blendB==255&&blendG==0)
        blendR--;
}

void title::destroyImages()
{
    SDL_DestroyTexture(bellImg);
    SDL_DestroyTexture(guyImg);
    SDL_DestroyTexture(memeImg);
}
