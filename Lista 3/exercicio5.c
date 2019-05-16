/* Q5) Escreva uma função que receba, como entrada, uma cadeia de caracteres s e um inteiro n, e, em
seguida, retire o "sufixo" da cadeia s de tamanho n (isto é, retire os n últimos caracteres). Se a
cadeia não tiver pelo menos n caracteres, deve ser impressa a mensagem "erro". Por exemplo, se s
= "abcdefghi" e n = 3, então a cadeia "abcdef" deve ser impressa; com a mesma cadeia s e n = 17,
deve ser impresso "erro". O protótipo desta função é o seguinte: void retira_fim_n (char *str, int n). */

#include<stdlib.h>
#include<stdio.h>

int string_size(char *str){
    int i = 0;
    while(str[i])
        i++;
    return i;
}

void retira_fim_n (char *str, int n){
    char *sufixo = (char*)malloc(sizeof(char)*n);
    int j = 0;
    if(n > string_size(str))
        printf("erro\n");
    else{
        for(int i = (string_size(str)-n); i < string_size(str); i++){
            sufixo[j] = str[i];
            j++;
        }
        printf("%s\n", sufixo);
    }
    str[string_size(str)-n] = '\0';
}

int main(void){
    char string[10];
    scanf("%s", string);
    retira_fim_n(string, 3);
    //retira_fim_n(string, 10);
    printf("%s", string);
    return 1;
}