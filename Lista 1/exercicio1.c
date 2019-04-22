/*
Q1) Escreva um programa que, infinitamente, leia um número inteiro n, que representa o tamanho,
seguida de uma sequência de n números inteiros, e determine o comprimento máximo de um
segmento crescente destes n números. Exemplos:
 Na sequência 5, 10, 3, 2, 4, 7, 9, 8, 5 o comprimento do segmento crescente máximo é 4.
 Na sequência 10, 8, 7, 5, 2 o comprimento de um segmento crescente máximo é 1.
Seu programa para quando n for menor ou igual a zero.
*/
#include <stdio.h>

int main()
{
    int n, tam_max, tam_temp;
    int num = 0;
    int tam = 0;
    int temp = 0;

    while (n)
    {
        scanf("%d", &n);
        while (n > 0)
        {
            temp = num;
            scanf("%d", &num);
            if (temp <= num)
            {
                tam++;
            }
            else
            {
                tam_max = tam;
                tam = 0;
            }
            if (tam > tam_max)
            {
                tam_max = tam;
            }
            n--;
        }
        printf("a maior sequência é: %d\n", tam_max);
        n++;
    }
    return 0;
}
