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

//printf("\n Código: %d \n Nome: %s \n Preço Venda: %f \n Idade: %d \n Pais: %s \n Quantidade em estoque: %d \n\n",cadCodProduto,cadNome,cadPrecoVenda,cadIdade,cadPais,cadQuantidadeEstoque);

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

    switch(opcao) {
        case 0 :
            break;
        case 1 :
            inicializarLista(&listaEstoque);
            goto iniciarPrograma;
        case 2 :
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

              elemento = (const REGISTRO){cadCodProduto,"juan",cadPrecoVenda,cadIdade,"brasil ne mano",cadQuantidadeEstoque};
              inserirElementoOrdenadoIdade(&listaEstoque, elemento);
              goto iniciarPrograma;
        case 3 :
            exibirLista(&listaEstoque);
            goto iniciarPrograma;
        case 4 :
            printf("\n");
            break;
        case 5 :
            printf("Better try again\n" );
            break;
        default :
            printf("\n Opcao invalida\n");
            goto iniciarPrograma;
    }

    return 0;
}
