#ifndef TURINGMACHINE_H_
#define TURINGMACHINE_H_

#include "Header.h"
#include "Fita.h"

class TuringMachine : public Fita
{
public:
	TuringMachine(vstr& cEstados, vchar& sEntrada, vchar& sFita, vstr& cTrans);
	bool reconhecer_linguagem(string input);
	bool processa_funcao(string input);
	
private:
	void init();
	void init_fita(string intput);
	int index_in(string& str, vest& ve); //returns the index
	vest create_estados();
	int verifica_transicao(Estado_t& e, char c); // verifica se o estado e tem uma transicao para c
	Transicao_t parse_transicao(Estado_t& e, int i); // verifica para qual estado a transicao leva, retorna o nome do estado
	vchar sEntrada, sFita;
	vstr  cTrans, cEstados;
};

#endif /*TURINGMACHINE_H_*/
