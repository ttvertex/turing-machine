#ifndef HEADER_H_
#define HEADER_H_


#include <iostream>
#include <vector>
#include <string.h>

#define PROCESSADOR_DE_FC 'P'
#define RECONHECEDOR_DE_LING 'R'

#define DIREITA 1
#define ESQUERDA -1

using namespace std;

// Pra facilitar
typedef vector<char>   vchar;
typedef vector<string> vstr;
typedef unsigned int   uint;

typedef struct  {
	vstr transicoes;
	string nome;
}Estado;

typedef vector<Estado> vest;

inline ostream& operator<<(ostream& os, const Estado& e) {
    return os << e.nome << endl; 
}

#endif /*HEADER_H_*/
