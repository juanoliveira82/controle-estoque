// Nome: Juan Carlos Cardoso de Oliveira
// RA: 120130
// Trabalho: Controle de Estoque (Lista Simplesmente Encadeada)

#include "controleEstoque.h" // O arquivo.h é um header, nele ficam as declarações de estruturas e variáveis.
#include "controleEstoque.c" // O arquivo.c é onde ficam todos os códigos das funcões.

int main() {
    int opcao;
    LISTA listaEstoque;
    REGISTRO elemento;
    // variaveis locais para cadastro.
    int   cadCodProduto;
    char  cadNome[75];
    float cadPrecoVenda;
    int   cadIdade;
    char  cadPais[50];
    int   cadQuantidadeEstoque;

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
            // Recebe todos os dados sobre o elemento que o usuario quer inserir em varaiveis locais.
            elemento.codProduto = cadCodProduto;
            strcpy (elemento.nome, cadNome);
            elemento.precoVenda = cadPrecoVenda;
            elemento.idade = cadIdade;
            strcpy (elemento.pais, cadPais);
            elemento.quantidadeEstoque = cadQuantidadeEstoque;
            // Cria um elemento com todas as informações fornecidas pelo usuario.
            printf("\n Como deseja inserir o elemento na lista ?\n");
            printf("\n [1] Inserir elemento ordenando por idade");
            printf("\n [2] Inserir elemento ordenando por quantidade");
            printf("\n [3] Inserir elemento ordenando por pais\n\n");
            scanf("%d",&opcao);
            // Lê a opção desejada pelo usuário.
            switch(opcao) {
                case 1 :
                    inserirElementoOrdenadoIdade(&listaEstoque, elemento);
                    // Insere o elemento na lista.
                    goto iniciarPrograma;
                case 2 :
                    //inserirElementoOrdenadoQuantidade(&listaEstoque, elemento);
                    // Insere o elemento na lista.
                    goto iniciarPrograma;
                case 3 :
                    //inserirElementoOrdenadoPais(&listaEstoque, elemento);
                    // Insere o elemento na lista.
                    goto iniciarPrograma;
            }
        case 3 :
            limparTela();
            exibirLista(&listaEstoque);
            goto iniciarPrograma;
        case 4 :
            printf("\n");
            break;
        case 5 :
            printf("Better try again\n" );
            break;
        case 6 :
            reinicializarLista(&listaEstoque);
            limparTela();
            printf("\n Lista de estoque reinicializada!\n");
            goto iniciarPrograma;
        default :
            printf("\n Opcao invalida\n");
            goto iniciarPrograma;
    }
            /* printf("\n [4] Excluir um elemento na lista");
    printf("\n [5] Buscar um elemento na lista");
    printf("\n [6] Reinicializar a lista"); */
    return 0;
}
