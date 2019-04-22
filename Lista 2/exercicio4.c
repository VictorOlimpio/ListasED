/* Q4) Implemente um programa que, infinitamente, teste se um número é um palíndromo (Dica: se
uma palavra pode ser lida, indiferentemente, da esquerda para a direita e vice-versa, ela é
considerada um palíndromo). Você deve passar o número a ser testado. O seu programa deverá
imprimir as seguintes mensagens “VERDADEIRO” (caso o número seja um palíndromo) ou
“FALSO” (caso o número não seja um palíndromo) na console. Seu programa para quando o
número for negativo. */

#include <stdio.h>
#include <stdlib.h>

int igual(int n1[], int n2[], int tam){
    for(int i = 0; i < tam; i++){
        if(n1[i] != n2[i]){
            return 0;
        }
    }
    return 1;
}
void imprime(int n[], int tam){
    for(int i = 0; i < tam; i++){
        printf("%d", n[i]);
    }
    printf("\n");
}

int main(void)
{
    long n, n_temp;
    int tam = 0;
    scanf("%ld", &n);
    n_temp = n;
    while(n_temp > 0){
        n_temp /= 10;
        tam++;
    }
    int n1[tam], n1_invertido[tam];

    for(int i = (tam -1); i >= 0; i--){
        n1[i] = n % 10;
        n /= 10;
    }
    for(int i = 0; i < tam; i++){
        n1_invertido[i] = n1[abs((tam-1) - i)];
    }
    imprime(n1, tam);
    imprime(n1_invertido, tam);

    if(igual(n1, n1_invertido, tam))
        printf("VERDADEIRO\n");
    else
        printf("FALSO\n");
    

    return 0;
}