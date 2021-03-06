// Nome: Juan Carlos Cardoso de Oliveira
// RA: 120130
// Trabalho: Controle de Estoque (Lista Encadeada Est�tica)

#include "controleEstoque.h"
#include "controleEstoque.c"

int main() {
    setlocale(LC_ALL, "Portuguese");
    // Coloca o idioma como portugu�s para exibi��o de acentos.
    int opcao=NULL, registroExcluir, registroBuscar;
    LISTA listaEstoque;
    REGISTRO elemento;
    printf("\n\tControle de estoque de whisky\n");
    menuInicio:
    menuInicial();
    // Mostra o menu inicial ao us�ario.
    scanf("%d",&opcao);
    // L� a op��o desejada pelo usu�rio.
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
        printf("\n Op��o inv�lida!\n");
        goto menuInicio;
        // Caso o us�ario informe uma op��o inv�lida, o programa o alerta e volta ao in�cio do mesmo.
    }
    iniciarPrograma:
    menuCompleto();
    // Mostra um menu com op��es de funcionamento do programa.
    scanf("%d",&opcao);
    // L� a op��o desejada pelo usu�rio.
    switch(opcao) {
        case 0 :
            limparTela();
            printf("\n Obrigado por usar o programa!\n\n Autor: Juan Oliveira\n");
            return 0;
        case 1 :
            limparTela();
            printf("\n Informe o c�digo: ");
            scanf("%i", &elemento.codProduto);
            printf("\n Informe o nome: ");
            setbuf(stdin, NULL);
            fgets(elemento.nome, 75, stdin);
            printf("\n Informe o pre�o de venda: ");
            scanf("%f", &elemento.precoVenda);
            printf("\n Informe a idade: ");
            scanf("%i", &elemento.idade);
            printf("\n Informe o pa�s: ");
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
            // L� a op��o desejada pelo usu�rio.
            switch(opcao) {
                // As tr�s op��es inserem o elemento na lista e voltam ao menu principal.
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
                    printf("\n Op��o inv�lida! Escolha a forma de ordena��o corretamente.\n");
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
            printf("\n Op��o invalida!\n");
            goto iniciarPrograma;
    }
    return 0;
}
