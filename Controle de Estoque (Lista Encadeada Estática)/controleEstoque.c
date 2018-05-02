#include "controleEstoque.h"

void inicializarLista(LISTA *l) {
    int i;
    l->inicio = -1;
    // O inicio está apontando para '-1', pois ainda não há nenhum elemento na lista, então não existe um início.
    l->disponivel = 0;
    // A posição '0' está disponivel para inserção.

    for(i=0; i<SIZE-1; i++) {
        l->A[i].prox = i+1;
    }
    l->A[SIZE-1].prox = -1;
}

void exibirLista(LISTA *l) {
    int i;
    for(i=l->inicio; i!=-1; i=l->A[i].prox) {
        printf("[%d]=%d  ",i,l->A[i].codProduto);
    }
}

void buscarProduto(LISTA *l, int codigoBuscar) {
    int i;

    for(i=l->inicio; i>=0 && codigoBuscar>l->A[i].codProduto; i=l->A[i].prox);


    if(i>=0 && codigoBuscar==l->A[i].codProduto){
    // encontra
    printf("\n Código: %d \n Nome: %s \n Preço Venda: %f \n Idade: %d \n Pais: %s \n Quantidade em estoque: %d \n\n",l->A[i].codProduto,l->A[i].nome,l->A[i].precoVenda,l->A[i].idade,l->A[i].pais,l->A[i].quantidadeEstoque);

    } else {
    // n encontra
    printf("n achou n");
    }
}

int inserirElementoOrdenadoIdade(LISTA *l, REGISTRO reg) {
    int ant = -1;
    int atual;
    int auxDisponivel = l->A[l->disponivel].prox;

    if(l->disponivel == -1) return(-1);

    l->A[l->disponivel].idade=reg.idade;

    atual = l->inicio;

    while(atual>=0 && l->A[atual].idade < reg.idade) {
        ant = atual;
        atual = l->A[atual].prox;
    }

    if(ant == -1) {
        l->A[l->disponivel].prox=l->inicio;
        l->inicio=l->disponivel;
    } else {
        l->A[ant].prox=l->disponivel;
        l->A[l->disponivel].prox=atual;
    }
    l->disponivel=auxDisponivel;
    return(1);
}

void excluirProduto(LISTA *l, int ch) {
    int ant = -1;
    int atual;

    if(l->disponivel == -1) {
        printf("\n Elemento nao esta na lista: LISTA VAZIA");
        return;
    }

    atual=l->inicio;
    while(atual>=0 && l->A[atual].codProduto<ch) {
        ant = atual;
        atual = l->A[atual].prox;
    }
    if(l->A[atual].codProduto == ch) {
        if(ant == -1) {
            l->inicio = l->A[atual].prox;
        } else {
            l->A[atual].prox = l->A[atual].prox;
        }
        l->A[atual].prox = l->disponivel;
        l->disponivel = atual;

    } else printf("\n O elemento nao esta na lista");
}

void reiniciarLista(LISTA *l) {
    inicializarLista(l);
}

void limparTela() {
    system("clear");
    // Limpa a tela para melhor exibição do programa.
}
