#ifndef MODELO_H  
#define MODELO_H
#include <vector>
#include "sistema.h"
#include "fluxo.h"

class Modelo {
    std::string nome;
    std::vector<Sistema> sistemas;
    std::vector<Fluxo> fluxos;
public:
    Modelo(const std::string& nome = "");

    std::string getNome();
    void setNome(const std::string& novo_nome);

    void adicionarSistema(Sistema sistema);
    void adicionarFluxo(Fluxo fluxo);

    std::vector<Sistema>& getSistemas();
    std::vector<Fluxo>& getFluxos();

    void executa(int t_inicial, int t_final, int acrescimo);
};

#endif // MODELO_H