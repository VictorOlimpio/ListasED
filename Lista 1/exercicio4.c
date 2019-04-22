/* Q4) Implemente um programa que, infinitamente, receba, como parâmetro de entrada, um número
n e retorne os n primeiros números primos existentes depois de n. Por exemplo, se n = 2, a
resposta será os primos 3 e 5. É necessário salientar que n não precisa ser primo. Seu programa
para quando n for menor ou igual a zero. */

#include<stdio.h>

int eprimo(int n)
{
    if (n == 2)
        return 1;

    if (n % 2 == 0)
        return 0;

    for (int j = 3; j < n / 2; j += 2)
    {
        if (n % j == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    int n = 0;
    while (1)
    {
        scanf("%d", &n);
        for (int i = n+1; n; i++)
        {
            if (eprimo(i))
                {
                    printf("%d ", i);
                    n--;
                }
        }
        printf("\n");
    }
    return 0;
}