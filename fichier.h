#ifndef FICHIER_H_INCLUDED
#define FICHIER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>



int controle_de_saisi();
int * initialiser_tableau(int);
void empiler(int *,int,int);
void depiler(int *,int);
void supprimer_tab(int *);


SDL_Window * creation_fenetre( char* ,int,int);
SDL_Renderer * remplissage_fenetre(SDL_Window *);
void barre_fixe(SDL_Renderer  *,int,int*,int,int*,int,int*,int);
void affichage_barre(SDL_Renderer*,int,int *,int);
void un_rectangle(SDL_Renderer *,int,int,int);
void initialiser_origine(int *,int);


void deplacement_horizontal(SDL_Renderer*,int *,int,int*,int,int*,int,int);
void deplacement_ascendant (SDL_Renderer*,int *,int,int*,int,int*,int,int);
void deplacement_descendant(SDL_Renderer*,int *,int,int*,int,int*,int,int);
void deplacer(SDL_Renderer * r,int *,int,int*,int,int*,int,int);
void hanoi(SDL_Renderer * r,int *,int ,int*,int,int*,int,int,int);



#endif // FICHIER_H_INCLUDED
