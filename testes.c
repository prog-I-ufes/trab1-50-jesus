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
    FILE *f;      // variável para config.txt
    int *k, qtdP; // parâmetros do cálculo de distância (coeficiente k e coeficiente r para Minkowski) e quantidade de parâmetros
    float a[tam], b[tam], soma[tam], distE, distM, distS, *r;
    char *prEnd, *segEnd, *endR, *d; // endereço do teste, treino e parâmetros do cálculo de distância (de Euclides, Minkowski ou Chebyshev)

    // parâmetros de distância
    prEnd = (char *) malloc(sizeof(char));
    segEnd = (char *) malloc(sizeof(char));
    endR = (char *) malloc(sizeof(char));
    k = (int *)malloc(2 * sizeof(int));
    d = (char *)malloc(2 * sizeof(char));
    r = (float *)malloc(2 * sizeof(float));

    leVet(a, tam);
    leVet(b, tam);

    f = fopen("config.txt", "r");
    qtdP = leConfig(f, &prEnd, &segEnd, &endR, &k, &d, &r);

    somaVet(a, b, tam, soma);
    printf("Vetor da soma:\n");
    printaVet(soma, tam);

    distEuclid(a, b, tam, &distE);
    printf("Distancia euclidiana: %.2f\n\n---Config---\n\n", distE);

    printf("%s\n%s\n%s\n", prEnd, segEnd, endR);
    for (int i = 0; i < qtdP - 1; i++)
    {
        printf("| %d || %c || %f |\n", k[i], d[i], r[i]);
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
