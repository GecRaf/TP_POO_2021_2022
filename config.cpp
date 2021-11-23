//
// Created by Rafac on 21/11/2021.
//

#include "config.h"

vector<vector<zona> > iniciaMatriz(int nLinhas, int nColunas) {
    zona z;
    vector<vector<zona> > zonas;
    vector<zona> tmp;
    for (int i = 0; i < nLinhas; i++) {
        for (int j = 0; j < nColunas; j++) {
            tmp.push_back(z);
        }
        zonas.push_back(tmp);
    }
    return zonas;
}

void mostraVector(vector<vector<zona> >, int nLinhas, int nColunas) {
    vector<vector<zona> > zonas;
    for (int i = 0; i < nLinhas; i++) {
        cout << "\n|";
        for (int j = 0; j < nColunas; j++) {
            cout << zonas[i][j].obtemTipoZona() << "\t|";
        }
        cout << "\n";
        cout << "|";
        for (int k = 0; k < nColunas; k++) {
            if (zonas[i][k].obtemTipoZona() == "")
                cout << zonas[i][k].obtemTipoZona() << "\t\t|";
            else
                cout << zonas[i][k].obtemTipoZona() << "\t|";
        }
        //tem de levar mais for's para imprimir tipo de Edificio, tipo de trabalhadores e num de trabalhadores
    }
}

