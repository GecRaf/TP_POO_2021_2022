//
// Created by Rafac on 12/01/2022.
//

#ifndef TP_POO_2021_2022_ZONA_H
#define TP_POO_2021_2022_ZONA_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iomanip>

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

void leitorComandos(vector<vector<zona*> > zonas, int nLinhas, int nColunas);

#endif //TP_POO_2021_2022_ZONA_H
