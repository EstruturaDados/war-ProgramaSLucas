#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definição da struct Territorio
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// Função que simula um ataque entre dois territórios
void atacar(Territorio* atacante, Territorio* defensor) {
    int dado_atacante, dado_defensor;

    // Gera valores aleatórios simulando o lançamento de um dado (1 a 6)
    dado_atacante = rand() % 6 + 1;
    dado_defensor = rand() % 6 + 1;

    printf("\n=== Simulação de Ataque ===\n");
    printf("%s (%s) ataca %s (%s)\n", atacante->nome, atacante->cor, defensor->nome, defensor->cor);
    printf("Dado atacante: %d | Dado defensor: %d\n", dado_atacante, dado_defensor);

    // Verifica quem venceu o ataque
    if (dado_atacante > dado_defensor) {
        printf("Resultado: %s venceu a batalha!\n", atacante->nome);

        // Defensor perde tropas
        defensor->tropas -= 1;

        if (defensor->tropas <= 0) {
            // Se as tropas do defensor acabarem, o território muda de dono
            defensor->tropas = atacante->tropas / 2;  // atacante envia metade das tropas para o novo território
            strcpy(defensor->cor, atacante->cor);
            printf("O território %s foi conquistado por %s!\n", defensor->nome, atacante->cor);
        }
    } else {
        printf("Resultado: %s defendeu com sucesso!\n", defensor->nome);
        atacante->tropas -= 1;  // atacante perde uma tropa
    }

    // Evita números negativos
    if (atacante->tropas < 0) atacante->tropas = 0;
    if (defensor->tropas < 0) defensor->tropas = 0;
}

int main() {
    int qtd, i;
    Territorio *territorios;
    int atk, def;

    srand(time(NULL)); // inicializa o gerador de números aleatórios

    printf("Informe a quantidade de territórios: ");
    scanf("%d", &qtd);
    getchar(); // consome o \n deixado pelo scanf

    // Aloca memória dinamicamente para os territórios
    territorios = (Territorio*) malloc(qtd * sizeof(Territorio));

    if (territorios == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Cadastro dos territórios
    printf("\n=== Cadastro de Territórios ===\n");
    for (i = 0; i < qtd; i++) {
        printf("\nTerritório %d:\n", i + 1);

        printf("Nome: ");
        fgets(territorios[i].nome, sizeof(territorios[i].nome), stdin);
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0';

        printf("Cor do exército: ");
        fgets(territorios[i].cor, sizeof(territorios[i].cor), stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0';

        printf("Quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);
        getchar();
    }

    // Exibição inicial
    printf("\n=== Territórios Cadastrados ===\n");
    for (i = 0; i < qtd; i++) {
        printf("\nTerritório %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do exército: %s\n", territorios[i].cor);
        printf("Tropas: %d\n", territorios[i].tropas);
    }

    // Simulação de ataques
    char continuar;
    do {
        printf("\n=== Simulação de Ataques ===\n");
        printf("Escolha o número do território atacante (1 a %d): ", qtd);
        scanf("%d", &atk);
        printf("Escolha o número do território defensor (1 a %d): ", qtd);
        scanf("%d", &def);
        getchar();

        if (atk < 1 || atk > qtd || def < 1 || def > qtd || atk == def) {
            printf("Escolha inválida!\n");
        } else {
            atacar(&territorios[atk - 1], &territorios[def - 1]);
        }

        // Exibição pós-ataque
        printf("\n=== Estado Atual dos Territórios ===\n");
        for (i = 0; i < qtd; i++) {
            printf("\nTerritório %d:\n", i + 1);
            printf("Nome: %s\n", territorios[i].nome);
            printf("Cor do exército: %s\n", territorios[i].cor);
            printf("Tropas: %d\n", territorios[i].tropas);
        }

        printf("\nDeseja realizar outro ataque? (s/n): ");
        scanf(" %c", &continuar);
        getchar();

    } while (continuar == 's' || continuar == 'S');

    // Libera a memória alocada
    free(territorios);

    printf("\nEncerrando o programa.\n");
    return 0;
}
