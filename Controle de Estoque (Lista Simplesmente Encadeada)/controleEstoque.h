#ifndef CONTROLE_ESTOQUE_HEADER
#define CONTROLE_ESTOQUE_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaração da estrutura dos registros.
typedef struct {
    char nome[75];
    float precoVenda;
    int idade;
    char pais[50];
    int codProduto;
    int quantidadeEstoque;
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

#endif // CONTROLE_ESTOQUE_HEADER
