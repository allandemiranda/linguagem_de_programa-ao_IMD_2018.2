# Estudo de Caso: Frações

O objetivo desse exercício é colocar em prática seus conhecimentos sobre como implementar, organizar e testar classes em C++. Especificamente, você deve projetar e implementar a classe `Fraction` que representa **frações**.

Organize seu código nos seguintes arquivos:
* `fraction.h`: cabeçalho com a declaração da classe.
* `fraction.cpp`: implementação da classe.
* `main.cpp`: código cliente para testar a fração.

Alternativamente, você pode optar por não implementar um cliente e utilizar, ao invés, uma infra-estrutura de testes com o [Google Tests](https://github.com/google/googletest/blob/master/googletest/docs/primer.md).

## Básico

Uma fração é composta de um _numerador_ e um _denominador_, de forma que nossa classe deve ter membros-dados para cada um destes componentes. A seguir, vamos considerar as operações que normalmente são aplicadas sobre frações.

Primeiramente precisamos _inicializar_ uma fração fornecendo valores para seu numerador e denominador. Isso pode ser feito tanto via `constructor`, no momento da **instanciação** (declaração) de um objeto e/ou por algum outro método que permite _atualizar_/_recuperar_ (métodos `set_` e `get_`) esses valores uma vez que o objeto fração já tenha sido instanciado.

Uma fração pode ser _própria_ ou _imprópria_. Recorde que uma fração própria é aquela em que o numerador é menor que o denominador. De maneira mais formal, uma fração própria teria a forma:

```math
    \frac{a}{b}\, |\, a < b \quad \text{e} \quad 0 < \frac{a}{b} < 1.
```

enquanto que uma fração imprópria teria a forma:
```math
    \frac{a}{b}\, |\, a \ge b \quad \text{e}\quad  \frac{a}{b} \ge 1.
```
É importante estar ciente que no caso se fração imprópria ela pode ser do tipo _aparente_, que acontece quando o numerador é _multiplo_ do denominador.
> _Qual seria, então, os valores para o numerador e denominador de uma fração aparente?_

Portanto, a classe pode oferecer o método `is_proper()` que verifica e retorna `true` se a fração é própria, ou `false`, caso contrário. 

No caso da fração ser própria, precisamos oferecer uma operação que realize a _redução_  da fração, se necessário: `reduce()`. Como o processo de redução acontece quando dividimos o numerador e e denominador pelo **máximo divisor comun (MDC)**, pode ser uma boa estratégia criar um método _privado_ `mdc(int,int)` que determina e retorna o MDC de dois números. Por exemplo, uma fração `6/8` 
é própria, mas não está reduzida. Após a aplicação do `reduce()` a fração seria `3/4`.

No caso da fração ser imprópria, precisamos oferecer um método para torná-la própria: `make_proper()`. Esse método reduz a fração e  retorna a parte inteira do número misto correspondente. Por exemplo, suponha que uma fração foi criada como sendo `15/14`. Neste caso temos uma fração imprópria. Ao apliacarmos o `make_proper()` o método deveria retornar o valor `3` e reduzir o numerador para `3` e o denominador para `4`, pois:
 
 ```math
 \frac{15}{4} = 3\,\, \frac{3}{4}
 ```

Outra tipo de consulta importante é saber se uma função é _zero_, ou seja, possui um numerador zero e um denominador diferente de zero. Para verificar essa situação, podemos projetar o método `is_zero()`.

## Aritmética de Frações

Sua classe deve sobrecarregar os operadores aritméticos para realizar as operações binárias de adição, subtração, multiplicação, divisão, e a operação unária de negação de fração.

Para tornar sua classe completa, é recomendado também sobrecarregar o operador de _extração_ `operator<<()` para permitir a utilização de fluxos de saída. Adicionalmente, você também pode implementar a sobrecarga do operador de _inserção_ `operator>>()` para permitir a inserção a partir de fluxos.

## Validação

Para validar sua classe, é possível utilizar duas estratégias:

1. Criar testes com Google Tests para testar cada um dos métodos implementados; ou
2. Criar uma aplicação-cliente que executa as operações suportadas pela classe `Fraction`. Essa aplicação poderia ler a lista de comandos de um arquivo de entrada e gerar um arquivo de saída com as respostas correspondentes. Neste caso, cada linha do arquivo de entrada conterá uma instrução ou comando a ser aplicado sobre uma fração. Para cada linha do arquivo de entrada a aplicação deve criar uma linha correspondente em um arquivo de saída com a resposta.

Exemplo de entrada:
```
Initialize 3 4
IsZero
IsProper
GetNumerator
GetDenominator
Initialize 4 3
IsProper
MakeProper
Initialize 9 12
IsReduced
Reduce
Add 3 4 5 6
```

Saída correspondente:
```
3/4
No
Yes
3
4
4/3
No
1 1/3
9/12
No
3/4
19/12
```

~ FIM ~