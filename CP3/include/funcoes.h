#ifndef FUNCOES_H
#define FUNCOES_H

#include "modulo.h"

int cadastrarAtivo(Ativo carteira[], int total);
void listarAtivos(Ativo carteira[], int total);
double valorTotal(Ativo carteira[], int total);
double rentabilidadeGeral(Ativo carteira[], int total);
double rentabilidade(Ativo ativo);
void classificarRisco(double percentual);
void ordenarCarteira(Ativo carteira[], int total);
void exibirRentabilidade(Ativo carteira[], int total);
void simulador(double valor);
void relatorio(Ativo carteira[], int total);

#endif
