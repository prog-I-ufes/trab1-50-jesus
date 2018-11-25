#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    // Para acessar posições corretamente
    linTreino -= 1, colTreino -= 1, linTeste -= 1, colTeste -= 1;

    int lenPathPredicoes = strlen(pathPredicoes);
    char pathAux[lenPathPredicoes];

    strcpy(pathAux, pathPredicoes);

    char num[12]; // Vetor capaz de acomodar o maior int

    // Gera o path de escrita
    sprintf(num, "%d", predicoes);
    strcat(pathPredicoes, "predicao_");
    strcat(pathPredicoes, num);
    strcat(pathPredicoes, ".txt");

    FILE *fpredicoes;
    fpredicoes = fopen(pathPredicoes, "w");

    // Para gerar a matriz de confusão
    float dists[linTreino];
    float rotulosTreino[linTreino];
    float kPrimeirosRotulos[k];
    float classificacaoOriginal[linTeste];
    float novaClassificacao[linTeste];
    float acertos = 0;

    for (i = 0; i < linTeste; i++)
    {
        classificacaoOriginal[i] = testeMat[i][colTeste];
    }

    for (j = 0; j < linTreino; j++)
    {
        rotulosTreino[j] = treinoMat[j][colTreino];
    }

    // Número de rótulos para gerar matriz de confusão
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
                distMinkowski(testeMat[i], treinoMat[j], colTeste, rMink, &dists[j]);
            }

            for (j = 0; j < linTreino; j++)
            {
                rotulosTreino[j] = treinoMat[j][colTreino];
            }

            douBoaSort(dists, rotulosTreino, linTreino);

            for (j = 0; j < k; j++)
            {
                kPrimeirosRotulos[j] = rotulosTreino[j];
            }

            novaClassificacao[i] = maioriaVet(kPrimeirosRotulos, k);

            //Exibe os k menores rotulos junto com a nova classificação de uma linha do teste

            /*fprintf(fpredicoes, "<Linha %d> - ", i+1);
            for(int m = 0; m < k; m++){
                fprintf(fpredicoes, " |%.2f| ", kPrimeirosRotulos[m] - 1);
            }
            fprintf(fpredicoes," - <Novo rotulo = %.2f>\n", novaClassificacao[i] - 1);*/

        }
        break;

    case 'E':
        for (i = 0; i < linTeste; i++)
        {
            for (j = 0; j < linTreino; j++)
            {
                distEuclid(testeMat[i], treinoMat[j], colTeste, &dists[j]);
            }

            for (j = 0; j < linTreino; j++)
            {
                rotulosTreino[j] = treinoMat[j][colTreino];
            }

            douBoaSort(dists, rotulosTreino, linTreino);

            for (j = 0; j < k; j++)
            {
                kPrimeirosRotulos[j] = rotulosTreino[j];
            }

            novaClassificacao[i] = maioriaVet(kPrimeirosRotulos, k);

            //Exibe os k menores rotulos junto com a nova classificação de uma linha do teste

            /*fprintf(fpredicoes, "<Linha %d> - ", i+1);
            for(int m = 0; m < k; m++){
                fprintf(fpredicoes, " |%.2f| ", kPrimeirosRotulos[m] - 1);
            }
            fprintf(fpredicoes," - <Novo rotulo = %.2f>\n", novaClassificacao[i] - 1);*/
        }
        break;

    case 'C':
        for (i = 0; i < linTeste; i++)
        {
            for (j = 0; j < linTreino; j++)
            {
                distChebyshev(testeMat[i], treinoMat[j], colTeste, &dists[j]);
            }

            for (j = 0; j < linTreino; j++)
            {
                rotulosTreino[j] = treinoMat[j][colTreino];
            }

            douBoaSort(dists, rotulosTreino, linTreino);

            for (j = 0; j < k; j++)
            {
                kPrimeirosRotulos[j] = rotulosTreino[j];
            }

            novaClassificacao[i] = maioriaVet(kPrimeirosRotulos, k);

            //Exibe os k menores rotulos junto com a nova classificação de uma linha do teste

            /*fprintf(fpredicoes, "<Linha %d> - ", i+1);
            for(int m = 0; m < k; m++){
                fprintf(fpredicoes, " |%.2f| ", kPrimeirosRotulos[m] - 1);
            }
            fprintf(fpredicoes," - <Novo rotulo = %.2f>\n", novaClassificacao[i] - 1);*/
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
    printf("O arquivo (%s) foi escrito\n", pathPredicoes);
    strcpy(pathPredicoes, pathAux);

    fclose(fpredicoes);
}

float acuracia(float acertos, float total)
{
    float acc;

    acc = acertos / total;

    return acc;
}
