#ifndef HEADER_H_
#define HEADER_H_


#include <iostream>
#include <vector>

#define PROCESSADOR_DE_FC 'P'
#define RECONHECEDOR_DE_LING 'R'

using namespace std;


typedef vector<char> vchar;
typedef vector<string> vstr;

struct Estado {
	vstr transicoes;
	string name;
};

typedef struct Estado Estado;



ostream& operator<<(ostream& os, const Estado& e) {
    return os << e.name << endl; 
}

#endif /*HEADER_H_*/
