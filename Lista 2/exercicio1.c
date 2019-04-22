/*
Q1) Uma forma simples e eficiente de calcular todos os números primos até um certo valor n é o
método da Peneira de Eratosthenes. O processo é simples: escrevem-se todos os valores entre 2
e n (limite máximo). Em seguida, faz-se um círculo em volta do 2, marcando como primo e riscamse 
todos os seus múltiplos. Continua-se a fazer círculos em volta do menor inteiro que se
encontra, eliminando todos os seus múltiplos. Quando não restarem números sem terem círculos
à volta ou traços por cima, os números com círculos à volta representam todos os primos até n. A
figura seguinte apresenta o método para n = 40.
Escreva um programa que implemente a Peneira de Eratosthenes. Você deve ler o valor n e
mostrar todos os números primos encontrados.
*/
#include <stdio.h>

int main(void)
{
    int n, tam, i;

    while (1)
    {
        scanf("%d", &n);
        tam = n * n;
        int primos[tam];
        for (i = 2; i < tam; i++)
            primos[i] = 1;
        for (i = 2; i < tam; i++)

            for (int j = i + 1; j < tam + 1; j++)
                if (j % i == 0)
                    primos[j] = 0;

        for (i = 2; n; i++)
            if (primos[i] == 1)
            {
                printf("%d ", i);
                n--;
            }
    }

    return 0;
}
