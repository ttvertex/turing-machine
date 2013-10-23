#include "TuringMachine.h"

#include <map>

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
	this->sEntrada = sEntrada;
	this->sFita    = sFita;
	this->cTrans   = cTrans;
	this->cEstados = cEstados;
}

/**
 * input: caso de teste
 */
bool TuringMachine::reconhecer_linguagem(string input){
	// Inicializa a fita
	
	fita.init(input, sFita);

	// Transforma o vetor de transicoes em um vetor de struct Estado
	vest estados = create_estados();

	// Nome do estado (q1,q2...) e o indice correspondente no vetor de estados
	// ex: q1 : 0
	//     q2 : 1
	map<string, int> estadoIndex; 
	for(uint i = 0; i < estados.size(); i++){ /// Inicializa o map
		estadoIndex[estados.at(i).nome] = i;
	}

	Estado_t eatual = estados.at(0);
	while( true ){ // enquanto nao chegar no qaceita
		// Retorna o indice no vetor de transicoes do estado, que tem a transicao para o char 
		int x = verifica_transicao(eatual, fita.get());

		if( x == -1 ){ // se nao encontrou a transicao no estado, aborta
			return false;
		}
#ifdef DEBUG
		fita.print();
#endif
		Transicao_t t = parse_transicao(eatual, x);
		fita.set(t.cescrita); // Escreve o caractere na fita
		if(t.direcao == 'D')   // Anda na fita
			fita.D();
		else if(t.direcao == 'E'){
			if(!fita.E()){ // mover para negativo! fita finita para a esquerda.
#ifdef DEBUG
				cout << "mover para negativo! fita finita para a esquerda." <<endl;
#endif
				return false;
			}
		}else{
#ifdef DEBUG
			cout << "\nErro: direcao intexistente!" << endl;
#endif
			exit(EXIT_FAILURE);
		}

		if( t.estado == QACEITA )
			return true;
			
		eatual = estados.at(estadoIndex[t.estado]);
	}
}

/**
 * Processa uma funcao e imprime o resultado final da fita
 */
bool TuringMachine::processa_funcao(string input){
	if(reconhecer_linguagem(input)){
		fita.print_sem_brancos();
		return true;
	}
	return false;
}

/**
 * Transforma um conjunto de strings (transicoes) em um conjunto de estados,
 * onde cada estado tem suas funcoes de transicao (que saem dele)
 */

vest TuringMachine::create_estados(){
	vest ve;
	char del[] = "(,";
	
	for(uint i = 0; i < cTrans.size(); i++){
		string s = cTrans.at(i).data();
		
		string tok = strtok((char*)s.data(), del);
		int index = index_in(tok, ve);

		if( index == -1 ){ // criar um novo estado
			Estado_t e;
			e.nome = tok;
			e.transicoes.push_back(cTrans.at(i).data());
			ve.push_back(e);
		} else { // adicionar em estado existente
			ve.at(index).transicoes.push_back(cTrans.at(i).data());
		}	
	}
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
int TuringMachine::verifica_transicao(Estado_t& e, char c){
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
 * Retorna uma struct correspondente ao destino da transicao, ou seja, pra onde ela vai levar,
 * o que vai escrever na fita, e para qual direcao o controle da fita deve ir.  
 * ex: (q1,0)=(q2,x,D)
 * RETORNA uma struct { q2, x, D}
 */
Transicao_t TuringMachine::parse_transicao(Estado_t& e, int index){
	Transicao_t t;
	string s = e.transicoes.at(index);

	string est;
	int pos = s.find("=(");
	char c = s[pos];
	for(int i = pos+2; c != ','; i++){
		c = s[i];
		if(c != ',')
			est += c;
		else{
			t.estado = est;
			t.cescrita = s[i+1];
			t.direcao  = s[i+3];
			break;
		}
	}
#ifdef DEBUG
	//cout << t << endl;
#endif
	return t;
}