#ifndef ENCADEADA_ESTATICA_HEADER
#define ENCADEADA_ESTATICA_HEADER
#define SIZE 50

// Declaração da estrutura dos registros.
typedef struct {
    int chave;
    int prox;
    char nome[SIZE];
    float precoVenda;
    int idade;
    char pais[SIZE];
    int codProduto;
    int quantidadeEstoque;
}REGISTRO;

// Declaração da lista de registros.
typedef struct {
    REGISTRO A[SIZE];
    int numElementos;
    // Contador do número de elementos na lista.
    int disponivel;
    int inicio;
}LISTA;

void inicializarLista(LISTA *l);
int tamanhoLista(LISTA *l);
void exibirLista(LISTA *l);
int buscaSequencialOrdenada(LISTA *l; int ch);
int inserirElementoOrdenado(LISTA *l, REGISTRO reg);
void excluirElemento(LISTA *l, int ch);
void reiniciarlista(LISTA *l);

#endif // ENCADEADA_ESTATICA_HEADER
