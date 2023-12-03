// #include <iostream>
// #include <fstream>
// #include <string>
// #include <vector>
// #include <sstream>

// using namespace std;

// struct Product {
// 	string id;
// 	double preco1,preco2,preco3;
// 	string descricao;
// };
// // Exibe o menu principal do programa
// void menu (vector <Product> &data);
// // Exibe o menu depois de uma tarefa ser concluída
// void menu1 (vector <Product> &data){
// 	cout<<"Agora, o que deseja fazer?\n";
// 	int opcao;
	
// 	cout<<"(1)Voltar ao inicio\n";
// 	cout<<"(2)Encerrar programa\n";
	
// 	cin>>opcao;
// 	 switch (opcao) {
//     case 1:
//         menu(data);
//         break;

//     case 2:
//         exit(0);
//         break;

//     default:
//         cout << "Opcao invalida\n";
//         menu1(data);
//     }
// 	}
// // Lê um arquivo em uma string
// string readFileIntoString(const string& path) {
//     // Lê o arquivo csv
//     auto ss = ostringstream{};
//     ifstream input_file(path);
//     //Checa se o arquivo foi aberto corretamente
//     if (!input_file.is_open()) {
//         cerr << "Could not open the file - '"
//              << path << "'" << endl;
//         exit(EXIT_FAILURE);
//     }
//     ss << input_file.rdbuf();
//     return ss.str();
// }
// // Função auxiliar de mesclagem para o método mergeSort_Inserido()
// void merge_Inserido(vector <double> &arr, unsigned int left, unsigned int mid, unsigned int right)
// {
//     int i, j, k;
//     int n1 = mid - left + 1;
//     int n2 = right - mid;

   
//     double L[n1], R[n2];


//     for (i = 0; i < n1; i++)
//         L[i] = arr[left + i];
//     for (j = 0; j < n2; j++)
//         R[j] = arr[mid + 1 + j];

    
//     i = 0; 
//     j = 0; 
//     k = left; 
//     while (i < n1 && j < n2) {
//         if (L[i] <= R[j]) {
//             arr[k] = L[i];
//             i++;
//         }
//         else {
//             arr[k] = R[j];
//             j++;
//         }
//         k++;
//     }

    
//     while (i < n1) {
//         arr[k] = L[i];
//         i++;
//         k++;
//     }

   
//     while (j < n2) {
//         arr[k] = R[j];
//         j++;
//         k++;
//     }
// }
// // Função de classificação para classificar valores double do vetor inserido em ordem crescente
// void mergeSort_Inserido(vector <double> &arr, unsigned int left, unsigned int right)
// {
//     if (left < right) {
       
//         int mid = left + (right - left) / 2;

      
//         mergeSort_Inserido(arr, left, mid);
//         mergeSort_Inserido(arr, mid + 1, right);

      
//         merge_Inserido(arr, left, mid, right);
//     }
// }
// // Função auxiliar de mesclagem para o método mergeSort_Preco1()
// void merge_Preco1(vector <Product> &arr, unsigned int left, unsigned int mid, unsigned int right)
// {
//     int i, j, k;
//     int n1 = mid - left + 1;
//     int n2 = right - mid;

   
//     vector <Product> L(n1), R(n2);

 
//     for (i = 0; i < n1; i++)
//         L[i] = arr[left + i];
//     for (j = 0; j < n2; j++)
//         R[j] = arr[mid + 1 + j];

    
//     i = 0; 
//     j = 0; 
//     k = left; 
//     while (i < n1 && j < n2) {
//         if (L[i].preco1 <= R[j].preco1) {
//             arr[k] = L[i];
//             i++;
//         }
//         else {
//             arr[k] = R[j];
//             j++;
//         }
//         k++;
//     }

    
//     while (i < n1) {
//         arr[k] = L[i];
//         i++;
//         k++;
//     }

    
//     while (j < n2) {
//         arr[k] = R[j];
//         j++;
//         k++;
//     }
// }
// // Função de classificação para classificar Produtos por preco1 em ordem crescente
// void mergeSort_Preco1(vector <Product> &arr, unsigned int left, unsigned int right)
// {
//     if (left < right) {
       
