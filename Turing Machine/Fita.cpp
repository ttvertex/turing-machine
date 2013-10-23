#include "Fita.h"

Fita::Fita()
{
	pos = 0;
}

void Fita::init(string& input, vchar& sFita)
{	
	this->sFita = sFita;
	fita.clear();
	for(uint i = 0; i < input.size(); i++)
		fita.push_back(input[i]);
	pos = 0;
}

char Fita::get(){
	return fita.at(pos);
}

void Fita::set(char c){
	fita[pos] = c;
}

void Fita::D(){
	if((pos + DIREITA) >= fita.size())
		fita.push_back('B');
	pos += DIREITA;
	
#ifdef DEBUG
	cout << "ptr da fita: " << pos - DIREITA << " -> " << pos << endl;
#endif
}

bool Fita::E(){
	if((pos + ESQUERDA) < 0)
		return false;
	else
		pos += ESQUERDA;
#ifdef DEBUG
	cout << "ptr da fita: " << pos - ESQUERDA << " -> " << pos << endl;
#endif
	return true;
}

void Fita::print(){
	cout  << "[ ";
	for(uint i = 0; i < fita.size(); i++)
		cout << fita.at(i) << " ";
	cout << "]\n";
}

void Fita::print_sem_brancos(){
	for(uint i = 0; i < fita.size(); i++){
		if(fita[i] != 'B')
			cout << fita[i];
	}
	cout << endl;
}