#include <iostream>
#include <fstream>

#include "Nomes.h"

using namespace std;

class ArquivoCSV{
    private:
    int posicao;
    bool ehValido;
    long int tamanho;

    public:
    string getNomeArq();
    int getPosicao();
    bool isValid();
    long int getTamanho();
    inline bool existe();
    inline void abrir();
    inline bool estaAberto();
    inline void fechar();

    protected:
    string nomeArq;
    fstream arqCSV;
};