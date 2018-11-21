// Módulo com funções para manipulação de arquivos

#ifndef __MANIPULAARQUIVOS_H
#define __MANIPULAARQUIVOS_H

int leConfig(FILE *f, char **pathTreino, char **pathTeste, char **pathEscrita, int *k[], char *d[], float *r[]);
float** leDados(FILE *p, int *ln, int *cl);

#endif
