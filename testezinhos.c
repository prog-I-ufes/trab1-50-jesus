/*
                  É ＳÓ ＰＲＡ ＴＥＳＴＡＲ
        Atílio Antônio Dadalto e Tiago da Cruz Santos
                       Data: 11/2018                         */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "include/ManipulaVetores.h"
#include "include/ManipulaMatrizes.h"
#include "include/Distancias.h"
#include "include/Classificador.h"
#include "include/ManipulaArquivos.h"

// Exemplo de uso de funções dos módulos
int main()
{
    int *tam;
    float *ordenadao;
    float *distC;
    float *a, *b; // se foda

    printf("Tamanho dos vetores:\n");
    scanf("%i", &tam);

    leVet(a, tam);
    leVet(b, tam);
    distChebyshev(a, b, tam, &distC);
    printf("%.2f\n\n", distC);

    copiaVet(ordenadao, a, tam);
    boaSort(a, tam, ordenadao);
    printaVet(ordenadao, tam);

    return 0;
}
