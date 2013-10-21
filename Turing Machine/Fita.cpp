#include "Fita.h"

Fita::Fita()
{
	pos = DEFAULT_INITIAL;
}

void Fita::init(string& input, vchar& sFita)
{	
	this->sFita = sFita;
	fita.clear();
	for(uint i = 0; i < input.size(); i++)
		fita.push_back(input[i]);
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

void Fita::E(){
	if(pos + ESQUERDA >= 0)
		pos += ESQUERDA;
#ifdef DEBUG
	cout << "ptr da fita: " << pos - ESQUERDA << " -> " << pos << endl;
#endif
}

void Fita::print(){
	cout  << "\n[ ";
	for(uint i = 0; i < fita.size(); i++)
		cout << fita.at(i) << " ";
	cout << "]\n";
}