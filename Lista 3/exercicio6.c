/* Q6) Escreva um programa que receba, como parâmetro de entrada, uma string, e verifique se esta
string é uma “boa” senha. Entende-se por “boa” senha uma senha com as seguintes características de
formação: (i) ela deve possuir, no mínimo, oito caracteres; (ii) ela deve ter, no mínimo, um caracter
entre '0' a '9'; (iii) ela deve possuir, no mínimo, uma letra maiúscula; (iv) ela deve ter, no mínimo, uma
letra minúscula; e (v) ela deve ter, pelo menos, um caracter do conjunto formato pelos demais
caracteres do teclado. */

#include<stdio.h>
#include<stdlib.h>

int n_char(char* str){
    int i = 0;
    while(str[i]){
        i++;
    }
    return i;
}

