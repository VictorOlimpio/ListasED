/* Um número a é dito permutação de um número b se os dígitos de a formam uma permutação
dos dígitos de b. Exemplo: 5412434 é uma permutação de 4321445, mas não é uma permutação
de 4312455. Faça um programa que receba a e b e responda se a é permutação de b. Obs.:
Considere que o dígito 0 (zero) não deve aparecer nos números. */
#include <stdio.h>

int compara(int n1[], int n2[], int tam1, int tam2)
{
    int cont = 0;
    if (tam1 != tam2)
        return 0;
    for (int i = 0; i < tam1; i++)
        for (int j = 0; j < tam2; j++)
            if (n1[i] == n2[j])
            {
                cont++;
                break;
            }
    if (cont == tam1)
        return 1;
    return 0;
}

int main(void)
{
    int a = 0, b = 0, tam1 = 0, tam2 = 0;
    scanf("%d %d, ", &a, &b);
    int a_temp = a, b_temp = b;
    while (a_temp)
    {
        a_temp /= 10;
        tam1 += 1;
    }
    while (b_temp)
    {
        b_temp /= 10;
        tam2 += 1;
    }
    int numero1[tam1], numero2[tam2];
    for (int i = 0; i < tam1; i++)
    {
        numero1[i] = a % 10;
        a /= 10;
        numero2[i] = b % 10;
        b /= 10;
    }

    if (compara(numero1, numero2, tam1, tam2))
        printf("é permutação\n");
    else
        printf("não é permutação");
    return 0;
}