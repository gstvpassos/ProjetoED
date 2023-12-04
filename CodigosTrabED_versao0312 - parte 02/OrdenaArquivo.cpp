#include "./Include/OrdenaArquivo.hpp"

void OrdenaArquivo::mergeSortExterno(const string& nome)
{
    char novo[20];
    int numArqs = criaArquivosOrdenados(nome);
    int k = limiteMaxItens / (numArqs + 1);

    remove(nome.c_str());
    merge(nome, numArqs, k);

    for (int i = 0; i < numArqs; ++i)
    {
        sprintf(novo, "Temp%d.bin", i + 1);
        remove(novo);
    }
}

int OrdenaArquivo::criaArquivosOrdenados(const string& nome)
{
    itens V[limiteMaxItens];
    int cont = 0, total = 0;

    char novo[20];
    ifstream f(nome, ios::binary);
    while (f.read(reinterpret_cast<char*>(&V[total]),sizeof(itens)))
    {
        total++;
        if(total == limiteMaxItens)
        {
            cont++;
            sprintf(novo, "Temp%d.bin", cont);
            sort(V, V + total, comparador);
            salvaArquivo(novo, V, total, 0);
            total = 0;
        }
    }
    if (total > 0) {
        cont++;
        sprintf(novo, "Temp%d.bin", cont);
        sort(V, V + total, comparador);
        salvaArquivo(novo, V, total, 0);
    }
    f.close();
    return cont;
}

void OrdenaArquivo::salvaArquivo(const string& nome, itens *vetItens, int tam, int mudaLinhaFinal)
{
    ofstream fileDeEscrita(nome, ios::app | ios::binary);
    for (int i = 0; i < tam - 1; ++i)
    {
        fileDeEscrita.write(reinterpret_cast<const char*>(&vetItens[i]), sizeof(itens));
    }
    //Testar quando tiver copilado - VERIFICAR NA VÍDEO AULA
    if (mudaLinhaFinal == 0)
    {
        int valor = '\n';
        fileDeEscrita.write(reinterpret_cast<const char*>(&valor), sizeof(int));
    }
    fileDeEscrita.close();
}

void OrdenaArquivo::merge(const string& nome, int numArqs, int k)
{
    char novo[20];
    itens *buffer = new itens[k];
    Arquivo* arq = new Arquivo[numArqs];

    for (int i = 0; i < numArqs; ++i)
    {
        sprintf(novo, "Temp%d.bin", i + 1);
        arq[i].file.open(novo, ios::binary);
        arq[i].MAX = 0;
        preencheBuffer(&arq[i], k);
    }

    itens menor;
    int qtdBuffer = 0;
    while (procuraMenor(arq, numArqs, k, &menor) == 1)
    {
        buffer[qtdBuffer] = menor;
        qtdBuffer++;
        if (qtdBuffer == k) {
            salvaArquivo(nome, buffer, k, 1);
            qtdBuffer = 0;
        }
    }

    if (qtdBuffer != 0) {
        salvaArquivo(nome, buffer, qtdBuffer, 1);
    }

    for (int i = 0; i < numArqs; ++i)
    {
        arq[i].file.close();
    }

    delete[] buffer;
    delete[] arq;
}

int OrdenaArquivo::procuraMenor(Arquivo* arq, int numArqs, int k, itens* menor) {
    int idx = -1;
    for (int i = 0; i < numArqs; i++)
    {
        if (arq[i].pos < arq[i].MAX)
        {
            if (idx == -1)
            {
                idx = i;
            }
            else
            {
                if (arq[i].buffer[arq[i].pos].tipo_produto < arq[idx].buffer[arq[idx].pos].tipo_produto)
                {
                    idx = i;
                }
            }
        }
    }
    if (idx != -1)
    {
        *menor = arq[idx].buffer[arq[idx].pos];
        arq[idx].pos++;
        if (arq[idx].pos == arq[idx].MAX)
            preencheBuffer(&arq[idx], k);
        return 1;
    }
    else
    {
        return 0;
    }
}

void OrdenaArquivo::preencheBuffer(Arquivo* arq, int k)
{
    if (!arq->file.is_open())
        cerr<<"Arquivo com erro\n";

    arq->pos = 0;
    arq->MAX = 0;

    int i=0;
    bool naoPreenchido = true;
    while(i<k and naoPreenchido)
    {
        if(arq->file.read(reinterpret_cast<char*>(&arq->buffer[arq->MAX]), sizeof(itens)))
        {
            arq->MAX++;
        }
        else
        {
            arq->file.close();
            arq->file.close();
            naoPreenchido = false;
        }
        i++;
    }
}

//Comparador para o método sort
bool OrdenaArquivo::comparador(const itens &item1, const itens &item2)
{
    if(item1.tipo_produto > item2.tipo_produto)
    {
        return true;
    }
    else if(item1.tipo_produto < item2.tipo_produto)
    {
        return false;
    }
    //Se entrar no else, significa que são iguais
    //logo desempata pelo campo de valor de cada item
    else
    {
        if(item1.valor > item2.valor)
        {
            return true;
        }
        return false;
    }
}