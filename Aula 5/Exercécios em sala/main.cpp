#include <iostream>

namespace lp1{
    template <class T>
    void swap (T& a, T& b){
        T novo(a);
        a = b;
        b = novo;        
    }
}

int main(void)){
    int i(5), j(6);
    double f(2.0), g(0.5);

    lp1::swap(i,j);
    lp1::swap(f,g);

    std::cout << i << "," << j << std::endl;
    std::cout << f << "," << g << std::endl;

    return 0;
}