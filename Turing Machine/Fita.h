#ifndef FITA_H_
#define FITA_H_

#include "Header.h"

class Fita
{
public:
	Fita();
	void init(string& input, vchar& sFita);
	char get();       // gets the current char
	void set(char c); // set the current char
	void D();         // walk the pointer to right
	bool E();         // walk the pointer to left
	void print();
	void print_sem_brancos();
private:
	vchar fita; // fita em si
	int  pos;   // posicao do ptr 
	vchar sFita; // simbolos da fita
};

#endif /*FITA_H_*/
