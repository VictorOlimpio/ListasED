/*
Q3) Implemente um programa que, infinitamente, receba, como parâmetro de entrada, um número
n e um número m, e retorne todas as potências de m, menores que n. Por exemplo, se n = 1000 e
m = 2, seu programa deve imprimir os seguintes números: 1, 2, 4, 8, 16, 32, 64, 128, 256 e 512.
Seu programa para quando n for menor que 1 ou quando m for 0, ou 1 ou -1.
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    int m, n, i, resultado;
    while (1)
    {
        scanf("%d %d", &m, &n);
        if (n < 1 || m == 0 || m == 1 || m == -1)
            break;
        for (i = 0;; i++)
        {
            resultado = pow(m, i);
            if (resultado > n)
                break;
            printf("%d ", resultado);
        }
    }
    return 0;
}