#include "unit_Sistema.h"
#include <assert.h>
#include <cmath>
#include "../../src/lib/sistema.h"
#include <iostream>

void unit_Sistema_constructor(void){
    // Teste construtor padrão
    Sistema s1;
    assert(s1.getValor() == 0.0);
    assert(s1.getNome() == "");

    // Teste construtor com parâmetros
    Sistema s2("Sistema2", 10.0);
    assert(s2.getNome() == "Sistema2");
    assert(std::abs(s2.getValor() - 10.0) < 0.0001);

    // Teste construtor de cópia
    Sistema s3(s2);
    assert(s3.getNome() == "Sistema2");
    assert(std::abs(s3.getValor() - 10.0) < 0.0001);
}

void unit_Sistema_destructor(void){
    
}

void unit_Sistema_setNome(void){
    Sistema s;
    s.setNome("NovoNome");
    assert(s.getNome() == "NovoNome");
}

void unit_Sistema_getNome(void){
    Sistema s("NomeTeste");
    assert(s.getNome() == "NomeTeste");
}

void unit_Sistema_setValor(void){
    Sistema s;
    s.setValor(100.0);
    assert(std::abs(s.getValor() - 100.0) < 0.0001);

    // Teste valor negativo 
    s.setValor(-10.0);
    assert(std::abs(s.getValor() - 0.0) < 0.0001);
}

void unit_Sistema_getValor(void){
    Sistema s("", 55.5);
    assert(std::abs(s.getValor() - 55.5) < 0.0001);
}

void unit_Sistema_assignmentOperator(void){
    Sistema s1("S1", 10.0);
    Sistema s2;
    s2 = s1;
    assert(s2.getNome() == "S1");
    assert(std::abs(s2.getValor() - 10.0) < 0.0001);
}

void run_unit_tests_Sistema(void){
    unit_Sistema_constructor();
    unit_Sistema_destructor();
    unit_Sistema_setNome();
    unit_Sistema_getNome();
    unit_Sistema_setValor();
    unit_Sistema_getValor();
    unit_Sistema_assignmentOperator();
    std::cout << "Testes de Sistema OK!" << std::endl;
}