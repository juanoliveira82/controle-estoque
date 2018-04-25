#include "controleEstoque.h"

/* checklist:
  -Inserir
  -Inicializar -> ok
  -Reinicializar
  -Busca -> ok
  -Excluir
  -Imprimir -> ok
  -Ordenação: Idade, Quantidade e País.

  Segunda implementação em:
  Lista Simplesmente Encadeada */

void inicializarLista(LISTA *l) {
    l->inicio=NULL;
}
void exibirLista(LISTA *l) {
    PONT end = l->inicio;
    printf("\n Lista: \" ");
    while(end!=NULL) {
        printf(" Nome: %s \n Preço Venda: %f \n Idade: %d \n Pais: %s \n Código: %d \n Quantidade em estoque: %d \n",end->reg.nome,end->reg.precoVenda,end->reg.idade,end->reg.pais,end->reg.codProduto,end->reg.quantidadeEstoque);
        end = end->prox;
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



