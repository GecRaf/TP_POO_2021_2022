//
// Created by Rafac on 21/11/2021.
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

using namespace std;

class zona{
private:
    string tipoZona;
    string edificio;
    string tipoTrabalhador;
    int nTrabalhadores;
public:
    string obtemTipoZona();
    void defineZona(string tipoZona);
    int obtemTrabalhadores();
    void defineTrabalhadores(int nTrabalhadores);
    string obtemEdificio();
    void defineEdificio(string edificio);
};

vector < vector<zona> > iniciaMatriz(int nLinhas, int nColunas);
void mostraVector(vector < vector<zona> >, int nLinhas, int nColunas);
void splitString(string &comando);

#endif //TP_POO_2021_2022_CONFIG_H
