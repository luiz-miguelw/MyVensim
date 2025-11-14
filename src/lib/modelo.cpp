// para gerar dll: g++ -shared fluxo.cpp modelo.cpp sistema.cpp -o ../../bin/libmyv.so 
#include <map> // Necessário para a solução limpa

#include "modelo.h"
#include <string>

Modelo::Modelo(const std::string& nome) : nome(nome) {}

std::string Modelo::getNome() {
    return nome;
}

void Modelo::setNome(const std::string& novo_nome) {
    nome = novo_nome;
}

void Modelo::adicionarSistema(Sistema sistema) {
    sistemas.push_back(sistema);
}

void Modelo::adicionarFluxo(Fluxo fluxo) {
    fluxos.push_back(fluxo);
}

std::vector<Sistema>& Modelo::getSistemas() {
    return sistemas;
}

std::vector<Fluxo>& Modelo::getFluxos() {
    return fluxos;
}


// Esta é a implementação correta do algoritmo da Figura 5 do PDF
void Modelo::executa(int t_inicial, int t_final, int acrescimo) {
    
    for (int t = t_inicial; t < t_final; t += acrescimo) {
        std::map<Sistema*, double> mudancas;

        for (Fluxo f : fluxos) {
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
            
            sistema_ptr->setValor(sistema_ptr->getValor() + mudanca_liquida);
        }
    }
}