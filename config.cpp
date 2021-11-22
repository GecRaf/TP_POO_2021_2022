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

void mostraVector(vector < vector<zona> >, int nLinhas, int nColunas)
{
    vector < vector<zona> > zonas;
    for(int i=0; i<nLinhas; i++)
    {
        cout << "\n|";
        for(int j=0; j<nColunas; j++)
        {
            cout << zonas[i][j].obtemTipoZona() << "\t|";
        }
        cout << "\n";
        cout << "|";
        for(int k=0; k<nColunas; k++)
        {
            if(zonas[i][k].obtemTipoZona() == "")
                cout << zonas[i][k].obtemTipoZona() << "\t\t|";
            else
                cout << zonas[i][k].obtemTipoZona() << "\t|";
        }
        //tem de levar mais for's para imprimir tipo de Edificio, tipo de trabalhadores e num de trabalhadores
    }
}

void splitString(string &comando) {
    string tipoComando = "";
    string nomeFicheiro = "";
    string tipo = "";
    string linha = ""; //mudar para int!!!
    string coluna = ""; //mudar para int!!!
    int indexComando = 0;

    for (char x: comando) {
        if (x != ' ') {
            tipoComando = tipoComando + x;
        } else {
            indexComando++;
            break;
        }
        indexComando++;
    }
    cout << "Tipo de comando: " << tipoComando << endl;

    if (tipoComando == "exec") {
        for (int i = indexComando; i < comando.size(); i++) {
            if (comando[i] != ' ') {
                nomeFicheiro = nomeFicheiro + comando[i];
            } else {
                indexComando = i;
                indexComando++;
                break;
            }
        }
        cout << "Nome do ficheiro: " << nomeFicheiro << endl;
    }
    if (tipoComando == "cons") {
            for (int j = indexComando; j < comando.size(); j++) {
                if (comando[j] != ' ') {
                    tipo = tipo + comando[j];
                } else {
                    indexComando = j;
                    indexComando++;
                    break;
                }
            }

            for (int k = indexComando; k < comando.size(); k++) {
                if (comando[k] != ' ') {
                    linha = linha + comando[k];
                } else {
                    indexComando = k;
                    indexComando++;
                    break;
                }
            }

            for (int l = indexComando; l < comando.size(); l++) {
            if (comando[l] != ' ') {
                coluna = coluna + comando[l];
            } else {
                indexComando = l;
                indexComando++;
                break;
            }
        }
        int intLinha = stoi(linha);
        int intColuna = stoi(coluna);
        cout << "Tipo: " << tipo << endl;
        cout << "Linha: " << intLinha << endl;
        cout << "Coluna: " << intColuna << endl;
    }

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

