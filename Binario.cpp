#include <iostream>
#include <fstream>

#include "./Include/Binario.h"
#include "./Include/ArquivoCSV.h"

using namespace std;

Binario::Binario(string nomeArqBin) : nomeBinario(nomeArqBin){
    ifstream arqBin(getNomeBinario());
}

Binario::~Binario(){
    arqBin.close();
}

void Binario::csvToBin(string nomeCSV){
    ifstream arquivoCSV(nomeCSV);

    if(!arquivoCSV.good()){
        cerr << "Base de dados " << nomeCSV << " nao encontrada!" << endl;
        cerr << "Certifique-se que ela esta baixada na pasta" << endl;
    }
    
}

string Binario::getNomeBinario(){
    return nomeBinario;
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