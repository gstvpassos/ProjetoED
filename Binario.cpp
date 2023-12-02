#include <iostream>
#include <fstream>

#include "./Include/Nomes.h"
#include "./Include/Binario.h"
#include "./Include/ArquivoCSV.h"

using namespace std;

Binario::Binario(string nomeArq){
    nomeBinario = nomeArq;
    ArquivoCSV arqCSV;
}

Binario::~Binario(){
    arqCSV.fechar();
}

void Binario::csvToBin(){

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

void Binario::remover(int posicao){

}

Produto Binario::adicionar(int posicao){

}

void Binario::imprimeTudo(){

}

void Binario::imprimeIntervalo(){

}

void Binario::trocarPosicoes(int pos1, int pos2){

}

void Binario::ordenar(){

}

void Binario::alterar(){

}