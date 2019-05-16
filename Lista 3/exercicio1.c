/* Q1) Implemente uma função em C que receba uma string como parâmetro e substitua todas as suas
letras por predecessoras do alfabeto, trocando maiúsculas por minúsculas. Por exemplo, a string
“Amor” seria alterada para “zLNQ”. Esta função deve obedecer o seguinte protótipo: void
shift_troca_string (char *str). A letra ‘a’ deve ser substituída por ‘Z’ (e ‘A’ por ‘z’). Caracteres que não
forem letras devem ser substituídos por ‘!’. Sabe-se que A = 65, Z = 90, a = 97 e z = 122. */

#include<stdlib.h>
#include<stdio.h>

void shift_troca_string (char *string){
    int i = 0;
    while(string[i]){
        if(string[i] >= 64 && string[i] <= 122){
            if(string[i] >= 65 && string[i] < 97){
                string[i] += 32;
            }else{
                string[i] -= 32;
            }
            string[i]--;
        }
        if(string[i] < 64 || (string[i] > 90 && string[i] < 97) || string[i] > 122 ){
            string[i] = '!';
        }else{
            if(string[i] == 64)
                string[i] = 122;
            if(string[i] == 97)
                string[i] = 90;
        }
        i++;
    }
}

int main(void){
    char *string = (char*)malloc(sizeof(char)*15);
    scanf("%s", string);
    shift_troca_string(string);
    printf("%s", string);
}