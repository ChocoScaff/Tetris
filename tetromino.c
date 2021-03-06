#include "sdl2.h"
#include "tetromino.h"

int valeurTetromino(void)
{
    srand(time(NULL));
    return rand()%7+1;
}

int positionYTetromino(int tetromino,int numero,int Y,int etat)
{
    if (tetromino == 1)
    {
        return positionYITetromino(numero,Y,etat);
    }
    if (tetromino == 2)
    {
        return positionYOTetromino(numero,Y,etat);
    }
    if (tetromino == 3)
    {
        return positionYTTetromino(numero,Y,etat);
    }
    if (tetromino == 4)
    {
        return positionYLTetromino(numero,Y,etat);
    }
    if (tetromino == 5)
    {
        return positionYJTetromino(numero,Y,etat);
    }
    if (tetromino == 6)
    {
        return positionYZTetromino(numero,Y,etat);
    }
    if (tetromino == 7)
    {
        return positionYSTetromino(numero,Y,etat);
    }
}

int positionXTetromino(int tetromino,int numero,int X, int etat)
{
    if (tetromino == 1)
    {
        return positionXITetromino(numero,X,etat);
    }
    if (tetromino == 2)
    {
        return positionXOTetromino(numero,X,etat);
    }
    if (tetromino == 3)
    {
        return positionXTTetromino(numero,X,etat);
    }
    if (tetromino == 4)
    {
        return positionXLTetromino(numero,X,etat);
    }
    if (tetromino == 5)
    {
        return positionXJTetromino(numero,X,etat);
    }
    if (tetromino == 6)
    {
        return positionXZTetromino(numero,X,etat);
    }
    if (tetromino == 7)
    {
        return positionXSTetromino(numero,X,etat);
    }
}

int Tetrominodescent(int Y,int compte,int vitesse)
{
    if (compte == vitesse)
    {
        if (Y >= Y_SCREEN)
        {
            Y=Y;
        }
        else
        {
            Y=Y+hauteurTile;
        }
    }
    return Y;
}

int compter(int compte,int vitesse)
{
    if (compte >= vitesse)
    {
        compte=0;
    }
    else
    {
        compte=compte+1;
    }
    return compte;
}
int positionYITetromino(int numero,int Y, int etat)
{
    if (etat == 1)
    {
        return Y-hauteurTile*(numero-1);
    }
    if (etat == 2)
    {
        return Y;
    }
    if (etat == 3)
    {
        return Y-hauteurTile*(numero-1);
    }
    if (etat == 4)
    {
        return Y;
    }
}

int positionXITetromino(int numero,int X, int etat)
{
    if (etat == 1)
    {
        return X;
    }
    if (etat == 2)
    {
        return X+largeurTile*(numero-1);
    }
    if (etat == 3)
    {
        return X;
    }
    if (etat == 4)
    {
        return X+largeurTile*(numero-1);
    }
}

int positionYOTetromino(int numero,int Y, int etat)
{
    if (numero == 2)
    {
        return Y-hauteurTile;
    }
    if (numero == 3)
    {
        return Y-hauteurTile;
    }
    if (numero == 4)
    {
        return Y;
    }
}
int positionXOTetromino(int numero,int X, int etat)
{
    if (numero == 2)
    {
        return X;
    }
    if (numero == 3)
    {
        return X+largeurTile;
    }
    if (numero == 4)
    {
        return X+largeurTile;
    }
}

