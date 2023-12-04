#include <iostream>
#include <fstream>

#include "./Include/Nomes.h"
#include "./Include/Binario.hpp"
#include "./Include/ArquivoCSV.h"

Binario::Binario(string nomeArqBin)
{
    nomeBinario = nomeArqBin;
    ifstream arqCSV(NOME_ARQ_CSV);
    ifstream arquivoBinario(nomeBinario);
}

Binario::~Binario(){
    arquivoBinario.close();
}

void Binario::csvToBin(string nomeCSV){
    ifstream arquivoCSV(nomeCSV);

    if(!arquivoCSV.good()){
        cerr << "Base de dados " << nomeCSV << " nao encontrada!" << endl;
        cerr << "Certifique-se que ela esta baixada na pasta" << endl;
    }

    arquivoBinario.open(nomeBinario, ios::out | ios::binary);
    arquivoBinario.seekp(0, ios::end);
}

Produto Binario::binToCsv(){

}

void Binario::exportarCSV(){

}

void Binario::exportarBin(){

}

void Binario::remover(int posicao)
{
    this->abrirArquivo();
    int totalItens = this->numTotalProdutos();

    itens umItem;
    this->arquivoBinario.seekg(0, this->arquivoBinario.beg);
    int contador = posicao - 1;

    if(contador<totalItens and contador>=0)
    {
        int tamItem = sizeof(itens);
        this->arquivoBinario.seekg(contador * tamItem);
        this->arquivoBinario.read((char* )&umItem, tamItem);

        //Verifica se o item apontado foi apagado anteriormente
        if(umItem.tempo_referencia != 0)
        {
            cout<<"Produto apagado:\n\n";
            exibirProduto(umItem);

            umItem.tempo_referencia = 0;
            this->arquivoBinario.seekp(contador * tamItem);
            this->arquivoBinario.write((char *)&umItem, tamItem);
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
    itens itemAux;

    this->arquivoBinario.open(nomeBinario, ios::binary | ios::in | ios::ate);
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
    streampos posInicial = this->arquivoBinario.tellg();
    streampos posInsercao = posicao * sizeof(itens);
    this->arquivoBinario.seekg(posInsercao);

    //Movendo os itens seguintes para frente (função de arrasto)
    for(int i=numTotalItens-1; i>=posicao;i--)
    {
        streampos posApontamento = i * sizeof(itens);
        this->arquivoBinario.seekg(posApontamento);
        itens umItem;
        this->arquivoBinario.read((char*)&umItem, sizeof(itens));

        streampos nextPos = (i+1) * sizeof(itens);
        this->arquivoBinario.seekp(nextPos);
        this->arquivoBinario.write((char *)&umItem, sizeof(itens));
    }

    //Gravando no arquivo;
    this->arquivoBinario.seekp(posInsercao);
    this->arquivoBinario.write((char *)&itemAux, sizeof(itens));

    this->fecharArquivo();
}

void Binario::imprimeTudo(){
    this->abrirArquivo();

    //Fazer apontamento para o início do arquivo
    this->arquivoBinario.seekg(0, ios::beg);

    itens umItem;

    int cont;
    while(cont<numTotalProdutos())
    {
        this->arquivoBinario.seekg(cont * sizeof(itens));
        this->arquivoBinario.read((char *)&umItem, sizeof(itens));
        //Verificando se o item apontado foi removido
        if(umItem.tempo_referencia != 0)
            exibirProduto(umItem);
    }
    this->fecharArquivo();
}

void Binario::imprimeIntervalo()
{
    this->arquivoBinario.open(nomeBinario, ios::binary | ios::in | ios::ate);

    //Determinar a quantidade de itens no arquivo a partir do seu tamanho
    //long int numProdutos = int(this->arquivoBinario.tellg() / sizeof(itens));
    long int numProdutos = numTotalProdutos();

    cout<<"Entre com os valores das posições de impressão dos produtos (1 até "<<numProdutos<<"):\n\n";
    int posBeg, posEnd;
    cout<<"Posição inicial: ";
    cin>>posBeg;
    cout<<"Posição final: ";
    cin>>posEnd;

    //Verificando a válidade do intervalo
    if((posEnd>0) and (posEnd<numProdutos))
    {
        if(posBeg<numProdutos and posBeg>0)
        {
            bool itemRemovido = true;
            itens itemAux;
            int produtosNoIntervalo = posEnd - (posBeg-1);
            while((posBeg <= posEnd) and (produtosNoIntervalo<=posEnd))
            {
                this->arquivoBinario.seekg((posBeg - 1)* sizeof(itens));
                this->arquivoBinario.read((char *)&itemAux, sizeof (itens));

                //Verifica se o item apontado já foi removido anteriormente
                if(itemAux.tempo_referencia != 0)
                {
                    exibirProduto(itemAux);
                    itemRemovido = false;
                }
                if(itemRemovido)
                {
                    posEnd++;
                    produtosNoIntervalo--;
                }
                posBeg++;
                itemRemovido = true;
            }
        }
        else
        {
            cout<<"Limite INFERIOR inválido\n\n";
        }
    }
    else
    {
        cout<<"Limite SUPERIOR inválido\n\n";
    }
    this->fecharArquivo();
}

void Binario::trocarPosicoes(int pos1, int pos2)
{
    this->arquivoBinario.open(nomeBinario, ios::binary | ios::in |ios::ate);

    itens item1, item2;
    int tamItem = sizeof(itens);

    //Fazer apontamento do início até os itens dos index1 e index2 para leitura
    this->arquivoBinario.seekg(pos1 * tamItem, ios::beg);
    this->arquivoBinario.read((char *)&item1, tamItem);
    this->arquivoBinario.seekg((pos2 * tamItem, ios::beg));
    this->arquivoBinario.read((char *)&item2, tamItem);

    //Fazer apontamentos para a escrita na posições trocadas:
    this->arquivoBinario.seekp(pos1 * tamItem, ios::beg);
    this->arquivoBinario.write((char *)&item2,tamItem);
    this->arquivoBinario.seekp(pos2 * tamItem, ios::beg);
    this->arquivoBinario.write((char *)&item1, tamItem);

    this->fecharArquivo();
}

void Binario::ordenar()
{
    if(this->arquivoBinario.good())
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

    itens itemAux;

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

    streampos posInicial = this->arquivoBinario.tellg();
    streampos posAlteracao = posicao * sizeof(itens);

    this->arquivoBinario.seekp(posAlteracao);
    this->arquivoBinario.write((char *)&itemAux, sizeof(itens));

    this->fecharArquivo();
}