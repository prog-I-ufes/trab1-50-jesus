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
#include "include/Classificador.h"
#include "include/LerArquivos.h"

int main()
{
    // Exemplo de uso de funções dos módulos
    int tam;
    printf("Tamanho dos vetores:\n");
    scanf("%i", &tam);
    // printf("r: "); // para distância minkowskiana
    // scanf("%i", &r);
    FILE *f; // config.txt
    int *k, qtdP; // parametros do calculo de distância (coeficiente k e coeficiente r para minkowisky) e quantidade de parametros
    float a[tam], b[tam], soma[tam], distE, distM, distS, *r;
    char prEnd[50], segEnd[50], endR[50], *d; // endereço do teste, treino e parametros do calculo de distância (Euclidiana, cosseno ou minkowisky)

    k = (int *)malloc(2*sizeof(int));       // parametros k 
    d = (char *)malloc(2*sizeof(char));     // parametros de distância
    r = (float *)malloc(2*sizeof(float));       // parametro r para distancia minkowiski

    leVet(a, tam);
    leVet(b, tam);

    f = fopen("src/iris/config.txt", "r"); // config.txt
    qtdP = leConfig(f, prEnd, segEnd, endR, &k, &d, &r);

    somaVet(a, b, tam, soma);
    printf("Vetor da soma:\n");
    printaVet(soma, tam);

    distEuclid(a, b, tam, &distE);
    printf("Distancia euclidiana: %.2f\n\n---Config---\n\n", distE);
    printf("%s\n%s\n%s\n", prEnd, segEnd, endR);
    for(int i = 0; i < qtdP-1; i++){
        printf("| %d || %c || %f |\n", k[i], d[i], r[i]);
    }
    // distSemCoss(a, b, tam, &distS);
    // printf("Distancia por semelhança de cosseno: %.2f\n", distS);
    // distMinkowsky(a, b, tam, r, &distM);
    // printf("Distancia minkowskiana: %.2f", distM);
    // resultadoFinal();
    free(k);
    free(r);
    free(d);
    fclose(f);
    return 0;
}
