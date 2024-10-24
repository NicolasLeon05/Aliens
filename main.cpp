#include "Game.h"
#include <iostream>
//Hacer un cpp y h para un text que se use en button
//Cambiar los numeros magicos de font en button
//Fijarse si rec se usa
//Tal vez combiene hacer un sprite.h o algo asi para que tenga el source, destination, scale, rotation

//Añadidos aliens, faltan colisiones y que sean un cricle en vez de un rectangle
//Falta hacer un circle.h y circle.cpp

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	Game::Run();

	return 0;
}