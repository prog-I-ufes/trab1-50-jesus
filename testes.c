/*
                  É ＳÓ ＰＲＡ ＴＥＳＴＡＲ
        Atílio Antônio Dadalto e Tiago da Cruz Santos
                       Data: 11/2018                         */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "include/ManipulaVetores.h"
#include "include/Distancias.h"
#include "include/Classificador.h"
#include "include/ManipulaArquivos.h"

// Exemplo de uso de funções dos módulos
int main()
{
    int tam;

    printf("Tamanho dos vetores:\n");
    scanf("%i", &tam);

    FILE *f;      // Variável para config.txt
    int *k, qtdP; // Parâmetros do cálculo de distância (coeficiente k e coeficiente r para Minkowski) e quantidade de parâmetros
    float a[tam], b[tam], soma[tam], ordenadao[tam], SotC[tam], distE, distM, distC, maiorzao, *r;
    char *prEnd, *segEnd, *endR, *d; // Endereço do teste, treino e parâmetros do cálculo de distância (de Euclides, Minkowski ou Chebyshev)

    // Parâmetros de distância
    prEnd = (char *)malloc(sizeof(char));
    segEnd = (char *)malloc(sizeof(char));
    endR = (char *)malloc(sizeof(char));
    k = (int *)malloc(2 * sizeof(int));
    d = (char *)malloc(2 * sizeof(char));
    r = (float *)malloc(2 * sizeof(float));

    // leVet(SotC, tam);
    // maiorzao = maiorVet(SotC, tam);
    // printf("\n%f\n", maiorzao);

    // mas o ordenadão é um vetor
    // e um ponteiro
    // e um vetor
    //AAAAAAAAAAAAAAAAAAAA*&*&*&*&*&*&&*&**&*&&*&*
    leVet(ordenadao, tam);
    boaSort(a, tam, ordenadao);

    // Ex: abrindo um dos config.txt (e printando seus componentes posteriormente)
    f = fopen("data/vowels/config.txt", "r");
    if (f == NULL)
    {
        printf("Nao foi possivel abrir o config.txt\n");
        free(k);
        free(r);
        free(d);
        free(prEnd);
        free(segEnd);
        free(endR);
        exit(1);
    }
    qtdP = leConfig(f, &prEnd, &segEnd, &endR, &k, &d, &r);

    /*
    somaVet(a, b, tam, soma);
    printf("Vetor da soma:\n");
    printaVet(soma, tam);

    distEuclid(a, b, tam, &distE);
    printf("Distancia euclidiana: %.2f\n\n---Config---\n\n", distE);
    */

    printf("%s\n%s\n%s\n", prEnd, segEnd, endR);
    for (int i = 0; i < qtdP - 1; i++)
    {
        printf("| %d || %c || %.2f |\n", k[i], d[i], r[i]);
    }

    free(k);
    free(r);
    free(d);
    free(prEnd);
    free(segEnd);
    free(endR);
    fclose(f);

    return 0;
}
