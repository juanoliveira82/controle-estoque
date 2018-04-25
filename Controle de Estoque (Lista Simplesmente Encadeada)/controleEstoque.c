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
  Lista Simplesmente Encadeada */

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
    return NULL
}

PONT buscaSequencialOrdenada(LISTA *l, int codigoBuscar) {
    PONT pos = l->inicio;
    while(pos!=NULL && pos->reg.codProduto<codigoBuscar) pos->prox;
    if(pos!=NULL && pos->reg.codProduto == codigoBuscar) return pos;
    return NULL;
}



int excluirElementoLista(LISTA *l, int elementoExcluir) {
    PONT ant, i;
    i = busca
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

