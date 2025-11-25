#include <iostream>
#include <string>
#include <vector>
#include "lib/modelo.h"
#include "lib/sistema.h"
#include "lib/fluxo.h"

int main() {
    std::cout << "MyVensim - Simulador de Modelos de Sistemas Dinâmicos" << std::endl;

    Modelo modelo("Cidade");

    Sistema populacao("Populacao", 10000.0);

    Fluxo nascimento("nascimento", nullptr, &populacao);
    Fluxo morte("morte", &populacao, nullptr);

    nascimento.setEquacao([&]() { return 100; });

    morte.setEquacao([&]() { return 0.05 * populacao.getValor(); });

    modelo.adicionarSistema(populacao);
    modelo.adicionarFluxo(nascimento);
    modelo.adicionarFluxo(morte);

    modelo.executa(0, 100, 1);

    std::cout << "Populacao final apos 100 unidades de tempo: " << populacao.getValor() << std::endl;
    
    return 0;
}