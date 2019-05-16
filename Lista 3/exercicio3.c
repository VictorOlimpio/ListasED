/* Q3) Considere que você receba um vetor de inteiros com números ímpares e pares e um número n,
sendo n o tamanho do vetor. Implemente uma função que separe os valores inteiros de um vetor em
ímpares e pares, obedecendo a ordem de entrada destes números no vetor. Implemente os dois
protótipos abaixo:
a) int* transf_i_p (int *vet, int n)
b) void transf_i_p (int *vet, int n) */

#include<stdio.h>
#include<stdlib.h>

int* transf_i_p (int *vet, int n){
    int i, pares[n], impares[n], npar = 0, nimpar = 0, *retorno = (int*)malloc(sizeof(int)*n);
    for(i = 0; i < n; i++){
        if(vet[i] % 2 == 0){
            pares[npar] = vet[i];
            npar++;
        }else{
            impares[nimpar] = vet[i];
            nimpar++;
        }
    }
    for(i = 0; i < nimpar; i++){
        retorno[i] = impares[i];
    }
    npar = 0;
    for(i = nimpar; i < n; i++){
        retorno[i] = pares[npar];
        npar++;
    }
    return retorno;
}

void preenche_vet(int *vet, int n){
    for(int i = 0; i < n; i++){
        vet[i] = i;
    }
}

void imprime(int *vet, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}

void transf_i_p_void (int *vet, int n){
    int i, pares[n], impares[n], npar = 0, nimpar = 0;
    for(i = 0; i < n; i++){
        if(vet[i] % 2 == 0){
            pares[npar] = vet[i];
            npar++;
        }else{
            impares[nimpar] = vet[i];
            nimpar++;
        }
    }
    for(i = 0; i < nimpar; i++){
        vet[i] = impares[i];
    }
    npar = 0;
    for(i = nimpar; i < n; i++){
        vet[i] = pares[npar];
        npar++;
    }
}

int main(void){
    int vet[10], *vet2;
    preenche_vet(vet, 10);
    imprime(vet, 10);
    transf_i_p_void(vet, 10);
    imprime(vet, 10);
}