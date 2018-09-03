#include <iostream>
#include <iomanip>
#include <vector>

void printHeader(const std::vector <std::string> & fields_){
	// contar quantidade de caracteres de cada palavra passado para a função
		//PROBLEMA POIS TEM O CARACTER DE TRANSIÇÃO
			//TENTAR USAR ALGUMA COISA PARA IMPRIMIR QUANTIDADE SEM IMPRIMIR A PALAVRA
	// adicionar caracteres finais e de transição de tabelaa quantidade de letaas
}

int main(void){
	std::vector <std::string> fieldNames = {"ITEM", "QUANTIDADE", "VALOR UNITARIO"};
	printHeader(fieldNames); // Imprimir cabeçalho da tabela.
	return EXIT_SUCCESS;
}