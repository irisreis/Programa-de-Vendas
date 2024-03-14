#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void titulo();

struct Venda {
    int codigo;
    char nome_produto[100];
    char marca[100];
    int qtd_itens;
    int preco_unitario;
    float preco_total;
    float desconto;
};

// Função titulo
void titulo() {
    printf("|-----------------------------------|\n");
    printf("|          Programa de Vendas       |\n");
    printf("|         Autores:                  |\n");
    printf("|---------------------------------- |\n");
    printf("| Carolina de Jesus Menezes         |\n");
    printf("| Leonardo Henrique Santos Zonta    |\n");
    printf("| Iris da Silva Reis                |\n");
    printf("| Matheus Vitor Ferreira            |\n");
    printf("| Lucas Suares da Silva             |\n");
    printf("|-----------------------------------|\n\n");
}

struct Venda registrar_Vendas() {
    struct Venda venda;

    printf("Registrar Vendas: \n\n");
    printf("Codigo: ");
    scanf("%d", &venda.codigo);

    printf("\nNome: ");
    getchar();
    fgets(venda.nome_produto, sizeof(venda.nome_produto), stdin);

    printf("\nMarca: ");
    fgets(venda.marca, sizeof(venda.marca), stdin);

    printf("\nQuantidade de Itens: ");
    scanf("%d", &venda.qtd_itens);

    printf("\nPreço Unitário: ");
    scanf("%d", &venda.preco_unitario);

    venda.preco_total = (float) (venda.qtd_itens * venda.preco_unitario);
    printf("\nPreço total: %.2f\n", venda.preco_total);

    return venda;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    titulo(); 

    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar nova venda\n");
        printf("2. Finalizar venda\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                system("CLS");
                registrar_Vendas();
                system("CLS");
                break;
            case 2:
                printf("\nFinalizando o programa.\n");
                break;
            default:
                printf("\nOpção inválida. Escolha novamente.\n");
        }
    } while (opcao != 2);
    
    return 0;
}
