#include <fstream>

#include "./Nomes.h"
#include "ArquivoCSV.h"

#ifndef PRODUTO_H
#define PRODUTO_H
struct itens{

    int tempo_referencia;
    string conta;
    int code;
    string codigo_pais;
    string tipo_produto;
    double valor;
    string status;
};

class Produto: public ArquivoCSV{

    private:
    itens item;

    public:
    Produto(string nomeArq, fstream arq);
    ~Produto();
    string toString() const;
};

#endif