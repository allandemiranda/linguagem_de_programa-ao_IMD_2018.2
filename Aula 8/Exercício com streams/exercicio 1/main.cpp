/**
 * @brief Exercício 1 - Exercícios com streams
 * 
 * @file main.cpp
 * @author Allan de Miranda Silva
 * @date 2018-09-04
 */
#include <iostream> // std::cout , std::cin 
#include <iomanip>
#include <vector> // std::vector

/**
 * @brief Função para criação do cabeçalho
 * 
 * @param fields_ Palavras que irão compor o cabeçalho das colunas da tabela
 */
void printHeader(const std::vector <std::string> & fields_){
	// Primeira linha
	std::cout << "+";
	for(auto i : fields_){
		std::cout << std::setw(i.size()+2) << std::setfill('-') << "";
		std::cout << "+"; 
	}
	std::cout << std::endl;
	
	// Segunda linha
	std::cout << "|";
	for(auto i : fields_){
		std::cout << " ";
		std::cout << i;
		std::cout << " |";
	}
	std::cout << std::endl;

	// Terceira linha
	std::cout << "+";
	for(auto i : fields_){
		std::cout << std::setw(i.size()+2) << std::setfill('-') << "";
		std::cout << "+"; 
	}
	std::cout << std::endl;	
}

int main(void){
	std::vector <std::string> fieldNames = {"ITEM", "QUANTIDADE", "VALOR UNITARIO"};
	printHeader(fieldNames); // Imprimir cabeçalho da tabela.
	return EXIT_SUCCESS;
}