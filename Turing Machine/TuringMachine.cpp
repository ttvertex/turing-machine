#include "TuringMachine.h"

/**
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

TuringMachine::TuringMachine(vchar& sEntrada, vchar& sFita, vstr& cTrans, vstr& cEstados)
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