void leitorComandos() {
    int teste = 0;
    do {
        string comando = "";
        string tipoComando = "";
        int indexComando = 0;
        cout << "COMANDO: " << endl;
        getline(cin, comando);

        cout << comando << endl;

        for (char x: comando) {
            if (x != ' ') {
                tipoComando = tipoComando + x;
            } else {
                indexComando++;
                break;
            }
            indexComando++;
        } //leitor do comando
        cout << "Tipo de comando: " << tipoComando << endl;

        if (tipoComando == "exec") {
            string nomeFicheiro = "";
            for (int i = indexComando; i < comando.size(); i++) {
                if (comando[i] != ' ') {
                    nomeFicheiro = nomeFicheiro + comando[i];
                } else {
                    indexComando = i;
                    indexComando++;
                    break;
                }
            }
            cout << "Nome do ficheiro: " << nomeFicheiro << endl; //verificação

            string fileOutput;

            ifstream ficheiroComandos(nomeFicheiro);
            if (!ficheiroComandos) {
                cout << "Ocorreu um erro ao abrir o ficheiro!" << endl;
            }

            while (getline(ficheiroComandos, fileOutput)) {
                cout << fileOutput << endl; //rever
                // falta leitura e validação dos comandos através do ficheiro
                //istringstream
                string fileCommand = "";
                for (char x: fileOutput) {
                    if (x != ' ') {
                        fileCommand = fileCommand + x;
                    } else {
                        indexComando++;
                        break;
                    }
                    indexComando++;
                } //leitor do comando
                cout << "Comando do ficheiro: " << fileCommand << endl;
            }
            ficheiroComandos.close();
        } else if (tipoComando == "cons") {
            string tipo = "";
            string linha = "";
            string coluna = "";
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
        } else if (tipoComando == "liga") {
            string linha = "";
            string coluna = "";
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
                int intLinha = stoi(linha);
                int intColuna = stoi(coluna);
                cout << "Linha: " << intLinha << endl;
                cout << "Coluna: " << intColuna << endl;
                //falta função que liga o edificio
            }
        } else if (tipoComando == "des") {
            string linha = "";
            string coluna = "";
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
                int intLinha = stoi(linha);
                int intColuna = stoi(coluna);
                cout << "Linha: " << intLinha << endl;
                cout << "Coluna: " << intColuna << endl;
                //falta função que desliga o edificio
            }
        } else if (tipoComando == "move") {
            string id = "";
            string linha = "";
            string coluna = "";
            for (int j = indexComando; j < comando.size(); j++) {
                if (comando[j] != ' ') {
                    id = id + comando[j];
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
            int intID = stoi(id);
            cout << "ID: " << intID << endl; //será int or string?
            cout << "Linha: " << intLinha << endl;
            cout << "Coluna: " << intColuna << endl;
        } else if (tipoComando == "vende") {
            string tipo = "";
            string quanto = "";
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
                    quanto = quanto + comando[k];
                } else {
                    indexComando = k;
                    indexComando++;
                    break;
                }
            }

            int intQuanto = stoi(quanto);
            cout << "Tipo: " << tipo << endl;
            cout << "Quanto: " << intQuanto << endl;
        }//falta ver como implementar o outro vende(relativo aos edificios) aqui
        else if (tipoComando == "cont") {
            string tipo = "";
            for (int j = indexComando; j < comando.size(); j++) {
                if (comando[j] != ' ') {
                    tipo = tipo + comando[j];
                } else {
                    indexComando = j;
                    indexComando++;
                    break;
                }
            }
            cout << "Tipo: " << tipo << endl;
        } else if (tipoComando == "list") {
            string linha = "";
            string coluna = "";
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
            cout << "Linha: " << intLinha << endl;
            cout << "Coluna: " << intColuna << endl;
        } else if (tipoComando == "next") {
            string nomeFicheiro = "";
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
        }//por entender como implementar
        else if (tipoComando == "save") {
            string nome = "";
            for (int i = indexComando; i < comando.size(); i++) {
                if (comando[i] != ' ') {
                    nome = nome + comando[i];
                } else {
                    indexComando = i;
                    indexComando++;
                    break;
                }
            }
            cout << "Nome gravado: " << nome << endl;
        } else if (tipoComando == "load") {
            string nome = "";
            for (int i = indexComando; i < comando.size(); i++) {
                if (comando[i] != ' ') {
                    nome = nome + comando[i];
                } else {
                    indexComando = i;
                    indexComando++;
                    break;
                }
            }
            cout << "Nome do jogo a executar: " << nome << endl;
        } else if (tipoComando == "apaga") {
            string nome = "";
            for (int i = indexComando; i < comando.size(); i++) {
                if (comando[i] != ' ') {
                    nome = nome + comando[i];
                } else {
                    indexComando = i;
                    indexComando++;
                    break;
                }
            }
            cout << "Nome do jogo a eliminar: " << nome << endl;
        } else if (tipoComando == "config") {
            string ficheiro = "";
            for (int i = indexComando; i < comando.size(); i++) {
                if (comando[i] != ' ') {
                    ficheiro = ficheiro + comando[i];
                } else {
                    indexComando = i;
                    indexComando++;
                    break;
                }
            }
            cout << "Ficheiro config: " << ficheiro << endl;
        } else if (tipoComando == "debcash") {
            string valor = "";
            for (int k = indexComando; k < comando.size(); k++) {
                if (comando[k] != ' ') {
                    valor = valor + comando[k];
                } else {
                    indexComando = k;
                    indexComando++;
                    break;
                }
            }

            int intValor = stoi(valor);
            cout << "Valor: " << intValor << endl;
        } else if (tipoComando == "debed") {
            string tipo = "";
            string linha = "";
            string coluna = "";
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
        }//serve para debug (adiciona edificio a custo zero)
        else if (tipoComando == "debkill") {
            string id = "";
            for (int j = indexComando; j < comando.size(); j++) {
                if (comando[j] != ' ') {
                    id = id + comando[j];
                } else {
                    indexComando = j;
                    indexComando++;
                    break;
                }
            }

            int intID = stoi(id);
            cout << "ID: " << intID << endl; //será int or string?
        } else if (tipoComando == "exit") {
            exit(1);
        } else {
            cout << "Comando invalido!" << endl;
        }//remove trabalhador com a identificação ID
    } while (true);

}

string zona::obtemTipoZona() {
    return tipoZona;
}

void zona::defineZona(string tipoZona) {
    this->tipoZona = tipoZona;
}

int zona::obtemTrabalhadores() {
    return nTrabalhadores;
}

void zona::defineTrabalhadores(int nTrabalhadores) {
    this->nTrabalhadores = nTrabalhadores;
}

string zona::obtemEdificio() {
    return edificio;
}

void zona::defineEdificio(string edificio) {
    this->edificio = edificio;
}

