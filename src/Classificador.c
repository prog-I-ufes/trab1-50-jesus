#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../include/Distancias.h"
#include "../include/ManipulaVetores.h"
#include "../include/ManipulaMatrizes.h"
#include "../include/Classificador.h"

// Recebe todos os vetores e que serão liberados
void freeAll(int *k, char *d, float *r, char *pathTreino, char *pathTeste, char *pathEscrita)
{
    free(k);
    free(d);
    free(r);
    free(pathTreino);
    free(pathTeste);
    free(pathEscrita);
}

void predict(int predicoes, char pathPredicoes[], int k, char tipoDist, float rMink, float **treinoMat, float **testeMat, int colTreino, int linTreino, int colTeste, int linTeste)
{
    int i, j;

    int lenPathPredicoes = strlen(pathPredicoes);
    char pathAux[lenPathPredicoes];

    strcpy(pathAux, pathPredicoes);

    char num[12]; //? pera q

    // Gera o path de escrita
    sprintf(num, "%d", predicoes);
    strcat(pathPredicoes, "predicao_"); //? é resultados_ ou predicao_ ???
    strcat(pathPredicoes, num);
    strcat(pathPredicoes, ".txt");

    FILE *fpredicoes;
    fpredicoes = fopen(pathPredicoes, "w");

    float dists[linTreino];
    float rotulosTreino[linTreino];
    // Para gerar a matriz de confusão
    float kPrimeirosRotulos[k];
    //float kPrimeirasDists[k];
    float classificacaoOriginal[linTeste];
    float novaClassificacao[linTeste];
    float acertos = 0;

    for (i = 0; i < linTeste; i++)
    {
        classificacaoOriginal[i] = testeMat[i][colTeste - 1];
    }

    for (j = 0; j < linTreino; j++)
    {
        rotulosTreino[j] = treinoMat[j][colTreino - 1];
    }

    // Número (em inteiro) de rótulos para gerar matriz de confusão
    int nRotulos = maiorVet(rotulosTreino, linTreino);

    int matrizConfusao[nRotulos][nRotulos];
    inicializaMat(nRotulos, nRotulos, matrizConfusao);

    switch (tipoDist)
    {
    case 'M':
        for (i = 0; i < linTeste; i++)
        {
            for (j = 0; j < linTreino; j++)
            {
                distMinkowski(testeMat[i], treinoMat[j], colTeste - 1, rMink, &dists[j]);
            }

            for (j = 0; j < linTreino; j++)
            {
                rotulosTreino[j] = treinoMat[j][colTreino - 1];
            }
            douBoaSort(dists, rotulosTreino, linTreino);

            for (j = 0; j < k; j++)
            {
                kPrimeirosRotulos[j] = rotulosTreino[j];
                //kPrimeirasDists[j] = dists[j];
            }
            //printf("||%d||\n", i+1);
            novaClassificacao[i] = maioriaVet(kPrimeirosRotulos, k);

        }
        break;

    case 'E':
        for (i = 0; i < linTeste; i++)
        {
            for (j = 0; j < linTreino; j++)
            {
                distEuclid(testeMat[i], treinoMat[j], colTeste - 1, &dists[j]);
            }

            for (j = 0; j < linTreino; j++)
            {
                rotulosTreino[j] = treinoMat[j][colTreino - 1];
            }
            douBoaSort(dists, rotulosTreino, linTreino);

            for (j = 0; j < k; j++)
            {
                kPrimeirosRotulos[j] = rotulosTreino[j];
                //kPrimeirasDists[j] = dists[j];
            }
            //printf("||%d||\n", i+1);
            novaClassificacao[i] = maioriaVet(kPrimeirosRotulos, k);
        }
        break;

    case 'C':
        for (i = 0; i < linTeste; i++)
        {
            for (j = 0; j < linTreino; j++)
            {
                distChebyshev(testeMat[i], treinoMat[j], colTeste - 1, &dists[j]);
            }

            for (j = 0; j < linTreino; j++)
            {
                rotulosTreino[j] = treinoMat[j][colTreino - 1];
            }

            douBoaSort(dists, rotulosTreino, linTreino);

            for (j = 0; j < k; j++)
            {
                kPrimeirosRotulos[j] = rotulosTreino[j];
                //kPrimeirasDists[j] = dists[j];
            }
            //printf("||%d||\n", i+1);
            novaClassificacao[i] = maioriaVet(kPrimeirosRotulos, k);
        }
        break;
    }

    /* Compara a nova classificação com a classificação original
       e altera a matriz de confusão */
    for (i = 0; i < linTeste; i++)
    {
        if (novaClassificacao[i] == classificacaoOriginal[i])
        {
            acertos++;
        }

        // Registrando a nova comparação na matriz de confusão
        matrizConfusao[(int)(classificacaoOriginal[i] - 1)][(int)(novaClassificacao[i] - 1)]++;
    }

    // Escrita da acurácia, matriz de confusão e predições no arquivo de predições
    float acc = acuracia(acertos, linTeste);
    fprintf(fpredicoes, "%.2f\n\n", acc);

    fprintaMat(fpredicoes, nRotulos, nRotulos, matrizConfusao);

    for (i = 0; i < linTeste; i++)
    {
        fprintf(fpredicoes, "%d\n", (int)(novaClassificacao[i] - 1));
    }

    // Volta com o path original
    printf("%s\n", pathPredicoes);
    strcpy(pathPredicoes, pathAux);

    fclose(fpredicoes);
}

float acuracia(float acertos, float total)
{
    float acc;

    acc = acertos / total;

    return acc;
}

//?
void round2(float *n)
{
    *n = (round(*n * 100)) / 100;
}
