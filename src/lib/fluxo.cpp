#include "fluxo.h"
#include "sistema.h"
#include <string>
using namespace std;

Fluxo::Fluxo(const string& nome, Sistema* origem, Sistema* destino,std::function<double()> nova_equacao) {
    this->nome = nome;
    this->origem = origem;
    this->destino = destino;
    this->equacao = nova_equacao;
}

string Fluxo::getNome() {
    return this->nome;
}
void Fluxo::setNome(const string& novo_nome) {
    this->nome = novo_nome;
}

Sistema* Fluxo::getOrigem() {
    return this->origem;
}
void Fluxo::setOrigem(Sistema* novo_origem) {
    this->origem = novo_origem;
}

Sistema* Fluxo::getDestino() {
    return this->destino;
}
void Fluxo::setDestino(Sistema* novo_destino) {
    this->destino = novo_destino;
}

void Fluxo::setEquacao(std::function<double()> nova_equacao) {
        this->equacao = nova_equacao;
}

double Fluxo::calcularEquacao() {
    if(this->equacao) {
        return this->equacao();
    }
    return 0.0;
}