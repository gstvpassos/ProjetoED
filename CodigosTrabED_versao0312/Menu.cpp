#include <iostream>
#include <cstring>

#include "./Include/Menu.h"
#include "./Include/Binario.h"

using namespace std;

void Menu::imprimeMenu(){
    cout<< "Escolha uma das opcoes a seguir:\n";
	cout<< "(1)Ordenar arquivo\n";
	cout<< "(2)Remover um elemento do arquivo\n";
	cout<< "(3)Adicionar um elemento no arquivo\n";
	cout<< "(4)Imprimir o arquivo\n";
	cout<< "(5)Exportar arquivo\n";
	cout<< "(6)Sair do programa\n";
}

int Menu::confirmaSaida(){
    int opcaoSaida;
    cout<<"Certeza que deseja sair?\n";
	cout<<"(1)Sim (2)Nao\n";
    cin >> opcaoSaida;
    
    return opcaoSaida;
}

Menu::Menu(){
    Binario binario(NOME_ARQ_BINARIO);
}
dsadas
int Menu::opcaoExporta(){
    int opcaoExporta;
    cout << "Voce deseja exportar os arquivos em .csv ou .bin?" << endl;
    cout << "(1).csv (2.bin)" << endl;
    return opcaoExporta;
}

void Menu::executaMenu(){
    int opcao;
    imprimeMenu();
    do{
        switch (opcao){

            case 1:
                binario.ordenar();
                break;
            case 2:
                int posicao;
                cin >> posicao;
                binario.remover(posicao);
                break;
            case 3:
                int posicao;
                cin >> posicao;
                binario.adicionar(posicao);
                break;
            case 4:
                opcaoImprime(); 
                int opImp;
                cin >> opImp;
                impressaoArquivo(opImp);
                break;
            case 5:
                int opcaoExport = opcaoExporta();
                (opcaoExport == 2) ? binario.exportarBin() : binario.exportarCSV();
                break;
            case 6:
                int opcaoSaida = confirmaSaida();
                (opcaoSaida == 1) ? exit(1) : executaMenu();
            default:
                cout << "Opcao invalida" << endl;
        }
    } while(opcao != 6);
}

void Menu::impressaoArquivo(int opcaoImpressao){
    (opcaoImpressao==1) ? binario.imprimeIntervalo() : binario.imprimeTudo();
}

void Menu::retornarMenu(){

}

/*int Menu::confirmaRemocao(Binario removido){
    cout << "Tem certeza que deseja remover {" << removido.getItem().tempo_referencia << "?" << endl;
    cout << "(1)Sim" << endl << "(2)Nao" << endl;
    int opcao;
    cin >> opcao;

    return opcao;
}*/
