#include "TuringMachine.h"

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


/**
 * input: caso de teste
 */
bool TuringMachine::reconhecer_linguagem(string input){
	OP = RECONHECEDOR_DE_LING;
	bool reconhece = false;
	
	cout << "\nInicializando fita com: " << input << endl;
	Fita::init(input, sFita);	
	Fita::print();
	
	vest estados;

 


	cout << "Inicializando Estados..." << endl;
	estados = parse_transicoes(); 
	
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




