#include "unit_tests.h"
#include <iostream>

int main() {
    std::cout << "========= INICIANDO TESTES UNITARIOS =========" << std::endl;
    
    testSistemaUnit();
    testFluxoUnit();
    testModeloUnit();
    
    std::cout << "============================================" << std::endl;
    std::cout << "TODOS OS TESTES UNITARIOS PASSARAM COM SUCESSO." << std::endl;
    
    return 0; // 0 indica sucesso
}