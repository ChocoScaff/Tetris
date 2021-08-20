#include <stdio.h>
#include "sdl2.h"
#include "tetromino.h"


int main ( int argc, char** argv )
{
    char fin = 1;
    char continuer=1;
    int xcube1, ycube1,xcube2, ycube2,xcube3, ycube3,xcube4, ycube4;
    char etat=1;//position
    char latence=10;
    char compte=0;
    char etat2=0;
    int i,j,k;
    char Grille[X_SCREEN][Y_SCREEN];
    char vitesseTetromino=100;
    char tetromino=1;
    int score=0;
    srand(time(NULL));

    // création de l'écran graphique
    Ecran ecran = creationEcran();
    // création de l'image de la balle en mémoire
    Image cube = creationImage("cube.bmp");
    Image menu = creationImage("menu.bmp");
    SDL_Event event;

    xcube1=(X_SCREEN/2);
    ycube1=0;

    for(i=0;i<X_SCREEN;i=i+largeurTile)
        {
            for(j=0;j<Y_SCREEN;j=j+hauteurTile)
            {
                Grille[i][j]=0;
            }
        }
    dessineImage(ecran,0,0,menu);
    miseAJourEcran(ecran);
    effaceEcran(ecran);

    while(continuer == 1 && fin == 1)
    {
        etatClavier = SDL_GetKeyboardState(NULL);
        SDL_WaitEvent(&event);
        if (etatClavier[SDL_SCANCODE_SPACE])
        {
            continuer=2;
        }
        if (etatClavier[SDL_SCANCODE_ESCAPE] )
        {
            fin=0;
        }
    }
    destructionImage(menu);

    // tant que fin n'est pas vrai
    while (continuer==2 && fin ==1)
    {
        // mise à jour des événements (clavier et souris)
        evenements();
        // si on appuie sur la touche "Echap" on termine le programme
        if (etatClavier[SDL_SCANCODE_ESCAPE] || !SDL_WINDOWEVENT_CLOSE)
        {
            fin=0;
        }


        if (etatClavier[SDL_SCANCODE_RIGHT])
        {
            SDL_Delay(50);
            if ((xcube1 == X_SCREEN-largeurTile) || (xcube4 == X_SCREEN-largeurTile) || (xcube2 == X_SCREEN-largeurTile) || (xcube3 == X_SCREEN-largeurTile))
            {
                xcube1=xcube1;
            }
            else
            {

                for(i=0;i<X_SCREEN;i=i+largeurTile)
                {
                    for(j=0;j<Y_SCREEN;j=j+hauteurTile)
                    {
                        if (Grille[i][j] == 1)
                        {
                            if (xcube1 == i-largeurTile && ycube1 == j)
                            {
                                xcube1=xcube1-largeurTile;
                            }
                            if (xcube2 == i-largeurTile && ycube2 == j)
                            {
                                xcube1=xcube1-largeurTile;
                            }
                            if (xcube3 == i-largeurTile && ycube3 == j)
                            {
                                xcube1=xcube1-largeurTile;
                            }
                            if (xcube4 == i-largeurTile && ycube4 == j)
                            {
                                xcube1=xcube1-largeurTile;
                            }
                        }
                    }
                }
                xcube1=xcube1+largeurTile;
            }

        }
        if (etatClavier[SDL_SCANCODE_LEFT])
        {
            SDL_Delay(50);
            if (xcube1 == 0 || xcube2 == 0 || xcube3 ==0 || xcube4==0)
            {

                xcube1=xcube1;
            }
            else
            {
                //xcube1=xcube1-largeurTile;
                for(i=0;i<X_SCREEN;i=i+largeurTile)
                {
                    for(j=0;j<Y_SCREEN;j=j+hauteurTile)
                    {
                        if (Grille[i][j] == 1)
                        {
                            if (xcube1 == i+largeurTile && ycube1 == j)
                            {
                                xcube1=xcube1+largeurTile;
                            }
                            if (xcube2 == i+largeurTile && ycube2 == j)
                            {
                                xcube1=xcube1+largeurTile;
                            }
                            if (xcube3 == i+largeurTile && ycube3 == j)
                            {
                                xcube1=xcube1+largeurTile;
                            }
                            if (xcube4 == i+largeurTile && ycube4 == j)
                            {
                                xcube1=xcube1+largeurTile;
                            }
                        }
                    }
                }
                xcube1=xcube1-largeurTile;
            }
        }
        if (etatClavier[SDL_SCANCODE_DOWN])
        {
            if ((ycube1 >= Y_SCREEN) || (ycube2 >= Y_SCREEN) || (ycube3 >= Y_SCREEN) || (ycube4 >= Y_SCREEN))
            {
                ycube1=ycube1;
            }
            else
            {
                ycube1=ycube1+hauteurTile;
            }
            SDL_Delay(50);
        }
        if (etatClavier[SDL_SCANCODE_SPACE])
        {
            SDL_Delay(50);
            if (etat == 4)
            {
                etat=1;
            }
            else
            {
                etat = etat+1;
            }
        }

        ycube2=positionYTetromino(tetromino,2,ycube1,etat);
        ycube3=positionYTetromino(tetromino,3,ycube1,etat);
        ycube4=positionYTetromino(tetromino,4,ycube1,etat);
        xcube2=positionXTetromino(tetromino,2,xcube1,etat);
        xcube3=positionXTetromino(tetromino,3,xcube1,etat);
        xcube4=positionXTetromino(tetromino,4,xcube1,etat);

        if (xcube1 < 0 || xcube2 < 0 || xcube3 < 0 || xcube4 < 0)
        {
            xcube1=xcube1+largeurTile;
            xcube2=positionXTetromino(tetromino,2,xcube1,etat);
            xcube3=positionXTetromino(tetromino,3,xcube1,etat);
            xcube4=positionXTetromino(tetromino,4,xcube1,etat);
        }
        if ((xcube1 > X_SCREEN-largeurTile) || (xcube4 > X_SCREEN-largeurTile) || (xcube2 > X_SCREEN-largeurTile) || (xcube3 > X_SCREEN-largeurTile))
        {
            xcube1=xcube1-largeurTile;
            xcube2=positionXTetromino(tetromino,2,xcube1,etat);
            xcube3=positionXTetromino(tetromino,3,xcube1,etat);
            xcube4=positionXTetromino(tetromino,4,xcube1,etat);
        }
        for(i=0;i<X_SCREEN;i=i+largeurTile)
        {
            for(j=0;j<Y_SCREEN;j=j+hauteurTile)
            {
                if (Grille[i][j] == 1)
                {
                    if ((ycube1 == j && xcube1 == i) || (ycube2 == j && xcube2 == i) || (ycube3 == j && xcube3 == i) || (ycube4 == j && xcube4 == i))
                    {
                        etat2=1;
                    }
                }
            }
        }
        if ((ycube1 == Y_SCREEN) || (ycube2 == Y_SCREEN) || (ycube3 == Y_SCREEN) || (ycube4 == Y_SCREEN) || (etat2 == 1))
        {
            Grille[xcube1][ycube1-hauteurTile]=1;
            Grille[xcube2][ycube2-hauteurTile]=1;
            Grille[xcube3][ycube3-hauteurTile]=1;
            Grille[xcube4][ycube4-hauteurTile]=1;
            ycube1 = 0;
            xcube1 = (X_SCREEN/2-largeurTile);
            tetromino=valeurTetromino();
            //SDL_Delay(10);
            //cube=couleurTetromino(cube,tetromino);
            etat=1;
            etat2=0;
            if (vitesseTetromino == 1)
            {
                vitesseTetromino=vitesseTetromino;
            }
            else
            {
                vitesseTetromino=vitesseTetromino-1;
            }
            for(j=0;j<Y_SCREEN;j=j+hauteurTile)
            {
                if(Grille[0][j] && Grille[largeurTile][j] && Grille[largeurTile*2][j] && Grille[largeurTile*3][j] && Grille[largeurTile*4][j] && Grille[largeurTile*5][j] && Grille[largeurTile*6][j] && Grille[largeurTile*7][j] && Grille[largeurTile*8][j] && Grille[largeurTile*9][j] && Grille[largeurTile*10][j] && Grille[largeurTile*11][j])
                {
                    score=score+20;
                    Grille[0][j]=0;
                    Grille[largeurTile][j]=0;
                    Grille[largeurTile*2][j]=0;
                    Grille[largeurTile*3][j]=0;
                    Grille[largeurTile*4][j]=0;
                    Grille[largeurTile*5][j]=0;
                    Grille[largeurTile*6][j]=0;
                    Grille[largeurTile*7][j]=0;
                    Grille[largeurTile*8][j]=0;
                    Grille[largeurTile*9][j]=0;
                    Grille[largeurTile*10][j]=0;
                    Grille[largeurTile*11][j]=0;
                    SDL_Delay(100);
                    for(k=j;k>0;k=k-hauteurTile)
                    {
                        for(i=0;i<X_SCREEN;i=i+largeurTile)
                        {
                            if (Grille[i][k-hauteurTile] == 1)
                            {
                                Grille[i][k]=1;
                            }
                            if (Grille[i][k-hauteurTile] == 0)
                            {
                                Grille[i][k]=0;
                            }
                        }
                    }
                }
            }
        }
        for(i=0;i<X_SCREEN;i=i+largeurTile)
        {
            for(j=0;j<Y_SCREEN;j=j+hauteurTile)
            {
                if(Grille[i][j] == 1)
                {
                    dessineImage(ecran,i,j,cube);
                }
            }
        }
        dessineImage(ecran,xcube1,ycube1,cube);
        dessineImage(ecran,xcube2,ycube2,cube);
        dessineImage(ecran,xcube3,ycube3,cube);
        dessineImage(ecran,xcube4,ycube4,cube);
        SDL_Delay(latence);
        // mise à jour de l'affichage
        miseAJourEcran(ecran);
        effaceEcran(ecran);
        compte=compter(compte,vitesseTetromino);
        ycube1=Tetrominodescent(ycube1,compte,vitesseTetromino);
        for(i=0;i<X_SCREEN;i=i+largeurTile)
        {
            if (Grille[i][-hauteurTile] == 1)
            {
                continuer=3;
            }
        }
    }
    SDL_Delay(200);
    printf("Votre score %d\n",score);
    // vide des images en mémoire
    destructionImage(cube);
    // ferme la fenêtre
    destructionEcran(ecran);

    return 0;
}
