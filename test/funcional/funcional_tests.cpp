#include "funcional_tests.h"
#include "../../src/lib/modelo.h"
#include "../../src/lib/sistema.h"
#include "../../src/lib/fluxo.h"
#include <iostream>
#include <cassert>
#include <cmath>

// Teste 1: Modelo Exponencial 
void exponentialFuncionalTest() {
    std::cout << "Executando Teste Funcional: Exponencial..." << std::endl;

    Modelo m("Exponencial");

    Sistema sis1("sis1", 100.0);
    Sistema sis2("sis2", 0.0);
    m.adicionarSistema(sis1);
    m.adicionarSistema(sis2);
    
    Fluxo exponencial("exponencial", &sis1, &sis2);
    
    exponencial.setEquacao([&]() {
        return 0.01 * sis1.getValor();
    });

    m.adicionarFluxo(exponencial);

    double valorInicial = sis1.getValor() + sis2.getValor();
    
    assert(std::abs(valorInicial - 100.0) < 0.001);
    
    m.executa(0, 100, 1);

    
    double valorFinal = sis1.getValor() + sis2.getValor();

    assert(std::abs(sis1.getValor() - 36.6032) < 0.001); 
    assert(std::abs(sis2.getValor() - 63.3968) < 0.001); 

    
    assert(std::abs(valorFinal - valorInicial) < 0.001);

    std::cout << "  -> Teste Exponencial APROVADO." << std::endl;
}

// Teste 2: Modelo Logístico 
void logisticalFuncionalTest() {
    std::cout << "Executando Teste Funcional: Logistico..." << std::endl;

    Modelo m("Logistico");
    double pmax = 70.0;

    Sistema sis1("sis1", 100.0);
    Sistema sis2("sis2", 10.0);
   
    m.adicionarSistema(sis1);
    m.adicionarSistema(sis2);

    Fluxo logistica("logistica", &sis1, &sis2);

    logistica.setEquacao([&]() {
        return 0.01 * sis2.getValor() * (1.0 - sis2.getValor() / pmax);
    });

    m.adicionarFluxo(logistica);

    m.executa(0, 100000, 1);

    
    
    assert(std::abs(sis2.getValor() - 70.0) < 0.0001); // sis2 se aproxima de 70
    assert(std::abs(sis1.getValor() - 40.0) < 0.0001); // sis1 perde o que sis2 ganhou

    std::cout << "  -> Teste Logistico APROVADO." << std::endl;
}

// Teste 3: Modelo Complexo 
void complexFuncionalTest() {
    std::cout << "Executando Teste Funcional: Complexo..." << std::endl;
    
    Modelo m("Complexo");

    
    Sistema Q1("Q1", 100.0);
    Sistema Q2("Q2", 0.0);
    Sistema Q3("Q3", 100.0);
    Sistema Q4("Q4", 0.0);
    Sistema Q5("Q5", 0.0);
    
    m.adicionarSistema(Q1);
    m.adicionarSistema(Q2);
    m.adicionarSistema(Q3);
    m.adicionarSistema(Q4);
    m.adicionarSistema(Q5);

    Fluxo f("f", &Q1, &Q2);
    Fluxo g("g", &Q1, &Q3);
    Fluxo r("r", &Q2, &Q5);
    Fluxo t("t", &Q2, &Q3);
    Fluxo u("u", &Q3, &Q4);
    Fluxo v("v", &Q4, &Q1);

    f.setEquacao( [&](){ return 0.01 * Q1.getValor(); } );
    g.setEquacao( [&](){ return 0.01 * Q1.getValor(); } );
    r.setEquacao( [&](){ return 0.01 * Q2.getValor(); } );
    t.setEquacao( [&](){ return 0.01 * Q2.getValor(); } );
    u.setEquacao( [&](){ return 0.01 * Q3.getValor(); } );
    v.setEquacao( [&](){ return 0.01 * Q4.getValor(); } );

    m.adicionarFluxo(f);
    m.adicionarFluxo(g);
    m.adicionarFluxo(r);
    m.adicionarFluxo(t);
    m.adicionarFluxo(u);
    m.adicionarFluxo(v);

    double valorInicial = Q1.getValor() + Q2.getValor() + Q3.getValor() + Q4.getValor() + Q5.getValor();
    assert(std::abs(valorInicial - 200.0) < 0.001);

    m.executa(0, 100, 1);

    double valorFinal = Q1.getValor() + Q2.getValor() + Q3.getValor() + Q4.getValor() + Q5.getValor();

    assert(std::abs(valorFinal - 200.0) < 0.001);

    assert(std::abs(Q1.getValor() - 31.8513) < 0.0001);
    assert(std::abs(Q2.getValor() - 18.4003) < 0.0001);
    assert(std::abs(Q3.getValor() - 77.1143) < 0.0001);
    assert(std::abs(Q4.getValor() - 56.1728) < 0.0001);
    assert(std::abs(Q5.getValor() - 16.4612) < 0.0001);


    std::cout << "  -> Teste Complexo APROVADO." << std::endl;
}