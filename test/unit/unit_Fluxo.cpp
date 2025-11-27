#include "unit_Fluxo.h"
#include <assert.h>
#include <cmath>
#include "../../src/lib/sistema.h"
#include "../../src/lib/fluxo.h"
#include <iostream>

void unit_Fluxo_constructor(void){
    Sistema s1, s2;
    // Teste construtor padrão
    Fluxo f1("Fluxo1", &s1, &s2);
    assert(f1.getNome() == "Fluxo1");
    assert(f1.getOrigem() == &s1);
    assert(f1.getDestino() == &s2);
    
    // Teste construtor de cópia
    Fluxo f2(f1);
    assert(f2.getNome() == "Fluxo1");
    assert(f2.getOrigem() == &s1);
}

void unit_Fluxo_destructor(void){
    // Destrutor padrão
}

void unit_Fluxo_setNome(void){
    Fluxo f;
    f.setNome("FluxoTeste");
    assert(f.getNome() == "FluxoTeste");
}

void unit_Fluxo_getNome(void){
    Fluxo f("FluxoTeste");
    assert(f.getNome() == "FluxoTeste");
}

void unit_Fluxo_setOrigem(void){
    Fluxo f;
    Sistema s;
    f.setOrigem(&s);
    assert(f.getOrigem() == &s);
}

void unit_Fluxo_getOrigem(void){
    Sistema s;
    Fluxo f("", &s, nullptr);
    assert(f.getOrigem() == &s);
}

void unit_Fluxo_setDestino(void){
    Fluxo f;
    Sistema s;
    f.setDestino(&s);
    assert(f.getDestino() == &s);
}

void unit_Fluxo_getDestino(void){
    Sistema s;
    Fluxo f("", nullptr, &s);
    assert(f.getDestino() == &s);
}

void unit_Fluxo_setEquacao(void){
    Fluxo f;
    
    f.setEquacao([]() { return 10.0; }); 
    assert(std::abs(f.calcularEquacao() - 10.0) < 0.0001);
}

void unit_Fluxo_calcularEquacao(void){
    Fluxo f;
    f.setEquacao([]() { return 5.0; });
    assert(std::abs(f.calcularEquacao() - 5.0) < 0.0001);
}

void unit_Fluxo_assignmentOperator(void){
    Sistema s1;
    Fluxo f1("F1", &s1, nullptr);
    Fluxo f2;
    f2 = f1;
    assert(f2.getNome() == "F1");
    assert(f2.getOrigem() == &s1);
}

void run_unit_tests_Fluxo(void){
    unit_Fluxo_constructor();
    unit_Fluxo_destructor();
    unit_Fluxo_setNome();
    unit_Fluxo_getNome();
    unit_Fluxo_setOrigem();
    unit_Fluxo_getOrigem();
    unit_Fluxo_setDestino();
    unit_Fluxo_getDestino();
    unit_Fluxo_setEquacao();
    unit_Fluxo_calcularEquacao();
    unit_Fluxo_assignmentOperator();
    std::cout << "Testes de Fluxo OK!" << std::endl;
}