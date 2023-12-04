#include "./Nomes.h"
#include "./ArquivoCSV.h"
#include "./produto.h"
#include "./OrdenaArquivo.h"

class Binario{

    private:
        ArquivoCSV arqCSV;
        string nomeBinario;
        fstream arquivoBinario;
        OrdenaArquivo ordena;

    public:
        Binario(string nomeArq);
        ~Binario();
        inline void csvToBin(string nomeArqCsv);
        inline Produto binToCsv();
        int inline busca();
        void exportarCSV();
        void exportarBin();
        Produto itemRemover(int posicao);
        void remover(int posicao);
        void adicionar(int posicao);
        void imprimeTudo();
        void imprimeIntervalo();
        void trocarPosicoes(int pos1, int pos2);
        void ordenar();
        void alterar(int posicao);


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
                cont = arquivoBinario.tellg()/sizeof(Produto);
                fecharArquivo();
            }

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