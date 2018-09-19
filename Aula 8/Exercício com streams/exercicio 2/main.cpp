/**
 * @brief Exercício 2 - Gravação de dados em arquivo
 * 
 * @file main.cpp
 * @author your name
 * @date 2018-09-19
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

/**
 * @brief Função para receber nome de arquivo a ser aberto
 * 
 * @param ifs_ Referencia para o arquivo stream de input aguardando ser aberto 
 * @param msg_ Mensagem para mostrar ao usuário quando perguntar pelo nome do arquivo
 * @return std::string Um string com o nome do arquivo fornecid pelo usuário
 */
std::string askUserFileName(std::ifstream & ifs_, std::string msg_ = ""){
    std::string fileName;
    while(true){
        std::cout << msg_;
        std::getline(std::cin, fileName); // Get the file name .
        ifs_.open(fileName.c_str()); // Try to open the file .
        if(! ifs_.fail()){
            return fileName;
        }
        fileName.clear(); // Clear file name , try again ...
        std::cout << "Unable to open the file . Try again .\ n";
        if(msg_ == ""){
            msg_ = "Enter file name: ";
        }
    }
}

int main(void){
    std::ifstream ifs;
    askUserFileName(ifs,"Please, ennter a file name: ");
    int number;
    std::vector <int> number_list;
    while(ifs >> number){
        number_list.push_back(number);
    }
    ifs.close();

    std::sort(number_list.begin(), number_list.end());

    std::ofstream outFile;
    outFile.open("tabela.txt", std::ios::app);

    for(int i=(number_list.size()-1); i>=0; --i){
        outFile << number_list[i] << " ";
    }

    outFile.close();

    return EXIT_SUCCESS;
}