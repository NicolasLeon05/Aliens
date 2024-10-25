#include "Game.h"
#include <iostream>
//Completar Scene_Tutorial
//Hacer Scene_Credits
//Añadir vida al player
//Añadir disparos
//Hacer un cpp y h para un text que se use en button
//Tal vez conviene hacer un sprite.h o algo asi para que tenga el source, destination, scale, rotation
//Tal vez conviene que en lugar de un vector de enemy sea una list

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	Game::Run();

	return 0;
}