#include <fstream>
#include <vector>

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
    Produto(string nomeArq);
    ~Produto();
    string toString() const;
    vector<itens> converte(fstream &csv_file);
    vector<string> split(const string& s, char delimiter);
};

#endif