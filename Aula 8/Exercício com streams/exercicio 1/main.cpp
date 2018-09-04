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
		std::cout << "-";
		for(auto j(0); j<i.size(); ++j){
			std::cout << "-";
		}
		std::cout << "-+"; 
	}

	// Segunda linha
	

	// Calcular largura da tabela
	auto largura_tabela(0); // Largura da tabela
	for(auto i : fields_){
		largura_tabela += 2; // Antes da Palavra
		largura_tabela += i.size(); // A Palavra
		largura_tabela += 2; // Depois da Palavra
	}
	
}

int main(void){
	std::vector <std::string> fieldNames = {"ITEM", "QUANTIDADE", "VALOR UNITARIO"};
	printHeader(fieldNames); // Imprimir cabeçalho da tabela.
	return EXIT_SUCCESS;
}