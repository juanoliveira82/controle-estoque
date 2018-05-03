// Autor: Juan Carlos Cardoso de Oliveira.
#ifndef CONTROLE_ESTOQUE_HEADER
#define CONTROLE_ESTOQUE_HEADER
#define SIZE 50
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

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
    REGISTRO A[SIZE];
    int disponivel;
    int inicio;
}LISTA;

// Declaração das funções.
void inicializarEstoque(LISTA *l);
int  obterDisponivel(LISTA *l);
void inserirProdutoOrdenadoIdade(LISTA *l, REGISTRO reg);
void inserirProdutoOrdenadoPais(LISTA *l, REGISTRO reg);
void inserirProdutoOrdenadoQuantidade(LISTA *l, REGISTRO reg);
void excluirProduto(LISTA *l, int produtoExcluir);
void exibirEstoque(LISTA *l);
void buscarProduto(LISTA *l, int codigoBuscar);
void reinicializarEstoque(LISTA *l);
void menuInicial();
void menuCompleto();
void limparTela();

#endif // CONTROLE_ESTOQUE_HEADER
