// Autor: Juan Carlos Cardoso de Oliveira.
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

int obterDisponivel(LISTA *l) {
    int aux = l->disponivel;
    // Variavel auxiliar aponta para o elemento disponível.
    if(l->disponivel != -1) {
        l->disponivel = l->A[aux].prox;
    }
    return aux;
    // Retorna a posição disponível.
}

// Função para inserir um produto no estoque, ordenando-o por idade.
void inserirProdutoOrdenadoIdade(LISTA *l, REGISTRO reg) {
    int ant = -1;
    int atual = l->inicio;
    if(l->disponivel == -1) {
    // Caso não exista uma posição disponível.
        printf("\n Não existe posição disponível para inserção no estoque.\n");
        return;
    }
    while(atual!=-1 && l->A[atual].idade<reg.idade) {
        ant = atual;
        atual = l->A[atual].prox;
    }
    if(atual!=-1 && l->A[atual].idade==reg.idade) {
        return;
    }
    atual = obterDisponivel(l);
    // Obtem a posição disponível.
    l->A[atual]=reg;
    // Insere os valores passados pelo usúario para a posição disponível.
    if(ant == -1) {
        l->A[atual].prox = l->inicio;
        l->inicio = atual;
    } else {
        l->A[atual].prox = l->A[ant].prox;
        l->A[ant].prox = atual;
    }
    l->disponivel = l->A[l->disponivel].prox;
    // Agora o elemento disponível é o próximo do disponível atual.
}

// Função para inserir um produto no estoque, ordenando-o por país.
void inserirProdutoOrdenadoPais(LISTA *l, REGISTRO reg) {
    int ant = -1;
    int atual = l->inicio;
    if(l->disponivel == -1) {
    // Caso não exista uma posição disponível.
        printf("\n Não existe posição disponível para inserção no estoque.\n");
        return;
    }
    while(atual!=-1 && strcmp(l->A[atual].pais,reg.pais)<0) {
    // Compara string para saber qual vem antes.
        ant = atual;
        atual = l->A[atual].prox;
    }
    if(atual!=-1 && l->A[atual].pais==reg.pais) {
        return;
    }
    atual = obterDisponivel(l);
    // Obtem a posição disponível.
    l->A[atual]=reg;
    // Insere os valores passados pelo usúario para a posição disponível.
    if(ant == -1) {
        l->A[atual].prox = l->inicio;
        l->inicio = atual;
    } else {
        l->A[atual].prox = l->A[ant].prox;
        l->A[ant].prox = atual;
    }
    l->disponivel = l->A[l->disponivel].prox;
    // Agora o elemento disponível é o próximo do disponível atual.
}

// Função para inserir um produto no estoque, ordenando-o por quantidade em estoque.
void inserirProdutoOrdenadoQuantidade(LISTA *l, REGISTRO reg) {
    int ant = -1;
    int atual = l->inicio;
    if(l->disponivel == -1) {
    // Caso não exista uma posição disponível.
        printf("\n Não existe posição disponível para inserção no estoque.\n");
        return;
    }
    while(atual!=-1 && l->A[atual].quantidadeEstoque<reg.quantidadeEstoque) {
        ant = atual;
        atual = l->A[atual].prox;
    }
    if(atual!=-1 && l->A[atual].quantidadeEstoque==reg.quantidadeEstoque) {
        return;
    }
    atual = obterDisponivel(l);
    // Obtem a posição disponível.
    l->A[atual]=reg;
    // Insere os valores passados pelo usúario para a posição disponível.
    if(ant == -1) {
        l->A[atual].prox = l->inicio;
        l->inicio = atual;
    } else {
        l->A[atual].prox = l->A[ant].prox;
        l->A[ant].prox = atual;
    }
    l->disponivel = l->A[l->disponivel].prox;
    // Agora o elemento disponível é o próximo do disponível atual.
}

// Função para excluir um produto do estoque.
void excluirProduto(LISTA *l, int produtoExcluir) {
    int ant = -1;
    int atual;
    if(l->disponivel == -1) {
    // Caso onde o produto que se deseja excluir, não é encontrado no estoque.
        printf("\n Elemento nao esta na lista.\n");
        return;
    }
    atual=l->inicio;
    while(atual>=0 && l->A[atual].codProduto<produtoExcluir) {
    // Percorre o estoque até chegar no produto que se deseja excluir.
        ant = atual;
        atual = l->A[atual].prox;
    }
    if(l->A[atual].codProduto == produtoExcluir) {
    // Caso onde o produto que se deseja excluir é encontrado, podendo ser excluído.
        if(ant == -1) {
            l->inicio = l->A[atual].prox;
        } else {
            l->A[atual].prox = l->A[atual].prox;
        }
        l->A[atual].prox = l->disponivel;
        l->disponivel = atual;
        printf("\n Produto excluido.\n");
    } else {
    // Caso onde o produto não está cadastrado no estoque.
        printf("\n O elemento nao esta no estoque.\n");
    }
}

void exibirEstoque(LISTA *l) {
    int i;
    if(l->inicio==-1){
    // Verifica se existe algum elemento inserido na lista.
        printf("\n Nenhum elemento inserido na lista.\n");
        // Avisa ao usúario que a lista não possui nenhum elemento inserido.
    } else {
    // Caso onde existem produtos no estoque.
        printf("\n Estoque: \n\n");
        for(i=l->inicio; i!=-1; i=l->A[i].prox) {
            printf("\n Codigo: %d \n\n Nome: %s \n Preco de venda: %f \n\n Idade: %d \n\n Pais: %s \n Quantidade em estoque: %d \n\n",l->A[i].codProduto,l->A[i].nome,l->A[i].precoVenda,l->A[i].idade,l->A[i].pais,l->A[i].quantidadeEstoque);
            // Mostra todos os produtos ao usúario.
        }
    }
}

void buscarProduto(LISTA *l, int codigoBuscar) {
    int i;
    for(i=l->inicio; i>=0 && codigoBuscar>l->A[i].codProduto; i=l->A[i].prox);
    if(i>=0 && codigoBuscar==l->A[i].codProduto){
    // Caso onde o produto é encontrado. Mostra o produto ao usúario.
        printf("\n Codigo: %d \n\n Nome: %s \n Preco de venda: %f \n\n Idade: %d \n\n Pais: %s \n Quantidade em estoque: %d \n\n",l->A[i].codProduto,l->A[i].nome,l->A[i].precoVenda,l->A[i].idade,l->A[i].pais,l->A[i].quantidadeEstoque);
    } else {
    // Caso onde o produto não é encontrado. Alerta o usúario.
        printf("\n Produto nao encontrado.\n");
    }
}

void reinicializarEstoque(LISTA *l) {
    inicializarEstoque(l);
    // Inicia a lista novamente.
}

void menuInicial() {
    printf("\n  O que deseja fazer?\n");
    printf("\n [1] Inicializar a lista");
    printf("\n [0] Sair\n\n");
    // Menu somente com as opções de iniciar a lista ou sair do programa.
}

void menuCompleto() {
    printf("\n  O que deseja fazer?\n");
    printf("\n [1] Inserir um elemento na lista");
    printf("\n [2] Exibir a lista");
    printf("\n [3] Excluir um elemento na lista");
    printf("\n [4] Buscar um elemento na lista");
    printf("\n [5] Reinicializar a lista");
    printf("\n [0] Sair\n\n");
    // Menu completo com todas as opções do programa.
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
