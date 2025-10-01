#ifndef funcoes_h
#define funcoes_h

// DECLARAÇÃO da STRUCT
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
    int prioridade; // Adicionado o campo de prioridade
} Item;

// DECLARAÇÕES DAS VARIÁVEIS GLOBAIS
#define MAX_ITENS 10
extern Item mochila[MAX_ITENS];
extern int total_itens;
extern const int capacidade_mochila;
extern int organizada_por_nome;
extern int organizada_por_tipo;
extern int organizada_por_quantidade;
extern int organizada_por_prioridade;

// DECLARAÇÕES DAS FUNÇÕES
void limparBufferEntrada();
void resetarFlagsOrganizacao();
void statusMochila();
void adicionarComponente();
void removerComponente();
void listarComponentes();
void organizarMochila();
void buscaBinariaComponente();

#endif