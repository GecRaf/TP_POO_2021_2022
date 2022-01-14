//
// Created by Rafac on 12/01/2022.
//

#ifndef TP_POO_2021_2022_TRABALHADOR_H
#define TP_POO_2021_2022_TRABALHADOR_H

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

class Trabalhador{
    private:
        int pagamento;
        string tipo;
        int id; // exemplo: 15.7 (15º trabalhador registado no 7º dia)
    public:
        void share_id();
};

#endif //TP_POO_2021_2022_TRABALHADOR_H