//         int mid = left + (right - left) / 2;

        
//         mergeSort_Preco1(arr, left, mid);
//         mergeSort_Preco1(arr, mid + 1, right);

       
//         merge_Preco1(arr, left, mid, right);
//     }
// }
// // Função auxiliar de mesclagem para o método mergeSort_Preco3()
// void merge_Preco3(vector <Product> &arr, unsigned int left, unsigned int mid, unsigned int right)
// {
//     int i, j, k;
//     int n1 = mid - left + 1;
//     int n2 = right - mid;

   
// 	vector <Product> L(n1), R(n2);

   
// 	for (i = 0; i < n1; i++)
//         L[i] = arr[left + i];
//     for (j = 0; j < n2; j++)
//         R[j] = arr[mid + 1 + j];

    
//     i = 0;
//     j = 0; 
//     k = left; 
//     while (i < n1 && j < n2) {
//         if (L[i].preco3 <= R[j].preco3) {
//             arr[k] = L[i];
//             i++;
//         }
//         else {
//             arr[k] = R[j];
//             j++;
//         }
//         k++;
//     }

   
//     while (i < n1) {
//         arr[k] = L[i];
//         i++;
//         k++;
//     }

    
//     while (j < n2) {
//         arr[k]= R[j];
//         j++;
//         k++;
//     }
// }
// // Função de classificação para classificar Produtos por preco3 em ordem crescente
// void mergeSort_Preco3(vector <Product> &arr, unsigned int left, unsigned int right)
// {
//     if (left < right) {
      
//         int mid = left + (right - left) / 2;

       
//         mergeSort_Preco3(arr, left, mid);
//         mergeSort_Preco3(arr, mid + 1, right);

       
//         merge_Preco3(arr, left, mid, right);
//     }
// }
// // Função que remove os itens que foram excluidos pela função exlcuir() que estavam marcados negativados
// void remover_Excluidos (vector <Product> &vet){
	
// 	for (unsigned int i=0;i<vet.size();i++){
// 		if (stoll(vet[i].id)<=0){
// 			vet.erase(vet.begin()+i);
// 			}
// 		}
// 	}
// // Função de menu para acessar as ordenações de cada preço
// void ordenar (vector <Product> &data){
// 	cout<<"Deseja ordenar pelo preco menor ou maior?\n";
// 	cout<<"(1)Preco menor\n";
// 	cout<<"(2)Preco maior\n";
// 	cout<<"(3)Retornar\n";
// 	int opcao;
// 	cin>>opcao;
	
// 	if (opcao==1) {
// 		remover_Excluidos(data);
// 		mergeSort_Preco1(data,0,data.size()-1);
// 		cout<<"Arquivo ordenado pelo menor preco\n";
// 		}
// 	else if (opcao==2){
// 		remover_Excluidos(data);
// 		mergeSort_Preco3(data,0,data.size()-1);
// 		cout<<"Arquivo ordenado pelo maior preco\n";
// 		}
// 	else if (opcao==3) menu(data);
// 	else {
// 		cout<<"Opcao invalida\n";
// 		ordenar(data);
// 			}
// 	menu1(data);
// 	}
// // Função que exclui algum registro pelo código
// void excluir(vector <Product> &vet){
// 	cout<<"Digite o codigo do produto a ser excluido\n";
// 	cout<<"Ou digite -1 para retornar\n";
	
// 	string codigoExcluir;
// 	bool codigo_Valido=false;
// 	cin>>codigoExcluir;
	
// 	int pos_id;
// 	if (codigoExcluir!="-1"){
// 		for (unsigned int i=0;i<vet.size();i++){
// 			if (vet[i].id==codigoExcluir) {
// 				pos_id=i;
// 				codigo_Valido=true;
// 				}
// 			}
// 		if (codigo_Valido){
// 			cout<<"Voce deseja excluir o produto: \""<<vet[pos_id].descricao<<"\"?"<<"\n";
// 			cout<<"(1)Sim\n";
// 			cout<<"(2)Nao\n";
// 			}
// 		else {
// 			cout<<"Codigo invalido\n";
// 			excluir(vet);
// 			}
// 		int opcao;
// 		cin>>opcao;
// 		if (opcao==1){
// 			vet[pos_id].id="-"+vet[pos_id].id;
			
// 			}
// 		else if (opcao==2){
// 			excluir(vet);
// 			}
// 		else {
// 			cout<<"Opcao invalida\n";
// 			excluir (vet);
// 			}
// 		menu1(vet);
// 	}
// 	else menu(vet);
// 	}
// //Declaração da função para ser usada antes da declaração
// void imprimir(vector <Product> &vet);
// // Função que busca algum dado no vetor de registro
// void buscar(vector <Product> &vet){
	
