#ifndef FITA_H_
#define FITA_H_

#include "Header.h"
#define DEFAULT_INITIAL 0

class Fita
{
public:
	Fita();
	void init(string& input, vchar& sFita);
	char get();       // gets the current char
	void set(char c); // set the current char
	void D();         // walk the pointer to right
	void E();         // walk the pointer to left
	void print();
	
private:
	vchar fita; // fita em si
	uint pos;   // posicao do ptr
	int sentido; 
	vchar sFita; // simbolos da fita
};

#endif /*FITA_H_*/
