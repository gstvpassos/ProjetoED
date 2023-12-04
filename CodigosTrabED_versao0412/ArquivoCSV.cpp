#include <iostream>
#include <fstream>

#include "./Include/ArquivoCSV.h"

using namespace std;

ArquivoCSV::ArquivoCSV(string nomeArq) : nomeArq(nomeArq) {
    if (existe()) abrir();
}

ArquivoCSV::~ArquivoCSV() {
    fechar();
}

string ArquivoCSV::getNomeArq() {
    return nomeArq;
}

int ArquivoCSV::getPosicao() {
    return posicao;
}

bool ArquivoCSV::isValid() {
    return arqCSV.good();
}

long int ArquivoCSV::getTamanho() {
    return tamanho;
}

bool ArquivoCSV::existe() {
    ifstream arqTeste(getNomeArq());
    bool existe = arqTeste.good();
    arqTeste.close();

    return existe;
}

void ArquivoCSV::seekp(int pos) {
    if (estaAberto()) {
        arqCSV.seekp(pos);
    } else {
        cerr << "Arquivo não está aberto." << endl;
    }
}

void ArquivoCSV::seekg(int pos) {
    if (estaAberto()) {
        arqCSV.seekg(pos);
    } else {
        cerr << "Arquivo não está aberto." << endl;
    }
}

void ArquivoCSV::ler(string& linha) {
    if (estaAberto()) {
        getline(arqCSV, linha);
    } else {
        cerr << "Arquivo não está aberto." << endl;
    }
}

void ArquivoCSV::ler(char* buffer, int tamanho) {
    if (estaAberto()) {
        arqCSV.read(buffer, tamanho);
    } else {
        cerr << "Arquivo não está aberto." << endl;
    }
}

void ArquivoCSV::abrir() {
    arqCSV.open(nomeArq, ios::in);
}

bool ArquivoCSV::estaAberto() {
    return arqCSV.is_open();
}

void ArquivoCSV::fechar() {
    if (estaAberto()) arqCSV.close();
}
