#include <stdio.h>
#include <string.h>

#define TOTAL 10

// Estrutura que representa um produto do supermercado.
typedef struct {
    char nome[50];
    float preco;
} Produto;

// Exibe a lista de produtos e seus respectivos preços.
void exibirProdutos(Produto produtos[], int tamanho) {
    printf("\n%-25s %s\n", "PRODUTO", "PRECO (R$)");
    printf("-----------------------------------------------\n");

    for (int i = 0; i < tamanho; i++) {
        printf("%-25s R$ %8.2f\n",
               produtos[i].nome,
               produtos[i].preco);
    }
}

// Bubble Sort: compara produtos vizinhos e troca suas
// posições quando estão fora da ordem crescente de preço.
// A cada passagem, o maior preço restante vai para o final.
void bubbleSort(Produto produtos[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int trocou = 0;

        for (int j = 0; j < tamanho - 1 - i; j++) {
            if (produtos[j].preco > produtos[j + 1].preco) {
                Produto temporario = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temporario;

                trocou = 1;
            }
        }

        // Se nenhuma troca ocorreu, a lista já está ordenada.
        if (!trocou) {
            break;
        }
    }
}

// Quick Sort: utiliza um pivô para dividir os produtos
// em dois grupos: preços menores ou iguais ao pivô e
// preços maiores que o pivô. Depois, ordena cada grupo
// recursivamente.
void quickSort(Produto produtos[], int inicio, int fim) {
    int i = inicio;
    int j = fim;

    // Escolhe o elemento central como pivô.
    float pivo = produtos[inicio + (fim - inicio) / 2].preco;

    while (i <= j) {
        // Procura um preço que deveria estar à direita.
        while (produtos[i].preco < pivo) {
            i++;
        }

        // Procura um preço que deveria estar à esquerda.
        while (produtos[j].preco > pivo) {
            j--;
        }

        // Troca os elementos que estão em posições incorretas.
        if (i <= j) {
            Produto temporario = produtos[i];
            produtos[i] = produtos[j];
            produtos[j] = temporario;

            i++;
            j--;
        }
    }

    // Ordena recursivamente a parte esquerda.
    if (inicio < j) {
        quickSort(produtos, inicio, j);
    }

    // Ordena recursivamente a parte direita.
    if (i < fim) {
        quickSort(produtos, i, fim);
    }
}

int main(void) {
    // Dados fictícios de produtos de um supermercado.
    // A situação escolhida permite organizar os preços
    // para facilitar a comparação entre os produtos.
    Produto produtosOriginais[TOTAL] = {
        {"Arroz", 28.90},
        {"Feijao", 8.50},
        {"Leite", 5.79},
        {"Cafe", 18.90},
        {"Acucar", 4.99},
        {"Macarrao", 6.49},
        {"Oleo", 7.89},
        {"Farinha", 5.49},
        {"Biscoito", 3.99},
        {"Queijo", 32.50}
    };

    // Criamos duas cópias para garantir que os algoritmos
    // ordenem exatamente o mesmo conjunto de dados.
    Produto produtosBubble[TOTAL];
    Produto produtosQuick[TOTAL];

    memcpy(produtosBubble, produtosOriginais, sizeof(produtosOriginais));
    memcpy(produtosQuick, produtosOriginais, sizeof(produtosOriginais));

    printf("============================================\n");
    printf(" ORGANIZACAO DE PRECOS DO SUPERMERCADO\n");
    printf("============================================\n");

    printf("\n1. Produtos antes da ordenacao:");
    exibirProdutos(produtosOriginais, TOTAL);

    // Ordenação utilizando o Bubble Sort.
    bubbleSort(produtosBubble, TOTAL);

    printf("\n2. Produtos ordenados pelo Bubble Sort:");
    exibirProdutos(produtosBubble, TOTAL);

    // Ordenação utilizando o Quick Sort.
    quickSort(produtosQuick, 0, TOTAL - 1);

    printf("\n3. Produtos ordenados pelo Quick Sort:");
    exibirProdutos(produtosQuick, TOTAL);

    printf("\nOs dois algoritmos ordenaram os produtos");
    printf(" do menor para o maior preco.\n");

    return 0;
}
