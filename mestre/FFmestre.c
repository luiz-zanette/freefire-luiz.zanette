// ===================   NÍVEL MESTRE =================== 
// Neste nível, o jogador consultará os itens que possui na sua mochila virtual.
// Ele poderá adicionar, remover, listar e buscar itens na mochila.

// REQUISITOS:
// 1. Deve ser capaz de buscar um item específico na mochila virtual pelo nome.
// 2. Deve ser capaz de organizar os itens na mochila por diferentes critérios (nome, tipo, quantidade, prioridade).
// 3. Iniciará o fim do jogo ao ativar a "Torre de Fuga".

#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main () {
    int escolha;

    do {
        printf("\n=== Plano de fuga Free Fire - Nível Mestre ===\n");
        printf("1. Adicionar componente\n");
        printf("2. Remover componente\n");
        printf("3. Listar componentes\n");
        printf("4. Organizar mochila (ordenar componentes)\n");
        printf("5. Busca binária por componente-chave (nome)\n");
        printf("0. Ativar Torre de Fuga (sair)\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);
        limparBufferEntrada(); // Limpa o buffer de entrada

        switch (escolha) {
            case 1:
                adicionarComponente();
                break;
            case 2:
                removerComponente();
                break;
            case 3:
                listarComponentes();
                break;

            case 4:
                organizarMochila();
                break;
            case 5:
                buscaBinariaComponente();
                break;

            case 0:
                printf("Rota de fuga feita com sucesso, saindo do jogo. Até a próxima!\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (escolha != 0);
    return 0;
}