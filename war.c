#include <stdio.h>

#define QTD_TERRITORIOS 5

// Definição da struct Territorio
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

int main() {
    struct Territorio territorios[QTD_TERRITORIOS];
    int i;

    printf("=== Cadastro de Territórios ===\n");

    // Cadastro dos 5 territórios
    for (i = 0; i < QTD_TERRITORIOS; i++) {
        printf("\nTerritório %d:\n", i + 1);

        printf("Nome: ");
        scanf(" %[^\n]", territorios[i].nome); // Lê string com espaços

        printf("Cor do exército: ");
        scanf(" %[^\n]", territorios[i].cor);

        printf("Quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);
    }

    // Exibição dos dados cadastrados
    printf("\n=== Territórios Cadastrados ===\n");
    for (i = 0; i < QTD_TERRITORIOS; i++) {
        printf("\nTerritório %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do exército: %s\n", territorios[i].cor);
        printf("Tropas: %d\n", territorios[i].tropas);
    }

    return 0;
}

