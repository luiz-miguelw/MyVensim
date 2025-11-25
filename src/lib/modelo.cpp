#include <map>
#include "modelo.h"
#include <string>
using namespace std;


Modelo::Modelo(const string& nome) : nome(nome) {}


Modelo::Modelo(const Modelo& obj) {
    this->nome = obj.nome;
    this->sistemas = obj.sistemas; 
    this->fluxos = obj.fluxos;
}


Modelo::~Modelo() {
    // Vector limpa automaticamente seus elementos
}


Modelo& Modelo::operator=(const Modelo& obj) {
    if (this == &obj) {
        return *this;
    }
    this->nome = obj.nome;
    this->sistemas = obj.sistemas;
    this->fluxos = obj.fluxos;
    return *this;
}

string Modelo::getNome() {
    return nome;
}

void Modelo::setNome(const string& novo_nome) {
    nome = novo_nome;
}

void Modelo::adicionarSistema(Sistema sistema) {
    sistemas.push_back(sistema);
}

void Modelo::adicionarFluxo(Fluxo fluxo) {
    fluxos.push_back(fluxo);
}

vector<Sistema>& Modelo::getSistemas() {
    return sistemas;
}

vector<Fluxo>& Modelo::getFluxos() {
    return fluxos;
}

void Modelo::executa(int t_inicial, int t_final, int acrescimo) {
    for (int t = t_inicial; t < t_final; t += acrescimo) {
        map<Sistema*, double> mudancas;

        for (Fluxo& f : fluxos) {
            double valor_fluxo = f.calcularEquacao();

            Sistema* origem = f.getOrigem();
            Sistema* destino = f.getDestino();
            
            if (origem != nullptr) {
                mudancas[origem] -= valor_fluxo;
            }
            if (destino != nullptr) {
                mudancas[destino] += valor_fluxo;
            }
        }
        
        for (auto const& par : mudancas) {
            Sistema* sistema_ptr = par.first;
            double mudanca_liquida = par.second;
            
            if (sistema_ptr != nullptr) {
                 sistema_ptr->setValor(sistema_ptr->getValor() + mudanca_liquida);
            }
        }
    }
}