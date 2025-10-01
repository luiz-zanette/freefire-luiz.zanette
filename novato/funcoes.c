#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DEFINIÇÕES DAS VARIÁVEIS GLOBAIS
#define MAX_ITENS 10
Item mochila[MAX_ITENS];
int total_itens = 0;
const int capacidade_mochila = MAX_ITENS;

// DEFINIÇÕES DAS FUNÇÕES
void limparBufferEntrada () {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void statusMochila () {
     printf("Total de itens na mochila: %d/%d\n\n", total_itens, capacidade_mochila);
     printf("Nome do Item | Tipo do Item | Quantidade\n");
     printf("--------------------------------------------------\n");
     for (int i = 0; i < total_itens; i++) {
         printf("%s | %s | %d", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
     }
}

void adicionarItem () {
    int escolha;
    do {
        if (total_itens >= capacidade_mochila) {
            printf("Mochila cheia! Não é possível adicionar mais itens.\n");
            break;
        }
        
        printf("Digite o nome do item: ");
        fgets(mochila[total_itens].nome, sizeof(mochila[total_itens].nome), stdin);
        mochila[total_itens].nome[strcspn(mochila[total_itens].nome, "\n")] = 0; // Remove o newline do final
        
        printf("Digite o tipo do item (arma, munição, kit médico, ferramenta): ");
        fgets(mochila[total_itens].tipo, sizeof(mochila[total_itens].tipo), stdin);
        mochila[total_itens].tipo[strcspn(mochila[total_itens].tipo, "\n")] = 0; // Remove o newline do final
        
        printf("Digite a quantidade do item: ");
        scanf("%d", &mochila[total_itens].quantidade);
        
        total_itens++;

        statusMochila();

        printf("Pressione 1 para continuar adicionando itens ou 0 para voltar ao menu principal: ");
        scanf("%d", &escolha);
        limparBufferEntrada(); // Limpa o buffer de entrada
        
    } while (escolha == 1);
}

void removerItem () {
    char nome[30];
    int encontrado = 0;

    if (total_itens == 0) {
        printf("Mochila vazia! Não há itens para remover.\n");
        return;
    }

    printf("Digite o nome do item a ser removido: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0; // Remove o newline do final

    for (int i = 0; i < total_itens; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            encontrado = 1;
            for (int j = i; j < total_itens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            total_itens--;
            printf("Item '%s' removido com sucesso!\n", nome);
            break;
        }
    }

    if (!encontrado) {
        printf("Item '%s' não encontrado na mochila.\n", nome);
    } else {
        statusMochila();
    }
}

void listarItens () {
    if (total_itens == 0) {
        printf("Mochila vazia! Não há itens para listar.\n");
        return;
    }
    statusMochila();
}