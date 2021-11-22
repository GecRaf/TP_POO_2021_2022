#include <iostream>
#include <vector>
#include "config.h"
#include <sstream>

//Dividir a string por espaços (sempre que chegar ao espaco mandar para a prox linha)
//Fazer verificação do "cons" (comando cons)
//Fazer interface visual

using namespace std;

int main() {
    int nLinhas;
    int nColunas;
    string comando;
    vector < vector<zona> > zonas;

    cout << "Bem-vindo ao jogo!" << endl;

    cout << "Introduza o numero de linhas: " << endl;
    cin >> nLinhas;
    cout << "Introduza o numero de colunas: " << endl;
    cin >> nColunas;

    zonas = iniciaMatriz(nLinhas, nColunas);

    cout << zonas[2][2].obtemTipoZona() << endl;
    fflush(stdin);
    cout << "COMANDO: " << endl;
    getline(cin, comando);
    splitString(comando); // dividir string comando por palavras

    istringstream iss(comando); //comando output
    cout << iss.str() << endl;

    //mostraVector(zonas, nLinhas, nColunas); por implementar meus bros

    return 0;
}
