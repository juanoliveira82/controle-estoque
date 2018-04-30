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
}REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux* prox;
}ELEMENTO;

typedef ELEMENTO* PONT;

// Declaração da lista de registros.
typedef struct {
    PONT inicio;
}LISTA;

void inicializarLista(LISTA *l);
void exibirLista(LISTA *l);
void buscarProduto(LISTA *l, int codigoBuscar);
void inserirElementoOrdenadoIdade(LISTA *l, REGISTRO elemento);
void inserirElementoOrdenadoQuantidade(LISTA *l, REGISTRO elemento);
void inserirElementoOrdenadoPais(LISTA *l, REGISTRO elemento);
void excluirElementoLista(LISTA *l, int elementoExcluir);
void reinicializarLista(LISTA *l);
void limparTela();

#endif // CONTROLE_ESTOQUE_HEADER
