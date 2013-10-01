#include "Header.h"

#include "TuringMachine.h"

int E, SE, SF, NT;
vchar sEntrada, sFita;
vstr  cTrans, cEstados, cTeste;
char OP;


void le_arquivo();
void imprime_arquivo();

int main(int argc, char** argv){

	le_arquivo();
	//imprime_arquivo();
	TuringMachine* t = new TuringMachine(cEstados, sEntrada, sFita, cTrans);
	t->reconhecer_linguagem(cTeste[0]);
}


void le_arquivo(){

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

	cout << "\nEstados: "<< E << "\nSimbolos de Entrada: " << SE 
	<< "\nSimbolos da Fita: " << SF << "\nNumero de Transicoes " << NT << endl;

	/// Estados
	cout << endl;
	for(int i = 0; i < E; i++){
		cout << cEstados[i] << " "; 
	}
	// Simbolos de Entrada
	cout << endl;
	for(int i = 0; i < SE; i++){
		cout << sEntrada[i] << " ";
	}
	/// Simbolos da Fita
	cout << endl;
	for(int i = 0; i < SF; i++){
		cout << sFita[i] << " ";
	}
	/// Conjunto de Transicoes
	cout << endl;
	for(int i = 0; i < NT; i++){
		cout << cTrans[i] << endl;
	}

	if(OP == RECONHECEDOR_DE_LING){
		/// Conjunto de testes
		cout << "\nReconhecer Linguagens: " << endl;
		for(unsigned int i = 0; i < cTeste.size(); i++){
			cout << cTeste[i] << endl;
		}
	}
}