/*
    Solução questão 1022
    Autor: Lucas Neiva <https://github.com/lucasneiva>
*/

#include<stdlib.h>
#include<stdio.h>

typedef struct
{
    int numerador, denominador;
} racional;

racional somar(racional, racional);
racional subtrair(racional, racional);
racional multiplicar(racional, racional);
racional dividir(racional, racional);
void simplificar(racional*);
void corrigirSinal(racional*);
int calcularMDC(int, int);

int main() {
    int N;
    racional op1, op2, res;
    char operacao;

    scanf("%d", &N);


    for (int i = 0; i < N; i++)
    {
        scanf("%d / %d %c %d / %d", &op1.numerador, &op1.denominador, &operacao, &op2.numerador, &op2.denominador);

        switch (operacao)
        {
        case '+':
            res = somar(op1, op2);
            break;
        case '-':
            res = subtrair(op1, op2);
            break;
        case '*':
            res = multiplicar(op1, op2);
            break;
        case '/':
            res = dividir(op1, op2);
            break;
        default:
            break;
        }
        corrigirSinal(&res);
        printf("%d/%d = ", res.numerador, res.denominador);
        simplificar(&res);
        printf("%d/%d\n", res.numerador, res.denominador);
    }
    
    return 0;
}

racional somar(racional operando1, racional operando2) {
    racional resultado;
    resultado.numerador = operando1.numerador * operando2.denominador + operando2.numerador * operando1.denominador;
    resultado.denominador = operando1.denominador * operando2.denominador;
    return resultado;
}

racional subtrair(racional operando1, racional operando2) {
    racional resultado;
    resultado.numerador = operando1.numerador * operando2.denominador - operando2.numerador * operando1.denominador;
    resultado.denominador = operando1.denominador * operando2.denominador;
    return resultado;
}

racional multiplicar(racional operando1, racional operando2) {
    racional resultado;
    resultado.numerador = operando1.numerador * operando2.numerador;
    resultado.denominador = operando1.denominador * operando2.denominador;
    return resultado;
}

racional dividir(racional operando1, racional operando2) {
    racional resultado;
    resultado.numerador = operando1.numerador * operando2.denominador;
    resultado.denominador = operando1.denominador * operando2.numerador;
    return resultado;
}

void simplificar(racional *simplificando) {
    int MDC = calcularMDC(simplificando->numerador, simplificando->denominador);
    simplificando->numerador /= MDC;
    simplificando->denominador /= MDC;
    corrigirSinal(simplificando);
}

int calcularMDC(int a, int b) {
    int aux;
    while(b != 0) {
        aux = b;
        b = a%b;
        a = aux;
    }
    return a;
}

void corrigirSinal(racional *operando) {
    if (operando->denominador < 0)
    {
        operando->denominador = -operando->denominador;
        operando->numerador = -operando->numerador;
    }
}
