#include "controleEstoque.h"

/* checklist:
  -Inserir
  -Inicializar -> ok
  -Reinicializar -> ok
  -Busca -> ok
  -Excluir
  -Imprimir -> ok
  -Ordenação: Idade, Quantidade e País.

  Segunda implementação em:
  Lista Simplesmente Encadeada (Dinâmica) */

void inicializarLista(LISTA *l) {
    l->inicio=NULL;
    // Coloca o inicio como NULL pois ainda não existem elementos, consequentemente, não há um inicio da lista.
}

void exibirLista(LISTA *l) {
    PONT end = l->inicio;
    // Cria-se um ponteiro auxiliar que aponta para o inicio da lista.
    printf("\n Lista: \" ");
    while(end!=NULL) {
    // Enquanto esse ponteiro não for NULL, ainda existem elementos, então ele percorre a lista e mostra seus elementos.
        printf(" Nome: %s \n Preço Venda: %f \n Idade: %d \n Pais: %s \n Código: %d \n Quantidade em estoque: %d \n",end->reg.nome,end->reg.precoVenda,end->reg.idade,end->reg.pais,end->reg.codProduto,end->reg.quantidadeEstoque);
        end = end->prox;
        // Ele sempre passa para o próximo elemento, a partir do inicio.
    }
}

PONT buscaSequencial(LISTA *l, int codigoBuscar) {
    PONT pos = l->inicio;
    while(pos!=NULL){
        if(pos->reg.codProduto == codigoBuscar) return pos;
        pos = pos->prox;
    }
    return NULL;
}

PONT buscaSequencialOrdenada(LISTA *l, int codigoBuscar) {
    PONT pos = l->inicio;
    while(pos!=NULL && pos->reg.codProduto<codigoBuscar) pos->prox;
    if(pos!=NULL && pos->reg.codProduto == codigoBuscar) return pos;
    return NULL;
}

// Função para inserir registros na lista, ordenando-os por idade.
void inserirElementoOrdenadoIdade(LISTA *l, REGISTRO elemento) {

    PONT anterior = NULL, atual = NULL, novoElemento = NULL;

    novoElemento = (PONT) malloc(sizeof(ELEMENTO));
    // Aloca memória para inserção do novo registro.

    novoElemento->reg = elemento;
    // O novo elemento é o elemento passado por parametro.

    novoElemento->prox = NULL;
    // O próximo do novo elemento é nulo, pois ainda não se sabe qual é.

    atual = l->inicio;
    // O atual aponta para o começo da lista.

    while(atual!=NULL && atual->reg.idade<elemento.idade) {
    /* Esse while serve para ir passando os elementos, até que o atual seja o mesmo que está sendo inserido,
    Ex.: ant=11 atual=12 novo=13
    Passando os comandos abaixo, tornam-se:
    Ex.: ant=12 atual=13 novo=13
    Agora o atual é o mesmo que o novo, assim, ele sai do while e continua o processo de inserção. */
        anterior = atual;
        atual = atual->prox;
    }

    if(anterior==NULL) {
    // Se o anterior for nulo, ainda estamos no primeiro elemento. (Início da lista).
        l->inicio = novoElemento;
        // O início é o elemento que está sendo inserido, pois ele é o primeiro a ser inserido.
    } else {
    // Caso o anterior não seja nulo, já existem elementos inseridos.
        anterior->prox = novoElemento;
        // Então o próximo registro do elemento anterior é o novo elemento que está sendo inserido.
    }
}

int excluirElementoLista(LISTA *l, int elementoExcluir) {
    PONT anterior = NULL, atual = l->inicio;

    if(anterior==NULL) {
        l->inicio =
    }
}

void reinicializarLista(LISTA *l) {
    PONT end = l->inicio;
    while(end!=NULL){
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    l->inicio = NULL;
}

