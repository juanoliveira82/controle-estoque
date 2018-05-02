#include "controleEstoque.h"

void inicializarEstoque(LISTA *l) {
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

void exibirEstoque(LISTA *l) {
    int i;
    if(l->inicio==-1){
    // Verifica se existe algum elemento inserido na lista.
        printf("\n Nenhum elemento inserido na lista.\n");
        // Avisa ao usúario que a lista não possui nenhum elemento inserido.
    } else {

    for(i=l->inicio; i!=-1; i=l->A[i].prox) {

    // encontra
    printf("\n Código: %d \n Nome: %s \n Preço Venda: %f \n Idade: %d \n Pais: %s \n Quantidade em estoque: %d \n\n",l->A[i].codProduto,l->A[i].nome,l->A[i].precoVenda,l->A[i].idade,l->A[i].pais,l->A[i].quantidadeEstoque);

        }
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

void inserirProdutoOrdenadoIdade(LISTA *l, REGISTRO reg) {
    int ant = -1;
    int atual;
    int auxDisponivel = l->A[l->disponivel].prox;

    if(l->disponivel == -1) {
        printf("nao tem disponivel chefia");
    }

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
    printf("inserido");
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

void reinicializarEstoque(LISTA *l) {
    inicializarEstoque(l);
    // Inicia a lista novamente.
}

void limparTela() {
    #ifdef __linux__
    system("clear");
    // Detecta o sistema linux, e executa o comando de limpar o terminal.
    #elif defined WIN32
    system("cls");
    // Detecta o sistema windows, e executa o comando de limpar o console.
    #endif
}
