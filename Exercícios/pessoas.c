#include <stdio.h>
#include <string.h>

#define NUM_PESSOAS 5

typedef struct {
    char nome[50];
    float altura;
    float peso;
    char cpf[15];
    char sexo;
} Pessoa;

void cadastrarPessoa(Pessoa *p) {
    printf("Informe o nome: ");
    scanf(" %[^\n]", p->nome);
    printf("Informe a altura (em metros): ");
    scanf("%f", &p->altura);
    printf("Informe o peso (em kg): ");
    scanf("%f", &p->peso);
    printf("Informe o CPF: ");
    scanf(" %s", p->cpf);
    printf("Informe o sexo (M/F): ");
    scanf(" %c", &p->sexo);
}

float calcularIMC(Pessoa p) {
    return p.peso / (p.altura * p.altura);
}

int main() {
    Pessoa pessoas[NUM_PESSOAS];

    for (int i = 0; i < NUM_PESSOAS; i++) {
        printf("\nCadastro da pessoa %d\n", i + 1);
        cadastrarPessoa(&pessoas[i]);
    }

    char cpf[15];
    printf("\nInforme o CPF para busca: ");
    scanf(" %s", cpf);

    for (int i = 0; i < NUM_PESSOAS; i++) {
        if (strcmp(pessoas[i].cpf, cpf) == 0) {
            printf("\nPessoa encontrada: %s\n", pessoas[i].nome);
            printf("IMC: %.2f\n", calcularIMC(pessoas[i]));
            return 0;
        }
    }

    printf("\nCPF não encontrado.\n");

    return 0;
}
