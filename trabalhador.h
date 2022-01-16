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
        int dia_contrato;
        int id; // exemplo: 15.7 (15º trabalhador registado no 7º dia)
        string tipo;
    public:

        int obtemPagamento();

        string obtemTipoTrabalhador();

        int obtemID();

        void defineTrabalhador();

        void obtemDiaContrato();  
};

class Operario : public Trabalhador{
    private:
        int preco=15;
        int operacoes;
        int cansaco=5;// a partir do 10º dia
    public:
        void obtemPreco();
        void obtemOperacoes();
};

class Lenhador : public Trabalhador{
    private:
        int preco=20;
        int lenha_cortada;
        // A cada 4 dias descansa 1
    public:
        void obtemPreco();
        void obtemLenhaCortada();
};

class Mineiro : public Trabalhador{
    private:
        int preco=10;
        int terra;
        int cansaco=10;// a partir 
    public:
        void obtemPreco();
        void obtemLenhaCortada();
};


#endif //TP_POO_2021_2022_TRABALHADOR_H
