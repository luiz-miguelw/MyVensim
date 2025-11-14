#ifndef FLUXO_H
#define FLUXO_H

#include "sistema.h"
#include <string>
#include <functional>

class Fluxo{
    std::string nome;
    Sistema* origem;
    Sistema* destino;
    std::function<double()> equacao;
public:
    Fluxo(const std::string& nome = "", Sistema* origem = nullptr, Sistema* destino = nullptr, std::function<double()> equacao = nullptr);

    std::string getNome();
    void setNome(const std::string& novo_nome);

    Sistema* getOrigem();
    void setOrigem(Sistema* novo_origem);

    Sistema* getDestino();
    void setDestino(Sistema* novo_destino);

    double calcularEquacao();

    void setEquacao(std::function<double()> nova_equacao);
};

#endif // FLUXO_H