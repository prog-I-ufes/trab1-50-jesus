/*
                ＴＲＡＢＡＬＨＯ ＰＲＯＧ ＩＩ
        Atílio Antônio Dadalto e Tiago da Cruz Santos
                       Data: 11/2018                         */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "include\ManipulaVetores.h"


int main()
{
    // Exemplo de uso de funções da ManipulaVetores.h
    int tam;
    scanf("%i", &tam);

    int a[tam], b[tam], soma[tam];

    leVet(a, tam);
    leVet(b, tam);

    somaVet(a, b, tam, soma);
    printaVet(soma, tam);

    return 0;
}