// 	cout<<"Voce quer buscar pelo codigo ou preco?\n";
// 	cout<<"(1)Codigo\n";
// 	cout<<"(2)Menor preco\n";
// 	cout<<"(3)Preco intermediario\n";
// 	cout<<"(4)Maior preco\n";
// 	cout<<"(5)Retornar\n";
	
// 	int opcao,pos=-1;
// 	cin>>opcao;
// 	if (opcao==1){
// 		cout<<"Digite o codigo do produto\n";
// 		string codigo_Buscar;
// 		cin>>codigo_Buscar;
		
// 		for (unsigned int i = 0;i<vet.size(); i++){ //busca sequencial pois o vetor esta ordenado pelos precos 
// 			if (codigo_Buscar==vet[i].id){
// 				pos=i;
// 				cout<<"Codigo: "<<vet[i].id<<"\n"
// 				<<"Menor preco: "<<vet[i].preco1<<"\n"
// 				<<"Preco intermediario: "<<vet[i].preco2<<"\n"
// 				<<"Maior preco: "<<vet[i].preco3<<"\n"
// 				<<"Descricao: "<<vet[i].descricao<<"\n"
// 				<<"A posicao do vetor e: "<<pos<<"\n";;
// 			}
// 		}
// 		if (pos==-1){
// 			cout<<"Codigo nao encontrado\n";
// 			buscar(vet);
// 		}
// 	}
	
// 	else if (opcao==2){
		
// 		cout<<"Digite o menor preco do produto\n";
// 		double preco_Buscar;
// 		cin>>preco_Buscar;
		
// 		for (unsigned int i = 0;i<vet.size(); i++){   //busca sequencial
			
// 			if (preco_Buscar==vet[i].preco1){
// 				pos=i;
// 				cout<<"Codigo: "<<vet[i].id<<"\n"
// 				<<"Menor preco: "<<vet[i].preco1<<"\n"
// 				<<"Preco intermediario: "<<vet[i].preco2<<"\n"
// 				<<"Maior preco: "<<vet[i].preco3<<"\n"
// 				<<vet[i].descricao<<"\n"
// 				<<"A posicao do vetor e: "<<pos<<"\n";
// 			}
// 		}
// 		if (pos==-1){
// 			cout<<"Preco nao encontrado\n";
// 			buscar(vet);
// 		} 
// 	}
	
// 	else if (opcao==3){
// 		cout<<"Digite o preco intermediario do produto\n";
// 		double preco_Buscar;
// 		cin>>preco_Buscar;
		
// 		for (unsigned int i = 0;i<vet.size(); i++){   //busca sequencial
// 			if (preco_Buscar==vet[i].preco2){
// 				pos=i;
// 				cout<<"Codigo: "<<vet[i].id<<"\n"
// 				<<"Menor preco: "<<vet[i].preco1<<"\n"
// 				<<"Preco intermediario: "<<vet[i].preco2<<"\n"
// 				<<"Maior preco: "<<vet[i].preco3<<"\n"
// 				<<vet[i].descricao<<"\n"
// 				<<"A posicao do vetor e: "<<pos<<"\n";
// 			}
// 		}
// 		if (pos==-1){
// 			cout<<"Preco nao encontrado\n";
// 			buscar(vet);
		
			
// 		}
	
// 	}	
	
// 	else if (opcao==4){
// 		cout<<"Digite o maior preco do produto\n";
// 		double preco_Buscar;
// 		cin>>preco_Buscar;
		
