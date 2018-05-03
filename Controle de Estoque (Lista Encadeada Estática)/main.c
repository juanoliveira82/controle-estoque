// Nome: Juan Carlos Cardoso de Oliveira
// RA: 120130
// Trabalho: Controle de Estoque (Lista Encadeada Estática)

#include "controleEstoque.h"
#include "controleEstoque.c"

int main() {
    setlocale(LC_ALL, "Portuguese");
    // Coloca o idioma como português para exibição de acentos.
    int opcao=NULL, registroExcluir, registroBuscar;
    LISTA listaEstoque;
    REGISTRO elemento;
    printf("\n\tControle de estoque de whisky\n");
    menuInicio:
    menuInicial();
    // Mostra o menu inicial ao usúario.
    scanf("%d",&opcao);
    // Lê a opção desejada pelo usuário.
    if(opcao==0){
        limparTela();
        printf("\n Obrigado por usar o programa!\n\n Autor: Juan Oliveira\n");
        return 0;
    } else if(opcao==1){
        inicializarEstoque(&listaEstoque);
        limparTela();
        printf("\n Lista de estoque inicializada!\n");
    } else {
        limparTela();
        printf("\n Opção inválida!\n");
        goto menuInicio;
        // Caso o usúario informe uma opção inválida, o programa o alerta e volta ao início do mesmo.
    }
    iniciarPrograma:
    menuCompleto();
    // Mostra um menu com opções de funcionamento do programa.
    scanf("%d",&opcao);
    // Lê a opção desejada pelo usuário.
    switch(opcao) {
        case 0 :
            limparTela();
            printf("\n Obrigado por usar o programa!\n\n Autor: Juan Oliveira\n");
            return 0;
        case 1 :
            limparTela();
            printf("\n Informe o código: ");
            scanf("%i", &elemento.codProduto);
            printf("\n Informe o nome: ");
            setbuf(stdin, NULL);
            fgets(elemento.nome, 75, stdin);
            printf("\n Informe o preço de venda: ");
            scanf("%f", &elemento.precoVenda);
            printf("\n Informe a idade: ");
            scanf("%i", &elemento.idade);
            printf("\n Informe o país: ");
            setbuf(stdin, NULL);
            fgets(elemento.pais, 50, stdin);
            printf("\n Informe a quantidade em estoque: ");
            scanf("%i", &elemento.quantidadeEstoque);
            escolherOrdenacao:
            printf("\n Como deseja inserir o elemento na lista ?\n");
            printf("\n [1] Inserir elemento ordenando por idade");
            printf("\n [2] Inserir elemento ordenando por quantidade");
            printf("\n [3] Inserir elemento ordenando por pais\n\n");
            scanf("%d",&opcao);
            // Lê a opção desejada pelo usuário.
            switch(opcao) {
                // As três opções inserem o elemento na lista e voltam ao menu principal.
                case 1 :
                    inserirProdutoOrdenadoIdade(&listaEstoque,elemento);
                    limparTela();
                    printf("\n Produto inserido com sucesso!\n");
                    goto iniciarPrograma;
                case 2 :
                    inserirProdutoOrdenadoQuantidade(&listaEstoque,elemento);
                    limparTela();
                    printf("\n Produto inserido com sucesso!\n");
                    goto iniciarPrograma;
                case 3 :
                    inserirProdutoOrdenadoPais(&listaEstoque,elemento);
                    limparTela();
                    printf("\n Produto inserido com sucesso!\n");
                    goto iniciarPrograma;
                default :
                    limparTela();
                    printf("\n Opção inválida! Escolha a forma de ordenação corretamente.\n");
                    goto escolherOrdenacao;
            }
        case 2 :
            limparTela();
            exibirEstoque(&listaEstoque);
            goto iniciarPrograma;
        case 3 :
            limparTela();
            printf("\n Qual produto deseja excluir ?  ");
            scanf("%d",&registroExcluir);
            excluirProduto(&listaEstoque,registroExcluir);
            goto iniciarPrograma;
        case 4 :
            limparTela();
            printf("\n Qual produto deseja buscar ?  ");
            scanf("%d",&registroBuscar);
            buscarProduto(&listaEstoque, registroBuscar);
            goto iniciarPrograma;
        case 5 :
            reinicializarEstoque(&listaEstoque);
            limparTela();
            printf("\n Lista de estoque reinicializada!\n");
            goto menuInicio;
        default :
            limparTela();
            printf("\n Opção invalida!\n");
            goto iniciarPrograma;
    }
    return 0;
}
