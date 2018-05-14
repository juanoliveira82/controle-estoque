// Autor: Juan Carlos Cardoso de Oliveira.
#ifndef CONTROLE_ESTOQUE_HEADER
#define CONTROLE_ESTOQUE_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaração da estrutura dos registros.
typedef struct {
    int   codProduto;
    char  nome[75];
    float precoVenda;
    int   idade;
    char  pais[50];
    int   quantidadeEstoque;
} REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux* prox;
} ELEMENTO;

typedef ELEMENTO* PONT;

// Declaração da lista de registros.
typedef struct {
    PONT inicio;
} LISTA;

// Declaração das funções.
void inicializarEstoque(LISTA *l);
void inserirProdutoOrdenadoIdade(LISTA *l, REGISTRO elemento);
void inserirProdutoOrdenadoQuantidade(LISTA *l, REGISTRO elemento);
void inserirProdutoOrdenadoPais(LISTA *l, REGISTRO elemento);
void excluirProduto(LISTA *l, int elementoExcluir);
void exibirEstoque(LISTA *l);
void buscarProduto(LISTA *l, int codigoBuscar);
void reinicializarEstoque(LISTA *l);
void menuInicial();
void menuCompleto();
void limparTela();

#endif // CONTROLE_ESTOQUE_HEADER
