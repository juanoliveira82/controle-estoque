#ifndef HEADER_H
#define HEADER_H
#define SIZE 100

// Declaração da estrutura dos registros.
typedef struct{
    char nome[SIZE];
    float precoVenda;
    int idade;
    char pais[SIZE];
    int codProduto
    int quantidadeEstoque;
}REGISTRO;

// Declaração da lista de registros.
typedef struct{
    REGISTRO A[SIZE];
    int numElemento;
}LISTA;

#endif
