//
// TP_2122_POO || Rafael Couto 2019142454 || Rodrigo Ferreira 2019138331
//

#include "trabalhador.h"

int Trabalhador::obtemPagamento()
{
    return pagamento;
};

string Trabalhador::obtemTipoTrabalhador()
{
    return tipo;
};

void Trabalhador::defineTrabalhador()
{
    this->tipo = tipo;
};

int Trabalhador::obtemID()
{
    return id;
};
