#include<iostream>
#include<list>
#include "Vector2.h"
#include "DebugStatement.h"
#include "GameObject.h"
#include "Player.h"
#include "Monster.h"
#include<string>
#include"MemoryManagement.h"
#pragma once


using namespace Engine;
using namespace std;

void main()
{
	
	int i, j, numMonsters;
	char *monName = new char[10];
	char *playerName = new char[10];
	char playerChoice;
	Vector2 Up = Vector2(0, 1);
	Vector2 Down = Vector2(0, -1);
	Vector2 Right = Vector2(1, 0);
	Vector2 Left = Vector2(-1, 0);
	list <Monster> Monsters;
	cout << "Enter number of monsters" << endl;
	cin >> numMonsters;

	
	for (i = 0; i < numMonsters; i++)
	{
		cout << "Enter monster #" << i + 1 << "'s name" << endl;
		//cin >> monName;
		scanf("%s", monName);
		Monster temp = Monster(monName);
		Monsters.push_front(temp);
	}

	cout << "Enter Player name" << endl;
	cin >> playerName;
	Player player(Vector2(0, 0), playerName);

	while (1)
	{
		for (std::list<Monster>::iterator i = Monsters.begin(); i != Monsters.end(); i++)
		{
			cout << i->name << "is at "<< i->getPosition() << endl;
		}

		cout << "Player is at " << player.getPosition() << endl;
		cout << "Enter your move: WASD or Q to quit" << endl;
		cin >> playerChoice;
		switch (playerChoice)
		{
		case 'w':
			player.moveGameObject(Up);
			break;
		case 'a':
			player.moveGameObject(Left);
			break;
		case 's':
			player.moveGameObject(Down);
			break;
		case 'd':
			player.moveGameObject(Right);
			break;
		case'q':
			exit(0);
		}
		player.checkBounds();
		for (std::list<Monster>::iterator i = Monsters.begin(); i != Monsters.end(); i++)
		{
			i->moveMonster();
			if (i->areYouFoodYet(player.getPosition()))
			{
				cout << "Player has been caught" << endl;
				exit(0);
			}
		}
	}
}