// 		for (unsigned int i = 0;i<vet.size(); i++){   //busca sequencial
// 			if (preco_Buscar==vet[i].preco3){
// 				pos=i;
// 				cout<<"Codigo: "<<vet[i].id<<"\n"
// 				<<"Menor preco: "<<vet[i].preco1<<"\n"
// 				<<"Preco intermediario: "<<vet[i].preco2<<"\n"
// 				<<"Maior preco: "<<vet[i].preco3<<"\n"
// 				<<vet[i].descricao<<"\n"
// 				<<"A posicao do vetor e: "<<pos<<"\n";
// 			}
// 		}
// 		if (pos==-1){
// 			cout<<"Preco nao encontrado\n";
// 			buscar(vet);
		
			
// 		}
// 	}
// 	else if(opcao==5){
// 		menu(vet);
// 		}
// 	else {
// 		cout<<"Opcao invalida\n";
// 		buscar (vet);
// 	}
// 	cout<<"Deseja realizar outra busca?\n";
// 	cout<<"(1)Sim  (2)Nao\n";
// 	int opcao1;
// 	cin>>opcao1;
// 	bool verifica=false;
// 	do{
// 		if (opcao1==1)buscar(vet);
// 		else if(opcao1==2) menu1(vet);
// 		else {
// 			cout<<"Opcao invalida\n";
// 			verifica=true;
// 			buscar(vet);
// 		}
// 	}while (verifica);
// }
// // Função que insere um registro novo no vetor de registros
// void inserir(vector <Product> &vet){
// 	cout<<"Insira os dados a serem adicionados\n";
// 	cout<<"Digite -1 para retornar\n";
// 	int opcao;
// 	cin>>opcao;
// 	if (opcao!=-1){
// 		string id1,descricao1;
// 		double v1,v2,v3;
// 		cin>>id1>>v1>>v2>>v3;
// 		cin.ignore();
// 		getline(cin,descricao1);
		
// 		vector<double>valores={v1,v2,v3};
		
// 		mergeSort_Inserido(valores,0,valores.size()-1);
		
// 		v1=valores[0];
// 		v2=valores[1];
// 		v3=valores[2];
		
// 		vet.push_back({id1,v1,v2,v3,descricao1});
// 		cout<<"Dados adicionados!\n";
// 		menu1(vet);
// 	}
// 	else menu(vet);
// }
// // Função que imprime o vetor de registro na tela ou apenas um intervalo do menor preço
// void imprimir(vector <Product> &vet){
// 	cout<<"Voce deseja imprimir o arquivo todo ou apenas os produtos de um intervalo de preco?\n";
// 	cout<<"(1)Arquivo todo\n";
// 	cout<<"(2)Intervalo do menor preco\n";
// 	cout<<"(3)Retornar\n";
// 	int opcao;
// 	cin>>opcao;
// 	if (opcao==1){
		
// 		for (unsigned int i=0;i<vet.size();i++){
// 			if (stoll(vet[i].id)>=0){
// 				cout<<vet[i].id<<" "<<vet[i].preco1<<" "
// 				<<vet[i].preco2<<" "<<vet[i].preco3<<" "<<vet[i].descricao<<"\n";
// 				}
// 			}
// 		}
// 	else if(opcao==2){
// 		cout<<"Digite os intervalos separados por espaco ou quebra de linha\n";
// 		float intervaloA, intervaloB;
// 		cin>>intervaloA>>intervaloB;
// 		unsigned int i=0;
// 		for (i=0;i<vet.size();i++){
// 			if (stoll(vet[i].id)>=0){
// 				if (vet[i].preco1>= intervaloA and vet[i].preco1<=intervaloB){
// 					cout<<vet[i].id<<" "<<vet[i].preco1
// 					<<" "<<vet[i].preco2<<" "<<vet[i].preco3
// 					<<" "<<vet[i].descricao<<"\n";
// 					}
// 				}
// 			}
// 		}
// 	else if (opcao==3)menu(vet);
// 	else {
// 		cout<<"Opcao invalida\n";
// 		imprimir(vet);
// 		}

// 	menu1(vet);
// 	}
// //Função que exporta os arquivos seja em .csv ou .bin
// void exportar(vector <Product> &vet){
// 	cout<<"Deseja exportar os dados para um arquivo .csv?\n";
// 	cout<<"(1)Sim (2)Nao\n";
// 	cout<<"(3)Retornar\n";
// 	int opcao;
// 	cin>>opcao;
// 	switch (opcao){
// 		case 1:
// 		{
			
// 			ofstream arq_csv("data.csv");
// 			if (!arq_csv.is_open()){
// 				cerr << "Nao foi possivel criar arquivo\n";
// 				exit (1);
// 				}
// 			for (unsigned int i=0;i<vet.size();i++) {
// 				arq_csv << vet[i].id << "," << vet[i].preco1 << ","
// 				<< vet[i].preco2 << "," << vet[i].preco3 << "," << vet[i].descricao << "\n";
// 			}
// 			cout<<"Arquivo exportado no nome data.csv\n";
// 			break;
// 		}
// 		case 2:
// 		{
// 			ofstream arq_csv("data.csv");
// 			if (!arq_csv.is_open()){
// 				cerr << "Nao foi possivel criar arquivo\n";
// 				exit (1);
// 				}
// 			for (unsigned int i=0;i<vet.size();i++) {
// 				arq_csv << vet[i].id << "," << vet[i].preco1 << ","
// 				<< vet[i].preco2 << "," << vet[i].preco3 << "," << vet[i].descricao << "\n";
// 			}
// 			cout<<"Arquivo exportado no nome data.csv\n";
// 			break;
// 		}
// 		case 3:
// 		menu(vet);
// 		break;
		
