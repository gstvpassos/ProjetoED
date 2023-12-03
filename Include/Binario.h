#ifndef BINARIO_H
#define BINARIO_H

#include <fstream>

#include "ArquivoCSV.h"
#include "produto.h"

class Binario {
private:
    fstream arqBin;
    string nomeBinario;

public:
    Binario(string nomeArqBin);
    ~Binario();
    void csvToBin(string nomeCSV);
    Produto binToCsv();
    int busca();
    string getNomeBinario();
    void exportarCSV();
    void exportarBin();
    Produto itemRemover(int posicao);
    void remover(int posicao);
    Produto adicionar(int posicao);
    void imprimeTudo();
    void imprimeIntervalo();
    void trocarPosicoes(int pos1, int pos2);
    void ordenar();
    void alterar();
};

#endif // BINARIO_H
