#include "./Nomes.h"
#include "./ArquivoCSV.h"
#include "./produto.h"

class Binario{

    private:
        ArquivoCSV arqCSV;
        string nomeBinario;
        fstream ArquivoBinario;

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
        void adicionar(int posicao);
        void imprimeTudo();
        void imprimeIntervalo();
        void trocarPosicoes(int pos1, int pos2);
        void ordenar();
        void alterar(int posicao);


        int numTotalProdutos()
        {
            int cont=0;
            if(ArquivoBinario.is_open())
            {
                streampos posInicio = ArquivoBinario.tellg();
                goToEndFile();
                ArquivoBinario.seekg(posInicio);
            }
            else
            {
                abrirArquivo();
                goToEndFile();
                cont = ArquivoBinario.tellg()/sizeof(Produto);
                fecharArquivo();
            }

        }

        void goToEndFile()
        {
            if(ArquivoBinario.is_open())
            {
                ArquivoBinario.seekg(0, ios::end);
            }
            else
            {
                ArquivoBinario.open(nomeBinario, ios::binary | ios::in | ios::ate);
            }
        }

        bool abrirArquivo()
        {
            fecharArquivo();
            ArquivoBinario.is_open();
            if(!ArquivoBinario)
                cerr<<"Erro! Arquivo Inexistente\n\n";

            return ArquivoBinario.is_open();
        }

        void fecharArquivo()
        {
            if(ArquivoBinario.is_open())
                ArquivoBinario.close();
        }

        void static exibirProduto(item umItem)
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