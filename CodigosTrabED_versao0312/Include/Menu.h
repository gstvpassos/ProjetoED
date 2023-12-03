#include "./Nomes.h"
#include "./Binario.h"

class Menu {

    private:
    Binario binario;

    public:
    Menu();
    ~Menu();
    void imprimeMenu();
    void executaMenu();
    int inline confirmaSaida();
    void retornarMenu();
    int inline opcaoImprime();
    int inline opcaoExporta();
    void inline impressaoArquivo(int opcaoImpressao);
    //int inline confirmaRemocao(Binario itemRemovido);

};