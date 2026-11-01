#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modulo.h"

/* Copia um campo separado por ponto e virgula.
   Retorna a posicao seguinte ou -1 quando o campo nao existe. */
static int extrairCampo(char linha[], int inicio, char destino[], int limite) {
    int i = inicio;
    int tamanho = 0;

    while (linha[i] != '\0' && linha[i] != '\n' && linha[i] != ';') {
        if (tamanho < limite - 1) {
            destino[tamanho] = linha[i];
            tamanho++;
        }
        i++;
    }

    destino[tamanho] = '\0';

    if (tamanho == 0) {
        return -1;
    }

    if (linha[i] == ';') {
        return i + 1;
    }

    return i;
}

/* Carrega os ativos armazenados no arquivo de texto. */
int carregarCarteira(Ativo carteira[]) {
    FILE *arquivo = fopen("data/carteira.txt", "r");
    char linha[300];
    char campo[100];
    int total = 0;
    int posicao;

    if (arquivo == NULL) {
        return 0;
    }

    while (total < MAX_ATIVOS && fgets(linha, sizeof(linha), arquivo) != NULL) {
        posicao = extrairCampo(linha, 0, carteira[total].nome,
                               sizeof(carteira[total].nome));
        if (posicao < 0) {
            continue;
        }

        posicao = extrairCampo(linha, posicao, carteira[total].categoria,
                               sizeof(carteira[total].categoria));
        if (posicao < 0) {
            continue;
        }

        posicao = extrairCampo(linha, posicao, campo, sizeof(campo));
        if (posicao < 0) {
            continue;
        }
        carteira[total].quantidade = atof(campo);

        posicao = extrairCampo(linha, posicao, campo, sizeof(campo));
        if (posicao < 0) {
            continue;
        }
        carteira[total].precoCompra = atof(campo);

        posicao = extrairCampo(linha, posicao, campo, sizeof(campo));
        if (posicao < 0) {
            continue;
        }
        carteira[total].precoAtual = atof(campo);

        total++;
    }

    fclose(arquivo);
    return total;
}

/* Salva todos os ativos no arquivo de texto. */
void salvarCarteira(Ativo carteira[], int total) {
    FILE *arquivo = fopen("data/carteira.txt", "w");
    int i;

    if (arquivo == NULL) {
        printf("Erro ao salvar arquivo.\n");
        return;
    }

    for (i = 0; i < total; i++) {
        fprintf(arquivo, "%s;%s;%.2f;%.2f;%.2f\n",
                carteira[i].nome,
                carteira[i].categoria,
                carteira[i].quantidade,
                carteira[i].precoCompra,
                carteira[i].precoAtual);
    }

    fclose(arquivo);
}
