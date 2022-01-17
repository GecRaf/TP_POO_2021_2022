//
// Created by Rafac on 12/01/2022.
//

#ifndef TP_POO_2021_2022_EDIFICIO_H
#define TP_POO_2021_2022_EDIFICIO_H

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

class Edificio{
    private:
        string tipo;
        bool active = false;
    public:
        string obtemTipo();

        void defineTipo();

        bool obtemActive();

        void ligaActive();

        void desligaActive();

        Edificio(string tipo);

        ~Edificio();

};



#endif //TP_POO_2021_2022_EDIFICIO_H

//zonas[intLinha][intColuna]->defineEdificio(new Edificio(tipo));