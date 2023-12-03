#ifndef ARQUIVOCSV_H
#define ARQUIVOCSV_H

#include <iostream>
#include <fstream>
#include "Nomes.h"

class ArquivoCSV {

public:
    ArquivoCSV(string nomeArq);
    string getNomeArq();
    int getPosicao();
    bool isValid();
    long int getTamanho();
    bool existe();
    void abrir();
    bool estaAberto();
    void fechar();

protected:
    string nomeArq;
    fstream arqCSV;
    int posicao;
    bool ehValido;
    long int tamanho;
};

#endif // ARQUIVOCSV_H
