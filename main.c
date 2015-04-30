#include "carte.h"
#include "robot.h"
#include "graphique.h"

int main(int argc,char **argv)
{
	Map * map = NULL;
	init_map(&map);
	/*int i;
	for (i=0; i<map->hauteur; i++)
	{
		printf("%s\n",map->carte[i]);
	}*/
	affich_map(map);
}
