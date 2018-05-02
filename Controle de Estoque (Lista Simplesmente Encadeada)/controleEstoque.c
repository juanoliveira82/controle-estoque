// Autor: Juan Carlos Cardoso de Oliveira.
#include "controleEstoque.h"

void inicializarLista(LISTA *l) {
    l->inicio=NULL;
    // Coloca o inicio como NULL pois ainda não existem elementos, consequentemente, não há um início da lista.
}

void exibirLista(LISTA *l) {
    PONT end = l->inicio;
    // Cria-se um ponteiro auxiliar que aponta para o inicio da lista.
    if(end==NULL) {
    // Verifica se existe algum elemento inserido na lista.
        printf("\n Nenhum elemento inserido na lista.\n");
        // Avisa ao usúario que a lista não possui nenhum elemento inserido.
    } else {
        printf("\n Estoque:\n\n");
        while(end!=NULL) {
        // Enquanto esse ponteiro não for NULL, ainda existem elementos, então ele percorre a lista e mostra seus elementos.
            printf(" Código: %d \n Nome: %s \n Preço Venda: %f \n Idade: %d \n Pais: %s \n Quantidade em estoque: %d \n\n",end->reg.codProduto,end->reg.nome,end->reg.precoVenda,end->reg.idade,end->reg.pais,end->reg.quantidadeEstoque);
            end = end->prox;
            // Ele sempre passa para o próximo elemento, a partir do inicio.
        }
    }
}

// Função para buscar produtos na lista.
void buscarProduto(LISTA *l, int codigoBuscar) {
    PONT auxiliar = l->inicio;
    // Criação de um ponteiro auxiliar que aponta para o início da lista.
    if(auxiliar==NULL){
    // Caso onde existem registros na lista.
        printf("\n Nao existem produtos cadastrados.\n");
    } else {
    // Caso onde não existem registros na lista.
        while(auxiliar!=NULL && auxiliar->reg.codProduto<codigoBuscar) {
        /* Enquanto o auxiliar não for nulo (existem elementos na lista),
        e o código do produto auxiliar for menor que o código do produto que se busca,
        deve-se passar para o próximo elemento. */
            auxiliar=auxiliar->prox;
            // Passa para o próximo elemento.
        }
        if(auxiliar!=NULL && auxiliar->reg.codProduto==codigoBuscar) {
        // Encontrou o produto que se estava buscando, e o exibe.
            printf("\n Código: %d \n Nome: %s \n Preço Venda: %f \n Idade: %d \n Pais: %s \n Quantidade em estoque: %d \n\n",auxiliar->reg.codProduto,auxiliar->reg.nome,auxiliar->reg.precoVenda,auxiliar->reg.idade,auxiliar->reg.pais,auxiliar->reg.quantidadeEstoque);
        } else {
        // Não encontrou o produto e alerta o usúario.
            printf("\n Produto não encontrado!\n");
        }
    }
}

// Função para inserir registros na lista, ordenando-os por idade.
void inserirElementoOrdenadoIdade(LISTA *l, REGISTRO elemento) {
    PONT anterior = NULL, atual = NULL, novoElemento = NULL;
    novoElemento = (PONT) malloc(sizeof(ELEMENTO));
    // Aloca memória para inserção do novo registro.
    novoElemento->reg = elemento;
    // O novo registro é o elemento passado por parametro.
    novoElemento->prox = NULL;
    // O próximo do novo elemento é nulo, pois ainda não se sabe qual é.
    atual = l->inicio;
    // O atual aponta para o começo da lista.
    while(atual!=NULL && atual->reg.idade<elemento.idade) {
    // Passa os elementos até que o atual seja o mesmo que está sendo inserido.
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
    printf("\n Elemento inserido com sucesso!\n");
}

// Função para inserir registros na lista, ordenando-os por quantidade.
void inserirElementoOrdenadoQuantidade(LISTA *l, REGISTRO elemento) {
    PONT anterior = NULL, atual = NULL, novoElemento = NULL;
    novoElemento = (PONT) malloc(sizeof(ELEMENTO));
    // Aloca memória para inserção do novo registro.
    novoElemento->reg = elemento;
    // O novo registro é o elemento passado por parametro.
    novoElemento->prox = NULL;
    // O próximo do novo elemento é nulo, pois ainda não se sabe qual é.
    atual = l->inicio;
    // O atual aponta para o começo da lista.
    while(atual!=NULL && atual->reg.quantidadeEstoque<elemento.quantidadeEstoque) {
    // Passa os elementos até que o atual seja o mesmo que está sendo inserido.
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
    printf("\n Elemento inserido com sucesso!\n");
}

// Função para inserir registros na lista, ordenando-os por país.
void inserirElementoOrdenadoPais(LISTA *l, REGISTRO elemento) {
    PONT anterior = NULL, atual = NULL, novoElemento = NULL;
    novoElemento = (PONT) malloc(sizeof(ELEMENTO));
    // Aloca memória para inserção do novo registro.
    novoElemento->reg = elemento;
    // O novo registro é o elemento passado por parametro.
    novoElemento->prox = NULL;
    // O próximo do novo elemento é nulo, pois ainda não se sabe qual é.
    atual = l->inicio;
    // O atual aponta para o começo da lista.
    while(atual!=NULL && strcmp(atual->reg.pais,elemento.pais)<0) {
    // Passa os elementos até que o atual seja o mesmo que está sendo inserido.
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
    printf("\n Elemento inserido com sucesso!\n");
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
    if(atual==NULL){
    // Caso onde o elemento que deseja-se ecluir não existe na lista.
        printf("\n O produto informado nao esta cadastrado.\n");
    } else {
    // Caso onde o elemento que deseja-se excluir existe na lista.
        if(anterior==NULL) {
        // Se o anterior for nulo, o elemento a ser excluído é o primeiro da lista.
            l->inicio = atual->prox;
            // Como o primeiro elemento foi excluído, o início da lista aponta para o próximo elemento.
        } else {
            anterior->prox = atual->prox;
            /* Após a remoção do elemento atual (que é o que deseja-se excluir),
            o próximo registro do elemento anterior, deve apontar para o próximo do elemento removido. */
        }
        free(atual);
        // Libera memória do elemento excluído.
        printf("\n O produto %d foi excluido.\n",elementoExcluir);
    }
}

void reinicializarLista(LISTA *l) {
    PONT end = l->inicio;
    while(end!=NULL) {
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    l->inicio = NULL;
}

void limparTela() {
    system("clear");
    // Limpa a tela para melhor exibição do programa.
}

void excluirElementoLista(LISTA *l, int elementoExcluir) {
    PONT anterior, atual;
    anterior = NULL;
    // ainda n tem anterior.
    atual = l->inicio;
    // Atual no começo da lista, para poder percorrer ela.
    while(atual!=NULL && atual->reg.codProduto<elementoExcluir) {
    /* Esse while serve para ir passando os elementos, até que o atual seja o mesmo que deseja-se excluir,
    Ex.: ant=11 atual=12 novo=13
    Passando os comandos abaixo, tornam-se:
    Ex.: ant=12 atual=13 novo=13
    Agora o atual é o mesmo que o novo, assim, ele sai do while e continua o processo de exclusão. */
        anterior = atual;
        atual = atual->prox;