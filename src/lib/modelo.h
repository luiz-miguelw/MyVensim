/**
 * @file modelo.h
 * @brief Declaração da classe Modelo.
 * @author Luiz Miguel Abreu
 * @date 2025-11-24
 */

#ifndef MODELO_H
#define MODELO_H

#include <vector>
#include <string>
#include "sistema.h"
#include "fluxo.h"

/**
 * @class Modelo
 * @brief Gerencia a simulação, contendo sistemas e fluxos.
 * * A classe Modelo é responsável por agrupar os componentes da simulação
 * e controlar a execução temporal (passos de tempo).
 */
class Modelo {
    std::string nome;               /**< Nome do modelo. */
    std::vector<Sistema> sistemas;  /**< Container de sistemas. */
    std::vector<Fluxo> fluxos;      /**< Container de fluxos. */

public:
    /**
     * @brief Construtor Padrão.
     * @param nome Nome do modelo.
     */
    Modelo(const std::string& nome = "");

    /**
     * @brief Construtor de Cópia.
     * @param obj Modelo a ser copiado.
     */
    Modelo(const Modelo& obj);

    /**
     * @brief Destrutor virtual.
     */
    virtual ~Modelo();

    /**
     * @brief Operador de atribuição.
     * @param obj Modelo a ser copiado.
     * @return Referência para o objeto.
     */
    Modelo& operator=(const Modelo& obj);

    /**
     * @brief Obtém o nome do modelo.
     * @return String com o nome.
     */
    std::string getNome();

    /**
     * @brief Define o nome do modelo.
     * @param novo_nome Novo nome.
     */
    void setNome(const std::string& novo_nome);

    /**
     * @brief Adiciona um sistema ao modelo.
     * @param sistema Objeto sistema a ser adicionado (cópia).
     */
    void adicionarSistema(Sistema sistema);

    /**
     * @brief Adiciona um fluxo ao modelo.
     * @param fluxo Objeto fluxo a ser adicionado (cópia).
     */
    void adicionarFluxo(Fluxo fluxo);

    /**
     * @brief Acessa o vetor de sistemas.
     * @return Referência para o vetor de sistemas.
     */
    std::vector<Sistema>& getSistemas();

    /**
     * @brief Acessa o vetor de fluxos.
     * @return Referência para o vetor de fluxos.
     */
    std::vector<Fluxo>& getFluxos();

    /**
     * @brief Executa a simulação.
     * * Itera do tempo inicial ao final, calculando os fluxos e atualizando
     * os sistemas a cada passo.
     * * @param t_inicial Tempo de início.
     * @param t_final Tempo de fim.
     * @param acrescimo Passo de tempo (incremento).
     */
    void executa(int t_inicial, int t_final, int acrescimo);
};

#endif // MODELO_H