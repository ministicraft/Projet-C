#include "carte.h"

/*Map *create_map (int hauteur, int largeur)
{
	int i;
	char ** carte;
	carte = malloc (hauteur * sizeof(char*));
	for(i=0; i<hauteur; i++)
	{
		carte [i] = malloc(largeur * sizeof(char));
	}
	Map * map = NULL;
	map = malloc(sizeof(Map));
	map->carte = carte;
	map->hauteur = hauteur;
	map->largeur = largeur;
	return map;
}
int init_map (Map **map)
{
	FILE* fp = NULL;
	char read;
	int i;
	int j;
	int hauteur;
	int largeur;

	if((fp=fopen("appart.txt","r"))==NULL)
	{
		printf("Erreur, impossible d'ouvrir le fichier");
		return 1;
	}

	fscanf(fp,"%d:%d", &largeur, &hauteur);

	Map * map_t = create_map(hauteur, largeur);

	char ligne[map_t->largeur+1];
	fgets(ligne,map_t->largeur,fp);
	for(i=0; i<(map_t->hauteur)-1; i++)
	{
		fgets(ligne,(map_t->largeur)+1,fp);
			map_t->carte [i]=ligne;
			printf("%s",ligne);
	}
	fclose(fp);
	* map = map_t;
	return 0;
}*/
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
	printf("largeur:%d,hauteur:%d\n",largeur,hauteur);
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
		fgets(ligne,largeur+2,fp); //2=+1+1 
		strncpy(map->carte[i],ligne,largeur);
		//printf("%s\n",map->carte[i]);
	}
	fclose(fp);
	//Epilogue
	*pmap = map;
	return 0;
}



int affich_map(Map *map)
{
	int i;
	for (i=0; i<map->hauteur; i++)
	{
		printf("%s\n",map->carte[i]);
	}

}

