#include "encadeadaEstatica.h"

void inicializarLista(LISTA *l) {
    int i;
    l->numElementos = 0;
    // O contador do número de elementos na lista está como 0 pois ainda não foi inserido nenhum elemento.
    l->inicio = -1;
    // O inicio está apontando para '-1', pois ainda não há nenhum elemento na lista, então não existe um início.
    l->disponivel = 0;
    // A posição '0' está disponivel para inserção.

    for(i=0; i<SIZE-1; i++) {
        l->A[i].prox = i+1;
    }
    l->A[SIZE-1].prox = -1;
}

int tamanhoLista(LISTA *l) {
    return(l->numElementos);
    // Retorna a variavel que armazena o numero de elementos na lista.
}

void exibirLista(LISTA *l) {
    int i;
    for(i=l->inicio; i!=-1; i=l->A[i].prox) {
        printf("[%d]=%d  ",i,l->A[i].chave);
    }
}

int buscaSequencialOrdenada(LISTA *l; int ch) {
    int i;

    if(l->numElementos==-1) return(-1);

    for(i=l->inicio; i>=0 && ch>l->A[i].chave; i=l->A[i].prox);

    if(i>=0 && ch==l->A[i].chave)   return(i);
    return(-1);
}

int inserirElementoOrdenado(LISTA *l, REGISTRO reg) {
    int ant = -1;
    int atual;
    int auxDisponivel = l->A[l->disponivel].prox;

    if(l->disponivel == -1) return(-1);

    l->A[l->disponivel].chave=reg.chave;
    l->numElementos=l->numElementos+1;

    atual = l->inicio;

    while(atual>=0 && l->A[atual].chave < reg.chave) {
        ant = atual;
        atual = l->A[atual].prox;
    }

    if(ant == -1) {
        l->A[l->disponivel].prox=1->inicio;
        l->inicio=1->disponivel;
    } else {
        l->A[ant].prox=l->disponivel;
        l->A[l->disponivel].prox=atual;
    }
    l->disponivel=auxDisponivel;
    return(1);
}

void excluirElemento(LISTA *l, int ch) {
    int ant = -1;
    int atual;

    if(l->disponivel == -1) {
        printf("\n Elemento nao esta na lista: LISTA VAZIA");
        return;
    }

    atual->l->inicio;
    while(atual>=0 && l->A[atual].chave<ch) {
        ant = atual;
        atual = l->A[atual].prox;
    }
    if(l->A[atual].chave == ch) {
        if(ant == -1) {
            l->inicio = l->A[atual].prox;
        } else {
            l->A[atual].prox = l->A[atual].prox;
        }
        l->A[atual].prox = l->disponivel;
        l->disponivel = atual;

        l->numElementos = l->numElementos-1;
        // Após a exclusão, diminui 1 no contador de elementos da lista.
    } else printf("\n O elemento nao esta na lista");
}

void reiniciarlista(LISTA *l) {
    inicializarLista(l);
}
