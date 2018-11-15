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

void predict(int prNum, char preDir[], int k, char tipoDist, float rMink, float **treinoMat, float **testeMat, int colTreino, int linTreino, int colTeste, int linTeste)
{
    char teste[strlen(preDir)];

    strcpy(teste, preDir);

    char num[12];

    // gera o path de escrita
    sprintf(num, "%d", prNum);
    strcat(preDir, "predicao_");
    strcat(preDir, num);
    strcat(preDir, ".txt");
    //printf("%s\n", preDir);

    FILE *f;
    f = fopen(preDir, "w");

    float dists[linTreino];
    float rotulosTreino[linTreino];
    float rotulosTreinoSORT[linTreino]; //PRA GERAR A MATRIZ DE CONFUSÃO
    float kPrimeirosRot[k];
    float kPrimeirosDist[k];
    float classificassaoOriginal[linTeste];
    float novaClassificacao[linTeste];
    float acertos = 0;

    for (int i = 0; i < linTeste; i++)
    {
        classificassaoOriginal[i] = testeMat[i][colTeste - 1];
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
            matrizConfusao[j][n] = 0; //inicializa a matriz com tudo 0
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
                kPrimeirosRot[j] = rotulosTreino[j];
                kPrimeirosDist[j] = dists[j];
            }
            //printaVet(kPrimeirosRot, k);
            //printaVet(kPrimeirosDist, k);
            novaClassificacao[i] = maioria(kPrimeirosRot, kPrimeirosDist, k); // AQUI VAI VIR A FUNÇÃO DE PEGAR A MAIORIA
            for(int j = 0; j < k; j++){
                fprintf(f, "|%.2f, %.2f|", kPrimeirosRot[j], kPrimeirosDist[j]);
            }
            fprintf(f, "nova class: %.2f\n", novaClassificacao[i]);
            // PARA DE GRITAR SEU ANIMAL
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
                kPrimeirosRot[j] = rotulosTreino[j];
                kPrimeirosDist[j] = dists[j];
            }
            //printaVet(kPrimeirosRot, k);
            //printaVet(kPrimeirosDist, k);
            novaClassificacao[i] = maioria(kPrimeirosRot, kPrimeirosDist, k);// AQUI VAI VIR A FUNÇÃO DE PEGAR A MAIORIA
            for(int j = 0; j < k; j++){
                fprintf(f, "|%.2f, %.2f|", kPrimeirosRot[j], kPrimeirosDist[j]);
            }
            fprintf(f, "nova class: %.2f\n", novaClassificacao[i]);
            
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
                kPrimeirosRot[j] = rotulosTreino[j];
                kPrimeirosDist[j] = dists[j];
            }
            //printaVet(kPrimeirosRot, k);
            //printaVet(kPrimeirosDist, k);
            novaClassificacao[i] = maioria(kPrimeirosRot, kPrimeirosDist, k); // AQUI VAI VIR A FUNÇÃO DE PEGAR A MAIORIA
            for(int j = 0; j < k; j++){
                fprintf(f, "|%.2f, %.2f|", kPrimeirosRot[j], kPrimeirosDist[j]);
            }
            fprintf(f, "nova class: %.2f\n", novaClassificacao[i]);
        }
        break;
    }

    for (int s = 0; s < linTeste; s++)
    {
        if (novaClassificacao[s] == classificassaoOriginal[s])
        {
            acertos++;
        }
        matrizConfusao[(int)(classificassaoOriginal[s] - 1)][(int)(novaClassificacao[s] - 1)]++; // Matriz de confusão
    }

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

    // Printa as novas classificações (o '-1' é por causa da bateria de testes e não está pronto já que eu so pego o primeiro dos k)
    for (int s = 0; s < linTeste; s++)
    {
        fprintf(f, "%d\n", (int)(novaClassificacao[s] - 1));
    }
    
    // Faz o path original voltar
    printf("%s\n", preDir);
    strcpy(preDir, teste);
    fclose(f);
}

int main()
{
    FILE *f;
    FILE *tr;
    FILE *ts; // Variável para config.txt

    int *k, qtdP; // Parâmetros do cálculo de distância (coeficiente k e coeficiente r para Minkowski) e quantidade de parâmetros
    float /*a[tam], b[tam], soma[tam], ordenadao[tam], distE, distM, distC,*/ *r;
    char *pathTreino, *pathTeste, *endR, *d; // Endereço do teste, treino e parâmetros do cálculo de distância (de Euclides, Minkowski ou Chebyshev)

    float **treino;
    float **teste;
    int linhaTreino, colunaTreino, linhaTeste, colunaTeste;

    // Parâmetros de distância
    pathTreino = (char *)malloc(sizeof(char));
    pathTeste = (char *)malloc(sizeof(char));
    endR = (char *)malloc(sizeof(char));
    k = (int *)malloc(2 * sizeof(int));
    d = (char *)malloc(2 * sizeof(char));
    r = (float *)malloc(2 * sizeof(float));

    // Ex: abrindo config.txt (e printando resultados posteriormente)
    // Libera vetores e fecha programa caso nao consiga abrir config
    f = fopen("config.txt", "r");
    if (f == NULL)
    {
        printf("Nao foi possivel abrir o config.txt\n");
        free(k);
        free(r);
        free(d);
        free(pathTreino);
        free(pathTeste);
        free(endR);
        exit(1);
    }

    // Lê config desejada e abre treino e teste
    qtdP = leConfig(f, &pathTreino, &pathTeste, &endR, &k, &d, &r);
    tr = fopen(pathTreino, "r");
    ts = fopen(pathTeste, "r");

    // distEuclid(a, b, tam, &distE);
    // printf("Distancia euclidiana: %.2f\n\n--- Config ---\n\n", distE);

    printf("%s\n%s\n%s\n", pathTreino, pathTeste, endR);
    for (int i = 0; i < qtdP - 1; i++)
    {
        printf("| %d || %c || %.2f |\n", k[i], d[i], r[i]);
    }

    // Passa o conteúdo do treino e do teste para matriz
    treino = leDados(tr, &linhaTreino, &colunaTreino);
    teste = leDados(ts, &linhaTeste, &colunaTeste);
    printf("\n\n");

    // Printa treino
    printf("---- Treino (%s) -----\n\n", pathTreino);
    for (int j = 0; j < (linhaTreino - 1); j++)
    {
        for (int m = 0; m < colunaTreino + 1; m++)
        {
            printf("%.2f ", treino[j][m]);
        }
        printf("\n");
    }

    // Printa teste
    printf("\n\n");
    printf("---- Teste (%s) ----\n\n", pathTeste);
    for (int j = 0; j < (linhaTeste - 1); j++)
    {
        for (int m = 0; m < colunaTeste + 1; m++)
        {
            printf("%.2f ", teste[j][m]);
        }
        printf("\n");
    }

    printf("\n\n\n------ TESTE DE PREDICT ------\n\n\n");
    for (int i = 0; i < qtdP - 1; i++)
    {
        predict(i + 1, endR, k[i], d[i], r[i], treino, teste, colunaTreino + 1, linhaTreino - 1, colunaTeste + 1, linhaTeste - 1);
    }

    // Libera vetores antes de fechar o programa
    free(k);
    free(r);
    free(d);
    free(pathTreino);
    free(pathTeste);
    free(endR);

    for (int j = 0; j < linhaTreino; j++)
    {
        free(treino[j]);
    }
    free(treino);

    for (int j = 0; j < linhaTeste; j++)
    {
        free(teste[j]);
    }
    free(teste);
    fclose(tr);
    fclose(ts);
    fclose(f);

    return 0;
}
