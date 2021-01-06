#include "fichier.h"



int main(int argc,char * argv[])
{

   SDL_Renderer * remplir;
   SDL_Window* window = NULL;
   int n;
   int* A;
   int* B;
   int* C;

   //POUR CONTROLER LA SAISIE
   n=controle_de_saisi();

   //INITIALISER NOTRE TOUR DE HANOI
   SDL_Init(SDL_INIT_VIDEO);
   window=creation_fenetre("TOUR DE HANOI",1300,600);
   remplir=remplissage_fenetre(window);
   A=initialiser_tableau(n);
   B=initialiser_tableau(n);
   C=initialiser_tableau(n);
   initialiser_origine(A,n);
   hanoi(remplir,A,250,C,1050,B,650,n,n);
   //barre_fixe(remplir,250,A,650,B,1050,C,n);
   SDL_Delay(3000);
   supprimer_tab(A);
   supprimer_tab(B);
   supprimer_tab(C);
   SDL_DestroyWindow(window);
   SDL_DestroyRenderer(remplir);
   SDL_Quit();
    return 0;
}