int positionXTTetromino(int numero,int X, int etat)
{
    if (etat == 1)
    {
        if (numero == 2)
        {
            return X;
        }
        if (numero == 3)
        {
            return X+largeurTile;
        }
        if (numero == 4)
        {
            return X-largeurTile;
        }
    }
    if (etat == 2)
    {
        if (numero == 2)
        {
            return X+largeurTile;
        }
        if (numero == 3)
        {
            return X+largeurTile;
        }
        if (numero == 4)
        {
            return X+largeurTile;
        }
    }
    if (etat == 3)
    {
        if (numero == 2)
        {
            return X;
        }
        if (numero == 3)
        {
            return X+largeurTile;
        }
        if (numero == 4)
        {
            return X-largeurTile;
        }
    }
    if (etat == 4)
    {
        if (numero == 2)
        {
            return X-largeurTile;
        }
        if (numero == 3)
        {
            return X-largeurTile;
        }
        if (numero == 4)
        {
            return X-largeurTile;
        }
    }
}
int positionYTTetromino(int numero,int Y, int etat)
{
    if (etat == 1)
    {
        if (numero == 2)
        {
            return Y+hauteurTile;
        }
        if (numero == 3)
        {
            return Y+hauteurTile;
        }
        if (numero == 4)
        {
            return Y+hauteurTile;
        }
    }
    if (etat == 2)
    {
        if (numero == 2)
        {
            return Y;
        }
        if (numero == 3)
        {
            return Y+hauteurTile;
        }
        if (numero == 4)
        {
            return Y-largeurTile;
        }
    }
    if (etat == 3)
    {
        if (numero == 2)
        {
            return Y-hauteurTile;
        }
        if (numero == 3)
        {
            return Y-hauteurTile;
        }
        if (numero == 4)
        {
            return Y-hauteurTile;
        }
    }
    if (etat == 4)
    {
        if (numero == 2)
        {
            return Y;
        }
        if (numero == 3)
        {
            return Y-hauteurTile;
        }
        if (numero == 4)
        {
            return Y+largeurTile;
        }
    }
}

int positionYLTetromino(int numero,int Y, int etat)
{
    if (etat == 1)
    {
        return Y-hauteurTile;
    }
    if (etat == 2)
    {
        return Y-hauteurTile*(numero-2);
    }
    if (etat == 3)
    {
        return Y+hauteurTile;
    }
    if (etat == 4)
    {
        return Y+hauteurTile*(numero-2);
    }
}

int positionXLTetromino(int numero,int X, int etat)
{
    if (etat == 1)
    {
        return X+largeurTile*(numero-2);
    }
    if (etat == 2)
    {
        return X-largeurTile;
    }
    if (etat == 3)
    {
        return X-largeurTile*(numero-2);
    }
    if (etat == 4)
    {
        return X+largeurTile;
    }
}

int positionYJTetromino(int numero,int Y, int etat)
{
    if (etat == 1)
    {
        return Y-hauteurTile;
    }
    if (etat == 2)
    {
        return Y+hauteurTile*(numero-2);
    }
    if (etat == 3)
    {
        return Y+hauteurTile;
    }
    if (etat == 4)
    {
        return Y-hauteurTile*(numero-2);
    }
}

int positionXJTetromino(int numero,int X, int etat)
{
    if (etat == 1)
    {
        return X-largeurTile*(numero-2);
    }
    if (etat == 2)
    {
        return X-largeurTile;
    }
    if (etat == 3)
    {
        return X+largeurTile*(numero-2);
    }
    if (etat == 4)
    {
        return X+largeurTile;
    }
}

int positionXZTetromino(int numero,int X, int etat)
{
    if (etat == 1 || etat == 3)
    {
        if (numero == 2)
        {
            return X+largeurTile;
        }
        if (numero == 3)
        {
            return X+largeurTile;
        }
        if (numero == 4)
        {
            return X+largeurTile*2;
        }
    }
    if (etat == 2 || etat == 4)
    {
        if (numero == 2)
        {
            return X;
        }
        if (numero == 3)
        {
            return X+largeurTile;
        }
        if (numero == 4)
        {
            return X+largeurTile;
        }
    }
}

int positionYZTetromino(int numero,int Y, int etat)
{
    if (etat == 1 || etat == 3)
    {
        if (numero == 2)
        {
            return Y;
        }
        if (numero == 3)
        {
            return Y+hauteurTile;
        }
        if (numero == 4)
        {
            return Y+hauteurTile;
        }
    }
    if (etat == 2 || etat == 4)
    {
        if (numero == 2)
        {
            return Y-hauteurTile;
        }
        if (numero == 3)
        {
            return Y-hauteurTile;
        }
        if (numero == 4)
        {
            return Y-hauteurTile*2;
        }
    }
}

int positionXSTetromino(int numero,int X, int etat)
{
    if (etat == 1 || etat == 3)
    {
        if (numero == 2)
        {
            return X+largeurTile;
        }
        if (numero == 3)
        {
            return X+largeurTile;
        }
        if (numero == 4)
        {
            return X+largeurTile*2;
        }
    }
    if (etat == 2 || etat == 4)
    {
        if (numero == 2)
        {
            return X;
        }
        if (numero == 3)
        {
            return X-largeurTile;
        }
        if (numero == 4)
        {
            return X-largeurTile;
        }
    }
}

