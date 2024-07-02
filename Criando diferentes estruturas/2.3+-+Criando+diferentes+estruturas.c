#include <stdio.h>
#include <string.h>

typedef struct
{
  char rua[30];
  char bairro[30];
  char cep[15];
  char cidade[30];
}TEndereco;

typedef struct
{
  char nome[250];
  char codTurma[10];
  long int matricula;
  int idade;

  TEndereco endereco;

}TAluno;

int main(void) {

  TAluno a, b;

  a.idade = 20;
  a.matricula = 1234;
  strcpy(a.nome, "Sicrano");
  strcpy(a.codTurma, "987");

  strcpy(a.endereco.rua, "Rua dos bobos");

  return 0;
}