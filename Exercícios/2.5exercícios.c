#include <stdio.h>
#include <string.h>

typedef struct
{
  int matricula;
  char nome[30];
  float notas[3];
  float media;

}Aluno;

int main(void) {

  Aluno alunos[60];

  //Cadastro dos alunos
  int i;

  for(i = 0; i < 60; i++)
  {
    printf("\nAluno (%i)\n\n", i);

    int matricula;
    printf("Matricula: ");
    scanf("%i", &matricula);

    getchar();

    if(matricula == 0)
    {
      break;
    }
    else
    {
      alunos[i].matricula = matricula;
    }

    printf("\nNome: ");
    scanf("%s", alunos[i].nome);

    getchar();

    printf("\nNotas: ");
    scanf("%f %f %f", &alunos[i].notas[0], &alunos[i].notas[1], &alunos[i].notas[2]);

    alunos[i].media = (alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2])/3;
  }

  printf("\n\n");

  for(int j = 0; j < i; j++)
  {
    printf("%s de matricula %i possui media %f.\n", alunos[j].nome, alunos[j].matricula, alunos[j].media);
  }
  
  return 0;
}