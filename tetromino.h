#include "sdl2.h"

int valeurTetromino(void);
int positionXTetromino(int tetromino,int numero,int X,int etat);
int positionYTetromino(int tetromino,int numero,int Y,int etat);
int positionXITetromino(int numero,int X, int etat);
int positionYITetromino(int numero,int Y, int etat);
int positionXOTetromino(int numero,int X, int etat);
int positionYOTetromino(int numero,int Y, int etat);
int positionXTTetromino(int numero,int X, int etat);
int positionYTTetromino(int numero,int Y, int etat);
int positionXLTetromino(int numero,int X, int etat);
int positionYLTetromino(int numero,int Y, int etat);
int positionXJTetromino(int numero,int X, int etat);
int positionYJTetromino(int numero,int Y, int etat);
int positionXZTetromino(int numero,int X, int etat);
int positionYZTetromino(int numero,int Y, int etat);
int positionXSTetromino(int numero,int X, int etat);
int positionYSTetromino(int numero,int Y, int etat);
int Tetrominodescent(int Y, int compte ,int vitesse);
int compter(int compter,int vitesse);
int colorTetromino(int ValteurTetromino);
void AffichageTetrominoQuiDescent(Ecran ecran,int color,int x1,int x2,int x3,int x4,int y1,int y2,int y3,int y4,Image cubeI,Image cubeO,Image cubeT,Image cubeL,Image cubeJ,Image cubeZ,Image cubeS);
void AffichageTetrominoMemoire(Ecran ecran,int color,int Grille,int i,int j,Image cubeI,Image cubeO,Image cubeT,Image cubeL,Image cubeJ,Image cubeZ,Image cubeS);
