#ifndef HEADER_H_
#define HEADER_H_


#include <iostream>
#include <vector>

#define PROCESSADOR_DE_FC 'P'
#define RECONHECEDOR_DE_LING 'R'

using namespace std;

// Pra facilitar
typedef vector<char> vchar;
typedef vector<string> vstr;

typedef struct  {
	vstr transicoes;
	string nome;
}Estado;

ostream& operator<<(ostream& os, const Estado& e) {
    return os << e.nome << endl; 
}

#endif /*HEADER_H_*/
