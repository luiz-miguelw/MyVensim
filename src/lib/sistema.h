/**
 * @file sistema.h
 * @brief Declaração da classe Sistema.
 * @author Luiz Miguel Abreu
 * @date 2025-11-24
 */

#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>
#include <ostream>

/**
 * @class Sistema
 * @brief Representa um reservatório ou "estoque" na simulação de dinâmica de sistemas.
 * * A classe Sistema armazena um valor (nível/estoque) e um nome. 
 * Ela é manipulada pelos fluxos durante a execução do modelo.
 */
class Sistema {
    double valor;       /**< Valor armazenado no sistema (estoque). */
    std::string nome;   /**< Nome de identificação do sistema. */

public:
    /**
     * @brief Construtor Padrão e de Inicialização.
     * @param nome Nome do sistema (padrão: vazio).
     * @param valor_inicial Valor inicial do sistema (padrão: 0.0).
     */
    Sistema(const std::string& nome = "", double valor_inicial = 0.0);

    /**
     * @brief Construtor de Cópia.
     * @param obj Objeto Sistema a ser copiado.
     */
    Sistema(const Sistema& obj);

    /**
     * @brief Destrutor virtual.
     */
    virtual ~Sistema();

    /**
     * @brief Operador de atribuição.
     * @param obj Objeto a ser atribuído.
     * @return Referência para o próprio objeto atualizado.
     */
    Sistema& operator=(const Sistema& obj);

    /**
     * @brief Retorna o valor atual do sistema.
     * @return Double contendo o valor.
     */
    double getValor();

    /**
     * @brief Define um novo valor para o sistema.
     * @param novo_valor O novo valor a ser atribuído (valores negativos tornam-se 0).
     */
    void setValor(double novo_valor);

    /**
     * @brief Retorna o nome do sistema.
     * @return String com o nome.
     */
    std::string getNome();

    /**
     * @brief Define um novo nome para o sistema.
     * @param novo_nome String contendo o novo nome.
     */
    void setNome(const std::string novo_nome);

    /**
     * @brief Sobrecarga do operador de igualdade.
     * @param s1 Primeiro sistema.
     * @param s2 Segundo sistema.
     * @return True se nome e valor forem iguais, False caso contrário.
     */
    friend bool operator==(const Sistema& s1, const Sistema& s2) {
        return (s1.nome == s2.nome) && (s1.valor == s2.valor);
    }
};

#endif // SISTEMA_H