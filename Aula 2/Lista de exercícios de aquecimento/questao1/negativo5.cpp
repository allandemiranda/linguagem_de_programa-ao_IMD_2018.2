/**
 * @file negativo5.cpp
 * @brief Questão 1 da lista
 * @copyright Allan de Miranda - BTI - IMD - UFRN - 2018.2
 */
#include <iostream> /*< Biblioteca usada para cout, cin e andl */
#include <iterator>  /*< Biblioteca usada para begin e end */

#define QUANTIDADE 5 /*< definir quantidade de números a analisar */

/**
 * @brief Função para ler os números e salvar no vetor escolhido
 * @param *vetor Aponta para a posição 0 do vetor
 * @param size Tamanho do vetor
 */
void incerir_numeros(int *vetor, const size_t size){
	/*! Loop para incerir vários números ao vetor **/
	for(auto i(0u); i<size; ++i){
		std::cin >> *(vetor + i); /*< Incerir número ao vetor */
	}
}

/**
 * @brief Fução para contar quantos negativos existem no vetor
 * @param *vetor Aponta para a posição 0 do vetor
 * @param size Tamanho do vetor a ser analisado
 * @retunr Retorna quantidade de números negativos que exitem no vetor
 */
size_t contar_negativos(const int *vetor, const size_t size){
	size_t cont(0); /*< Contar quantos negativos existem no vetor */
	/*! Analisar o vetor **/
	for(auto i(0u); i<size; ++i){
		/*! Teste lógico para saber se é negativo */
		if(*(vetor+i)<0){
			++cont; /*< Some mais um pois ele é negativo */
		}
	}
	return cont; /*< Retornar a quatidade de negativos do vetor */
}

/**
 * @brief Função main
 * @param void void
 * @retunr 0
 */
int main(void) {
	int vetor_de_numeros[QUANTIDADE]; /*< Vetor para conter os números */
	size_t tamanho_do_vetor = sizeof(vetor_de_numeros)/sizeof(int); /*< Calcular o tamanho do vetor */

	incerir_numeros(std::begin(vetor_de_numeros), tamanho_do_vetor); /*< Adicionar números ao vetor */

	size_t negativos = contar_negativos(std::begin(vetor_de_numeros), tamanho_do_vetor); /*< Verificar quatidade de negativos */

	/*! Verificador da resposta e imprimir ela de forma correta */
	switch(negativos){
		case 0: /*< Quando não achar números negativos */
			std::cout << "Não existem núemros negativos" << std::endl;
			return 0; /*< FIM */
		case 1: /*< Qunado tiver somente um número negotivo */
			std::cout << "Existe somente 1 número negativo" << std::endl;
			return 0; /*< FIM */
		default: /*< Quando tiver mais de um número negativo */
			std::cout << "Existem " << negativos << " números negativos" << std::endl;
			return 0; /*< FIM */
	}
}