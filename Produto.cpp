#include <iostream>
#include <fstream>

#include "./Include/Nomes.h"
#include "./Include/produto.h"

using namespace std;

Produto::Produto(string NOME_ARQ_CSV){
    nomeArq = NOME_ARQ_CSV;
    ifstream arqCSV;
}

Produto::~Produto(){
    fechar();
}
