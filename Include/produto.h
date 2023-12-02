#include <fstream>

#include "./Nomes.h"
#include "ArquivoCSV.h"

struct item{

    int tempo_referencia;
    string conta;
    int code;
    string codigo_pais;
    string tipo_produto;
    double valor;
    string status;
};

class Produto: public ArquivoCSV{

    private:
    item produto;

    public:
    Produto(string NOME_ARQ_CSV);
    ~Produto();
    //item getItem();

};

