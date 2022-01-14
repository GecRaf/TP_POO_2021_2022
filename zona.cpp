//
// TP_2122_POO || Rafael Couto 2019142454
//

#include "zona.h"



string zona::obtemTipoZona() {
    string tipoZona = "";
    int randnum;

    srand((unsigned) time(0));

    randnum = 1 + (rand() % 6);

    switch(randnum){
        case 1:
            tipoZona="mnt";
            break;
        case 2:
            tipoZona="dsr";
            break;
        case 3:
            tipoZona="pas";
            break;
        case 4:
            tipoZona="flr";
            break;
        case 5:
            tipoZona="pnt";
            break;
        case 6:
            tipoZona="znZ";
            break;
        default:
            cout << "Erro ao atribuir uma zona";
            break;
    }
    return tipoZona;
}

void zona::defineZona(string tipoZona) {
    this->tipoZona = tipoZona;
}

int zona::obtemTrabalhadores() {
    return nTrabalhadores;
}

string zona::obtemTipoTrabalhador(){
    return tipoTrabalhador;
}

void zona::defineTrabalhadores(string tipoTrabalhador) {
    this->tipoTrabalhador = tipoTrabalhador;
}

string zona::obtemEdificio() {
    return edificio;
}

void zona::defineEdificio(string edificio) {
    cout << "\n";
    cout << "Edificio " << edificio << " construido!" << endl;
    cout << "\n";
    this->edificio = edificio;
}


