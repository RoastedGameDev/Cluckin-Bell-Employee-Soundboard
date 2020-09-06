#include <SDL.h>
#include <SDL_image.h>
#include <windows.h>
#include "title.h"
#include "menu.h"
#include "SDL_FontCache.h"

void update(SDL_Renderer *renderer,title &headline,menu &soundboard);
bool spawnQuitBtn(SDL_Renderer *renderer,FC_Font *quitBtn,bool &isPrompted,int height,int vert);

int main(int argc,char** args)
{
    int dHeight;
    int dVert;
    RECT desktop;
    const HWND dhDesktop=GetDesktopWindow();
    GetWindowRect(dhDesktop,&desktop);
    dHeight=desktop.right;
    dVert=desktop.bottom;
    bool appLoop=true;
    bool isPrompted=false;
    FC_Font *quitBtn=FC_CreateFont();
    title headline;
    menu soundboard;
    headline.height=dHeight;
    headline.vert=dVert;
    soundboard.height=dHeight;
    soundboard.vert=dVert;
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    SDL_Window *win;
    win=SDL_CreateWindow("GTA Soundboards",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,dHeight,dVert,SDL_WINDOW_FULLSCREEN_DESKTOP);
    SDL_Renderer *renderer=SDL_CreateRenderer(win,-1,0);
    headline.init(renderer);
    soundboard.init(renderer);
    FC_LoadFont(quitBtn,renderer,"Walkway_SemiBold.ttf",((dHeight*0.013)+(dVert*0.023)),FC_MakeColor(255,255,0,255),TTF_STYLE_NORMAL);
    while(appLoop==true)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            if(event.type==SDL_QUIT)
            {
                SDL_DestroyWindow(win);
                SDL_Quit();
            }
        }
        SDL_SetRenderDrawColor(renderer,0,0,0,0);
        SDL_RenderClear(renderer);
        update(renderer,headline,soundboard);
        appLoop=spawnQuitBtn(renderer,quitBtn,isPrompted,dHeight,dVert);
        SDL_RenderPresent(renderer);//only call once
    }
    FC_FreeFont(quitBtn);
    headline.destroyTitleTxt();
    headline.destroyInstructions();
    headline.destroyImages();
    soundboard.freeMenuTxt();
    soundboard.freeMenuTextures();
    return 0;
}

void update(SDL_Renderer *renderer,title &headline,menu &soundboard)
{
    headline.spawnText(renderer);
    headline.spawnInstructions(renderer);
    headline.spawnImages(renderer);
    soundboard.spawnPlayBtns(renderer);
}

bool spawnQuitBtn(SDL_Renderer *renderer,FC_Font *quitBtn,bool &isPrompted,int height,int vert)
{
    int checkX;
    int checkY;
    if(isPrompted==true)
    {
        FC_LoadFont(quitBtn,renderer,"Walkway_SemiBold.ttf",((height*0.013)+(vert*0.023)),FC_MakeColor(150,150,150,255),TTF_STYLE_NORMAL);
        FC_Draw(quitBtn,renderer,height*0.78,vert*0.83,"Exit");
        FC_LoadFont(quitBtn,renderer,"Walkway_SemiBold.ttf",((height*0.013)+(vert*0.023)),FC_MakeColor(255,255,0,255),TTF_STYLE_NORMAL);
        FC_Draw(quitBtn,renderer,height*0.83,vert*0.83,"Are you sure?");
        FC_Draw(quitBtn,renderer,height*0.83,vert*0.88,"Yes");
        FC_Draw(quitBtn,renderer,height*0.94,vert*0.88,"No");
        if(SDL_GetMouseState(&checkX,&checkY)&&GetKeyState(VK_LBUTTON)&&checkX>=height*0.94&&checkX<=(height*0.94)+(height*0.03)&&checkY>=vert*0.88&&checkY<=(vert*0.88)+(vert*0.05))
            isPrompted=false;
        else if(SDL_GetMouseState(&checkX,&checkY)&&GetKeyState(VK_LBUTTON)&&checkX>=height*0.83&&checkX<=(height*0.83)+(height*0.04)&&checkY>=vert*0.88&&checkY<=(vert*0.88)+(vert*0.05))
            return false;
    }
    else
        FC_Draw(quitBtn,renderer,height*0.78,vert*0.83,"Exit");
    if(SDL_GetMouseState(&checkX,&checkY)&&GetKeyState(VK_LBUTTON)&&checkX>=height*0.78&&checkX<=(height*0.78)+(height*0.04)&&checkY>=vert*0.83&&checkY<=(vert*0.83)+(vert*0.05))
        isPrompted=true;
    return true;
}
