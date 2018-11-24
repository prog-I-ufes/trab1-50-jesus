// Módulo com funções mais gerais do classificador e a função do classificador em si

#ifndef __CLASSIFICADOR_H
#define __CLASSIFICADOR_H

void freeAll(int *k, char *d, float *r, char *pathTreino, char *pathTeste, char *pathEscrita);
void predict(int predicoes, char pathPredicoes[], int k, char tipoDist, float rMink, float **treinoMat,float **testeMat, int colTreino, int linTreino, int colTeste, int linTeste);
float acuracia(float acertos, float total);

#endif
