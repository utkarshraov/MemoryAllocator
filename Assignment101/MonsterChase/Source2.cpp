#include<iostream>
#include<list>
#include "Vector2.h"
#include "DebugStatement.h"
#include "GameObject.h"
#include "Player.h"
#include "Monster.h"
#include<string>
#pragma once
using namespace Engine;
using namespace std;
void main()
{
	
	int i, j, numMonsters;
	char * monName, * playerName;
	list <Monster> Monsters;
	cout << "Enter number of monsters" << endl;
	cin >> numMonsters;

	
	for (i = 0; i < numMonsters; i++)
	{
		cout << "Enter monster #" << i + 1 << "'s name" << endl;
		cin >> monName;
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
			cout << i->name << "is at ";
		}
	}
}