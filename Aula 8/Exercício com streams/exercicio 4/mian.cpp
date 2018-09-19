/**
 * @brief Exercício 4 - Exercícios com streams - Tabela suprema
 * 
 * @file mian.cpp
 * @author Allan de Miranda Silva
 * @date 2018-09-19
 */

#include <iostream> // std::cout , std::cin 
#include <iomanip>
#include <vector> // std::vector
#include <fstream>
#include <string>

/**
 * @brief 
 * 
 * @param header 
 * @param dados 
 */
void print(const std::vector <std::string> & header, const std::vector <int> & dados){
	std::vector <int> tamanho_coluna;
	// ### HEADER ###
	
	// Primeira linha
	std::cout << "+";
	for(auto i : header){
		std::cout << std::setw(i.size()+2) << std::setfill('-') << "";
		std::cout << "+"; 
	}
	std::cout << std::endl;
	
	// Segunda linha
	std::cout << "|";
	for(auto i : header){
		std::cout << std::setfill (' ') << std::fixed << std::setw(i.size()+1) << i << " |";
	}
	std::cout << std::endl;

	// Terceira linha
	std::cout << "+";
	for(auto i : header){
		std::cout << std::setw(i.size()+2) << std::setfill('-') << "";
		tamanho_coluna.push_back(i.size()+2);
		std::cout << "+"; 
	}
	std::cout << std::endl;

	// ### DADOS ###

	// Dados
	std::cout << "|";
	int j(0);
	for(auto i(dados.begin()); i<dados.end(); ++i){
		if(j>=header.size()){
			j = 0;
			std::cout << std::endl;	
			std::cout << "|";
		}
		std::cout << std::fixed << std::setw(header[j].size()+1) << std::setfill(' ') << *i;
		std::cout << " |";
		++j;		
	}
	std::cout << std::endl;	

	// Ultima linha
	std::cout << "+";
	for(auto i : header){
		std::cout << std::setw(i.size()+2) << std::setfill('-') << "";
		tamanho_coluna.push_back(i.size()+2);
		std::cout << "+"; 
	}
	std::cout << std::endl;
	
}

int main(int argc, char const *argv[])
{
	std::ifstream ifs;
    std::string palavra;
    std::vector <std::string> cabecalho;
	ifs.open(argv[1]);
    while(getline ( ifs , palavra )){
        cabecalho.push_back(palavra);
    }
    ifs.close();

	int numero;
    std::vector <int> dados;
	ifs.open(argv[2]);
    while(ifs >> numero){
        dados.push_back(numero);
    }
    ifs.close();

	print(cabecalho, dados); // Imprimir cabeçalho da tabela.

	return EXIT_SUCCESS;
}

