typedef struct {
    char estado;
    char codigo[4];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Carta;

// Função para cadastrar uma carta
void cadastrarCarta(Carta *carta) {
    printf("\nDigite o estado (A-H): ");
    scanf(" %c", &carta->estado);

    printf("Digite o código da carta (ex: A01): ");
    scanf(" %s", carta->codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %49s", carta->nome);

    printf("Digite a população: ");
    scanf(" %d", &carta->populacao);

    printf("Digite a área em km²: ");
    scanf(" %f", &carta->area);

    printf("Digite o PIB: ");
    scanf(" %f", &carta->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf(" %d", &carta->pontos_turisticos);

    printf("\nCarta cadastrada com sucesso!\n");
}

// Função para exibir os dados de uma carta
void exibirCarta(const Carta *carta) {
    printf("\n========================\n");
    printf("Estado: %c\n", carta->estado);
    printf("Código: %s\n", carta->codigo);
    printf("Cidade: %s\n", carta->nome);
    printf("População: %d\n", carta->populacao);
    printf("Área: %.2f km²\n", carta->area);
    printf("PIB: %.2f\n", carta->pib);
    printf("Pontos turísticos: %d\n", carta->pontos_turisticos);
    printf("========================\n");
}

int main() {
    Carta cartas[MAX_CARTAS];
    int totalCartas = 0;
    char opcao;

    printf("Bem-vindo ao sistema de cadastro do Super Trunfo de Países!\n\n");

    do {
        if (totalCartas >= MAX_CARTAS) {
            printf("\nLimite máximo de cartas atingido! Não é possível cadastrar mais cartas.\n");
            break;
        }

        printf("\n--- Menu ---\n");
        printf("1. Cadastrar nova carta\n");
        printf("2. Exibir todas as cartas\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                cadastrarCarta(&cartas[totalCartas]);
                totalCartas++;
                break;

            case '2':
                if (totalCartas == 0) {
                    printf("\nNenhuma carta cadastrada ainda!\n");
                } else {
                    for (int i = 0; i < totalCartas; i++) {
                        exibirCarta(&cartas[i]);
                    }
                }
                break;

            case '3':
                printf("\nSaindo do sistema. Até mais!\n");
                break;

            default:
                printf("\nOpção inválida! Tente novamente.\n");
                break;
        }

    } while (opcao != '3');

    return 0;
}
