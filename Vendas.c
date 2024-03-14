#include <stdio.h>


void titulo();

struct Vendas {
    int codigo;
    char nome_produto[100];
    char marca[100];
    int qtd_itens;
    int preco_unitario;
    float preco_total;
    float desconto;
} venda;

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
void registrar_Vendas() {
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

    venda.preco_total = venda.qtd_itens * venda.preco_unitario;
    printf("\nPreço total: %.2f\n", venda.preco_total);
}

int main() {
    titulo(); 
    registrar_Vendas();
    
    return 0;
}
