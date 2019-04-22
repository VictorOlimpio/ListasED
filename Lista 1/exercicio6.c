/* Q6) Supondo as seguintes declarações:
int x, y, z;
int teste;
x = 5;
y = x++;
z = x--;
Informe os valores de teste, x, y e z depois da avaliação das seguintes expressões:
(a) teste = !y == !x;
(b) teste = ((x++ > y) || (--z <= y));
(c) teste = ((!x) || (!(!z)));
(d) teste = (((x + y) > z) && (x++));
(e) teste = x && y + !3 || 4;  */

#include<stdio.h>

int main(void){
    int x, y, z;
    int teste;
    x = 5;
    y = x++;
    z = x--;

    //a)
    teste = !y == !x;
    printf("a) x = %d, y = %d, z = %d, teste = %d \n", x, y, z, teste);

    //b)
    x = 5;
    y = x++;
    z = x--;
    teste = ((x++ > y) || (--z <= y));
    printf("b) x = %d, y = %d, z = %d, teste = %d \n", x, y, z, teste);

    //c)
    x = 5;
    y = x++;
    z = x--;
    teste = ((!x) || (!(!z)));
    printf("C) x = %d, y = %d, z = %d, teste = %d \n", x, y, z, teste);

    //d)
    x = 5;
    y = x++;
    z = x--;
    teste = (((x + y) > z) && (x++));
    printf("d) x = %d, y = %d, z = %d, teste = %d \n", x, y, z, teste);

    //e)
    x = 5;
    y = x++;
    z = x--;
    teste = x && y + !3 || 4;
    printf("e) x = %d, y = %d, z = %d, teste = %d \n", x, y, z, teste);


}