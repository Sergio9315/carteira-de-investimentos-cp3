#include <stdio.h>
#include "modulo.h"

int carregarCarteira(Ativo carteira[]) {
    FILE *arq = fopen("data/carteira.txt", "r");
    int total = 0;

    if (arq == NULL) return 0;

    while (total < MAX_ATIVOS &&
           fscanf(arq, " %99[^;];%49[^;];%lf;%lf;%lf",
                  carteira[total].nome, carteira[total].categoria,
                  &carteira[total].quantidade, &carteira[total].precoCompra,
                  &carteira[total].precoAtual) == 5) {
        total++;
    }

    fclose(arq);
    return total;
}

void salvarCarteira(Ativo carteira[], int total) {
    FILE *arq = fopen("data/carteira.txt", "w");
    int i;

    if (arq == NULL) {
        printf("Erro ao salvar arquivo.\n");
        return;
    }

    for (i = 0; i < total; i++)
        fprintf(arq, "%s;%s;%.2f;%.2f;%.2f\n", carteira[i].nome,
                carteira[i].categoria, carteira[i].quantidade,
                carteira[i].precoCompra, carteira[i].precoAtual);

    fclose(arq);
}
