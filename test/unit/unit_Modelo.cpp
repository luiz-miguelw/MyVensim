#include "unit_Modelo.h"
#include <assert.h>
#include <cmath>
#include <cassert>
#include "../../src/lib/modelo.h"
#include "../../src/lib/sistema.h"
#include "../../src/lib/fluxo.h"
#include <iostream>
using namespace std;

void unit_Modelo_constructor(void){
    Modelo m("Modelo1");
    assert(m.getNome() == "Modelo1");
}

void unit_Modelo_destructor(void){
}

void unit_Modelo_adicionarSistema(void){
    Modelo m;
    Sistema s("S1", 100.0);
    m.adicionarSistema(s);

    assert(m.sistBegin() != m.sistEnd());
    
    assert((*m.sistBegin()).getNome() == "S1");
    assert((*m.sistBegin()).getValor() == 100.0);
}

void unit_Modelo_adicionarFluxo(void){
    Modelo m;
    Sistema s1("Origem"), s2("Destino");
    Fluxo f("F1", &s1, &s2);
    m.adicionarFluxo(f);

    // TESTE ATUALIZADO:
    // 1. Verifica se a lista não está vazia
    assert(m.fluxoBegin() != m.fluxoEnd());

    // 2. Verifica se o fluxo inserido tem o nome correto
    assert((*m.fluxoBegin()).getNome() == "F1");
    assert((*m.fluxoBegin()).getOrigem() == &s1);
}

void unit_Modelo_executa(void){
    
    Modelo m;
    Sistema s1("Origem", 100.0);
    Sistema s2("Destino", 0.0);
    
    Fluxo f("Fluxo", &s1, &s2, [](){ return 10.0; });
    
    m.adicionarFluxo(f); 
    
    m.adicionarSistema(s1); 
    m.adicionarSistema(s2);

    m.executa(0, 1, 1); 

    assert(std::abs(s1.getValor() - 90.0) < 0.0001);
    assert(std::abs(s2.getValor() - 10.0) < 0.0001);

    assert(m.sistBegin()->getValor() == s1.getValor());
    assert((m.sistBegin()+1)->getValor() == s2.getValor());

}

void unit_Modelo_assignmentOperator(void){
    Modelo m1("M1");
    Sistema s("S1", 10.0);
    m1.adicionarSistema(s);

    Modelo m2;
    m2 = m1;
    
    assert(m2.getNome() == "M1");
    // Verifica se a cópia profunda do vetor funcionou usando os novos iteradores
    assert(m2.sistBegin() != m2.sistEnd());
    assert((*m2.sistBegin()).getNome() == "S1");
}

void run_unit_tests_Modelo(void){
    unit_Modelo_constructor();
    unit_Modelo_destructor();
    unit_Modelo_adicionarSistema(); // Agora descomentado e funcional
    unit_Modelo_adicionarFluxo();   // Agora descomentado e funcional
    unit_Modelo_executa();
    unit_Modelo_assignmentOperator();
    std::cout << "Testes de Modelo OK!" << std::endl;
}