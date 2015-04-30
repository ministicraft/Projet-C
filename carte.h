#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct map
{
	char** carte;
	int hauteur;
	int largeur;
};
typedef struct map Map;

int init_map (Map* *map);
int affich_map(Map *map);
