#include <iostream>
#include <fstream>

#include "./Include/produto.h"
#include "./Include/ArquivoCSV.h"

using namespace std;

Produto::Produto(string nomeArqCSV, fstream arq) : ArquivoCSV(nomeArqCSV){
}   

Produto::~Produto(){
    fechar();
}

string Produto::toString() const {
    // Convertendo os campos do item para uma representação de string
    string result = "Tempo de Referencia: " + to_string(item.tempo_referencia) + "\n";
    result += "Conta: " + item.conta + ",";
    result += "Code: " + to_string(item.code) + ",";
    result += "Código do País: " + item.codigo_pais + ",";
    result += "Tipo de Produto: " + item.tipo_produto + ",";
    result += "Valor: " + to_string(item.valor) + ",";
    result += "Status: " + item.status + "\n";

    return result;
}