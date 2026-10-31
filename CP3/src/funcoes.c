#include <stdio.h>
#include "funcoes.h"

int cadastrarAtivo(Ativo carteira[], int total) {
    if (total >= MAX_ATIVOS) {
        printf("Limite de ativos atingido.\n");
        return total;
    }

    printf("\nNome: ");
    scanf(" %99[^\n]", carteira[total].nome);
    printf("Categoria: ");
    scanf(" %49[^\n]", carteira[total].categoria);
    printf("Quantidade: ");
    scanf("%lf", &carteira[total].quantidade);
    printf("Preco de compra: R$ ");
    scanf("%lf", &carteira[total].precoCompra);
    printf("Preco atual: R$ ");
    scanf("%lf", &carteira[total].precoAtual);

    printf("Ativo cadastrado!\n");
    return total + 1;
}

double rentabilidade(Ativo ativo) {
    if (ativo.precoCompra <= 0) return 0;
    return (ativo.precoAtual - ativo.precoCompra) / ativo.precoCompra * 100;
}

const char *classificarRisco(double percentual) {
    if (percentual < -10) return "Risco alto";
    if (percentual < 0) return "Risco moderado";
    if (percentual == 0) return "Risco baixo";
    return "Rentabilidade positiva";
}

void listarAtivos(Ativo carteira[], int total) {
    int i;

    if (total == 0) {
        printf("\nCarteira vazia.\n");
        return;
    }

    for (i = 0; i < total; i++) {
        double lucro = (carteira[i].precoAtual - carteira[i].precoCompra)
                       * carteira[i].quantidade;
        double percentual = rentabilidade(carteira[i]);

        printf("\n%s (%s)\n", carteira[i].nome, carteira[i].categoria);
        printf("Quantidade: %.2f | Compra: R$ %.2f | Atual: R$ %.2f\n",
               carteira[i].quantidade, carteira[i].precoCompra,
               carteira[i].precoAtual);
        printf("Rentabilidade: %.2f%% | ", percentual);
        if (lucro >= 0) printf("Lucro: R$ %.2f\n", lucro);
        else printf("Prejuizo: R$ %.2f\n", -lucro);
        printf("Classificacao: %s\n", classificarRisco(percentual));
    }
}

double valorTotal(Ativo carteira[], int total) {
    double soma = 0;
    int i;

    for (i = 0; i < total; i++)
        soma += carteira[i].quantidade * carteira[i].precoAtual;
    return soma;
}

double rentabilidadeGeral(Ativo carteira[], int total) {
    double investido = 0, atual = valorTotal(carteira, total);
    int i;

    for (i = 0; i < total; i++)
        investido += carteira[i].quantidade * carteira[i].precoCompra;

    if (investido == 0) return 0;
    return (atual - investido) / investido * 100;
}

/* Bubble Sort: organiza da maior para a menor rentabilidade. */
void ordenarCarteira(Ativo carteira[], int total) {
    int i, j;

    for (i = 0; i < total - 1; i++)
        for (j = 0; j < total - 1 - i; j++)
            if (rentabilidade(carteira[j]) < rentabilidade(carteira[j + 1])) {
                Ativo aux = carteira[j];
                carteira[j] = carteira[j + 1];
                carteira[j + 1] = aux;
            }

    printf("\nCarteira ordenada por rentabilidade!\n");
    listarAtivos(carteira, total);
}

void simulador(double valor) {
    double poupanca = valor, selic = valor, cdb = valor;
    int mes;

    for (mes = 0; mes < 12; mes++) {
        poupanca *= 1.005;
        selic *= 1.008;
        cdb *= 1.009;
    }

    printf("\nSimulacao para 12 meses (taxas ilustrativas):\n");
    printf("Poupanca: R$ %.2f\n", poupanca);
    printf("Tesouro Selic: R$ %.2f\n", selic);
    printf("CDB: R$ %.2f\n", cdb);
    printf("Taxas hipoteticas, apenas para fins educativos.\n");
}

void relatorio(Ativo carteira[], int total) {
    double investido = 0, atual = valorTotal(carteira, total);
    int i;

    for (i = 0; i < total; i++)
        investido += carteira[i].quantidade * carteira[i].precoCompra;

    ordenarCarteira(carteira, total);
    printf("\n--- RELATORIO FINAL ---\n");
    printf("Valor investido: R$ %.2f\n", investido);
    printf("Valor atual: R$ %.2f\n", atual);
    printf("Rentabilidade geral: %.2f%%\n", rentabilidadeGeral(carteira, total));
    printf("%s total: R$ %.2f\n", atual >= investido ? "Lucro" : "Prejuizo",
           atual >= investido ? atual - investido : investido - atual);
    printf("\n--- IMPACTO SOCIAL E INCLUSAO FINANCEIRA ---\n");
    printf("O simulador contribui para a educacao financeira, permitindo\n");
    printf("que os usuarios comparem diferentes modalidades de investimento,\n");
    printf("compreendam os rendimentos e conhecam alternativas acessiveis.\n");
    printf("Dessa forma, incentiva o conhecimento financeiro e auxilia na\n");
    printf("tomada de decisoes mais conscientes sobre o uso do dinheiro,\n");
    printf("estando alinhado ao ODS 8.10 da ONU, que busca ampliar o acesso\n");
    printf("a servicos financeiros. As taxas utilizadas sao ilustrativas\n");
    printf("e nao representam recomendacoes de investimento.\n");
}
