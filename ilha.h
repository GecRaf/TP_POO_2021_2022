//
// Created by Rafac on 12/01/2022.
//

#ifndef TP_POO_2021_2022_ILHA_H
#define TP_POO_2021_2022_ILHA_H

#include "zona.h"

class Ilha{
private:
    int nLinhas, nColunas;
    vector< vector<zona*> > zonas;
public:
    Ilha(int linhas, int colunas);
    void mostraVector();
    void iniciaMatriz(int nLinhas, int nColunas);
    void leitorComandos();
};

#endif //TP_POO_2021_2022_ILHA_H
