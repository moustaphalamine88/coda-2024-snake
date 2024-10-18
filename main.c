
  #include "reader.h"



int main()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
    {
        printf("Error SDL2 Init : %s\n", SDL_GetError());
        return 1;
    }

    if (IMG_Init(IMG_INIT_PNG) == 0) 
    {
        printf("Erreur d'initialisation de la SDL_Image\n");
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Exercice 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 320, 320, SDL_WINDOW_OPENGL);

    if (window == NULL) 
    {
        printf("Error while creating a window : %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) 
    {
        printf("Erreur à la création du renderer\n");
        return 1;
    }

    SDL_Surface* surface = IMG_Load("colors.png");
    if (surface == NULL) 
    {
        printf("Error loading image %s\n", IMG_GetError());
        return 1;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == NULL) 
    {
        printf("Error creating texture\n");
        return 1;
    }

    SDL_FreeSurface(surface);   


    while(1)
    {
        SDL_Event e;
        if (SDL_WaitEvent(&e)) 
        {
            if (e.type == SDL_QUIT) 
            {
                break;
            }
        }

        SDL_Rect screen_snake = {110 - 11, 110 - 11, 16, 16};
        SDL_Rect img_snake = {16, 0, 16, 16}; 


        SDL_Rect screen_food ={192, 272, 16, 16};
        SDL_Rect img_food = {0, 0, 16, 16};


        SDL_Rect img_wall = {48, 0, 16, 16};


        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, &img_snake, &screen_snake);
        SDL_RenderCopy(renderer, texture, &img_food, &screen_food);
        int i = 0;
        while(i < 20)
        {
            int j = 0;
            while (j < 20)
            {
                if (i == 0|| i == 19 || j == 0 || j == 19)
                {
                    SDL_Rect screen_wall ={i * 16, j * 16, 16, 16};
                SDL_RenderCopy(renderer, texture, &img_wall, &screen_wall);
                }
                j++;
            }
            i++;
        }
        SDL_RenderPresent(renderer);
    }


    SDL_Quit();
    return 0; 
}


