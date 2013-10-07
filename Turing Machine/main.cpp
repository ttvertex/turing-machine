

#include "Header.h"

#include "TuringMachine.h"


vchar sEntrada, sFita;
vstr  cTrans, cEstados, cTeste;
char OP;


void le_arquivo();
void imprime_arquivo();

int main(int argc, char** argv){

	le_arquivo();	
	
	TuringMachine tm(cEstados, sEntrada, sFita, cTrans);
	if(tm.reconhecer_linguagem(cTeste[0]+"B"))
		cout << "aceita" << endl;
	else
		cout << "rejeita" << endl;
}


void le_arquivo(){
	int E, SE, SF, NT;

	cin >> E >> SE >> SF >> NT;

	/// Estados
	for(int i = 0; i < E; i++){
		string s;
		cin >> s;
		cEstados.push_back(s);
	}

	// Simbolos de Entrada	
	for(int i = 0; i < SE; i++){
		char c;
		cin >> c;
		sEntrada.push_back(c);
	}

	/// Simbolos da Fita
	for(int i = 0; i < SF; i++){
		char c; 
		cin >> c;
		sFita.push_back(c);
	}

	/// Conjunto de Transicoes
	for(int i = 0; i < NT; i++){
		string s;
		cin >> s;
		cTrans.push_back(s);
	}

	cin >> OP;
	if(OP == RECONHECEDOR_DE_LING){
		int t;
		cin >> t;
		for(int i = 0; i < t; i++){
			string s;
			cin >> s;
			cTeste.push_back(s);
		}
	}else if (OP == PROCESSADOR_DE_FC){ 
		
	}
}

void imprime_arquivo() {

	cout << "\nEstados: "<< cEstados.size() << "\nSimbolos de Entrada: " << sEntrada.size() 
	<< "\nSimbolos da Fita: " << sFita.size() << "\nNumero de Transicoes " << cTrans.size() << endl;

	/// Estados
	cout << endl;
	for(uint i = 0; i < cEstados.size(); i++){
		cout << cEstados[i] << " "; 
	}
	// Simbolos de Entrada
	cout << endl;
	for(uint i = 0; i < sEntrada.size(); i++){
		cout << sEntrada[i] << " ";
	}
	/// Simbolos da Fita
	cout << endl;
	for(uint i = 0; i < sFita.size(); i++){
		cout << sFita[i] << " ";
	}
	/// Conjunto de Transicoes
	cout << endl;
	for(uint i = 0; i <  cTrans.size(); i++){
		cout << cTrans[i] << endl;
	}

	if(OP == RECONHECEDOR_DE_LING){
		/// Conjunto de testes
		cout << "\nReconhecer Linguagens: " << endl;
		for(uint i = 0; i < cTeste.size(); i++){
			cout << cTeste[i] << endl;
		}
	}
}