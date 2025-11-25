/**
 * @file fluxo.h
 * @brief Declaração da classe Fluxo.
 * @author Luiz Miguel Abreu
 * @date 2025-11-24
 */

#ifndef FLUXO_H
#define FLUXO_H

#include "sistema.h"
#include <string>
#include <functional>

/**
 * @class Fluxo
 * @brief Representa a transferência de valor entre dois Sistemas.
 * * O Fluxo conecta um sistema de origem a um sistema de destino e utiliza
 * uma equação (função) para determinar quanto deve ser transferido a cada passo de tempo.
 */
class Fluxo {
    std::string nome;               /**< Nome do fluxo. */
    Sistema* origem;                /**< Ponteiro para o sistema de origem. */
    Sistema* destino;               /**< Ponteiro para o sistema de destino. */
    std::function<double()> equacao; /**< Função lambda ou functor que define a equação do fluxo. */

public:
    /**
     * @brief Construtor Padrão.
     * @param nome Nome do fluxo.
     * @param origem Ponteiro para sistema de origem.
     * @param destino Ponteiro para sistema de destino.
     * @param equacao Função que retorna o valor do fluxo.
     */
    Fluxo(const std::string& nome = "", Sistema* origem = nullptr, Sistema* destino = nullptr, std::function<double()> equacao = nullptr);

    /**
     * @brief Construtor de Cópia.
     * @param obj Objeto Fluxo a ser copiado.
     */
    Fluxo(const Fluxo& obj);

    /**
     * @brief Destrutor virtual.
     */
    virtual ~Fluxo();

    /**
     * @brief Operador de atribuição.
     * @param obj Fluxo a ser copiado.
     * @return Referência para o objeto.
     */
    Fluxo& operator=(const Fluxo& obj);

    /**
     * @brief Obtém o nome do fluxo.
     * @return String com o nome.
     */
    std::string getNome();

    /**
     * @brief Define o nome do fluxo.
     * @param novo_nome Novo nome.
     */
    void setNome(const std::string& novo_nome);

    /**
     * @brief Obtém o sistema de origem.
     * @return Ponteiro para Sistema.
     */
    Sistema* getOrigem();

    /**
     * @brief Define o sistema de origem.
     * @param novo_origem Ponteiro para o novo sistema de origem.
     */
    void setOrigem(Sistema* novo_origem);

    /**
     * @brief Obtém o sistema de destino.
     * @return Ponteiro para Sistema.
     */
    Sistema* getDestino();

    /**
     * @brief Define o sistema de destino.
     * @param novo_destino Ponteiro para o novo sistema de destino.
     */
    void setDestino(Sistema* novo_destino);

    /**
     * @brief Executa a equação do fluxo.
     * @return Double com o valor calculado pela equação.
     */
    double calcularEquacao();

    /**
     * @brief Define a equação que rege o fluxo.
     * @param nova_equacao Função do tipo std::function<double()>.
     */
    void setEquacao(std::function<double()> nova_equacao);
};

#endif // FLUXO_H