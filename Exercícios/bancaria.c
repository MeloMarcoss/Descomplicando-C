#include <stdio.h>
#include <string.h>

#define NUM_CONTAS 3

typedef struct {
    char nome[50];
    char cpf[15];
    int numeroConta;
    float saldo;
} ContaBancaria;

void criarConta(ContaBancaria *conta) {
    printf("Informe o nome do cliente: ");
    scanf(" %[^\n]", conta->nome);
    printf("Informe o CPF do cliente: ");
    scanf(" %s", conta->cpf);
    printf("Informe o número da conta: ");
    scanf("%d", &conta->numeroConta);
    printf("Informe o depósito inicial: ");
    scanf("%f", &conta->saldo);
}

void realizarDeposito(ContaBancaria *conta, float valor) {
    conta->saldo += valor;
    printf("Depósito realizado com sucesso.\n");
}

void realizarSaque(ContaBancaria *conta, float valor) {
    if (valor <= conta->saldo) {
        conta->saldo -= valor;
        printf("Saque realizado com sucesso.\n");
    } else {
        printf("Saldo insuficiente.\n");
    }
}

ContaBancaria* buscarConta(ContaBancaria contas[], int numeroConta) {
    for (int i = 0; i < NUM_CONTAS; i++) {
        if (contas[i].numeroConta == numeroConta) {
            return &contas[i];
        }
    }
    return NULL;
}

int main() {
    ContaBancaria contas[NUM_CONTAS];

    for (int i = 0; i < NUM_CONTAS; i++) {
        printf("\nCriação da conta %d\n", i + 1);
        criarConta(&contas[i]);
    }

    int opcao;
    do {
        printf("\nMenu de Operações:\n");
        printf("1. Realizar depósito\n");
        printf("2. Realizar saque\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1 || opcao == 2) {
            int numeroConta;
            float valor;
            printf("Informe o número da conta: ");
            scanf("%d", &numeroConta);
            ContaBancaria *conta = buscarConta(contas, numeroConta);

            if (conta != NULL) {
                printf("Informe o valor: ");
                scanf("%f", &valor);
                if (opcao == 1) {
                    realizarDeposito(conta, valor);
                } else {
                    realizarSaque(conta, valor);
                }
                printf("Titular: %s\n", conta->nome);
                printf("Saldo atual: %.2f\n", conta->saldo);
            } else {
                printf("Conta não encontrada.\n");
            }
        }
    } while (opcao != 3);

    return 0;
}
