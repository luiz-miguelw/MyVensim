// para gerar dll: g++ -shared fluxo.cpp modelo.cpp sistema.cpp -o ../../bin/libmyv.dll 

#include "sistema.h"
#include <string>
using namespace std;

Sistema::Sistema(const string& nome, double valor_inicial) {
    this->nome = nome;
    setValor(valor_inicial);
}

double Sistema::getValor() {
    return this->valor;
}

void Sistema::setValor(double novo_valor) {
    if(novo_valor < 0) {
        novo_valor = 0;
    }
    this->valor = novo_valor;
}

std::string Sistema::getNome() {
    return this->nome;
}

void Sistema::setNome(std::string novo_nome) {
    this->nome = novo_nome;
}