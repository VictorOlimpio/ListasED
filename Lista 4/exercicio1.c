/* Q1) Dada uma matriz quadrada de dimensão 9, com valores de 1 a 9 em suas posições, escreva
um programa que verifique se esta matriz é uma solução válida para o Sudoku (isto é, uma
solução é válida no Sudoku se cada linha, cada coluna e cada bloco contém os números de 1 a 9
somente uma vez).
5 3 4 | 6 7 8 | 9 1 2
6 7 2 | 1 9 5 | 3 4 8
1 9 8 | 3 4 2 | 5 6 7
-------+-------+------
8 5 9 | 7 6 1 | 4 2 3
4 2 6 | 8 5 3 | 7 9 1
7 1 3 | 9 2 4 | 8 5 6
-------+-------+------
9 6 1 | 5 3 7 | 2 8 4
2 8 7 | 4 1 9 | 6 3 5
3 4 5 | 2 8 6 | 1 7 9 */

#include<stdio.h>

int compara(int val1, int val2){
    if(val1 == val2)
        return 1;
    return 0;
}

void imprime(int linha, int coluna, int mat[linha][coluna]){
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int valida_linha(int linha, int coluna, int mat[linha][coluna]){
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna-1; j++){
            if(compara(mat[i][j], mat[i][j+1]))
                return 0;
        }
    }
    return 1;
}

int valida_coluna(int linha, int coluna, int mat[linha][coluna]){
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna-1; j++){
            if(compara(mat[j][i],mat[j+1][i]))
                return 0;
        }
    }
    return 1;
}

int repetido(int linha, int coluna, int mat[linha][coluna]){
    int contador = 0;
    int pivo = 0;
    for(int i = 0; i < linha; i++){
        pivo = mat[i][0];
        for(int j = 0; j < linha; j++){
            for(int k = 0; k < coluna; k++){
                if(compara(pivo, mat[j][k]) && k != 0)
                    contador++;
            }
        }
    }
    if(contador == 0)
        return 0;
    else
        return 1;           
}

int valida_quadrado(int mat[9][9]){
    for(int i = 1; i < 8; i += 3){
        for(int j = 1; j < 8; j += 3){
            int mat_temp[3][3] = {{mat[i-1][j-1], mat[i-1][j], mat[i-1][j+1]},
                                {mat[i][j-1], mat[i][j], mat[i][j+1]},
                                {mat[i+1][j-1], mat[i+1][j], mat[i+1][j+1]}};
            if(repetido(3, 3, mat_temp)){
                return 0;
            }
        }
    }
    return 1;
}

int solucao(int mat[9][9]){
    if(valida_linha(9, 9, mat) && valida_coluna(9, 9, mat) && valida_quadrado(mat))
        return 1;
}

int main(void){
    int mat[9][9] = {{5, 3, 4, 6, 7, 8, 9, 1, 2},
                     {6, 7, 5, 1, 9, 2, 3, 4, 8},
                     {1, 9, 8, 3, 4, 5, 2, 6, 7},
                     {8, 5, 9, 7, 6, 1, 4, 2, 3},
                     {4, 2, 6, 8, 5, 3, 7, 9, 1},
                     {7, 1, 3, 9, 2, 4, 8, 5, 6},
                     {9, 6, 1, 5, 3, 7, 2, 8, 4},
                     {2, 8, 7, 4, 1, 9, 6, 3, 5},
                     {3, 4, 1, 2, 8, 6, 5, 7, 9}};
    /* int mat[9][9] = {{5, 3, 4, 6, 7, 8, 9, 1, 2},
                     {6, 7, 2, 1, 9, 5, 3, 4, 8},
                     {1, 9, 8, 3, 4, 2, 5, 6, 7},
                     {8, 5, 9, 7, 6, 1, 4, 2, 3},
                     {4, 2, 6, 8, 5, 3, 7, 9, 1},
                     {7, 1, 3, 9, 2, 4, 8, 5, 6},
                     {9, 6, 1, 5, 3, 7, 2, 8, 4},
                     {2, 8, 7, 4, 1, 9, 6, 3, 5},
                     {3, 4, 5, 2, 8, 6, 1, 7, 9}}; */

    printf("%d\n", solucao(mat));
    return 0;
}