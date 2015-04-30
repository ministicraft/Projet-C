#include "robot.h"


void turn_left (Robot *robot)
{
	if (robot->dir == 'N') robot->dir = 'W';
	else if (robot->dir == 'W') robot->dir = 'S';
	else if (robot->dir == 'S') robot->dir = 'E';
	else if (robot->dir == 'E') robot->dir = 'N';
	robot->compteur=robot->compteur+1;
}
void turn_right (Robot *robot)
{
	if (robot->dir == 'N') robot->dir = 'E';
	else if (robot->dir == 'E') robot->dir = 'S';
	else if (robot->dir == 'S') robot->dir = 'W';
	else if (robot->dir == 'W') robot->dir = 'N';
	robot->compteur=robot->compteur-1;
}
int test_collision(Robot *robot, Map * map)
{
	printf("test\n");
	if (robot->dir == 'N')
	{
		printf("test N\n");
		if (map->carte[robot->posY-1][robot->posX]=='x')
		{
			printf("colision N\n");
			turn_right(robot);
			printf("compteur:%d\n",robot->compteur);
			return 1;
		}
		else
		{
			printf("Pas de collision\n");
			return 0;
		}
	}
	else if (robot->dir == 'W')
	{
		printf("test W\n");
		if (map->carte[robot->posY][robot->posX-1]=='x')
		{		
			printf("colision W\n");
			turn_right(robot);
			printf("compteur:%d\n",robot->compteur);
			return 1;
		}
		else
		{
			printf("Pas de collision\n");
			return 0;
		}
	}
	else if (robot->dir == 'S')
	{
		printf("test S\n");
		if (map->carte[robot->posY+1][robot->posX]=='x')
		{
			printf("colision S\n");
			turn_right(robot);
			printf("compteur:%d\n",robot->compteur);
			return 1;
		}
		else
		{
			printf("Pas de collision\n");
			return 0;
		}
	}
	else if (robot->dir == 'E')
	{
		printf("test E\n");
		if (map->carte[robot->posY][robot->posX+1]=='x')
		{
			printf("colision E\n");
			turn_right(robot);
			printf("compteur:%d\n",robot->compteur);
			return 1;
		}
		else
		{
			printf("Pas de collision\n");
			return 0;
		}
	}
}
/*int exit_test(Robot *robot,Map * map)
{
	
}*/
Robot* init_robot(Map * map)
{
	Robot* robot = NULL;
	robot = malloc (sizeof(Robot));
	int i;
	int j;
	char* ptr_d=NULL;
	for (i=0; i<(map->hauteur); i++)
	{
		for(j=0;j<(map->largeur);j++)
		{
			if (map->carte[i][j]=='D')
			{
				robot->posY=i;
				robot->posX=j;
				break;
			}
		}
		if (map->carte[i][j]=='D') break;
	}
	map->carte[i][j]='R';
	robot->dir='N';
	robot->compteur=0;
	return robot;
}

int test_wall_left(Robot * robot, Map * map)
{
	turn_left(robot);
	int collision = test_collision(robot,map);
	return collision;
}
void avance(Robot * robot, Map * map)
{
	map->carte[robot->posY][robot->posX]=' ';
	if (robot->dir == 'N') robot->posY = robot->posY-1;
	else if (robot->dir == 'S') robot->posY = robot->posY+1;
	else if (robot->dir == 'W') robot->posX = robot->posX-1;
	else if (robot->dir == 'E') robot->posX = robot->posX+1;
	map->carte[robot->posY][robot->posX]='R';
	//printf("posX: %d posY: %d dir: %c",robot->posX,robot->posY,robot->dir);
}
void mouvement_robot (Robot * robot, Map *map)
{
	int collision = test_collision(robot,map);
	printf("compteur: %d\n",robot->compteur);
	if (robot->compteur==0 && collision==0)
	{
		avance(robot,map);
	}
	if (robot->compteur!=0 && collision==0)
	{
		if(test_wall_left(robot,map)==1)
		{
			avance(robot,map);
		}
		else
		{
			avance(robot,map);
		}
	}
	
}
