//
// Created by Rafac on 21/11/2021.
//

#include "config.h"

vector < vector<zona> > iniciaMatriz(int nLinhas, int nColunas)
{
    zona z;
    vector < vector<zona> > zonas;
    vector <zona> tmp;
    for (int i=0; i<nLinhas; i++)
    {
        for (int j=0; j<nColunas; j++)
        {
            tmp.push_back(z);
        }
        zonas.push_back(tmp);
    }
    return zonas;
}

string zona::obtemTipoZona() {
    return tipoZona;
}

void zona::defineZona(string tipoZona)
{
    this->tipoZona=tipoZona;
}
int zona::obtemTrabalhadores()
{
    return nTrabalhadores;
}
void zona::defineTrabalhadores(int nTrabalhadores)
{
    this->nTrabalhadores = nTrabalhadores;
}
string zona::obtemEdificio()
{
    return edificio;
}
void zona::defineEdificio(string edificio)
{
    this->edificio = edificio;
}