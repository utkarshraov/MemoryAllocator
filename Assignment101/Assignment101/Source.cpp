// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include "Engine-init.h"
#include "Monster.h"
#include "Player.h"
#include "Vector2.h"
#define PLAYER_POS 1
#define MONSTER_POS  2

class coordinate {
public:
	int xPos;
	int yPos;
};




int main()
{
	int grid[50][50], numMonsters, monsterTracker[10], monsterCount = 0;;
	char a[15];
	Monster monster[10];
	Player player1;
	printf("\nEnter player name:");
	fgets(player1.playerName, 15, stdin);
	printf("\nEnter the number of monsters: \n");
	scanf_s("%d", &numMonsters);
	monsterCount = numMonsters;

	fgets(a, 15, stdin);

	for (int i = 0; i < 10; i++)
		monsterTracker[i] = 0;

	for (int i = 0; i < numMonsters; i++)
	{
		printf("\nEnter the name of Monster %d:\n", i + 1);
		fgets(monster[i].monsterName, 15, stdin);
		printf("\nName of monster %d is %s", i + 1, monster[i].monsterName);
		monsterTracker[i] = 1;
	}

	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			grid[i][j] = 0;
		}
	}
	printf("\n\n\n\n");
	printf("You spawned at (%d,%d)\n\n", player1.currentLocation.xPos, player1.currentLocation.yPos);
	for (int i = 0; i < numMonsters; i++)
	{
		grid[monster[i].currentLocation.xPos][monster[i].currentLocation.yPos] = MONSTER_POS;
	}

	grid[player1.currentLocation.xPos][player1.currentLocation.yPos] = PLAYER_POS;
	char option;
	int success;
	bool dead = false;
	while (1)
	{


		printf("\nPlayer is in position (%d,%d)", player1.currentLocation.xPos, player1.currentLocation.yPos);
		for (int i = 0; i < numMonsters; i++)
		{


			for (int j = 0; j < numMonsters; j++)
			{
				if (i != j) {
					if (monster[i].currentLocation.xPos == monster[j].currentLocation.xPos)
					{
						if (monster[i].currentLocation.xPos == monster[j].currentLocation.xPos)
							monsterTracker[i] = 0;
						monsterCount--;
					}
				}
			}
			if (monsterCount == 0)
			{
				printf("\n\n All monsters are dead, you win yay \n\n");
				fgets(a, 15, stdin);
				exit(0);
			}
			if (monsterTracker[i]) {
				printf("\nMonster %d is in position (%d,%d)", i + 1, monster[i].currentLocation.xPos, monster[i].currentLocation.yPos);

				dead = monster[i].areYouFoodYet(player1.currentLocation);
				monster[i].moveMonster();
			}
		}
		if (dead)
		{
			printf("\n\n The monster ate you!\n\n GAME OVER \n\n");
			fgets(a, 15, stdin);
			exit(0);
		}

		printf("\nEnter a direction(WASD) or press Q to exit:\n");
		scanf_s("%c", &option, 1);
		fgets(a, 15, stdin);

		switch (option)
		{
		case 'w':
		case 'W': success = player1.updateLocation('w');
			break;
		case 'a':
		case 'A': success = player1.updateLocation('a');
			break;
		case 's':
		case 'S': success = player1.updateLocation('s');
			break;
		case 'd':
		case 'D': success = player1.updateLocation('d');
			break;
		case 'q':
		case 'Q': exit(0);
		}
		if (success)
		{
			printf("\nThe option you entered does not do anything.\n");
		}
	}

	fgets(a, 15, stdin);


}

