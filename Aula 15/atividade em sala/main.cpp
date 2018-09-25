#include <iostream>

class circulo{
        int x, y;
        float raio;
    public:
        circulo(int, int);
        void set_raio(float);
        float area(void);
        bool intecesao(circulo);
};

circulo::circulo(int d_um, int d_dois){
    x = d_um;
    y = d_dois;
}

void circulo::set_raio(float tamanho){
    raio = tamanho;
}

float circulo::area(){
    return (3.14 * raio);
}

bool circulo::intecesao(circulo b){
    if(x == b.x){
        if(y == b.y){
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    circulo balao_um(10, 20);
    circulo balao_dois(10, 20);

    balao_um.set_raio(10);
    balao_dois.set_raio(30);

    std::cout << balao_um.area() << " - " << balao_dois.area() << std::endl;

    if(balao_um.intecesao(balao_dois)){
        std::cout << "verdade" << std::endl;
    } else {
        std::cout << "falso" << std::endl;
    }
    return 0;
}

