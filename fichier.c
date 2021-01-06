#include "fichier.h"
#define N 8

int controle_de_saisi(){
 char c;
 int n;
     printf("DONNER LE NOMBRE DE DISK ");
    do{

        scanf("%c",&c);
        fflush(stdin);
        if(isdigit(c)){
                        n=atoi(&c);
                        if(n>N) {printf("VEUILLEZ SAISIR UN NOMBRE DE DISK INFERIEUR A 9 :");
                                 c='a';
                                 }
                        }
        else        {
                         printf("VEUILLEZ SAISIR UN CHIFFRE SVP ");
                    }
    }while(!isdigit(c));

return n;
}



// MANIPULATION DE MON TABLEAU
int * initialiser_tableau(int nbre_element){
int *tab;
int i;
tab=(int *)malloc(nbre_element*sizeof(int));
for(i=0;i<nbre_element;i++) tab[i]=0;
return tab;

}




void empiler(int * t ,int taille,int tail){
int i;

i=0;
while((t[i]!=0) && (i<taille))  i++;

t[i]=tail;

}



void depiler(int *tab,int taille){
int i;
i=0;
while((tab[i]!=0) && (i<taille)) i++;
tab[i-1]=0;
}
//FIN MANIPULATION LISTE




SDL_Window * creation_fenetre(char * nom_fenetre,int taille,int hauteur){
SDL_Window* w;
w=SDL_CreateWindow(nom_fenetre,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,taille,hauteur,SDL_WINDOW_SHOWN);
return w;

  }




  SDL_Renderer * remplissage_fenetre(SDL_Window * fenetre){
            SDL_Renderer * r;
            r=SDL_CreateRenderer(fenetre,-1,SDL_RENDERER_ACCELERATED);

            return r;
            }








 void un_rectangle(SDL_Renderer *r,int pos_x,int pos_y,int largeur){
                     int rouge,vert,bleu;
                     rouge=250;
                     vert=largeur/3;
                     bleu=largeur-50;
                     SDL_Rect un_rect={pos_x,pos_y,largeur,40};
                     SDL_SetRenderDrawColor( r,rouge,vert,bleu,0);
                     SDL_RenderFillRect(r,&un_rect);


                                                                    }







void affichage_barre(SDL_Renderer * r,int position_barre,int* tab,int  taille){
int le_x,pos_y,i;


pos_y=460;

i=0;

                while((tab[i]!=0) && (i<taille)){
                   le_x=position_barre-(tab[i]/2)+5;
                   un_rectangle(r,le_x,pos_y,tab[i]);
                   pos_y=pos_y-40;
                   i=i+1;
                                               }




                                                                     }




void barre_fixe(SDL_Renderer * r,int pos1,int *t1,int pos2,int *t2,int pos3,int *t3,int taille){
            SDL_Rect horiz={50,500,1210,10};
            SDL_Rect vert1={250,200,10,300};
            SDL_Rect vert2={650,200,10,300};
            SDL_Rect vert3={1050,200,10,300};

            SDL_SetRenderDrawColor( r, 255, 255, 255, 0 );
            SDL_RenderFillRect(r,&horiz);
            SDL_RenderFillRect(r,&vert1);
            SDL_RenderFillRect(r,&vert2);
            SDL_RenderFillRect(r,&vert3);

            affichage_barre(r,pos1,t1,taille);
            affichage_barre(r,pos2,t2,taille);
            affichage_barre(r,pos3,t3,taille);
            SDL_RenderPresent(r);

                                 }




int nbre_disk(int * t,int taille){
int i=0;
while(t[i]!=0 && i<taille )  i++;

return i;
                                 }



 void supprimer_tab(int *t){
 free(t);
 }



 void initialiser_origine(int * A,int nbre){
 int i;
 for(i=0;i<nbre;i++){
    empiler(A,nbre,(400-50*i));
 }

 }











