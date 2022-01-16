//
// TP_2122_POO || Rafael Couto 2019142454 || Rodrigo Ferreira 2019138331
//

#include "edificio.h"

string Edificio::obtemTipo()
{
    return tipo;
};

void Edificio::defineTipo()
{
    this->tipo = tipo;
};

bool Edificio::obtemActive()
{
    return active;
};

Edificio::Edificio(string tipo){
    this->tipo = tipo;
};

Edificio::~Edificio(){

};