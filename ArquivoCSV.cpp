#include <iostream>
#include <fstream>

#include "./Include/ArquivoCSV.h"

using namespace std;

ArquivoCSV::ArquivoCSV(string nomeArq) : nomeArq(nomeArq){
    if(existe()) abrir();
}

string ArquivoCSV::getNomeArq(){
    return nomeArq;
}

int ArquivoCSV::getPosicao(){
    return posicao;
}

bool ArquivoCSV::isValid(){
    
}

long int ArquivoCSV::getTamanho(){
    return tamanho;
}

bool ArquivoCSV::existe(){
    ifstream arqTeste(getNomeArq());
    bool existe = arqTeste.good();
    arqTeste.close();

    return existe;
}

inline void ArquivoCSV::abrir(){
    arqCSV.open(nomeArq, ios::in);
}

inline bool ArquivoCSV::estaAberto(){
    return arqCSV.is_open(); 
}

inline void ArquivoCSV::fechar(){
    if(estaAberto()) arqCSV.close();
}