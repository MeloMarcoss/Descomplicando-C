#include <stdio.h>
#include <string.h>

#define MAX_CONTATOS 100

typedef struct {
    char nome[50];
    char telefone[15];
} Contato;

void inserirContato(Contato contatos[], int *numContatos) {
    if (*numContatos < MAX_CONTATOS) {
        printf("Informe o nome: ");
        scanf(" %[^\n]", contatos[*numContatos].nome);
        printf("Informe o telefone: ");
        scanf(" %s", contatos[*numContatos].telefone);
        (*numContatos)++;
    } else {
        printf("Agenda cheia.\n");
    }
}

void visualizarContatos(Contato contatos[], int numContatos) {
    for (int i = 0; i < numContatos; i++) {
        printf("\nContato %d\n", i + 1);
        printf("Nome: %s\n", contatos[i].nome);
        printf("Telefone: %s\n", contatos[i].telefone);
    }
}

void alterarContato(Contato contatos[], int numContatos) {
    char nome[50];
    printf("Informe o nome do contato a ser alterado: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < numContatos; i++) {
        if (strcmp(contatos[i].nome, nome) == 0) {
            printf("Informe o novo nome: ");
            scanf(" %[^\n]", contatos[i].nome);
            printf("Informe o novo telefone: ");
            scanf(" %s", contatos[i].telefone);
            printf("Contato alterado com sucesso.\n");
            return;
        }
    }
    printf("Contato não encontrado.\n");
}

int main() {
    Contato contatos[MAX_CONTATOS];
    int numContatos = 0;
    int opcao;

    do {
        printf("\nMenu da Agenda Telefônica:\n");
        printf("1. Inserir um contato\n");
        printf("2. Visualizar todos os contatos\n");
        printf("3. Alterar nome ou número do contato\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirContato(contatos, &numContatos);
                break;
            case 2:
                visualizarContatos(contatos, numContatos);
                break;
            case 3:
                alterarContato(contatos, numContatos);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}
