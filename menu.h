#ifndef MENU_H
#define MENU_H
#include <SDL_image.h>
#include <string>
#include "SDL_FontCache.h"

class menu
{
    public:
        menu();
        int height;
        int vert;
        void init(SDL_Renderer *fromMain);
        void spawnPlayBtns(SDL_Renderer *fromMain);
        void freeMenuTxt();
        void freeMenuTextures();
        virtual ~menu();

    private:
        FC_Font *menuTxt;
        SDL_Texture *btnUp;
        SDL_Texture *btnDown;
        unsigned int elements=38;
        SDL_Rect imageInstances[38];
        std::string quotes[38]={"What is it with you?","SCRAM!!","You want more??","Get outta here!","You got better shit to do","throw up your brain","Enjoy-a-doodle-doo","bone fragments","Chewy bits","You're a moron",
                                "Choke-a-doodle-do","Only 10 percent guano","find a feather","Cluckity cluck sir","Take it out on me","Bother some other bastard","Take it outside","Just fuck off","We got another one","Cluckin-hell!",
                                "Work that diaphram","Any blood in there?","Disinfectant","I ain't serving you!","We're closed","Embarrassing yourself","Do yourself a favor pal","fuck-a-doodle-dandy","Cluckin bastard!","What do you want?",
                                "How can I serve you?","Cluckity fuck,place your order","Welcome","Hello-a-doodle-doo","Plz place an order","degrade myself","Yummy-doodle-do","chicken ass"};
        int playedIndex=-1;
};

#endif // MENU_H
