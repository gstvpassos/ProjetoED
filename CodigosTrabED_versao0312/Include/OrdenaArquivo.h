#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "./Include/produto.h"

using namespace std;

#define limiteMaxItens 100

struct Arquivo
{
    ifstream file;
    int pos, MAX;
    item* buffer;
};

class OrdenaArquivo
{
    private:
        Arquivo arquivo;
        //Método auxiliares, chamados dentro da classe Arquivo
        int criaArquivosOrdenados(const string& nome);
        void salvaArquivo(const string& nome, item *vetItens, int tam, int mudaLinhaFinal);
        void merge(const string& nome, int numArqs, int k);
        int procuraMenor(Arquivo* arq, int numArqs, int k, item* menor);
        void preencheBuffer(Arquivo* arq, int k);
        static bool comparador(const item &item1, const item &item2);

public:
        OrdenaArquivo()//construtor
        {
            arquivo.pos = 0;
            arquivo.MAX = 0;
            arquivo.buffer = new item[limiteMaxItens];
        }
        ~OrdenaArquivo(){delete[] arquivo.buffer;}//destrutor
        void mergeSortExterno(const string& nome);
};