// 		default:
// 			cout<<"Opcao invalida\n";
// 			exportar(vet);
// 	}
// 	menu1(vet);
// }
// //Menu que permite acessar toda a funcionalidade do programa
// void menu (vector <Product> &data){
// 	cout<< "Escolha uma das opcoes a seguir:\n";
// 	cout<< "(1)Ordenar arquivo\n";
// 	cout<< "(2)Excluir um elemento do arquivo\n";
// 	cout<< "(3)Inserir um elemento no arquivo\n";
// 	cout<< "(4)Buscar algum elemento no arquivo\n";
// 	cout<< "(5)Imprimir o arquivo\n";
// 	cout<< "(6)Exportar arquivo\n";
// 	cout<< "(7)Sair do programa\n";
// 	int opcao;
// 	cin>>opcao;
	
// 	switch (opcao) {
//         case 1:
//             ordenar(data);
//             break;
//         case 2:
//             excluir(data);
//             break;
//         case 3:
//             inserir(data);
//             break;
//         case 4:
//             buscar(data);
//             break;
//         case 5:
// 			imprimir(data);
// 			break;
// 		case 6:
// 			exportar(data);
// 			break;
// 		case 7:
// 			cout<<"Certeza que deseja sair?\n";
// 			cout<<"(1)Sim (2)Nao\n";
// 			int a;
// 			cin>>a;
// 			switch (a) {
// 				case 1:
// 				exit(0);
// 				break;
				
// 				case 2:
// 				menu(data);
// 				break;
				
// 				default:
// 				cout<<"Opcao invalida\n";
// 				menu1(data);
// 				}
// 			exit(0);
			
//         default:
//             cout << "Opcao invalida" << endl;
//             menu(data);
// 		}
// 	}
// //Função de vetor para realizar a leitura do arquivo .csv
// vector<string> split(const string& s, char delimiter) {
//     vector<string> tokens;
//     string token;
//     istringstream tokenStream(s);
//     while (getline(tokenStream, token, delimiter)) {
//         tokens.push_back(token);
//     }
//     return tokens;
// }
// //Função que escreve o arquivo binário
// void writeProductsToBinary(const vector<Product>& products, const string& filename) {
//     ofstream file(filename, ios::binary);

//     for (const auto& p : products) {
//         file.write(reinterpret_cast<const char*>(&p), sizeof(Product));
//     }

//     file.close();
// }
// //Função main que faz a abertura do arquivo.csv, transforma no vetor de registros e acessa a função de menu e escrita do arquivo binario
// int main() {
    
//     string csv_filename = "C:\Users\gusta\OneDrive\Desktop\ialg\base7aaaa.csv";
//     string binary_filename = "product.bin";

//     vector <Product> products;
	
//     ifstream csv_file(csv_filename);
//     if (!csv_file) {
//         cerr << "Nao foi possivel abrir arquivo " << csv_filename << endl;
//         return 1;
//     }

//     string line;
//     while (getline(csv_file, line)) {
//         vector<string> fields = split(line, ';');
//         if (fields.size() != 5) {
//             cerr << "Linha invalida: " << line << endl;
//             continue;
//         }
//         Product product;
//         product.id = fields[0];
//         size_t pos;
//         pos = fields[1].find(',');
//         if (pos != string::npos) {
//             fields[1].replace(pos, 1, ".");
//         }
//         product.preco1 = stod(fields[1]);
//         pos = fields[2].find(',');
//         if (pos != string::npos) {
//             fields[2].replace(pos, 1, ".");
//         }
//         product.preco2 = stod(fields[2]);
//         pos = fields[3].find(',');
//         if (pos != string::npos) {
//             fields[3].replace(pos, 1, ".");
//         }
//         product.preco3 = stod(fields[3]);
//         product.descricao = fields[4];
//         products.push_back(product);
		
//     }
// 	writeProductsToBinary(products, "base7.bin");
// 	menu (products);
    
   

//     return 0;
// }
