#include "sistema.h"
#include <string>
using namespace std;

Sistema::Sistema(const string& nome, double valor_inicial) {
    this->nome = nome;
    setValor(valor_inicial);
}

Sistema::Sistema(const Sistema& obj) {
    this->nome = obj.nome;
    this->valor = obj.valor;
}

Sistema::~Sistema() {
    // Não há alocação dinâmica manual para limpar aqui
}

Sistema& Sistema::operator=(const Sistema& obj) {
    if (this == &obj) {
        return *this;
    }
    this->nome = obj.nome;
    this->valor = obj.valor;
    return *this;
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