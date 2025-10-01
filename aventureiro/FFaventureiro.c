// ===================   NÍVEL AVENTUREIRO =================== 
// Neste nível, o jogador consultarr aos itens que possui na sua mochila virtual.
// Ele poderá adicionar, remover, listar e buscar itens na mochil

// REQUISITOS:
// 1. Deve ser capaz de buscar um item específico na mochila virtual pelo nome.

#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main () {
    int escolha;

    do {
        printf("\n=== Menu do Jogo Free Fire - Nível Aventureiro ===\n");
        printf("1. Adicionar item à mochila\n");
        printf("2. Remover item da mochila\n");
        printf("3. Listar itens da mochila\n");
        printf("4. Buscar item na mochila\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);
        limparBufferEntrada(); // Limpa o buffer de entrada

        switch (escolha) {
            case 1:
                adicionarItem();
                break;
            case 2:
                removerItem();
                break;
            case 3:
                listarItens();
                break;

            case 4:
                buscarItem();
                break;

            case 0:
                printf("Saindo do jogo. Até a próxima!\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (escolha != 0);
    return 0;
}