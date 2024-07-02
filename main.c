#include <stdio.h>
#include <string.h>

int main(void) {
  
  char palavra[100] = "palavra";
  int tamanho = strlen(palavra);
  char segredo[tamanho+1];

  //inicializar segredo com _
  for(int i = 0; i < tamanho; i++)
  {
    segredo[i] = '_';
  }
  int jogando = 1;
  int acertos = 0;
  int tentativas = tamanho;

  printf("### JOGO DA FORCA ###\n\n");

  do
  {
    //imprimie estado atual do segredo
    printf("segredo: ");
    for(int i = 0; i < tamanho; i++)
    {
      printf("%c ", segredo[i]);
    }
    //Pedir letra ao jogador
    printf("\nTentativas: %i", tentativas);
    printf("\nLetras: ");
    char letra = getchar();

    getchar();

    int errou = 1;

    //Verificar se letra existe em palavra
    for(int i = 0; i < tamanho; i++)
    {
      if(letra == palavra[i])
      {
        segredo[i] = letra;
        acertos++;
        errou = 0;
      }
    }
    if(errou == 1)
    {
      tentativas--;
    }
    printf("\n\n");

    if(acertos == tamanho)
    {
      jogando = 0;
      printf("\nVoce venceu! A palavra eh %s", palavra);
    }
    if(tentativas == 0)
    {
      jogando = 0;
      printf("\nVoce perdeu! A palavra eh %s", palavra);
    }
  }
  while(jogando == 1);

  return 0;
}