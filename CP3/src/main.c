#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include "modulo.h"

int main(void) {
    Ativo carteira[MAX_ATIVOS];
    char linha[100];
    int total = carregarCarteira(carteira);
    int opcao = -1;

    do {
        printf("\n=== CARTEIRA DE INVESTIMENTOS ===\n");
        printf("1. Cadastrar ativo\n");
        printf("2. Listar ativos\n");
        printf("3. Valor total da carteira\n");
        printf("4. Rentabilidade geral\n");
        printf("5. Ordenar por rentabilidade\n");
        printf("6. Simulador educativo\n");
        printf("7. Relatorio final\n");
        printf("0. Salvar e sair\n");
        printf("Opcao: ");

        if (fgets(linha, sizeof(linha), stdin) == NULL) {
            printf("Erro na leitura da opcao.\n");
            break;
        }

        opcao = atoi(linha);

        switch (opcao) {
            case 1:
                total = cadastrarAtivo(carteira, total);
                salvarCarteira(carteira, total);
                break;

            case 2:
                listarAtivos(carteira, total);
                break;

            case 3:
                printf("Valor total: R$ %.2f\n", valorTotal(carteira, total));
                break;

            case 4:
                exibirRentabilidade(carteira, total);
                break;

            case 5:
                ordenarCarteira(carteira, total);
                salvarCarteira(carteira, total);
                break;

            case 6:
                simulador(carteira, total);
                break;

            case 7:
                relatorio(carteira, total);
                break;

            case 0:
                salvarCarteira(carteira, total);
                printf("Dados salvos. Ate logo!\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}
