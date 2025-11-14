// para gerar dll: g++ main.cpp funcional_tests.cpp -L../../bin -llibmyv -o ../../bin/funcional_test.exe
#ifndef MAIN_FUNCIONAL_TESTS
#define MAIN_FUNCIONAL_TESTS

#include "funcional_tests.h"
#include "../../src/lib/modelo.h"
#include "../../src/lib/sistema.h"
#include "../../src/lib/fluxo.h"
#include <iostream>

int main() {
    std::cout << "======== INICIANDO TESTES FUNCIONAIS ========" << std::endl;
    
    exponentialFuncionalTest();
    logisticalFuncionalTest();
    complexFuncionalTest();

    std::cout << "============================================" << std::endl;
    std::cout << "TODOS OS TESTES FUNCIONAIS PASSARAM COM SUCESSO." << std::endl;
    
    return 0; // 0 indica sucesso
}

#endif // MAIN_FUNCIONAL_TESTS