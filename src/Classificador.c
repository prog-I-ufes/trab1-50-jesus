#include <stdio.h>
#include <string.h>
#include <math.h> // round()
#include "../include/Distancias.h"
#include "../include/ManipulaVetores.h"
#include "../include/Classificador.h"

void predict(int predicoes, char pathPredicoes[], int k, char tipoDist, float rMink, float **treinoMat, float **testeMat, int colTreino, int linTreino, int colTeste, int linTeste)
{
    int lenPathPredicoes = strlen(pathPredicoes);
    char pathAux[lenPathPredicoes];

    strcpy(pathAux, pathPredicoes);

    char num[12];

    // Gera o path de escrita
    sprintf(num, "%d", predicoes);
    strcat(pathPredicoes, "predicao_");
    strcat(pathPredicoes, num);
    strcat(pathPredicoes, ".txt");
    // printf("%s\n", pathPredicoes);

    FILE *f;
    f = fopen(pathPredicoes, "w");

    float dists[linTreino];
    float rotulosTreino[linTreino];
    float rotulosTreinoSORT[linTreino]; // PARA GERAR A MATRIZ DE CONFUSÃO
    float kPrimeirosRotulos[k];
    float kPrimeirasDists[k];
    float classificacaoOriginal[linTeste];
    float novaClassificacao[linTeste];
    float acertos = 0;

    for (int i = 0; i < linTeste; i++)
    {
        classificacaoOriginal[i] = testeMat[i][colTeste - 1];
    }

    for (int j = 0; j < linTreino; j++)
    {
        rotulosTreino[j] = treinoMat[j][colTreino - 1];
        rotulosTreinoSORT[j] = treinoMat[j][colTreino - 1];
    }

    boaSort(rotulosTreinoSORT, linTreino, rotulosTreinoSORT);
    int matrizConfusao[(int)rotulosTreinoSORT[linTreino - 1]][(int)rotulosTreinoSORT[linTreino - 1]];

    for (int j = 0; j < (int)rotulosTreinoSORT[linTreino - 1]; j++)
    {
        for (int n = 0; n < (int)rotulosTreinoSORT[linTreino - 1]; n++)
        {
            matrizConfusao[j][n] = 0; // Inicializa a matriz
        }
    }

    switch (tipoDist)
    {
    case 'M':
        for (int i = 0; i < linTeste; i++)
        {
            //printf("Minkowski: linha = %d\n", i + 1);
            //printf("------------ AMOSTRA DE TESTE ------------\n");
            //printaVet(testeMat[i], colTeste - 1);
            for (int j = 0; j < linTreino; j++)
            {
                //printf("---------- AMOSTRA DE TREINO DE NUMERO %d ----------\n", j + 1);
                //printaVet(treinoMat[j], colTreino - 1);
                distMinkowski(testeMat[i], treinoMat[j], colTeste - 1, rMink, &dists[j]);
            }
            //printf("\n");
            ////printf("----- VETOR DE DISTANCIAS -----\n");
            //printaVet(dists, linTreino);
            for (int j = 0; j < linTreino; j++)
            {
                rotulosTreino[j] = treinoMat[j][colTreino - 1];
            }
            //printf("\n\n----- VETOR DISTANCIAS DESORGANIZADO -----\n\n");
            //printaVet(dists, linTreino);
            //printf("\n\n------- ROTULOS DESORGANIZADOS -------\n\n");
            //printaVet(rotulosTreino, linTreino);
            douBoaSort(dists, rotulosTreino, linTreino);
            //printf("\n\n------- VETOR DISTANCIAS ORGANIZADO -------\n\n");
            //printaVet(dists, linTreino);
            //printf("\n\n------- ROTULOS ORGANIZADOS -------\n\n");
            //printaVet(rotulosTreino, linTreino);

            for (int j = 0; j < k; j++)
            {
                kPrimeirosRotulos[j] = rotulosTreino[j];
                kPrimeirasDists[j] = dists[j];
            }
            //printaVet(kPrimeirosRotulos, k);
            //printaVet(kPrimeirasDists, k);
            novaClassificacao[i] = maioriaVet(kPrimeirosRotulos, k); // AQUI VAI VIR A FUNÇÃO DE PEGAR A maioriaVet
            /*for(int j = 0; j < k; j++){
                fprintf(f, "|%.2f, %.2f|", kPrimeirosRotulos[j], kPrimeirasDists[j]);
            }
            fprintf(f, "nova class: %.2f\n", novaClassificacao[i]);*/
        }
        break;

    case 'E':
        for (int i = 0; i < linTeste; i++)
        {
            //printf("Euclidiana: linha = %d\n", i + 1);
            //printf("------------ AMOSTRA DE TESTE ----------\n");
            //printaVet(testeMat[i], colTeste - 1);
            for (int j = 0; j < linTreino; j++)
            {
                //printf("------------ AMOSTRA DE TREINO DE NUMERO %d ----------\n", j + 1);
                //printaVet(treinoMat[j], colTreino - 1);
                distEuclid(testeMat[i], treinoMat[j], colTeste - 1, &dists[j]);
            }
            //printf("\n");
            ////printf("----- VETOR DE DISTANCIAS -----\n");
            //printaVet(dists, linTreino);
            for (int j = 0; j < linTreino; j++)
            {
                rotulosTreino[j] = treinoMat[j][colTreino - 1];
            }
            //printf("\n\n------- VETOR DISTANCIAS DESORGANIZADO -------\n\n");
            //printaVet(dists, linTreino);
            //printf("\n\n------- Rotulos DESorganizados -------\n\n");
            //printaVet(rotulosTreino, linTreino);
            douBoaSort(dists, rotulosTreino, linTreino);
            //printf("\n\n------- VETOR DISTANCIAS ORGANIZADO -------\n\n");
            //printaVet(dists, linTreino);
            //printf("\n\n------- ROTULOS ORGANIZADOS ------\n\n");
            //printaVet(rotulosTreino, linTreino);

            for (int j = 0; j < k; j++)
            {
                kPrimeirosRotulos[j] = rotulosTreino[j];
                kPrimeirasDists[j] = dists[j];
            }
            //printaVet(kPrimeirosRotulos, k);
            //printaVet(kPrimeirasDists, k);
            novaClassificacao[i] = maioriaVet(kPrimeirosRotulos, k); // AQUI VAI VIR A FUNÇÃO DE PEGAR A maioriaVet
            /*for(int j = 0; j < k; j++){
                fprintf(f, "|%.2f, %.2f|", kPrimeirosRotulos[j], kPrimeirasDists[j]);
            }
            fprintf(f, "nova class: %.2f\n", novaClassificacao[i]);*/
        }
        break;

    case 'C':
        for (int i = 0; i < linTeste; i++)
        {
            //printf("Chebyshev: linha = %d\n", i + 1);
            //printf("------------- AMOSTRA DE TESTE -------------\n");
            //printaVet(testeMat[i], colTeste - 1);
            for (int j = 0; j < linTreino; j++)
            {
                //printf("----------- AMOSTRA DE TREINO DE NUMERO %d -----------\n", j + 1);
                //printaVet(treinoMat[j], colTreino - 1);
                distChebyshev(testeMat[i], treinoMat[j], colTeste - 1, &dists[j]);
            }
            //printf("\n");
            ////printf("----- VETOR DE DISTANCIAS ----\n");
            //printaVet(dists, linTreino);
            for (int j = 0; j < linTreino; j++)
            {
                rotulosTreino[j] = treinoMat[j][colTreino - 1];
            }
            //printf("\n\n----- VETOR DE DISTANCIAS DESORGANIZADO -----\n\n");
            //printaVet(dists, linTreino);
            //printf("\n\n------ ROTULOS DESORGANIZADOS ------\n\n");
            //printaVet(rotulosTreino, linTreino);

            douBoaSort(dists, rotulosTreino, linTreino);
            //printf("\n\n----- VETOR DISTANCIAS ORGANIZADO -----\n\n");
            //printaVet(dists, linTreino);
            //printf("\n\n-------- ROTULOS ORGANIZADOS --------\n\n"); // que
            //printaVet(rotulosTreino, linTreino);

            for (int j = 0; j < k; j++)
            {
                kPrimeirosRotulos[j] = rotulosTreino[j];
                kPrimeirasDists[j] = dists[j];
            }
            //printaVet(kPrimeirosRotulos, k);
            //printaVet(kPrimeirasDists, k);
            novaClassificacao[i] = maioriaVet(kPrimeirosRotulos, k); // AQUI VAI VIR A FUNÇÃO DE PEGAR A maioriaVet
            /*for(int j = 0; j < k; j++){
                fprintf(f, "|%.2f, %.2f|", kPrimeirosRotulos[j], kPrimeirasDists[j]);
            }
            fprintf(f, "nova class: %.2f\n", novaClassificacao[i]);*/
        }
        break;
    }

    for (int s = 0; s < linTeste; s++)
    {
        if (novaClassificacao[s] == classificacaoOriginal[s])
        {
            acertos++;
        }
        matrizConfusao[(int)(classificacaoOriginal[s] - 1)][(int)(novaClassificacao[s] - 1)]++;
    }

    // Cálculo e escrita da acurácia
    float acc = acuracia(acertos, linTeste);
    fprintf(f, "%.2f\n\n", acc);

    // Printa a matriz de confusão
    for (int j = 0; j < (int)rotulosTreinoSORT[linTreino - 1]; j++)
    {
        fprintf(f, "%d", matrizConfusao[j][0]);
        for (int n = 1; n < (int)rotulosTreinoSORT[linTreino - 1]; n++)
        {
            fprintf(f, " %d", matrizConfusao[j][n]);
        }
        fprintf(f, "\n");
    }

    fprintf(f, "\n");

    // Printa as novas classificações (o '-1' é por causa da bateria de testes e não está pronto já que eu sÓ pego o primeiro dos k)
    for (int s = 0; s < linTeste; s++)
    {
        fprintf(f, "%d\n", (int)(novaClassificacao[s] - 1));
    }

    // Volta com o path original
    printf("%s\n", pathPredicoes);
    strcpy(pathPredicoes, pathAux);
    fclose(f);
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
