#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

#define N 100

class OrdenaArquivo
{
    private:
        ifstream f;
        int pos, MAX;
        int* buffer;

        //Método auxiliares, chamados dentro da classe Arquivo
        int criaArquivosOrdenados(const string& nome);
        void salvaArquivo(const string& nome, int *V, int tam, int mudaLinhaFinal);
        void merge(const string& nome, int numArqs, int k);
        int procuraMenor(OrdenaArquivo* arq, int numArqs, int k, int* menor);
        void preencheBuffer(OrdenaArquivo* arq, int k);


    public:
        OrdenaArquivo() : pos(0), MAX(0), buffer(new int[N]){}//construtor
        ~OrdenaArquivo() {delete[] buffer;}//destrutor
        void mergeSortExterno(const string& nome);
};