#include <stdio.h>
#include <string.h>

typedef struct
{
  char nome[30];
  int idade;
}Aluno;

int main(void) {

  Aluno a;
  strcpy(a.nome, "Sicrano");
  a.idade = 27;

  Aluno* p = &a;

  printf("Idade: %i.\n", (*p).idade);
  printf("Nome: %s.", (*p).nome);

  p->idade = 17;
  strcpy(p->nome, "Beltrano");

  printf("\n\nIdade: %i.\n", p->idade);
  printf("Nome: %s.", p->nome);

  return 0;
}