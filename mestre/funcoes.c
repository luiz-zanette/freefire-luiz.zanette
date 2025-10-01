#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DEFINIÇÕES DAS VARIÁVEIS GLOBAIS
#define MAX_ITENS 10
Item mochila[MAX_ITENS];
int total_itens = 0;
const int capacidade_mochila = MAX_ITENS;
int organizada_por_nome = 0;
int organizada_por_tipo = 0;
int organizada_por_quantidade = 0;
int organizada_por_prioridade = 0;

// DEFINIÇÕES DAS FUNÇÕES
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void resetarFlagsOrganizacao() {
    organizada_por_nome = 0;
    organizada_por_tipo = 0;
    organizada_por_quantidade = 0;
    organizada_por_prioridade = 0;
}

void statusMochila() {
    printf("\nTotal de itens na mochila: %d/%d\n", total_itens, capacidade_mochila);
    if (total_itens == 0) {
        printf("Mochila vazia.\n");
        return;
    }
    printf("-----------------------------------------------------------\n");
    printf("Nome do Item      | Tipo do Item      | Quantidade | Prioridade\n");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < total_itens; i++) {
        printf("%-18s| %-18s| %-11d| %d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade, mochila[i].prioridade);
    }
    printf("-----------------------------------------------------------\n");
}

void adicionarComponente() {
    if (total_itens >= capacidade_mochila) {
        printf("Mochila cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    printf("\nAdicionar novo componente:\n");
    printf("Digite o nome do componente: ");
    fgets(mochila[total_itens].nome, sizeof(mochila[total_itens].nome), stdin);
    mochila[total_itens].nome[strcspn(mochila[total_itens].nome, "\n")] = 0;

    printf("Digite o tipo do componente (Estrutural, Funcional, Eletrônico): ");
    fgets(mochila[total_itens].tipo, sizeof(mochila[total_itens].tipo), stdin);
    mochila[total_itens].tipo[strcspn(mochila[total_itens].tipo, "\n")] = 0;

    printf("Digite a quantidade do componente: ");
    scanf("%d", &mochila[total_itens].quantidade);
    limparBufferEntrada();

    printf("Digite a prioridade do componente (1-5): ");
    scanf("%d", &mochila[total_itens].prioridade);
    limparBufferEntrada();

    total_itens++;
    printf("Item adicionado com sucesso!\n");
    statusMochila();
    // Reseta as flags de organização após a alteração da lista
    resetarFlagsOrganizacao();
}

void removerComponente() {
    char nome[30];
    int encontrado = 0;

    if (total_itens == 0) {
        printf("Mochila vazia! Não há componentes para remover.\n");
        return;
    }

    printf("Digite o nome do componente a ser removido: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;

    for (int i = 0; i < total_itens; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            encontrado = 1;
            for (int j = i; j < total_itens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            total_itens--;
            printf("Item removido com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Item não encontrado na mochila.\n");
    } else {
        statusMochila();
        // Reseta as flags de organização após a alteração da lista
        resetarFlagsOrganizacao();
    }
}

void listarComponentes() {
    if (total_itens == 0) {
        printf("Mochila vazia! Não há componentes para listar.\n");
        return;
    }
    statusMochila();
}

void organizarMochila() {
    if (total_itens == 0) {
        printf("Mochila vazia! Não há componentes para organizar.\n");
        return;
    }

    int escolha;
    printf("\nOrganizar mochila por:\n");
    printf("1. Nome\n");
    printf("2. Tipo\n");
    printf("3. Quantidade\n");
    printf("4. Prioridade\n");
    printf("Escolha uma opção: ");
    scanf("%d", &escolha);
    limparBufferEntrada();

    // Resetar todas as flags de organização antes de organizar
    resetarFlagsOrganizacao();

    switch (escolha) {
        case 1:
            // Ordenação por nome (Bubble Sort)
            for (int i = 0; i < total_itens - 1; i++) {
                for (int j = 0; j < total_itens - i - 1; j++) {
                    if (strcmp(mochila[j].nome, mochila[j + 1].nome) > 0) {
                        Item temp = mochila[j];
                        mochila[j] = mochila[j + 1];
                        mochila[j + 1] = temp;
                    }
                }
            }
            organizada_por_nome = 1;
            printf("Mochila organizada por nome.\n");
            break;
        case 2:
            // Ordenação por tipo (Bubble Sort)
            for (int i = 0; i < total_itens - 1; i++) {
                for (int j = 0; j < total_itens - i - 1; j++) {
                    if (strcmp(mochila[j].tipo, mochila[j + 1].tipo) > 0) {
                        Item temp = mochila[j];
                        mochila[j] = mochila[j + 1];
                        mochila[j + 1] = temp;
                    }
                }
            }
            organizada_por_tipo = 1;
            printf("Mochila organizada por tipo.\n");
            break;
        case 3:
            // Ordenação por quantidade (Bubble Sort)
            for (int i = 0; i < total_itens - 1; i++) {
                for (int j = 0; j < total_itens - i - 1; j++) {
                    if (mochila[j].quantidade > mochila[j + 1].quantidade) {
                        Item temp = mochila[j];
                        mochila[j] = mochila[j + 1];
                        mochila[j + 1] = temp;
                    }
                }
            }
            organizada_por_quantidade = 1;
            printf("Mochila organizada por quantidade.\n");
            break;
        case 4:
            // Ordenação por prioridade (Bubble Sort)
            for (int i = 0; i < total_itens - 1; i++) {
                for (int j = 0; j < total_itens - i - 1; j++) {
                    if (mochila[j].prioridade > mochila[j + 1].prioridade) {
                        Item temp = mochila[j];
                        mochila[j] = mochila[j + 1];
                        mochila[j + 1] = temp;
                    }
                }
            }
            organizada_por_prioridade = 1;
            printf("Mochila organizada por prioridade.\n");
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
            return;
    }
    statusMochila();
}

void buscaBinariaComponente() {
    char nome[30];
    int encontrado = 0;

    if (total_itens == 0) {
        printf("Mochila vazia! Não há componentes para buscar.\n");
        return;
    }

    if (!organizada_por_nome) {
        printf("A mochila deve ser organizada por nome antes de realizar a busca binária.\n");
        return;
    }

    printf("Digite o nome do componente a ser buscado: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;

    int esquerda = 0;
    int direita = total_itens - 1;

    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        int cmp = strcmp(mochila[meio].nome, nome);

        if (cmp == 0) {
            encontrado = 1;
            printf("\nItem encontrado:\n");
            printf("Nome: %s\n", mochila[meio].nome);
            printf("Tipo: %s\n", mochila[meio].tipo);
            printf("Quantidade: %d\n", mochila[meio].quantidade);
            printf("Prioridade: %d\n", mochila[meio].prioridade);
            break;
        } else if (cmp < 0) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }

    if (!encontrado) {
        printf("Item '%s' não encontrado na mochila.\n", nome);
    }
}