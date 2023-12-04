#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <sstream>

#include "./Include/produto.h"
#include "./Include/ArquivoCSV.h"

using namespace std;

Produto::Produto(string nomeArqCSV) : ArquivoCSV(nomeArqCSV){
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

vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}


vector<itens> Produto::converte(fstream &csv_file) {
    vector<itens> products;  // Certifique-se de inicializar o vetor

    string line;
    while (getline(csv_file, line)) {
        vector<string> fields = split(line, ';');
        if (fields.size() != 7) {  // Corrigido para 7 campos
            cerr << "Linha inválida: " << line << endl;
            continue;
        }

        // Cria uma variável temporária para armazenar os dados
        itens product;
        
        // Campos do arquivo CSV
        product.tempo_referencia = stoi(fields[0]);
        product.conta = fields[1];
        product.code = stoi(fields[2]);
        product.codigo_pais = fields[3];
        product.tipo_produto = fields[4];
        product.valor = stod(fields[5]);
        product.status = fields[6];

        // Adiciona o produto ao vetor
        products.push_back(product);
    }

    return products;
}
