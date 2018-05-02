// Nome: Juan Carlos Cardoso de Oliveira
// RA: 120130
// Trabalho: Controle de Estoque (Lista Simplesmente Encadeada)

#include "controleEstoque.h"
#include "controleEstoque.c"

int main() {
    int opcao, registroExcluir, registroBuscar;
    LISTA listaEstoque;
    REGISTRO elemento;
    int   cadCodProduto;
    char  cadNome[75];
    float cadPrecoVenda;
    int   cadIdade;
    char  cadPais[50];
    int   cadQuantidadeEstoque;
    // Criação de variáveis locais para cadastro dos registros.
    printf("\n\tControde de estoque de whisky\n");
    iniciarPrograma:
    printf("\n  O que deseja fazer?\n");
    printf("\n [1] Inicializar a lista");
    printf("\n [2] Inserir um elemento na lista");
    printf("\n [3] Exibir a lista");
    printf("\n [4] Excluir um elemento na lista");
    printf("\n [5] Buscar um elemento na lista");
    printf("\n [6] Reinicializar a lista");
    printf("\n [0] Sair\n\n");
    // Menu do programa.
    scanf("%d",&opcao);
    // Lê a opção desejada pelo usuário.
    switch(opcao) {
        case 0 :
            limparTela();
            printf("\n Obrigado por usar o programa!\n\n Autor: Juan Oliveira\n");
            break;
        case 1 :
            inicializarLista(&listaEstoque);
            limparTela();
            printf("\n Lista de estoque inicializada!\n");
            goto iniciarPrograma;
        case 2 :
            limparTela();
            printf("\n Informe o código: ");
            scanf("%d",&cadCodProduto);
            printf("\n Informe o nome: ");
            scanf("%s",&cadNome);
            printf("\n Informe o preco de venda: ");
            scanf("%f",&cadPrecoVenda);
            printf("\n Informe a idade: ");
            scanf("%d",&cadIdade);
            printf("\n Informe o pais: ");
            scanf("%s",&cadPais);
            printf("\n Informe a quantidade em estoque: ");
            scanf("%d",&cadQuantidadeEstoque);
            // Recebe todos os dados sobre o elemento que o usúario quer inserir em varaiveis locais.
            elemento.codProduto = cadCodProduto;
            strcpy (elemento.nome, cadNome);
            elemento.precoVenda = cadPrecoVenda;
            elemento.idade = cadIdade;
            strcpy (elemento.pais, cadPais);
            elemento.quantidadeEstoque = cadQuantidadeEstoque;
            // Cria um elemento com todas as informações fornecidas pelo usuario.
            escolherOrdenacao:
            printf("\n Como deseja inserir o elemento '%s' na lista ?\n",&cadNome);
            printf("\n [1] Inserir elemento ordenando por idade");
            printf("\n [2] Inserir elemento ordenando por quantidade");
            printf("\n [3] Inserir elemento ordenando por pais\n\n");
            scanf("%d",&opcao);
            // Lê a opção desejada pelo usuário.
            switch(opcao) {
                // As três opções inserem o elemento na lista e voltam ao menu principal.
                case 1 :
                    inserirElementoOrdenadoIdade(&listaEstoque,elemento);
                    goto iniciarPrograma;
                case 2 :
                    inserirElementoOrdenadoQuantidade(&listaEstoque,elemento);
                    goto iniciarPrograma;
                case 3 :
                    inserirElementoOrdenadoPais(&listaEstoque,elemento);
                    goto iniciarPrograma;
                default :
                    limparTela();
                    printf("\n Opcao invalida! Escolha a forma de ordenacao corretamente.\n");
                    goto escolherOrdenacao;
            }
        case 3 :
            limparTela();
            exibirLista(&listaEstoque);
            goto iniciarPrograma;
        case 4 :
            printf("\n Qual produto deseja excluir ?  ");
            scanf("%d",&registroExcluir);
            excluirElementoLista(&listaEstoque,registroExcluir);
            goto iniciarPrograma;
        case 5 :
            printf("\n Qual produto deseja buscar ?  ");
            scanf("%d",&registroBuscar);
            buscarProduto(&listaEstoque, registroBuscar);
            goto iniciarPrograma;
        case 6 :
            reinicializarLista(&listaEstoque);
            limparTela();
            printf("\n Lista de estoque reinicializada!\n");
            goto iniciarPrograma;
        default :
            limparTela();
            printf("\n Opcao invalida!\n");
            goto iniciarPrograma;
    }
    return 0;
}
