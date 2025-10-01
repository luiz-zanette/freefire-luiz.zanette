// ===================   NÍVEL NOVATO =================== 
// Neste nível, o jogador precisa coletar rapidamente recursos essenciais (armas, munições, kits médicos e ferramentas) e organizar esses itens dentro da mochila virtual, garantindo eficiência nas primeiras decisões estratégicas do jogo.

// REQUISITOS:
// 1. O jogador deve ser capaz de cadastrar itens à mochila virtual até o limite de 10 intens.
// 2. Deve ser capaz de remover intens da mochila virtual pelo nome.
// 3. Deve ser capaz de listar todos os itens atualmente na mochila virtual.
// 4. Deve ser capaz de buscar um item específico na mochila virtual pelo nome.

#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main () {
    int escolha;

    do {
        printf("=== Menu do Jogo Free Fire - Nível Novato ===\n");
        printf("1. Adicionar item à mochila\n");
        printf("2. Remover item da mochila\n");
        printf("3. Listar itens da mochila\n");
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
            case 0:
                printf("Saindo do jogo. Até a próxima!\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (escolha != 0);
    return 0;
}