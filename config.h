//
// TP_2122_POO || Rafael Couto 2019142454 || Rodrigo Ferreira 2019138331
//

#ifndef TP_POO_2021_2022_CONFIG_H
#define TP_POO_2021_2022_CONFIG_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace std;

class zona {
private:
    string tipoZona;
    string edificio;
    string tipoTrabalhador;
    int nTrabalhadores = 0;
public:
    string obtemTipoZona();

    void defineZona(string tipoZona);

    int obtemTrabalhadores();

    string obtemTipoTrabalhador();

    void defineTrabalhadores(string tipoTrabalhadores);

    string obtemEdificio();

    void defineEdificio(string edificio);
};

vector<vector<zona> > iniciaMatriz(int nLinhas, int nColunas);

void mostraVector(vector<vector<zona> >, int nLinhas, int nColunas);

void leitorComandos(vector<vector<zona> > zonas, int nLinhas, int nColunas);

#endif //TP_POO_2021_2022_CONFIG_H
