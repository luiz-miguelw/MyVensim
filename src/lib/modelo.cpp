#include <map>
#include "modelo.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
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


void Modelo::executa(int t_inicial, int t_final, int acrescimo) {
    for (int t = t_inicial; t < t_final; t += acrescimo) {
        
        std::map<Sistema*, double> mudancas;

        for (Fluxo& f : fluxos) {
            double valor_fluxo = f.calcularEquacao();

            Sistema* origem_ptr = f.getOrigem();
            Sistema* destino_ptr = f.getDestino();

            Sistema* sistema_origem_interno = nullptr;
            Sistema* sistema_destino_interno = nullptr;

            if (origem_ptr != nullptr) {
                auto it_origem = std::find_if(sistemas.begin(), sistemas.end(),
                    [origem_ptr](const Sistema& s) {return s == *origem_ptr;});

                if (it_origem != sistemas.end()) {
                    sistema_origem_interno = &(*it_origem);
                }
            }

            if (destino_ptr != nullptr) {
                auto it_destino = std::find_if(sistemas.begin(), sistemas.end(),
                    [destino_ptr](const Sistema& s) {return s == *destino_ptr;});

                if (it_destino != sistemas.end()) {
                    sistema_destino_interno = &(*it_destino);
                }
            }

            if (sistema_origem_interno != nullptr) {
                mudancas[sistema_origem_interno] -= valor_fluxo;
                mudancas[origem_ptr] -= valor_fluxo;
            }
            
            if (sistema_destino_interno != nullptr) {
                mudancas[sistema_destino_interno] += valor_fluxo;
                mudancas[destino_ptr] += valor_fluxo;
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