#include "./Binario.hpp"

#ifndef MENU_H
#define MENU_H
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

#endif