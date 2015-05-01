#include "carte.h"

int init_map (Map* *pmap)
{
	//Prologue
	Map * map = *pmap;

	FILE* fp = NULL;
	char read;
	int i;
	int n;
	int hauteur;
	int largeur;
	//Map * map = NULL;
	//ouverture du fichier
	if((fp=fopen("appart.txt","r"))==NULL)
	{
		printf("Erreur, impossible d'ouvrir le fichier");
		return 1;
	}
	//récupération du nb de ligne et de colone de la carte
	fscanf(fp,"%d:%d", &largeur, &hauteur);
	fgetc(fp); //vide le buffer
	//printf("largeur:%d,hauteur:%d\n",largeur,hauteur);
	//création de la carte
	char** carte;
	carte = malloc (hauteur * sizeof(char*));
	for(i=0; i<hauteur; i++)
	{
		carte [i] = malloc(largeur * sizeof(char));
	}
	map = malloc(sizeof(Map));
	map->carte = carte;
	map->hauteur = hauteur;
	map->largeur = largeur;

	char ligne[largeur+2];
	for(i=0; i<hauteur; i++)
	{
		fgets(ligne,largeur+2,fp); //2=+1+1 car fgets prend 1 char de moin
									//donc +1 pour \n et +1 pour fgets
		strncpy(map->carte[i],ligne,largeur);
		//printf("%s\n",map->carte[i]);
	}
	fclose(fp);
	//Epilogue
	*pmap = map;
	return 0;
}

Sortie* init_sortie(Map * map)
{
	Sortie* sortie = NULL;
	sortie = malloc (sizeof(Sortie));
	int i;
	int j;
	char* ptr_j=NULL;
	for (i=0; i<(map->hauteur); i++)
	{
		for(j=0;j<(map->largeur);j++)
		{
			if (map->carte[i][j]=='S')
			{
				sortie->posY=i;
				sortie->posX=j;
				break;
			}
		}
		if (map->carte[i][j]=='S') break;
	}
	return sortie;
}

int affich_map(Map *map)
{
	int i;
	for (i=0; i<map->hauteur; i++)
	{
		printf("%s\n",map->carte[i]);
	}

}

