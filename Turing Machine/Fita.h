#ifndef FITA_H_
#define FITA_H_

#include "Header.h"

class Fita
{
public:
	Fita();
	char get();       // gets the current char
	void set(char c); // set the current char
	void D();         // walk the pointer to right
	void E();         // walk the pointer to left
	
private:
	vchar fita;
	uint pos;
	int sentido;
};

#endif /*FITA_H_*/
