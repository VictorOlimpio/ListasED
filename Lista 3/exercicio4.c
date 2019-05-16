/* Q4) Escreva uma função que receba, como entrada, uma cadeia de caracteres s e um inteiro n, e, em
seguida, retire o "prefixo" da cadeia s de tamanho n (isto é, retire os n primeiros caracteres). Se a
cadeia não tiver pelo menos n caracteres, deve ser impressa a mensagem "erro". Por exemplo, se s
= "abcdefghi" e n = 3, então a cadeia "defghi" deve ser impressa; com a mesma cadeia s e n = 17,
deve ser impresso "erro". O protótipo desta função é o seguinte: void retira_inicio_n (char *str, int
n). */

#include<stdlib.h>
#include<stdio.h>

int string_size(char *str){
    int i = 0;
    while(str[i])
        i++;
    return i;
}
char* substring(char *str, int n){
    char *prefixo = (char*)malloc(sizeof(char)*n), *substring = (char*)malloc(sizeof(char)*(string_size(str)-n));
    int j = 0;
    for(int i = 0; i < n; i++){
        prefixo[i] = str[i];
    }
    for(int i = n; i < string_size(str); i++){
        substring[j] = str[i];
        j++;
    }
    for(int i = 0; i < string_size(substring); i++){
        str[i] = substring[i];
    }
    str[string_size(substring)] = '\0';
    free(substring);
    return prefixo;
}

void retira_inicio_n (char *str, int n){
    
    if(n > string_size(str))
        printf("erro\n");
    else{
        printf("%s\n", substring(str, n));
    }
}

int main(void){
    char string[10];
    scanf("%s", string);
    retira_inicio_n(string, 3);
    //retira_inicio_n(string, 10);
    printf("%s", string);
    return 1;
}