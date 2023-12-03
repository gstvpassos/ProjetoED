#include <iostream>
#include <fstream>

#include "./Include/Nomes.h"
#include "./Include/ArquivoCSV.h"

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