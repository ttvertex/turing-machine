#ifndef TURINGMACHINE_H_
#define TURINGMACHINE_H_

#include "Header.h"
#include "Fita.h"

class TuringMachine : public Fita
{
public:
	TuringMachine(vstr& cEstados, vchar& sEntrada, vchar& sFita, vstr& cTrans);
	bool reconhecer_linguagem(string input);
	
private:
	void init();
	void init_fita(string intput);
	vest parse_transicoes();
	int index_in(string& str, vest& ve); //returns the index
	
	int E, SE, SF, NT;
	vchar sEntrada, sFita;
	vstr  cTrans, cEstados;
	char OP;
};

#endif /*TURINGMACHINE_H_*/
