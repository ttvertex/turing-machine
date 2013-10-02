#include "TuringMachine.h"

#include <map>
#include <cstdio>

/**
 * 
 * sEntrada[] -> alfabeto de entrada 
 * sFita[]    -> alfabeto da fita
 * cTrans[]   -> conjunto de transicoes
 * cEstados[] -> conjunto de estados
 * 
 * E  = # de estados
 * SE = # de simbolos de entrada
 * SF = # de simbolos da fita
 * NT = # de transicoes
 * 
 */

TuringMachine::TuringMachine(vstr& cEstados, vchar& sEntrada, vchar& sFita, vstr& cTrans)
{
	E  = cEstados.size(); 
	SE = sEntrada.size();
	SF = sFita.size();
	NT = cTrans.size();

	this->sEntrada = sEntrada;
	this->sFita    = sFita;
	this->cTrans   = cTrans;
	this->cEstados = cEstados;
}

void TuringMachine::init_fita(string input){
	
}

#define QACEITA "qac"
#define QREJEITA "qrej"

/**
 * input: caso de teste
 */
bool TuringMachine::reconhecer_linguagem(string input){
	OP = RECONHECEDOR_DE_LING;
	bool reconhece = false;

	cout << "\nInicializando fita..." << endl;
	Fita::init(input, sFita);
	
	// Transforma o vetor de transicoes em um vetor de struct Estado
	cout << "Inicializando Estados..." << endl;
	vest estados = parse_transicoes();
	
	// Nome do estado (q1,q2...) e o indice correspondente no vetor de estados
	map<string, int> estadoIndex; 
	for(uint i = 0; i < estados.size(); i++){ /// Inicializa o map
		estadoIndex[estados.at(i).nome] = i;
	}
	
	Estado eatual = estados.at(0);
	while( eatual.nome != QACEITA && eatual.nome != QREJEITA ){ // enquanto nao chegar no qaceita
		// Retorna o indice no vetor de transicoes do estado, que tem a transicao para o char 
		int x = verifica_transicao(eatual, Fita::get());

		if( x == -1 ){ // se nao encontrou a transicao no estado, aborta
			eatual.nome = QREJEITA;
			return false;
		}else{
			string s = aonde_ir(eatual, x);
			cout << estadoIndex[s] << endl;
		}
		eatual.nome = QACEITA;
	}
	/**
	 * @TODO: Implementar a verificacao das transicoes, conforme o caso de teste
	 * e terminar de fazer a fita p/ verificar se a maquina reconhece;
	 * 
	 */
	return reconhece;
}

/**
 * Transforma um conjunto de strings (transicoes) em um conjunto de estados,
 * onde cada estado tem suas funcoes de transicao (que saem dele)
 */

vest TuringMachine::parse_transicoes(){
	vest ve;
	char del[] = "(,";
	
	for(uint i = 0; i < cTrans.size(); i++){
		string s = cTrans.at(i).data();
		string tok = strtok((char*)cTrans.at(i).data(), del);
		int index = index_in(tok, ve);
		
		if( index == -1 ){ // criar um novo estado
			Estado e;
			e.nome = tok;
			e.transicoes.push_back(s);
			ve.push_back(e);
		} else { // adicionar em estado existente
			ve.at(index).transicoes.push_back(s);
		}
	}
//	for(uint i = 0; i < ve.size(); i++){
//		cout << ve[i] << endl;
//		for(uint j = 0; j < ve.at(i).transicoes.size(); j++)
//			cout << ve[i].transicoes.at(j) << endl;
//	}
	return ve;
}

/**
 * Se o estado ja foi adicionado, retorna o indice, senao retorna -1
 */
int TuringMachine::index_in(string& str, vest& ve){
	for(uint i = 0; i < ve.size(); i++){
		if(ve.at(i).nome == str)
			return i;
	}
	return -1;
}

/**
 * Verifica se o estado e tem uma transicao para c
 * Se sim, retorna o indice no vetor de transicoes, senao retorna -1
 * 
 */
int TuringMachine::verifica_transicao(Estado& e, char c){
	vstr v = e.transicoes;
	char del[] = ")";
	for(uint i = 0; i < v.size(); i++){
		char * s = strtok((char*)v.at(i).data(), del);
		char t = s[strlen(s)-1]; // char das possiveis transicoes a partir de um estado
		if(t == c)
			return i;
	}
	return -1;
}

/*
 * Verifica para qual estado a transicao leva, retorna o nome do estado
 * ex: (q0,1)=(q1,x,D)
 * RETORNA "q1"
 */
string TuringMachine::aonde_ir(Estado& e, int i){
	string s = e.transicoes.at(i);
	string res;
	int pos = s.find("=(");
	char c = s[pos];
	for(int i = pos+2; c != ','; i++){
		c = s[i];
		if(c != ',')
			res += c;
	}
	cout << res << endl;
	return res;
}