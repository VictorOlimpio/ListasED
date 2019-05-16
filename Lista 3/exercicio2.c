/* Q2) Implemente uma função em C que receba uma string como parâmetro e retorne uma nova string
com todos os caracteres minúsculos substituídos pelo caracter ‘?’. Por exemplo, se for passada a
string “740-Charitas-Leme”, a função deve retornar a string “740-Ch?r?t?s-L?m?”. A assinatura desta
função deve ser char * codifica (char *str). A string passada como parâmetro não pode ser alterada.
O espaço de memória para a nova string deve ser alocado dinamicamente. */

#include<stdio.h>
#include<stdlib.h>

char * codifica (char *str){
    char *retorno = (char*)malloc(sizeof(char)*100);
    int i = 0;
    while(str[i]){
        retorno[i] = str[i];
        if(retorno[i] >= 97 && retorno[i] <= 122){
            retorno[i] = '?';
        }
        i++;
    }
    return retorno;
}

int main(void){
    char *string = (char*)malloc(sizeof(char)*100), *string_alterada = (char*)malloc(sizeof(char)*100);
    scanf("%s", string);
    string_alterada = codifica(string);
    printf("%s\n", string);
    printf("%s\n", string_alterada);
}