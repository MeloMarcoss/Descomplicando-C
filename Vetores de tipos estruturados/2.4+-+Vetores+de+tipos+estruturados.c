#include <stdio.h>
#include <string.h>

typedef struct
{
  char nome[30];
  float saldo;

}TCliente;

int main(void) {

  TCliente clientes[3];

  //preenchimento
  for(int i = 0; i < 3; i++)
  {
    printf("\nCliente(%i) - Digite o seu nome e saldo: ", i);
    scanf("%s %f", clientes[i].nome, &clientes[i].saldo);

    getchar();
  }

  //impressao
  for(int i = 0; i < 3; i++)
  {
    printf("%s possui %f reais de saldo.\n", clientes[i].nome, clientes[i].saldo);
  }

  return 0;
}