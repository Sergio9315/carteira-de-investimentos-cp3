#include <stdio.h>
#include "funcoes.h"
#include "modulo.h"

int main(void) {
    Ativo carteira[MAX_ATIVOS];
    int total = carregarCarteira(carteira), opcao;

    do {
        printf("\n=== CARTEIRA DE INVESTIMENTOS ===\n");
        printf("1. Cadastrar ativo\n2. Listar ativos\n");
        printf("3. Valor total da carteira\n4. Rentabilidade geral\n");
        printf("5. Ordenar por rentabilidade\n6. Simulador educativo\n");
        printf("7. Relatorio final\n0. Salvar e sair\nOpcao: ");
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida.\n");
            return 1;
        }

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
                printf("Rentabilidade geral: %.2f%%\n",
                       rentabilidadeGeral(carteira, total));
                break;
            case 5:
                ordenarCarteira(carteira, total);
                salvarCarteira(carteira, total);
                break;
            case 6:
                simulador(valorTotal(carteira, total));
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
