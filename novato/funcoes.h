#ifndef funcoes_h
#define funcoes_h

// DECLARAÇÃO da STRUCT
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// DECLARAÇÕES DAS VARIÁVEIS GLOBAIS
#define MAX_ITENS 10
extern Item mochila[MAX_ITENS];
extern int total_itens;
extern const int capacidade_mochila;

// DECLARAÇÕES DAS FUNÇÕES
void limparBufferEntrada ();
void statusMochila ();
void adicionarItem ();
void removerItem ();
void listarItens ();

#endif