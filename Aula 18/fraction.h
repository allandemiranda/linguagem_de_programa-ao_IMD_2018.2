/**
 * @file fraction.h
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief Cabeçalho com a declaração da classe
 * @version 0.1
 * @date 2018-10-02
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#ifndef _FRACTION_H_
#define _FRACTION_H_

/**
 * @brief
 * 
 */
class Fraction{
        int numerador_faction;
        int denominador_fraction;
        int mdc(int, int);
    public:
        Fraction(int = 0, int = 0); // Pegar a fração
        void set_(int, int); // Atualizar a fração
        bool is_proper(Fraction); // Verifica e retorna true se a fração é própria, ou false, caso contrário
        void reduce(Fraction); // Realize a redução  da fração
        int make_proper(Fraction);
        bool is_zero(Fraction);
        // Operadores
        Fraction operator * (const Fraction&);
        Fraction operator / (const Fraction&);
        Fraction operator + (const Fraction&);
        Fraction operator - (const Fraction&);
};

#endif