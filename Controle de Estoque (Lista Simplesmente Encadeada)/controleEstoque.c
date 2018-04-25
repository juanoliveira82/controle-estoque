#include "controleEstoque.h"

/* checklist:
  -Inserir
  -Inicializar -> ok
  -Reinicializar
  -Busca
  -Excluir
  -Imprimir -> ok
  -Ordenação: Idade, Quantidade e País.

  Primeira implementação em:
  Lista Encadeada Estática */

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


