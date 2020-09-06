#include "menu.h"
#include <windows.h>

menu::menu()
{
    //ctor
}

menu::~menu()
{
    //dtor
}

void menu::init(SDL_Renderer *fromMain)
{
    int initX=height*0.01;
    int initY=vert*0.463;
    menuTxt=FC_CreateFont();
    FC_LoadFont(menuTxt,fromMain,"Walkway_SemiBold.ttf",((height*0.008)+(vert*0.014)),FC_MakeColor(255,255,0,255),TTF_STYLE_NORMAL);
    SDL_Surface* intermediate=IMG_Load("btnUp.png");
    btnUp=SDL_CreateTextureFromSurface(fromMain,intermediate);
    intermediate=IMG_Load("btnDown.png");
    btnDown=SDL_CreateTextureFromSurface(fromMain,intermediate);
    SDL_FreeSurface(intermediate);
    for(unsigned int i=0;i<elements;i++)
    {
        imageInstances[i].x=initX;
        imageInstances[i].y=initY;
        imageInstances[i].h=height*0.01;
        imageInstances[i].w=vert*0.019;
        initY+=vert*0.05;
        if(initY>=vert*0.97)
        {
            initY=vert*0.463;
            initX+=height*0.21;
        }
    }
}

void menu::spawnPlayBtns(SDL_Renderer *fromMain)
{
    int checkX;
    int checkY;
    std::string file;
    SDL_Rect playingBtn;
    for(unsigned int i=0;i<elements;i++)
    {
        FC_Draw(menuTxt,fromMain,imageInstances[i].x+(height*0.016),imageInstances[i].y-(vert*0.0065),quotes[i].c_str());
        SDL_RenderCopy(fromMain,btnUp,NULL,&imageInstances[i]);
        if(SDL_GetMouseState(&checkX,&checkY)&&GetKeyState(VK_LBUTTON)&&checkX>=imageInstances[i].x&&checkX<=imageInstances[i].x+(height*0.012)&&checkY>=imageInstances[i].y&&checkY<=imageInstances[i].y+(vert*0.0213))
        {
            file="sound\\CB"+std::to_string(i+1)+".wav";
            playedIndex=i;
            playingBtn.x=imageInstances[i].x;
            playingBtn.y=imageInstances[i].y;
            playingBtn.h=imageInstances[i].h;
            playingBtn.w=imageInstances[i].w;
            SDL_RenderCopy(fromMain,btnDown,NULL,&playingBtn);
            PlaySound(NULL,NULL,SND_APPLICATION);
        }
        if(i==playedIndex)
            PlaySound(&file[0],NULL,SND_FILENAME | SND_ASYNC);
    }
    if(GetAsyncKeyState(VK_SPACE))
    {
        PlaySound(NULL,NULL,SND_APPLICATION);
        playedIndex=-1;
    }
}

void menu::freeMenuTxt()
{
    FC_FreeFont(menuTxt);
}

void menu::freeMenuTextures()
{
    SDL_DestroyTexture(btnUp);
    SDL_DestroyTexture(btnDown);
}
