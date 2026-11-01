#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

/* Le textos sem utilizar scanf e sem operador de endereco. */
static void lerTexto(char destino[], int tamanho) {
    if (fgets(destino, tamanho, stdin) != NULL) {
        destino[strcspn(destino, "\n")] = '\0';
    } else {
        destino[0] = '\0';
    }
}

/* Le numeros a partir de uma linha de texto. */
static double lerNumero(void) {
    char linha[100];
    lerTexto(linha, sizeof(linha));
    return atof(linha);
}

/* Cadastra um novo ativo na carteira. */
int cadastrarAtivo(Ativo carteira[], int total) {
    if (total >= MAX_ATIVOS) {
        printf("\nLimite de ativos atingido!\n");
        return total;
    }

    printf("\n=== CADASTRAR ATIVO ===\n");

    printf("Nome do ativo: ");
    lerTexto(carteira[total].nome, sizeof(carteira[total].nome));

    printf("Categoria: ");
    lerTexto(carteira[total].categoria, sizeof(carteira[total].categoria));

    printf("Quantidade: ");
    carteira[total].quantidade = lerNumero();

    printf("Preco de compra: ");
    carteira[total].precoCompra = lerNumero();

    printf("Preco atual: ");
    carteira[total].precoAtual = lerNumero();

    printf("\nAtivo cadastrado com sucesso!\n");
    return total + 1;
}

/* Calcula a rentabilidade de um ativo. */
double rentabilidade(Ativo ativo) {
    if (ativo.precoCompra <= 0) {
        return 0;
    }

    return ((ativo.precoAtual - ativo.precoCompra)
            / ativo.precoCompra) * 100;
}

/* Exibe a classificacao conforme a rentabilidade. */
void classificarRisco(double percentual) {
    if (percentual < -10) {
        printf("Alto");
    } else if (percentual < 0) {
        printf("Moderado");
    } else if (percentual == 0) {
        printf("Baixo");
    } else {
        printf("Positivo");
    }
}

/* Lista todos os ativos cadastrados. */
void listarAtivos(Ativo carteira[], int total) {
    int i;

    if (total == 0) {
        printf("\nNenhum ativo cadastrado.\n");
        return;
    }

    printf("\n=== LISTA DE ATIVOS ===\n");

    for (i = 0; i < total; i++) {
        printf("\nAtivo: %s\n", carteira[i].nome);
        printf("Categoria: %s\n", carteira[i].categoria);
        printf("Quantidade: %.2f\n", carteira[i].quantidade);
        printf("Preco de compra: R$ %.2f\n", carteira[i].precoCompra);
        printf("Preco atual: R$ %.2f\n", carteira[i].precoAtual);
        printf("Rentabilidade: %.2f%%\n", rentabilidade(carteira[i]));
        printf("Classificacao: ");
        classificarRisco(rentabilidade(carteira[i]));
        printf("\n");
    }
}

/* Calcula o valor total atual da carteira. */
double valorTotal(Ativo carteira[], int total) {
    int i;
    double totalCarteira = 0;

    for (i = 0; i < total; i++) {
        totalCarteira += carteira[i].quantidade * carteira[i].precoAtual;
    }

    return totalCarteira;
}

/* Calcula a rentabilidade geral da carteira. */
double rentabilidadeGeral(Ativo carteira[], int total) {
    int i;
    double investido = 0;
    double atual = 0;

    for (i = 0; i < total; i++) {
        investido += carteira[i].quantidade * carteira[i].precoCompra;
        atual += carteira[i].quantidade * carteira[i].precoAtual;
    }

    if (investido <= 0) {
        return 0;
    }

    return ((atual - investido) / investido) * 100;
}

