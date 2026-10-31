#ifndef MODULO_H
#define MODULO_H

#define MAX_ATIVOS 100

typedef struct {
    char nome[100], categoria[50];
    double quantidade, precoCompra, precoAtual;
} Ativo;

int carregarCarteira(Ativo carteira[]);
void salvarCarteira(Ativo carteira[], int total);

#endif
