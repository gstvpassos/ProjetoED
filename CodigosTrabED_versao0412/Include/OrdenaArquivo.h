#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "./produto.h"

using namespace std;

#define limiteMaxItens 500

struct Arquivo
{
    ifstream file;
    int pos = 0;
    int MAX = 0;
    itens* buffer = NULL;
};

class OrdenaArquivo
{
    private:
        Arquivo arquivo;
        //Método auxiliares, chamados dentro da classe Arquivo
        int criaArquivosOrdenados(const string& nome);
        void salvaArquivo(const string& nome, itens *vetItens, int tam, int mudaLinhaFinal);
        void merge(const string& nome, int numArqs, int k);
        int procuraMenor(Arquivo* arq, int numArqs, int k, itens* menor);
        void preencheBuffer(Arquivo* arq, int k);
        static bool comparador(const itens &item1, const itens &item2);

public:
        OrdenaArquivo()//construtor
        {
            arquivo.pos = 0;
            arquivo.MAX = 0;
            arquivo.buffer = new itens[limiteMaxItens];
        }
        ~OrdenaArquivo(){delete[] arquivo.buffer;}//destrutor
        void mergeSortExterno(const string& nome);
};