/* Ordena os ativos usando Bubble Sort, da maior para a menor rentabilidade. */
void ordenarCarteira(Ativo carteira[], int total) {
    int i, j;
    Ativo aux;

    for (i = 0; i < total - 1; i++) {
        for (j = 0; j < total - 1 - i; j++) {
            if (rentabilidade(carteira[j]) < rentabilidade(carteira[j + 1])) {
                aux = carteira[j];
                carteira[j] = carteira[j + 1];
                carteira[j + 1] = aux;
            }
        }
    }

    printf("\nCarteira ordenada por rentabilidade!\n");
    listarAtivos(carteira, total);
}

/* Exibe a rentabilidade individual e geral dos investimentos. */
void exibirRentabilidade(Ativo carteira[], int total) {
    int i;
    double investido = 0;
    double atual;
    double resultado;

    if (total == 0) {
        printf("\nCarteira vazia.\n");
        return;
    }

    ordenarCarteira(carteira, total);
    atual = valorTotal(carteira, total);

    printf("\n=== RENTABILIDADE DOS INVESTIMENTOS ===\n");

    for (i = 0; i < total; i++) {
        printf("\n%d. %s\n", i + 1, carteira[i].nome);
        printf("Categoria: %s\n", carteira[i].categoria);
        printf("Rentabilidade: %.2f%%\n", rentabilidade(carteira[i]));
        investido += carteira[i].quantidade * carteira[i].precoCompra;
    }

    resultado = atual - investido;

    printf("\nValor total da carteira: R$ %.2f\n", atual);
    printf("Rentabilidade geral: %.2f%%\n", rentabilidadeGeral(carteira, total));

    if (resultado >= 0) {
        printf("Lucro total: R$ %.2f\n", resultado);
    } else {
        printf("Prejuizo total: R$ %.2f\n", -resultado);
    }
}

/* Simulador educativo de investimentos para 12 meses. */
void simulador(double valor) {
    int i;
    double poupanca = valor;
    double selic = valor;
    double cdb = valor;

    for (i = 1; i <= 12; i++) {
        poupanca *= 1.005;
        selic *= 1.008;
        cdb *= 1.009;
    }

    printf("\n=== SIMULADOR EDUCATIVO ===\n");
    printf("Simulacao de R$ %.2f durante 12 meses:\n\n", valor);
    printf("POUPANCA      (0.50%%/mes): R$ %.2f (+R$ %.2f)\n",
           poupanca, poupanca - valor);
    printf("TESOURO SELIC (0.80%%/mes): R$ %.2f (+R$ %.2f)\n",
           selic, selic - valor);
    printf("CDB           (0.90%%/mes): R$ %.2f (+R$ %.2f)\n",
           cdb, cdb - valor);

    printf("\nAs taxas sao hipoteticas e possuem finalidade exclusivamente didatica.\n");
}

/* Gera o relatorio final da carteira. */
void relatorio(Ativo carteira[], int total) {
    int i;
    double investido = 0;
    double atual;
    double resultado;

    if (total == 0) {
        printf("\nNao existem ativos para gerar o relatorio.\n");
        return;
    }

    atual = valorTotal(carteira, total);

    for (i = 0; i < total; i++) {
        investido += carteira[i].quantidade * carteira[i].precoCompra;
    }

    resultado = atual - investido;

    printf("\n=== RELATORIO FINAL ===\n");
    printf("Quantidade de ativos: %d\n", total);
    printf("Valor investido: R$ %.2f\n", investido);
    printf("Valor atual: R$ %.2f\n", atual);
    printf("Rentabilidade geral: %.2f%%\n", rentabilidadeGeral(carteira, total));

    if (resultado >= 0) {
        printf("Resultado: Lucro de R$ %.2f\n", resultado);
    } else {
        printf("Resultado: Prejuizo de R$ %.2f\n", -resultado);
    }

    printf("\nODS - Objetivos de Desenvolvimento Sustentavel\n");
    printf("8.10 - Ampliar o acesso a servicos financeiros,\n");
    printf("bancarios e de seguros, promovendo a inclusao financeira\n");
    printf("e melhores oportunidades de crescimento economico.\n");
}
