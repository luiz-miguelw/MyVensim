// para gerar dll: g++ main.cpp unit_tests.cpp -L../../bin -lmyv -o ../../bin/unit_test.exe

#include "unit_tests.h"
#include "../../src/lib/modelo.h"
#include "../../src/lib/sistema.h"
#include "../../src/lib/fluxo.h"

#include <iostream>
#include <cassert>
#include <cmath> 

// Teste Unitário: Classe Sistema
void testSistemaUnit() {
    std::cout << "  Executando Teste Unitario: Sistema..." << std::endl;

    // Teste de construtor e getters
    Sistema s("pop", 120.5);
    assert(s.getNome() == "pop");
    assert(std::abs(s.getValor() - 120.5) < 0.001);

    // Teste de setter e getter
    s.setValor(50.2);
    assert(std::abs(s.getValor() - 50.2) < 0.001);

    
    Sistema s2;
    s2.setNome("q1");
    s2.setValor(10);
    assert(s2.getNome() == "q1");
    assert(std::abs(s2.getValor() - 10) < 0.001);
}

// Teste Unitário: Classe Fluxo
void testFluxoUnit() {
    std::cout << "  Executando Teste Unitario: Fluxo..." << std::endl;
    
    Sistema s1("s1", 10.0);
    Sistema s2("s2", 20.0);

    
    Fluxo f("f1", &s1, &s2);
    assert(f.getOrigem() == &s1);
    assert(f.getDestino() == &s2);
    assert(f.getNome() == "f1");
    f.setEquacao([&]() { return 0.1 * s1.getValor(); });
    double resultado = f.calcularEquacao();
    assert(std::abs(resultado - 1.0) < 0.001);
}

// Teste Unitário: Classe Modelo
void testModeloUnit() {
    std::cout << "  Executando Teste Unitario: Modelo..." << std::endl;
    
    Modelo m("modelo1");

    // Teste de criação de Sistema
    Sistema s1("s1", 10.0);
    assert(s1.getNome() == "s1");
    assert(std::abs(s1.getValor() - 10.0) < 0.001);

    Sistema s2("s2", 20.0);
    assert(s2.getNome() == "s2");
    // Teste de criação de Fluxo
    Fluxo f1("f1", &s1, &s2);
    assert(f1.getOrigem() == &s1);
    assert(f1.getDestino() == &s2);
    f1.setEquacao([&]() { return 1;});

    // Adiciona Sistemas e Fluxos ao Modelo
    m.adicionarSistema(s1);
    m.adicionarSistema(s2);
    m.adicionarFluxo(f1);

    assert(m.getSistemas().size() == 2);
    assert(m.getFluxos().size() == 1);

    m.executa(0, 5, 1);
    
    assert(s1.getValor() == 5);
    assert(s2.getValor() == 25);
}