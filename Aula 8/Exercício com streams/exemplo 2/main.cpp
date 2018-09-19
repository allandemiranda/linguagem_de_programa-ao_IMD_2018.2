#include <iostream>
#include <fstream>
#include <string>

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
    askUserFileName(ifs, "Please , enter a file name :");
    char ch;
    while(ifs.get(ch)){
        std::cout.put(ch);
    }
    ifs.close();

    return EXIT_SUCCESS;
}