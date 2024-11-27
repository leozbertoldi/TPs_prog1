/* 
 * Tipos Abstratos de Dados - TADs
 * Arquivo do programa principal, que usa o TAD racional.
 * Feito em 16/09/2024 para a disciplina CI1001 - Programação 1.
*/

#include <stdio.h>
#include <stdlib.h>
#include "racional.h"

int main ()
{
  int n, i, max;
  srand (0); 
  scanf("%d", &n);
  while ( (n <= 0) || (n >=100) ) //confirmando que 0<n<100
    scanf("%d", &n);
  scanf("%d", &max); 
  while ( (max <= 0) || (max >= 30) ) //confirmando que 0<max<30
    scanf("%d", &max); 
  for (i = 1; i <= n; i++){
    printf("%d: ", i);
    sortear
    printf r1 r2
    if (invalido){
      printf("NUMERO INVALIDO\n");
      return (1);
    }
    soma
    subtrai
    multiplica
    divide 
    if (divisao invalida){
      printf("DIVISAO INVALIDA\n");
      return (1);
    printf soma
    printf subtrai
    printf multiplica 
    printf divisao \n 
  }
  return (0) ;
}
