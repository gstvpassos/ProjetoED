#include <fstream>

#include "./Nomes.h"
#include "ArquivoCSV.h"

struct item{

    int tempo_referencia;
    char conta[255];
    int code;
    char codigo_pais[2];
    char tipo_produto[10];
    double valor;
    char status[1];
};

class Produto: public ArquivoCSV{

    private:
    item produto;

    public:
    Produto(string NOME_ARQ_CSV);
    ~Produto();
    //item getItem();

};

