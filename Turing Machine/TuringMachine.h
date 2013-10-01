#ifndef TURINGMACHINE_H_
#define TURINGMACHINE_H_

#include "Header.h"

class TuringMachine
{
public:
	TuringMachine(vchar& sEntrada, vchar& sFita, vstr& cTrans, vstr& cEstados);
	
	
private:
	int E, SE, SF, NT;
	vchar sEntrada, sFita;
	vstr  cTrans, cEstados, cTeste;
	char OP;
};

#endif /*TURINGMACHINE_H_*/
