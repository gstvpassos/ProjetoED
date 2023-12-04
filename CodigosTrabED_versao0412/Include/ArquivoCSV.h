#ifndef ARQUIVOCSV_H
#define ARQUIVOCSV_H

#include <iostream>
#include <fstream>

using namespace std;

class ArquivoCSV {

public:
    ArquivoCSV(string nomeArq);
    ~ArquivoCSV();
    string getNomeArq();
    int getPosicao();
    bool isValid();
    long int getTamanho();
    bool existe();
    void abrir();
    bool estaAberto();
    void fechar();
    void seekp(int pos);
    void seekg(int pos);
    void ler(string& linha);
    void ler(char* buffer, int tamanho);
    virtual string toString() const;
    fstream getArqCSV();

protected:
    string nomeArq;
    fstream arqCSV;
    int posicao;
    bool ehValido;
    long int tamanho;
};

#endif // ARQUIVOCSV_H
