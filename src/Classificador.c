#include <stdio.h>
#include <string.h>
#include <math.h> // round()
#include "../include/Distancias.h"
#include "../include/ManipulaVetores.h"
#include "../include/ManipulaMatrizes.h"
#include "../include/Classificador.h"

void predict(int predicoes, char pathPredicoes[], int k, char tipoDist, float rMink, float **treinoMat, float **testeMat, int colTreino, int linTreino, int colTeste, int linTeste)
{
    int i, j;

    int lenPathPredicoes = strlen(pathPredicoes);
    char pathAux[lenPathPredicoes];

    strcpy(pathAux, pathPredicoes);

    char num[12];

    // Gera o path de escrita
    sprintf(num, "%d", predicoes);
    strcat(pathPredicoes, "predicao_"); //? é resultado_ ou predicao_ ???
    strcat(pathPredicoes, num);
    strcat(pathPredicoes, ".txt");
    // printf("%s\n", pathPredicoes);

    FILE *fpredicoes;
    fpredicoes = fopen(pathPredicoes, "w");

    float dists[linTreino];
    float rotulosTreino[linTreino];
    float rotulosTreinoSORT[linTreino]; // PARA GERAR A MATRIZ DE CONFUSÃO
    float kPrimeirosRotulos[k];
    float kPrimeirasDists[k];
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
        rotulosTreinoSORT[j] = treinoMat[j][colTreino - 1];
    }

    boaSort(rotulosTreinoSORT, linTreino, rotulosTreinoSORT);

    // Número (em inteiro) de rótulos para gerar matriz de confusão
    int tamConfusao = (int)rotulosTreinoSORT[linTreino - 1];

    int matrizConfusao[tamConfusao][tamConfusao];
    inicializaMat(tamConfusao, tamConfusao, matrizConfusao);

    switch (tipoDist)
    {
    case 'M':
        for (i = 0; i < linTeste; i++)
        {
            // printf("Minkowskiana: linha = %d\n", i + 1);
            // printf("------------ AMOSTRA DE TESTE ------------\n");
            // printaVet(testeMat[i], colTeste - 1);
            for (j = 0; j < linTreino; j++)
            {
                // printf("---------- AMOSTRA DE TREINO DE NUMERO %d ----------\n", j + 1);
                // printaVet(treinoMat[j], colTreino - 1);
                distMinkowski(testeMat[i], treinoMat[j], colTeste - 1, rMink, &dists[j]);
            }
            // printf("\n");
            // // printf("----- VETOR DE DISTANCIAS -----\n");
            // printaVet(dists, linTreino);
            for (j = 0; j < linTreino; j++)
            {
                rotulosTreino[j] = treinoMat[j][colTreino - 1];
            }
            // printf("\n\n----- VETOR DISTANCIAS DESORGANIZADO -----\n\n");
            // printaVet(dists, linTreino);
            // printf("\n\n------- ROTULOS DESORGANIZADOS -------\n\n");
            // printaVet(rotulosTreino, linTreino);
            douBoaSort(dists, rotulosTreino, linTreino);
            // printf("\n\n------- VETOR DISTANCIAS ORGANIZADO -------\n\n");
            // printaVet(dists, linTreino);
            // printf("\n\n-------- ROTULOS ORGANIZADOS --------\n\n");
            // printaVet(rotulosTreino, linTreino);

            for (j = 0; j < k; j++)
            {
                kPrimeirosRotulos[j] = rotulosTreino[j];
                kPrimeirasDists[j] = dists[j];
            }
            // printaVet(kPrimeirosRotulos, k);
            // printaVet(kPrimeirasDists, k);
            novaClassificacao[i] = maioriaVet(kPrimeirosRotulos, k);
            /* for(j = 0; j < k; j++){
                fprintf(fpredicoes, "|%.2f, %.2f|", kPrimeirosRotulos[j], kPrimeirasDists[j]);
            }
            fprintf(fpredicoes, "nova class: %.2f\n", novaClassificacao[i]); */
        }
        break;

    case 'E':
        for (i = 0; i < linTeste; i++)
        {
            // printf("Euclidiana: linha = %d\n", i + 1);
            // printf("------------ AMOSTRA DE TESTE ----------\n");
            // printaVet(testeMat[i], colTeste - 1);
            for (j = 0; j < linTreino; j++)
            {
                // printf("------------ AMOSTRA DE TREINO DE NUMERO %d ----------\n", j + 1);
                // printaVet(treinoMat[j], colTreino - 1);
                distEuclid(testeMat[i], treinoMat[j], colTeste - 1, &dists[j]);
            }
            // printf("\n");
            // // printf("----- VETOR DE DISTANCIAS -----\n");
            // printaVet(dists, linTreino);
            for (j = 0; j < linTreino; j++)
            {
                rotulosTreino[j] = treinoMat[j][colTreino - 1];
            }
            // printf("\n\n------- VETOR DISTANCIAS DESORGANIZADO -------\n\n");
            // printaVet(dists, linTreino);
            // printf("\n\n------- RÓTULOS DESORGANIZADOS -------\n\n");
            // printaVet(rotulosTreino, linTreino);
            douBoaSort(dists, rotulosTreino, linTreino);
            // printf("\n\n------- VETOR DISTANCIAS ORGANIZADO -------\n\n");
            // printaVet(dists, linTreino);
            // printf("\n\n-------- ROTULOS ORGANIZADOS --------\n\n");
            // printaVet(rotulosTreino, linTreino);

            for (j = 0; j < k; j++)
            {
                kPrimeirosRotulos[j] = rotulosTreino[j];
                kPrimeirasDists[j] = dists[j];
            }
            // printaVet(kPrimeirosRotulos, k);
            // printaVet(kPrimeirasDists, k);
            novaClassificacao[i] = maioriaVet(kPrimeirosRotulos, k);
            /* for(j = 0; j < k; j++){
                fprintf(fpredicoes, "|%.2f, %.2f|", kPrimeirosRotulos[j], kPrimeirasDists[j]);
            }
            fprintf(fpredicoes, "nova class: %.2f\n", novaClassificacao[i]); */
        }
        break;

    case 'C':
        for (i = 0; i < linTeste; i++)
        {
            // printf("Chebyshev: linha = %d\n", i + 1);
            // printf("------------- AMOSTRA DE TESTE -------------\n");
            // printaVet(testeMat[i], colTeste - 1);
            for (j = 0; j < linTreino; j++)
            {
                // printf("----------- AMOSTRA DE TREINO DE NUMERO %d -----------\n", j + 1);
                // printaVet(treinoMat[j], colTreino - 1);
                distChebyshev(testeMat[i], treinoMat[j], colTeste - 1, &dists[j]);
            }
            // printf("\n");
            // // printf("----- VETOR DE DISTANCIAS ----\n");
            // printaVet(dists, linTreino);
            for (j = 0; j < linTreino; j++)
            {
                rotulosTreino[j] = treinoMat[j][colTreino - 1];
            }
            // printf("\n\n----- VETOR DE DISTANCIAS DESORGANIZADO -----\n\n");
            // printaVet(dists, linTreino);
            // printf("\n\n------ ROTULOS DESORGANIZADOS ------\n\n");
            // printaVet(rotulosTreino, linTreino);

            douBoaSort(dists, rotulosTreino, linTreino);
            // printf("\n\n------- VETOR DISTANCIAS ORGANIZADO -------\n\n");
            // printaVet(dists, linTreino);
            // printf("\n\n-------- ROTULOS ORGANIZADOS --------\n\n");
            // printaVet(rotulosTreino, linTreino);

            for (j = 0; j < k; j++)
            {
                kPrimeirosRotulos[j] = rotulosTreino[j];
                kPrimeirasDists[j] = dists[j];
            }
            // printaVet(kPrimeirosRotulos, k);
            // printaVet(kPrimeirasDists, k);
            novaClassificacao[i] = maioriaVet(kPrimeirosRotulos, k);
            /* for(j = 0; j < k; j++){
                fprintf(fpredicoes, "|%.2f, %.2f|", kPrimeirosRotulos[j], kPrimeirasDists[j]);
            }
            fprintf(fpredicoes, "nova class: %.2f\n", novaClassificacao[i]); */
        }
        break;
    }

    /*Compara a nova classificação com a classificação original
      e altera a matriz de confusão*/
    for (i = 0; i < linTeste; i++)
    {
        if (novaClassificacao[i] == classificacaoOriginal[i])
        {
            acertos++;
        }

        // Registrando a nova comparação na matriz de confusão
        matrizConfusao[(int)(classificacaoOriginal[i] - 1)][(int)(novaClassificacao[i] - 1)]++;
    }

    // Cálculo e escrita da acurácia
    float acc = acuracia(acertos, linTeste);
    fprintf(fpredicoes, "%.2f\n\n", acc);

    fprintaMat(fpredicoes, tamConfusao, tamConfusao, matrizConfusao);

    // Printa as novas classificações (o '-1' é por causa da bateria de testes e não está pronto já que eu só pego o primeiro dos k)
    for (int s = 0; s < linTeste; s++)
    {
        fprintf(fpredicoes, "%d\n", (int)(novaClassificacao[s] - 1));
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

void round2(float *n)
{
    *n = (round(*n * 100)) / 100;
}