void deplacement_horizontal(SDL_Renderer * r,int *t1,int pos1,int *t2,int pos2,int *t3,int pos3,int taille){

int i,nbre,nbre2,nbre3,xd,yd,xa,ya,tail1,tail2,tail3;





i=0;
nbre=nbre_disk(t1,taille);
nbre2=nbre_disk(t2,taille);
nbre3=nbre_disk(t3,taille);
tail1=t1[nbre-1];
tail2=t2[nbre2-1];
tail3=t3[nbre3-1];
xd=pos1-(tail1/2)+5;
xa=pos2-(tail1/2)+5;
yd=140;


depiler(t1,taille);
if(xd<xa){

            while(i<1){

                            if(xd==(xa+10)){
                                                i=1;
                                            }

                            else            {

                                             SDL_Delay(15);
                                             un_rectangle(r,xd,yd,tail1);
                                             barre_fixe(r,pos1,t1,pos2,t2,pos3,t3,taille);
                                             SDL_SetRenderDrawColor( r, 0, 0, 0, 0);
                                             SDL_RenderClear(r);

                                            xd=xd+10;
                                            }

                  }
        }
 else            {

     while(i<1){

                            if(xd==xa+10){
                                                i=1;
                                            }

                            else            {

                                             SDL_Delay(20);
                                             un_rectangle(r,xd,yd,tail1);
                                             barre_fixe(r,pos1,t1,pos2,t2,pos3,t3,taille);
                                             SDL_SetRenderDrawColor( r, 0, 0, 0, 0);
                                             SDL_RenderClear(r);

                                            xd=xd-10;
                                            }

                  }




                  }

empiler(t1,taille,tail1);
         }










void deplacement_ascendant(SDL_Renderer * r,int *t1,int pos1,int *t2,int pos2,int *t3,int pos3,int taille){

int i,nbre,nbre2,nbre3,xd,yd,xa,ya,tail1,tail2,tail3;
i=0;
nbre=nbre_disk(t1,taille);
nbre2=nbre_disk(t2,taille);
nbre3=nbre_disk(t3,taille);
tail1=t1[nbre-1];
tail2=t2[nbre2-1];
tail3=t3[nbre3-1];
xd=pos1-(tail1/2)+5;
xa=pos2-(tail1/2)+5;
yd=460-(nbre)*40;
ya=140;
depiler(t1,taille);
 while(i<1){

            if(yd==ya){
                                        i=1;
                           }

            else      {




                              SDL_Delay(15);
                              un_rectangle(r,xd,yd,tail1);
                              barre_fixe(r,pos1,t1,pos2,t2,pos3,t3,taille);
                              SDL_SetRenderDrawColor( r, 0, 0, 0, 0);
                              SDL_RenderClear(r);





                            yd=yd-10;
                      }

          }

empiler(t1,taille,tail1);
 }












void deplacement_descendant(SDL_Renderer * r,int *t1,int pos1,int *t2,int pos2,int *t3,int pos3,int taille){

int i,nbre,nbre2,nbre3,xd,yd,xa,ya,tail1,tail2,tail3;
i=0;
nbre=nbre_disk(t1,taille);
nbre2=nbre_disk(t2,taille);
nbre3=nbre_disk(t3,taille);
tail1=t1[nbre-1];
tail2=t2[nbre2-1];
tail3=t3[nbre3-1];
xd=pos1-(tail1/2)+5;
xa=pos2-(tail1/2)+5;
yd=140;
ya=460-(nbre2)*40;
depiler(t1,taille);
 while(i<1){

            if(yd==(ya+10)){
                                        i=1;
                           }

            else      {


                            SDL_Delay(15);
                            un_rectangle(r,xa,yd,tail1);
                            barre_fixe(r,pos1,t1,pos2,t2,pos3,t3,taille);
                            SDL_SetRenderDrawColor( r, 0, 0, 0, 0);
                            SDL_RenderClear(r);

                            yd=yd+10;
                      }

          }
empiler(t2,taille,tail1);
 }








void deplacer(SDL_Renderer * r,int *t1,int pos1,int*t2,int pos2,int* t3,int pos3,int nbre_de_disk){

deplacement_ascendant(r,t1,pos1,t2,pos2,t3, pos3,nbre_de_disk);
deplacement_horizontal(r,t1,pos1,t2,pos2,t3, pos3,nbre_de_disk);
deplacement_descendant(r,t1,pos1,t2,pos2,t3, pos3,nbre_de_disk);


 }







 void hanoi(SDL_Renderer * r,int *A,int posA,int* B,int posB,int* C ,int posC,int n_disk,int n_fix){
 if(n_disk>0){
           hanoi(r,A,posA,C,posC,B,posB,n_disk-1,n_fix);
           deplacer(r,A,posA,B,posB,C,posC,n_fix);
           hanoi(r,C,posC,B,posB,A,posA,n_disk-1,n_fix);
       }
 }













