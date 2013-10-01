#include "Fita.h"

Fita::Fita()
{
	pos = DEFAULT_INITIAL;
}

void Fita::init(string& input, vchar& sFita)
{
	this->sFita = sFita;
	for(uint i = 0; i < input.size(); i++)
		fita.push_back(input[i]);
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

void Fita::print(){
	cout  << "\n[ ";
	for(uint i = 0; i < fita.size(); i++)
		cout << fita.at(i) << " ";
	cout << "]\n";
}