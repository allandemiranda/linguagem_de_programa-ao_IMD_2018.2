/**
 * @file fraction.cpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief Implementação da classe
 * @version 0.1
 * @date 2018-10-02
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include "fraction.h" // Cabeçalho com a declaração da classe

/**
 * @brief Construct a new Fraction:: Fraction object
 * 
 * @param numerador Numerador da fração
 * @param denominador Denominador da fração
 */
Fraction::Fraction(int numerador, int denominador){
    numerador_faction = numerador;
    denominador_fraction = denominador;
}

/**
 * @brief 
 * 
 * @param numerador Numerador da fração
 * @param denominador Denominador da fração 
 */
void Fraction::set_(int numerador, int denominador){
    numerador_faction = numerador;
    denominador_fraction = denominador;
}

/**
 * @brief Verifica a fração própria
 * 
 * @param nova_facao 
 * @return true se a fração é própria
 * @return false caso contrário
 */
bool Fraction::is_proper(Fraction nova_facao){
    if(nova_facao.numerador_faction<nova_facao.denominador_fraction){
        if(((nova_facao.numerador_faction/nova_facao.denominador_fraction)>0) and ((nova_facao.numerador_faction/nova_facao.denominador_fraction)<1)){
            return true;
        }
    } else {
        if((nova_facao.numerador_faction/nova_facao.denominador_fraction)>=1){
            return false;
        }
    }
}

/**
 * @brief Calcular o MDC
 * 
 * @param nova_fracao 
 * @return int O valor que divide o numerador e o denominador
 */
int Fraction::mdc(int n_1, int n_2){
    if(n_2>n_1){
        int temp = n_1;
        n_1 = n_2;
        n_2 = temp;
    }
    int resto = (n_1 % n_2);
    while(resto!=0){
        n_1 = n_2;
        n_2 = resto;
        resto = (n_1 % n_2);         
    }
    return n_2;
}

/**
 * @brief Realize a redução  da fração
 * 
 * @param nova_facao 
 */
void Fraction::reduce(Fraction nova_facao){
    int num_redutor = Fraction::mdc(nova_facao.numerador_faction, nova_facao.denominador_fraction);
    int n_1 = (nova_facao.numerador_faction / num_redutor);
    int n_2 = (nova_facao.denominador_fraction / num_redutor);
    nova_facao.set_(n_1,n_2);
}

/**
 * @brief Reduz a fração e  retorna a parte inteira do número misto correspondente
 * 
 * @param nova_facao 
 * @return int 
 */
int Fraction::make_proper(Fraction nova_facao){
    Fraction::reduce(nova_facao);
    int resto = (nova_facao.numerador_faction % nova_facao.denominador_fraction);
    nova_facao.set_(resto,nova_facao.denominador_fraction);
    return (nova_facao.numerador_faction / nova_facao.denominador_fraction);
}

/**
 * @brief 
 * 
 * @param nova_facao 
 * @return true possui um numerador zero e um denominador diferente de zero
 * @return false 
 */
bool Fraction::is_zero(Fraction nova_facao){
    if((nova_facao.numerador_faction == 0) and (nova_facao.numerador_faction != 0)){
        return true;
    } else {
        return false;
    }
}

/**
 * @brief Operador de multiplicação
 * 
 * @param param 
 * @return Fraction 
 */
Fraction Fraction::operator*(const Fraction& param){
    Fraction temp;
    temp.numerador_faction = numerador_faction * param.numerador_faction;
    temp.denominador_fraction = denominador_fraction * param.denominador_fraction;
    return temp;
}

/**
 * @brief Operador de divisão
 * 
 * @param param 
 * @return Fraction 
 */
Fraction Fraction::operator/(const Fraction& param){
    Fraction temp;
    temp.numerador_faction = denominador_fraction * param.denominador_fraction;
    temp.denominador_fraction = numerador_faction * param.numerador_faction;
    return temp;
}

/**
 * @brief Operador soma
 * 
 * @param param 
 * @return Fraction 
 */
Fraction Fraction::operator+(const Fraction& param){
    Fraction temp;
    int novo_denominador = Fraction::mdc(denominador_fraction, param.denominador_fraction);
    temp.numerador_faction = ((novo_denominador/denominador_fraction)*numerador_faction)+((novo_denominador/param.denominador_fraction)*param.numerador_faction);
    temp.denominador_fraction = novo_denominador;
    return temp;
}

/**
 * @brief Operador subitração
 * 
 * @param param 
 * @return Fraction 
 */
Fraction Fraction::operator-(const Fraction& param){
    Fraction temp;
    int novo_denominador = Fraction::mdc(denominador_fraction, param.denominador_fraction);
    temp.numerador_faction = ((novo_denominador/denominador_fraction)*numerador_faction)-((novo_denominador/param.denominador_fraction)*param.numerador_faction);
    temp.denominador_fraction = novo_denominador;
    return temp;
}