int positionYSTetromino(int numero,int Y, int etat)
{
    if (etat == 1 || etat == 3)
    {
        if (numero == 2)
        {
            return Y;
        }
        if (numero == 3)
        {
            return Y-hauteurTile;
        }
        if (numero == 4)
        {
            return Y-hauteurTile;
        }
    }
    if (etat == 2 || etat == 4)
    {
        if (numero == 2)
        {
            return Y-hauteurTile;
        }
        if (numero == 3)
        {
            return Y-hauteurTile;
        }
        if (numero == 4)
        {
            return Y-hauteurTile*2;
        }
    }
}

int colorTetromino(int valeurTetromino)
{
    return valeurTetromino;
}

void AffichageTetrominoQuiDescent(Ecran ecran,int color,int x1,int x2,int x3,int x4,int y1,int y2,int y3,int y4,Image cubesheet)
{
    if (color ==1)
    {
        dessineTetromino(ecran,x1,y1,cubesheet,color);
        dessineTetromino(ecran,x2,y2,cubesheet,color);
        dessineTetromino(ecran,x3,y3,cubesheet,color);
        dessineTetromino(ecran,x4,y4,cubesheet,color);
    }
    else if (color == 2)
    {
        dessineTetromino(ecran,x1,y1,cubesheet,color);
        dessineTetromino(ecran,x2,y2,cubesheet,color);
        dessineTetromino(ecran,x3,y3,cubesheet,color);
        dessineTetromino(ecran,x4,y4,cubesheet,color);
    }
    else if (color == 3)
    {
        dessineTetromino(ecran,x1,y1,cubesheet,color);
        dessineTetromino(ecran,x2,y2,cubesheet,color);
        dessineTetromino(ecran,x3,y3,cubesheet,color);
        dessineTetromino(ecran,x4,y4,cubesheet,color);
    }
    else if (color == 4)
    {
        dessineTetromino(ecran,x1,y1,cubesheet,color);
        dessineTetromino(ecran,x2,y2,cubesheet,color);
        dessineTetromino(ecran,x3,y3,cubesheet,color);
        dessineTetromino(ecran,x4,y4,cubesheet,color);
    }
    else if (color == 5)
    {
        dessineTetromino(ecran,x1,y1,cubesheet,color);
        dessineTetromino(ecran,x2,y2,cubesheet,color);
        dessineTetromino(ecran,x3,y3,cubesheet,color);
        dessineTetromino(ecran,x4,y4,cubesheet,color);
    }
    else if (color == 6)
    {
        dessineTetromino(ecran,x1,y1,cubesheet,color);
        dessineTetromino(ecran,x2,y2,cubesheet,color);
        dessineTetromino(ecran,x3,y3,cubesheet,color);
        dessineTetromino(ecran,x4,y4,cubesheet,color);
    }
    else if (color == 7)
    {
        dessineTetromino(ecran,x1,y1,cubesheet,color);
        dessineTetromino(ecran,x2,y2,cubesheet,color);
        dessineTetromino(ecran,x3,y3,cubesheet,color);
        dessineTetromino(ecran,x4,y4,cubesheet,color);
    }
}

void AffichageTetrominoMemoire(Ecran ecran,int color,int Grille,int i,int j,Image cubesheet)
{
    if(Grille == 1)
    {
        dessineTetromino(ecran,i,j,cubesheet,Grille);
    }
    else if (Grille == 2)
    {
        dessineTetromino(ecran,i,j,cubesheet,Grille);
    }
    else if (Grille == 3)
    {
        dessineTetromino(ecran,i,j,cubesheet,Grille);
    }
    else if (Grille == 4)
    {
        dessineTetromino(ecran,i,j,cubesheet,Grille);
    }
    else if (Grille == 5)
    {
        dessineTetromino(ecran,i,j,cubesheet,Grille);
    }
    else if (Grille == 6)
    {
        dessineTetromino(ecran,i,j,cubesheet,Grille);
    }
    else if (Grille == 7)
    {
        dessineTetromino(ecran,i,j,cubesheet,Grille);
    }
}
