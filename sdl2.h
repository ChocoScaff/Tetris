#include <SDL2/SDL.h>

#define largeurTile 40
#define hauteurTile 40
#define caselargeur 12
#define casehauteur 16
#define X_SCREEN        caselargeur*largeurTile
#define Y_SCREEN        casehauteur*hauteurTile

typedef SDL_Surface* Image;
typedef SDL_Renderer* Ecran;

extern const Uint8 *etatClavier;

Ecran creationEcran(void);
Image creationImage(char *fichier);
void dessineImage(Ecran ecran, int x, int y, Image image);
void effaceEcran(Ecran ecran);
void miseAJourEcran(Ecran ecran);
int largImage(Image image);
int hautImage(Image image);
void destructionImage(Image image);
void destructionEcran(Ecran ecran);
void evenements(void);
