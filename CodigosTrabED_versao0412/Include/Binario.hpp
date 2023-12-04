#include <iostream>
#include <fstream>

#include "./Nomes.h"
#include "./ArquivoCSV.h"
#include "./OrdenaArquivo.h"

using namespace std;

class Binario{

    private:
        ArquivoCSV arqCSV;
        string nomeBinario;
        fstream arquivoBinario;
        OrdenaArquivo ordena;

    public:
        inline void csvToBin(const vector<itens>& item, const string& filename);
        inline fstream binToCsv();
        void exportarCSV(string nomeSaidaCSV);
        void exportarBin();
        void remover(int posicao);
        void adicionar(int posicao);
        void imprimeTudo();
        void imprimeIntervalo();
        void trocarPosicoes(int pos1, int pos2);
        void ordenar();
        void alterar(int posicao);
        int quantidadeItens();

        Binario(string nomeArqBin):arqCSV(NOME_ARQ_CSV)
        {
            nomeBinario = nomeArqBin;
            //ifstream arqCSV(NOME_ARQ_CSV);
            ifstream arquivoBinario(nomeBinario);
        }

        ~Binario()
        {
            arquivoBinario.close();
        }


        int numTotalProdutos()
        {
            int cont=0;
            if(arquivoBinario.is_open())
            {
                streampos posInicio = arquivoBinario.tellg();
                goToEndFile();
                arquivoBinario.seekg(posInicio);
            }
            else
            {
                abrirArquivo();
                goToEndFile();
                cont = int(arquivoBinario.tellg()/sizeof(Produto));
                fecharArquivo();
            }
            return cont;
        }

        void goToEndFile()
        {
            if(arquivoBinario.is_open())
            {
                arquivoBinario.seekg(0, ios::end);
            }
            else
            {
                arquivoBinario.open(nomeBinario, ios::binary | ios::in | ios::ate);
            }
        }

        bool abrirArquivo()
        {
            fecharArquivo();
            arquivoBinario.is_open();
            if(!arquivoBinario)
                cerr<<"Erro! Arquivo Inexistente\n\n";

            return arquivoBinario.is_open();
        }

        void fecharArquivo()
        {
            if(arquivoBinario.is_open())
                arquivoBinario.close();
        }

        void static exibirProduto(itens umItem)
        {
            cout<<"Tempo de referencia: "<<umItem.tempo_referencia<<endl;
            cout<<"Conta: "<<umItem.conta<<endl;
            cout<<"Código: "<<umItem.code<<endl;
            cout<<"Código do país: "<<umItem.codigo_pais<<endl;
            cout<<"Tipo do produto: "<<umItem.tipo_produto<<endl;
            cout<<"Valor: "<<umItem.valor<<endl;
            cout<<"Status: "<<umItem.status<<endl;
        }
};