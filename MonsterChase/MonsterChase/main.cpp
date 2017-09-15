#include<stdio.h>
#include<conio.h>
#include "Engine-init.h"

void main(int i_argc, char ** i_argl)
{
	Engine::Init();

	printf("hi");
	_getch();
}