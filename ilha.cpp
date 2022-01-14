//
// TP_2122_POO || Rafael Couto 2019142454 || Rodrigo Ferreira 2019138331
//
#include "ilha.h"

void Ilha::vector<vector<zona> > iniciaMatriz(int nLinhas, int nColunas) {
    zona z;
    vector<vector<zona*> > zonas;
    vector<zona*> tmp;
    for (int i = 0; i < nLinhas; i++) {
        for (int j = 0; j < nColunas; j++) {
            tmp->push_back(z);
        }
        zonas->push_back(tmp);
    }
}

void Ilha::mostraVector() {
    vector<vector<zona*> > zonas;

    for(int i = 0; i < nLinhas; i++){
        for(int j = 0; j < nColunas; j++){
            cout << "*-------";
            if(j == (nColunas - 1)){
                cout <<  "*";
            }
        }
        cout << endl;
        for(int z = 0; z < 4; z++){
            for(int k = 0; k < nColunas; k++){
                if(z == 0) cout << "|" << left << setfill(' ') << setw(7) << zonas[i][k]->obtemTipoZona();
                else if(z == 1){
                    cout << "|" << left << setfill(' ') << setw(7) << zonas[i][k]->obtemEdificio();
                }

                else if(z == 2) cout << "|" << left << setfill(' ') << setw(7) << zonas[i][k]->obtemTipoTrabalhador().substr(0, 6);
                else if(z == 3) cout << "|" << left << setfill(' ') << setw(7) << zonas[i][k]->obtemTrabalhadores();
                else cout << "|       ";
                if(k == (nColunas - 1)){
                    cout <<  "|";
                }
            }
            cout << endl;
        }
    }
    for(int j = 0; j < nColunas; j++){
        cout << "*-------";
        if(j == (nColunas - 1)){
            cout <<  "*";
        }
    }

    /*cout << endl;
    cout << "[DIA " << dia << "]" << endl;
    cout << "Saldo: " << saldo << " euros" << endl;
    cout << "Numero de Trabalhadores: " << getNrTrabalhadores() << endl << endl;
    cout << "Recursos: " << endl;
    cout << "Vigas de Madeira: " << nrVigasMadeira << endl;
    cout << "Ferro: " << nrFerro << endl;
    cout << "Barras de Aco: " << nrBarraDeAco << endl;
    cout << "Carvao: " << nrCarvao << endl;
    cout << "Madeira: " << nrMadeira << endl;
    cout << "Eletricidade: " << nrEletricidade << endl << endl;*/
}

