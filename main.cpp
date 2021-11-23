#include <iostream>
#include <vector>
#include "config.h"
#include <sstream>

//Validação dos comandos através do ficheiro config
//Interface visual da ilha
//Construção de edifício do tipo minaferro através de comandos (cons), tanto pelo teclado como por
//ficheiro (comando exec)
//Contratação de mineiros (comando cont), tanto pelo teclado como por ficheiro (comando exec)
//Visualização dos dados do jogo e de zonas (comando list )

using namespace std;

int main() {
    int nLinhas;
    int nColunas;
    string comando;
    vector<vector<zona> > zonas;

    cout << "Bem-vindo ao jogo!" << endl;

    cout << "Introduza o numero de linhas: " << endl;
    cin >> nLinhas;
    cout << "Introduza o numero de colunas: " << endl;
    cin >> nColunas;

    zonas = iniciaMatriz(nLinhas, nColunas);

    //cout << zonas[2][2].obtemTipoZona() << endl;
    fflush(stdin);
    leitorComandos(); // lê comandos

    //istringstream iss(comando); //comando output
    //cout << iss.str() << endl;

    //mostraVector(zonas, nLinhas, nColunas); por implementar meus bros

    return 0;
}
