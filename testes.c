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
    FILE *f;
    FILE *tr;
    FILE *ts;      // variável para config.txt
    int *k, qtdP; // parâmetros do cálculo de distância (coeficiente k e coeficiente r para Minkowski) e quantidade de parâmetros
    float a[tam], b[tam], soma[tam], distE, distM, distS, *r;
    char *prEnd, *segEnd, *endR, *d; // endereço do teste, treino e parâmetros do cálculo de distância (de Euclides, Minkowski ou Chebyshev)
    float **treino;
    float **teste;
    int linhaTr;
    int colunaTr;
    int linhaTe;
    int colunaTe;
    
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
    if (f == NULL)
    {
        printf("Não foi possivel abrir o config.txt\n"); // libera vetores e fecha programa caso n consiga abrir config
        free(k);
        free(r);
        free(d);
        free(prEnd);
        free(segEnd);
        free(endR);
        exit(1);
    }
    //le config e abre treino e teste
    qtdP = leConfig(f, &prEnd, &segEnd, &endR, &k, &d, &r);
    tr = fopen(prEnd, "r");
    ts = fopen(segEnd, "r");

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
    // passa conteudo do treino e teste para matriz
    treino = leTre(tr, &linhaTr, &colunaTr);
    teste = leTre(ts, &linhaTe, &colunaTe);
    printf("\n\n");

    printf("----Treino(%s)-----\n\n", prEnd); // printa treino
    for(int j = 0; j < (linhaTr-1); j++){
        for(int m = 0; m < colunaTr+1; m++){
            printf("%.2f ", treino[j][m]);
        }
        printf("\n");
    }

    printf("\n\n");
    printf("----Teste(%s)----\n\n", segEnd); // printa teste
    for(int j = 0; j < (linhaTe-1); j++){
        for(int m = 0; m < colunaTe+1; m++){
            printf("%.2f ", teste[j][m]);
        }
        printf("\n");
    }
    // libera vetores antes de fechar o programa
    free(k);
    free(r);
    free(d);
    free(prEnd);
    free(segEnd);
    free(endR);
    for(int j = 0; j < linhaTr; j++){
        free(treino[j]);
    }
    free(treino);
    for(int j = 0; j < linhaTe; j++){
        free(teste[j]);
    }
    free(teste);
    fclose(f);
    fclose(tr);
    fclose(ts);

    return 0;
}
