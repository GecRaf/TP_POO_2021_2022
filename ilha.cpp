//
// TP_2122_POO || Rafael Couto 2019142454 || Rodrigo Ferreira 2019138331
//
#include "ilha.h"
#include "zona.h"

Ilha::Ilha(int linhas, int colunas) {
    nLinhas = linhas;
    nColunas = colunas;
    iniciaMatriz(nLinhas, nColunas);
    mostraVector();
    leitorComandos();
}

void Ilha::iniciaMatriz(int nLinhas, int nColunas) {
    zona *z;
    vector<vector<zona*> > zonas;
    vector<zona*> tmp;
    for (int i = 0; i < nLinhas; i++) {
        for (int j = 0; j < nColunas; j++) {
            tmp.push_back(z);
        }
        zonas.push_back(tmp);
    }
}

void Ilha::mostraVector() {
    vector<vector<zona*> > zonas;

    for(int i = 0; i < nLinhas; i++){
        for(int j = 0; j < nColunas; j++){
            cout << ".-------";
            if(j == (nColunas - 1)){
                cout <<  ".";
            }
        }
        cout << endl;
        for(int z = 0; z < 4; z++){
            for(int k = 0; k < nColunas; k++){
                if(z == 0) cout << "|       " ;//<< zonas[i][k]->obtemTipoZona();
                else if(z == 1){
                    cout << "|       " ;//<< zonas[i][k]->obtemEdificio();
                }

                else if(z == 2) cout << "|       " ;//<< zonas[i][k]->obtemTipoTrabalhador();
                else if(z == 3) cout << "|       " ;//<< zonas[i][k]->obtemTrabalhadores();
                else cout << "|       ";
                if(k == (nColunas - 1)){
                    cout <<  "|";
                }
            }
            cout << endl;
        }
    }
    for(int j = 0; j < nColunas; j++){
        cout << ".-------";
        if(j == (nColunas - 1)){
            cout <<  ".";
        }
    }
    cout << endl;
}

void Ilha::leitorComandos() {
    fflush(stdin);
    int teste = 0;
    do {
        string comando = "";
        string tipoComando = "";
        int indexComando = 0;
        cout << "COMANDO: " << endl;
        getline(cin, comando); //prevenir a entrada de lixo

        //cout << comando << endl; //verificacao

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
        }
        else if (tipoComando == "cons") {
            string linha = "";
            string coluna = "";
            string tipo = "";
            for (int j = indexComando; j < comando.size(); j++) {
                if (comando[j] != ' ') {
                    tipo = tipo  + comando[j];
                } else {
                    indexComando = j;
                    indexComando++;
                    break;
                }
            }
            if(tipo == "minaf" || tipo == "minac" || tipo == "central" || tipo == "bat" || tipo == "fund" || tipo == "edx"){
                for (int k = indexComando; k < comando.size(); k++) {
                    if (comando[k] != ' ') {
                        linha = linha + comando[k];
                    } else {
                        indexComando = k;
                        indexComando++;
                        break;
                    }
                }
                int intLinha = stoi(linha);
                if(intLinha > nLinhas || intLinha < 0)
                {
                    cout << "Linha invalida!" << endl;
                }
                else
                {
                    for (int l = indexComando; l < comando.size(); l++) {
                        if (comando[l] != ' ') {
                            coluna = coluna + comando[l];
                        } else {
                            indexComando = l;
                            indexComando++;
                            break;
                        }
                    }
                    int intColuna = stoi(coluna);
                    if(intColuna > nColunas || intColuna < 0)
                    {
                        cout << "Coluna invalida!" << endl;
                    }
                    else
                    {
                        cout << "Tipo: " << tipo << endl;
                        cout << "Linha: " << intLinha << endl;
                        cout << "Coluna: " << intColuna << endl;
                        zonas[intLinha][intColuna]->defineEdificio(new Edificio(tipo));
                    }
                }
            }
            else
            {
                cout << "Tipo de edificio invalido!" << endl;
            }
        }
        else if (tipoComando == "liga") {
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
                zonas[intLinha][intColuna]->obtemEdificio()->ligaActive();
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
                zonas[intLinha][intColuna]->obtemEdificio()->desligaActive();
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
            if(tipo == "oper" || tipo == "len" || tipo == "miner")
            {
                int verificaPasto=0;
                for(int i=0; i<nLinhas; i++)
                {
                    for(int j=0; j<nColunas; j++)
                    {
                        if(zonas[i][j]->obtemTipoZona() == "pas")
                        {
                            verificaPasto=1;
                            //zonas[nLinhas][nColunas]->defineTrabalhadores(Trabalhador(tipo));
                            //zonas[nLinhas][nColunas]->defineTrabalhadores(tipo);
                        }
                    }
                }
                if(verificaPasto == 0){
                    cout << "Nao ha zonas de pasto disponiveis!" << endl;
                }
            }
            else
            {
                cout << "Tipo de trabalhador invalido!" << endl;
            }
        }
        else if (tipoComando == "list") {
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

            if(linha == "" || coluna == "")
            {
                cout << "Dados globais" << endl;
            }
            else
            {
                int intLinha = stoi(linha);
                int intColuna = stoi(coluna);
                cout << "\n";
                cout << "Linha: " << intLinha << "\t|\t" << "Coluna: " << intColuna << endl;
                cout << "\n";
                cout << "Tipo de zona: " << zonas[intLinha][intColuna]->obtemTipoZona() << endl;
                cout << "Tipo de edificio: " << zonas[intLinha][intColuna]->obtemEdificio() << endl;
                cout << "Numero de trabalhadores: " << zonas[intLinha][intColuna]->obtemTrabalhadores() << endl;
                cout << "\n";
            }
        }
        else if (tipoComando == "next") {
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
        }
        else if (tipoComando == "load") {
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
        }
        else if (tipoComando == "apaga") {
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
        }
        else if (tipoComando == "config") {
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
        }
        else if (tipoComando == "debcash") {
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
        }
        else if (tipoComando == "debed") {
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
        }
        else if (tipoComando == "exit") {
            exit(1);
        }
        else {
            cout << "Comando invalido!" << endl;
        }
    } while (true);

}


