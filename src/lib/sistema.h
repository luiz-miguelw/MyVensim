#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>  

class Sistema {
    double valor;
    std::string nome; 
    
public:
    Sistema(const std::string& nome = "", double valor_inicial = 0.0);

    double getValor();
    void setValor(double novo_valor);  
    
    std::string getNome();
    void setNome(std::string novo_nome);

    bool friend operator==(const Sistema& s1, const Sistema& s2) {
        return (s1.nome == s2.nome) && (s1.valor == s2.valor);
    }
};

#endif // SISTEMA_H