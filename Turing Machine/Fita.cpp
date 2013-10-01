#include "Fita.h"

Fita::Fita()
{
	pos = 0;
}

char Fita::get(){
	return fita.at(pos);
}

void Fita::D(){
	pos += DIREITA;
}

void Fita::E(){
	pos += ESQUERDA;
}

void Fita::set(char c){
	fita[pos] = c;
}