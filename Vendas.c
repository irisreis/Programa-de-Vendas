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


    
void encontrar_mais_vendido(struct Venda *vendas, int num_vendas) {
    int vendas_por_produto[num_vendas];
    for (int i = 0; i < num_vendas; i++) {
        vendas_por_produto[i] = contar_vendas_por_produto(vendas, num_vendas, vendas[i].codigo);
    }

    int index_mais_vendido = encontrar_max_index(vendas_por_produto, num_vendas);
    printf("O item mais vendido é: %s (Marca: %s) com um total de %d itens vendidos.\n",
           vendas[index_mais_vendido].nome_produto,
           vendas[index_mais_vendido].marca,
           vendas_por_produto[index_mais_vendido]);
}

void encontrar_menos_vendido(struct Venda *vendas, int num_vendas) {
    int vendas_por_produto[num_vendas];
    for (int i = 0; i < num_vendas; i++) {
        vendas_por_produto[i] = contar_vendas_por_produto(vendas, num_vendas, vendas[i].codigo);
    }
    int index_menos_vendido = encontrar_min_index(vendas_por_produto, num_vendas);
    printf("O item menos vendido é: %s (Marca: %s) com um total de %d itens vendidos.\n",
           vendas[index_menos_vendido].nome_produto,
           vendas[index_menos_vendido].marca,
           vendas_por_produto[index_menos_vendido]);
}
int encontrar_max_index(int *array, int size) {
    int max = array[0];
    int index = 0;
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
            index = i;
        }
    }
    return index;
}
int encontrar_min_index(int *array, int size) {
    int min = array[0];
    int index = 0;
    for (int i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
            index = i;
        }
    }
    return index;
}
int calcular_quantidade_clientes(struct Venda *vendas, int num_vendas) {
    int clientes[num_vendas]; 
    int contador_clientes = 0;
    for (int i = 0; i < num_vendas; i++) {
        int codigo_cliente_atual = vendas[i].codigo;
        int cliente_ja_registrado = 0;
        for (int j = 0; j < contador_clientes; j++) {
            if (clientes[j] == codigo_cliente_atual) {
                cliente_ja_registrado = 1;
                break;
            }
        }
        if (!cliente_ja_registrado) {
            clientes[contador_clientes] = codigo_cliente_atual;
            contador_clientes++;
        }
    }
    return contador_clientes;
}

    return 0;
}
