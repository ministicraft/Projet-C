#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carte.h"

#ifndef IDENTIFICATEUR
#define IDENTIFICATEUR

struct robot
{
	int posX;
	int posY;
	char dir;
	int compteur;
};
typedef struct robot Robot;

#endif /* guard */

void turn_left (Robot *robot);
void turn_right (Robot *robot);
int test_collision(Robot *robot, Map * map);
int exit_test(Robot *robot, Map * map);
Robot* init_robot(Map * map);
void avance(Robot * robot, Map * map);
void mouvement_robot (Robot * robot, Map *map);
int test_wall_left(Robot * robot, Map * map);
