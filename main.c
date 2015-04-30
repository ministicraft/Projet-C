#include "carte.h"
#include "robot.h"
#include "graphique.h"

int main(int argc,char **argv)
{
	//int compteur = 0;
	Map * map = NULL;
	Robot * robot = NULL;
	init_map(&map);
	/*int i;
	for (i=0; i<map->hauteur; i++)
	{
		printf("%s\n",map->carte[i]);
	}*/
	robot=init_robot(map);
	affich_map(map);
	printf("robot posX:%d robot posY:%d robot Dir:%c\n",robot->posX,robot->posY, robot->dir);
	getchar();
	system("clear");
	while(1)
	{
//		printf("Exit: %d\n",exit_test(robot,map));
		mouvement_robot(robot,map);
		affich_map(map);
		//printf("robot posX:%d robot posY:%d robot Dir:%c\n",robot->posX,robot->posY, robot->dir);
		getchar();
		system("clear");
	}
}
