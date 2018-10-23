/*
                ＴＲＡＢＡＬＨＯ ＰＲＯＧ ＩＩ
        Atílio Antônio Dadalto e Tiago da Cruz Santos
                       Data: 11/2018                         */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "include/ManipulaVetores.h"
#include "include/Distancias.h"

int main()
{
    // Exemplo de uso de funções dos módulos
    int tam;
    printf("Tamanho dos vetores:\n");
    scanf("%i", &tam);
    // printf("r: "); // para distância minkowskiana
    // scanf("%i", &r);

    float a[tam], b[tam], soma[tam], distE, distM, distS;

    leVet(a, tam);
    leVet(b, tam);

    somaVet(a, b, tam, soma);
    printf("Vetor da soma:\n");
    printaVet(soma, tam);

    distEuclid(a, b, tam, &distE);
    printf("Distancia euclidiana: %.2f\n", distE);
    // distSemCoss(a, b, tam, &distS);
    // printf("Distancia por semelhança de cosseno: %.2f\n", distS);
    // distMinkowsky(a, b, tam, r, &distM);
    // printf("Distancia minkowskiana: %.2f", distM);

    return 0;
}
