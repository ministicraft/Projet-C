#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef CARTE_H
#define CARTE_H

struct map
{
	char** carte;
	int hauteur;
	int largeur;
};
typedef struct map Map;
 #endif /* guard */
int init_map (Map* *map);
int affich_map(Map *map);
