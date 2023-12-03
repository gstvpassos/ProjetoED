#include <iostream>
#include <fstream>

#include "./Include/Nomes.h"
#include "./Include/Binario.h"
#include "./Include/ArquivoCSV.h"
#include "./Include/OrdenaArquivo.h"

using namespace std;

Binario::Binario(string nomeArq)
{
    nomeBinario = nomeArq;
    ArquivoCSV arqCSV;
}

Binario::~Binario(){
    arqCSV.fechar();
}

void Binario::csvToBin()
{

}

Produto Binario::binToCsv(){

}

int Binario::busca(){

}

void Binario::exportarCSV(){

}

void Binario::exportarBin(){

}

Produto Binario::itemRemover(int posicao){

}

void Binario::remover(int posicao)
{
    this->abrirArquivo();
    int totalItens = this->numTotalProdutos();

    item umItem;
    this->ArquivoBinario.seekg(0, this->ArquivoBinario.beg);
    int contador = posicao - 1;

    if(contador<totalItens and contador>=0)
    {
        int tamItem = sizeof(item);
        this->ArquivoBinario.seekg(contador * tamItem);
        this->ArquivoBinario.read((char* )&umItem, tamItem);

        //Verifica se o item apontado foi apagado anteriormente
        if(umItem.tempo_referencia != 0)
        {
            cout<<"Produto apagado:\n\n";
            exibirProduto(umItem);

            umItem.tempo_referencia = 0;
            this->ArquivoBinario.seekp(contador * tamItem);
            this->ArquivoBinario.write((char *)&umItem, tamItem);
        }
        else if (umItem.tempo_referencia == 0)
        {
            cout<<"\n\nItem removido anteriormente!\n\n";
        }
    }
    else
    {
        cout<<"\n\nPosição sem item cadastrado!\n\n";
    }
    this->fecharArquivo();
}

void Binario::adicionar(int posicao)
{
    item itemAux;

    this->ArquivoBinario.open(nomeBinario, ios::binary | ios::in | ios::ate);
    int numTotalItens = numTotalProdutos();

    //Entradas:
    cout<<"Tempo de referencia: ";
    cin>>itemAux.tempo_referencia;
    cout<<"Conta: ";
    cin>>itemAux.conta;
    cout<<"Código: ";
    cin>>itemAux.code;
    cout<<"Código do país: ";
    cin>>itemAux.codigo_pais;
    cout<<"Tipo do produto: ";
    cin>>itemAux.tipo_produto;
    cout<<"Valor: ";
    cin>>itemAux.valor;
    cout<<"Status: ";
    cin>>itemAux.status;

    //Determinar posição dentro do arquivo binario
    streampos posInicial = this->ArquivoBinario.tellg();
    streampos posInsercao = posicao * sizeof(item);
    this->ArquivoBinario.seekg(posInsercao);

    //Movendo os itens seguintes para frente (função de arrasto)
    for(int i=numTotalItens-1; i>=posicao;i--)
    {
        streampos posApontamento = i * sizeof(item);
        this->ArquivoBinario.seekg(posApontamento);
        item umItem;
        this->ArquivoBinario.read((char*)&umItem, sizeof(item));

        streampos nextPos = (i+1) * sizeof(item);
        this->ArquivoBinario.seekp(nextPos);
        this->ArquivoBinario.write((char *)&umItem, sizeof(item));
    }

    //Gravando no arquivo;
    this->ArquivoBinario.seekp(posInsercao);
    this->ArquivoBinario.write((char *)&itemAux, sizeof(item));

    this->fecharArquivo();
}

void Binario::imprimeTudo()
{
    this->abrirArquivo();

    //Fazer apontamento para o início do arquivo
    this->ArquivoBinario.seekg(0, ios::beg);

    item umItem;

    int cont;
    while(cont<numTotalProdutos())
    {
        this->ArquivoBinario.seekg(cont * sizeof(item));
        this->ArquivoBinario.read((char *)&umItem, sizeof(item));
        //Verificando se o item apontado foi removido
        if(umItem.tempo_referencia != 0)
            exibirProduto(umItem);
    }
    this->fecharArquivo();
}

void Binario::imprimeIntervalo()
{
    this->ArquivoBinario.open(nomeBinario, ios::binary | ios::in | ios::ate)


}

void Binario::trocarPosicoes(int index1, int index2)
{
    this->ArquivoBinario.open(nomeBinario, ios::binary | ios::in |ios::ate);

    item item1, item2;
    int tamItem = sizeof(item);

    //Fazer apontamento do início até os itens dos index1 e index2 para leitura
    this->ArquivoBinario.seekg(index1 * tamItem, ios::beg);
    this->ArquivoBinario.read((char *)&item1, tamItem);
    this->ArquivoBinario.seekg((index2 * tamItem, ios::beg));
    this->ArquivoBinario.read((char *)&item2, tamItem);

    //Fazer apontamentos para a escrita na posições trocadas:
    this->ArquivoBinario.seekp(index1 * tamItem, ios::beg);
    this->ArquivoBinario.write((char *)&item2,tamItem);
    this->ArquivoBinario.seekp(index2 * tamItem, ios::beg);
    this->ArquivoBinario.write((char *)&item1, tamItem);

    this->fecharArquivo();
}

void Binario::ordenar()
{
    if(this->ArquivoBinario.good())
    {
        ordena.mergeSortExterno(nomeBinario);
    }
    else
    {
        cerr<<"\n\nArquivo inexistente\n\n";
    }

}

void Binario::alterar(int posicao)
{
    this->abrirArquivo();

    //Verifica se posição possui um registro válido
    if(posicao >= this->numTotalProdutos() or posicao < 0)
    {
        cout<<"Posição inválida!\n\n";
    }

    item itemAux;

    cout<<"Tempo de referencia: ";
    cin>>itemAux.tempo_referencia;
    cout<<"Conta: ";
    cin>>itemAux.conta;
    cout<<"Código: ";
    cin>>itemAux.code;
    cout<<"Código do país: ";
    cin>>itemAux.codigo_pais;
    cout<<"Tipo do produto: ";
    cin>>itemAux.tipo_produto;
    cout<<"Valor: ";
    cin>>itemAux.valor;
    cout<<"Status: ";
    cin>>itemAux.status;

    streampos posInicial = this->ArquivoBinario.tellg();
    streampos posAlteracao = posicao * sizeof(item);

    this->ArquivoBinario.seekp(posAlteracao);
    this->ArquivoBinario.write((char *)&itemAux, sizeof(item));

    this->fecharArquivo();
}