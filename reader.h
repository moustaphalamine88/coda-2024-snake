
#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define TAILLE_TERRAIN 320
#define LARGEUR_FENETRE TAILLE_TERRAIN
#define HAUTEUR_FENETRE TAILLE_TERRAIN

#define TAILLE_SERPENT 10 

typedef struct {
    int x;
    int y;
} Position;

typedef struct 
{
    Position segments[100]; 
    char taille;
    char direction;         
} Serpent;

typedef struct 
{
    Position position; 
    //bool mangee;       
} Nourriture;


int initialiser(SDL_Window** fenetre, SDL_Renderer** renderer);


SDL_Texture* chargerTexture(const char* chemin, SDL_Renderer* renderer);


void dessinerMurs(SDL_Renderer* renderer);


void dessinerSerpent(SDL_Renderer* renderer, Serpent* serpent);


void genererNourriture(Nourriture* nourriture);


void dessinerNourriture(SDL_Renderer* renderer, Nourriture* nourriture);


void mettreAJourSerpent(Serpent* serpent, Nourriture* nourriture);


bool verifierCollisions(Serpent* serpent);

#endif 