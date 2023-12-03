#include "./Include/OrdenaArquivo.h"

void OrdenaArquivo::mergeSortExterno(const string& nome)
{
    char novo[20];
    int numArqs = criaArquivosOrdenados(nome);
    int k = N / (numArqs + 1);

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
    int V[N], cont = 0, total = 0;
    char novo[20];
    ifstream f(nome, ios::binary);
    while (f.read(reinterpret_cast<char*>(&V[total]),sizeof(int)))
    {
        total++;
        if(total == N)
        {
            cont++;
            sprintf(novo, "Temp%d.bin", cont);
            sort(V, V + total, greater<int>());
            salvaArquivo(novo, V, total, 0);
            total = 0;
        }
    }
    if (total > 0) {
        cont++;
        sprintf(novo, "Temp%d.bin", cont);
        sort(V, V + total, greater<int>());
        salvaArquivo(novo, V, total, 0);
    }
    f.close();
    return cont;
}

void OrdenaArquivo::salvaArquivo(const string& nome, int *V, int tam, int mudaLinhaFinal) {
    ofstream f(nome, ios::app | ios::binary);
    for (int i = 0; i < tam - 1; ++i)
    {
        f.write(reinterpret_cast<const char*>(&V[i]), sizeof(int));
    }
    if (mudaLinhaFinal == 0)
    {
        int valor = '\n';
        f.write(reinterpret_cast<const char*>(&valor), sizeof(int));
    }
    f.close();
}

void OrdenaArquivo::merge(const string& nome, int numArqs, int k) {
    char novo[20];
    int *buffer = new int[k];
    OrdenaArquivo* arq = new OrdenaArquivo[numArqs];

    for (int i = 0; i < numArqs; ++i)
    {
        sprintf(novo, "Temp%d.bin", i + 1);
        arq[i].f.open(novo, ios::binary);
        arq[i].MAX = 0;
        preencheBuffer(&arq[i], k);
    }

    int menor, qtdBuffer = 0;
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
        arq[i].f.close();
    }

    delete[] buffer;
    delete[] arq;
}

int OrdenaArquivo::procuraMenor(OrdenaArquivo* arq, int numArqs, int k, int* menor) {
    int idx = -1;
    for (int i = 0; i < numArqs; i++) {
        if (arq[i].pos < arq[i].MAX) {
            if (idx == -1) {
                idx = i;
            }
            else {
                if (arq[i].buffer[arq[i].pos] < arq[idx].buffer[arq[idx].pos]) {
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

void OrdenaArquivo::preencheBuffer(OrdenaArquivo* arq, int k)
{
    if (!arq->f.is_open())
        cerr<<"Arquivo com erro\n";

    arq->pos = 0;
    arq->MAX = 0;

    int i=0;
    bool naoPreenchido = true;
    while(i<k and naoPreenchido)
    {
        if(arq->f.read(reinterpret_cast<char*>(&arq->buffer[arq->MAX]), sizeof(int)))
        {
            arq->MAX++;
        }
        else
        {
            arq->f.close();
            arq->f.close();
            naoPreenchido = false;
        }
    }
}