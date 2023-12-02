#include "./Nomes.h"
#include "./ArquivoCSV.h"
#include "./produto.h"

class Binario{

    private:
    ArquivoCSV arqCSV;
    string nomeBinario;

    public:
    Binario(string nomeArq);
    ~Binario();
    inline void csvToBin();
    inline Produto binToCsv();
    int inline busca();
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