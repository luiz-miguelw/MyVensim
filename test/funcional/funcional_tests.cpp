#include "funcional_tests.h"
#include "..\..\src\lib\modelo.h"
#include "..\..\src\lib\sistema.h"
#include "..\..\src\lib\fluxo.h"

#include <iostream>
#include <cassert>
#include <cmath>

// Teste 1: Modelo Exponencial (pop1, pop2)
void exponentialFuncionalTest() {
    std::cout << "Executando Teste Funcional: Exponencial..." << std::endl;

    Modelo m;
    Sistema* pop1 = m.criaSistema("pop1", 100.0);
    Sistema* pop2 = m.criaSistema("pop2", 0.0);

    Fluxo* exponencial = m.criaFluxo("exponencial", pop1, pop2);
    exponencial->setEquacao([&]() {
        return 0.01 * pop1->getValor();
    });

    // Valor inicial total
    double valorInicial = pop1->getValor() + pop2->getValor();
    assert(std::abs(valorInicial - 100.0) < 0.001);

    m.executa(0, 100, 1);

    // Valor final total
    double valorFinal = pop1->getValor() + pop2->getValor();

    // Teste de conservação de matéria:
    // A soma de pop1 e pop2 deve sempre ser 100.
    assert(std::abs(valorFinal - 100.0) < 0.001);

    std::cout << "  -> Teste Exponencial APROVADO." << std::endl;
}

// Teste 2: Modelo Logístico (p1, p2)
void logisticalFuncionalTest() {
    std::cout << "Executando Teste Funcional: Logistico..." << std::endl;

    Modelo m;
    double pmax = 70.0;

    Sistema* p1 = m.criaSistema("p1", 100.0);
    Sistema* p2 = m.criaSistema("p2", 10.0);

    Fluxo* logistica = m.criaFluxo("logistica", p1, p2);
    logistica->setEquacao([&]() {
        return 0.01 * p2->getValor() * (1.0 - p2->getValor() / pmax);
    });

    m.executa(0, 100, 1);

    // Teste de critério:
    // A população p2 deve se aproximar do limite Pmax (70).
    // Após 100 iterações, o valor deve estar muito próximo de 70.
    assert(std::abs(p2->getValor() - 70.0) < 0.1);

    std::cout << "  -> Teste Logistico APROVADO." << std::endl;
}

// Teste 3: Modelo Complexo (Q1-Q5)
void complexFuncionalTest() {
    std::cout << "Executando Teste Funcional: Complexo..." << std::endl;
    
    Modelo m;

    // 2. Criação dos Sistemas
    Sistema* Q1 = m.criaSistema("Q1", 100.0);
    Sistema* Q2 = m.criaSistema("Q2", 0.0);
    Sistema* Q3 = m.criaSistema("Q3", 100.0);
    Sistema* Q4 = m.criaSistema("Q4", 0.0);
    Sistema* Q5 = m.criaSistema("Q5", 0.0);

    // 3. Criação dos Fluxos
    Fluxo* f = m.criaFluxo("f", Q1, Q2);
    Fluxo* g = m.criaFluxo("g", Q1, Q3);
    Fluxo* r = m.criaFluxo("r", Q2, Q5);
    Fluxo* t = m.criaFluxo("t", Q2, Q3);
    Fluxo* u = m.criaFluxo("u", Q3, Q4);
    Fluxo* v = m.criaFluxo("v", Q4, Q1);

    // 4. Definição das Equações
    f->setEquacao( [&](){ return 0.01 * Q1->getValor(); } );
    g->setEquacao( [&](){ return 0.01 * Q1->getValor(); } );
    r->setEquacao( [&](){ return 0.01 * Q2->getValor(); } );
    t->setEquacao( [&](){ return 0.01 * Q2->getValor(); } );
    u->setEquacao( [&](){ return 0.01 * Q3->getValor(); } );
    v->setEquacao( [&](){ return 0.01 * Q4->getValor(); } );

    // Valor inicial total
    double valorInicial = Q1->getValor() + Q2->getValor() + Q3->getValor() + Q4->getValor() + Q5->getValor();
    assert(std::abs(valorInicial - 200.0) < 0.001);

    // 5. Execução
    m.executa(0, 100, 1);

    // Valor final total
    double valorFinal = Q1->getValor() + Q2->getValor() + Q3->getValor() + Q4->getValor() + Q5->getValor();

    // Teste de conservação de matéria:
    assert(std::abs(valorFinal - 200.0) < 0.001);

    std::cout << "  -> Teste Complexo APROVADO." << std::endl;
}