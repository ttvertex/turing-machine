#ifndef HEADER_H_
#define HEADER_H_


#include <iostream>
#include <vector>
#include <string.h>
#include <cstdlib>

//#define DEBUG

#define PROCESSADOR_DE_FC 'P'
#define RECONHECEDOR_DE_LING 'R'

#define QACEITA "qac"
#define QREJEITA "qrej"

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
}Estado_t;

typedef struct {
	string estado;   // praonde ir 
	char   cescrita; // escrever oq
	char   direcao;  // andar a fita em qual dir
} Transicao_t;

typedef vector<Estado_t> vest;

inline ostream& operator<<(ostream& os, const Estado_t& e) {
    return os << e.nome << endl; 
}
inline ostream& operator<<(ostream& os, const Transicao_t& t) {
    return os << "(" << t.estado << "," << t.cescrita << "," << t.direcao << ")" << endl; 
}

#endif /*HEADER_H_*/
