#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

//Declaração do registro de arquivos
struct arquivo
{
    FILE *f;
    int pos, MAX, *buffer;
};

//Escopo de funções
void criarArquivoTeste(char* nome);
void mergeSortExterno(char* nome);
int criaArquivosOrdenados(char* nome);
void salvaArquivo(char *nome, int *V, int tam, int mudaLinhaFinal);
void merge(char *nome, int numArqs, int k);
int procuraMenor(struct arquivo* arq, int numArqs, int k, int* menor);
void preencheBuffer(struct arquivo* arq, int k);
int comparaDescrescente(const void* p1, const void* p2);

//FUNÇÕES
void criarArquivoTeste(char* nome)
{
    int i;
    FILE *f = fopen(nome, "w");
    srand(time(NULL));
    for (i = 0;  i<1000 ; i++)
    {
        fprintf(f, "%d\n", rand());
    }
    fprintf(f, "%d",rand());
    fclose(f);
}

void mergeSortExterno(char* nome)
{
    char novo[20];
    int numArqs = criaArquivosOrdenados(nome);
    int i;
    int k = N / (numArqs+1);//Numero de buffers

    remove(nome);
    merge(nome, numArqs, k);

    for (i = 0; i < numArqs; ++i)
    {
        sprintf(novo, "Temp%d.txt", i+1);
        remove(novo);
    }
}

int criaArquivosOrdenados(char *nome)
{
    int V[N], cont = 0, total = 0;
    char novo[20];
    FILE *f = fopen(nome, "r");
    while(!feof(f))
    {
        fscanf(f, "%d", &V[total]);
        total++;
        if(total == N)
        {
            cont++;
            sprintf(novo, "Temp%d.txt",cont);
            qsort(V, total, sizeof(int), comparaDescrescente);
            salvaArquivo(novo, V, total, 0);
            total = 0;
        }
    }
    if(total>0) {
        cont++;
        sprintf(novo, "Temp%d.txt", cont);
        qsort(V, total, sizeof(int), comparaDescrescente);
        salvaArquivo(novo, V, total, 0);
    }
    fclose(f);
    return cont;
}

void salvaArquivo(char *nome, int *V, int tam, int mudaLinhaFinal)
{
    int i;
    FILE *f = fopen(nome, "a");
    for (i = 0; i < tam-1 ; ++i)
    {
        fprintf(f, "%d\n", V[i]);
    }
    if(mudaLinhaFinal==0)
    {
        fprintf(f, "%d", V[tam-1]);
    }
    else
    {
        fprintf(f, "%d\n", V[tam-1]);
    }
    fclose(f);
}

void merge(char *nome, int numArqs, int k)
{
    char novo[20];
    int i;
    int *buffer = (int*) malloc(k*sizeof (int));

    struct arquivo* arq;
    arq = (struct arquivo*) malloc(numArqs*sizeof(struct arquivo));

    for (i = 0; i < numArqs; ++i)
    {
        sprintf(novo, "Temp%d.txt", i + 1);
        arq[i].f = fopen(novo, "r");
        arq[i].MAX = 0;
        arq[i].buffer = (int *) malloc(k * sizeof(int));
        preencheBuffer(&arq[i], k);
    }

    int menor, qtdBuffer = 0;
    while(procuraMenor(arq, numArqs, k, &menor)==1)
    {
        buffer[qtdBuffer] = menor;
        qtdBuffer++;
        if(qtdBuffer==k) {
            salvaArquivo(nome, buffer, k, 1);
            qtdBuffer = 0;
        }
    }
    if(qtdBuffer!=0)
    {
        salvaArquivo(nome, buffer, qtdBuffer, 1);
    }
    for (i = 0; i < numArqs; ++i)
    {
        free(arq[i].buffer);
    }

    free(arq);
    free(buffer);
}

int procuraMenor(struct arquivo* arq, int numArqs, int k, int* menor)
{
    int i, idx = -1;
    for(i=0; i<numArqs; i++)
    {
        if(arq[i].pos < arq[i].MAX)
        {
            if(idx == -1)
            {
                idx = i;
            }
            else
            {
                if(arq[i].buffer[arq[i].pos] < arq[idx].buffer[arq[idx].pos])
                {
                    idx = i;
                }
            }
        }
    }
    if(idx!=-1)
    {
        *menor = arq[idx].buffer[arq[idx].pos];
        arq[idx].pos++;
        if(arq[idx].pos == arq[idx].MAX)
            preencheBuffer(&arq[idx], k);
        return 1;
    }
    else
    {
        return 0;
    }
}

void preencheBuffer(struct arquivo* arq, int k)
{
    int i;
    if(arq->f == NULL)
        return;

    arq->pos = 0;
    arq->MAX = 0;

    for(i = 0; i<k; i++)
    {
        if(!feof(arq->f))
        {
            fscanf(arq->f, "%d", &arq->buffer[arq->MAX]);
            arq->MAX++;
        }
        else
        {
            fclose(arq->f);
            arq->f = NULL;
            break;
        }
    }
}

int comparaDescrescente(const void* p1, const void* p2)
{
    if(*(int*)p1 == *(int*)p2)
        return 0;
    else
    {
        if(*(int*)p1 < *(int*)p2)
            return 1;
        else
            return -1;
    }
}

int main()
{
    criarArquivoTeste("dados.txt");
    mergeSortExterno("dados.txt");
}