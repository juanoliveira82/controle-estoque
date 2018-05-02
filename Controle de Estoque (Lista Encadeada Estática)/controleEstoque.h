// Autor: Juan Carlos Cardoso de Oliveira.
#ifndef CONTROLE_ESTOQUE_HEADER
#define CONTROLE_ESTOQUE_HEADER
#define SIZE 50
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaração da estrutura dos registros.
typedef struct {
    int   prox;
    int   codProduto;
    char  nome[75];
    float precoVenda;
    int   idade;
    char  pais[50];
    int   quantidadeEstoque;
}REGISTRO;

// Declaração da lista de registros.
typedef struct {
    REGISTRO A[1];
    int disponivel;
    int inicio;
}LISTA;


void inicializarEstoque(LISTA *l);
void exibirEstoque(LISTA *l);
void buscarProduto(LISTA *l, int codigoBuscar);
void inserirProdutoOrdenadoIdade(LISTA *l, REGISTRO reg);
void excluirProduto(LISTA *l, int ch);
void reinicializarEstoque(LISTA *l);
void limparTela();

#endif // CONTROLE_ESTOQUE_HEADER
