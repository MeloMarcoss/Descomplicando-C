#include <stdio.h>
#include <math.h>

int main(void) {
  
  printf("### Paridade ###\n");
  int n;
  printf("\nDigite um número: ");
  scanf("%i", &n);

  if( n % 2 == 0)
  {
    printf("O numero %i eh par.", n);
  }
  else
  {
    printf("O numero %i eh impar.", n);
  }

  return 0;
}