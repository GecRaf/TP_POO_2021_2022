//
// TP_2122_POO || Rafael Couto 2019142454 || Rodrigo Ferreira 2019138331
//

#include <iostream>
#include <vector>
#include "config.h"
#include <sstream>

//Validação dos comandos através do ficheiro config
//Interface visual da ilha
//Visualização dos dados do jogo e de zonas (comando list )

using namespace std;

int main() {
    int nLinhas;
    int nColunas;
    string comando;
    vector<vector<zona> > zonas;


    cout << "Bem-vindo ao jogo CPP Island!" << endl;
    cout <<"   _____ _____  _____    _____  _____ _               _   _ _____   " << endl;
    cout <<"  / ____|  __ \\|  __ \\  |_   _|/ ____| |        /\\   | \\ | |  __ \\  " << endl;
    cout <<" | |    | |__) | |__) |   | | | (___ | |       /  \\  |  \\|   " << endl;
    cout <<" | |    |  ___/|  ___/    | |  \\___ \\| |      / /\\ \\ | . ` | |  | | " << endl;
    cout <<" | |____| |    | |       _| |_ ____) | |____ / ____ \\| |\\  | |__| | " << endl;
    cout <<"  \\_____|_|    |_|      |_____|_____/|______/_/    \\_\\_| \\_|_____/  " << endl;
    cout << "\n";
    cout << "Introduza o numero de linhas: ";
    cin >> nLinhas;
    cout << "\n";
    cout << "Introduza o numero de colunas: ";
    cin >> nColunas;
    cout << "\n";

    zonas = iniciaMatriz(nLinhas, nColunas);

    fflush(stdin);
    leitorComandos(zonas,nLinhas, nColunas); // lê comandos

    //istringstream iss(comando); //comando output
    //cout << iss.str() << endl;

    //mostraVector(zonas, nLinhas, nColunas); //interface visual

    return 0;
}
