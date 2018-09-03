#include <iostream>
#include <iomanip>

int main(void){
	const double N_PI = 3.14159265358979323846;
	const double N_GRAVITY = 9.80665;

	for(auto prec(2); prec < 5; ++prec){
		std::cout << std::setw(40) << std::setfill('-') << "" << std::endl; // imprimir linha
		std::cout << std::setfill(' '); // preencher com espaço em branco
		std::cout << std::fixed << std::setprecision(prec) << "[" << std::setw(12) << N_PI << "]" << std::endl;
		std::cout << std::setfill('*'); // preencher com *
		std::cout << std::scientific << std::setprecision(prec) << "[" << std::setw(12) << N_GRAVITY << "]" << std::endl;
	}

	return EXIT_SUCCESS;
}