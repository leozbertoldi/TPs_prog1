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
  int n, i, max, min;
  struct racional r1, r2, r_soma, r_subtrai, r_multiplica, r_divide;
  srand (0); 
  scanf("%d", &n);
  while ( (n <= 0) || (n >=100) ) //confirmando que 0<n<100
    scanf("%d", &n);
  scanf("%d", &max); 
  while ( (max <= 0) || (max >= 30) ) //confirmando que 0<max<30
    scanf("%d", &max); 
  min = (-1)*max;
  for (i = 1; i <= n; i++){
    printf("%d: ", i);
    r1 = sorteia_r(min, max); //sorteia r1
    r2 = sorteia_r(min, max); //sorteia r2
    imprime_r(r1);
    imprime_r(r2);
    if (valido_r(r1) == 0 || valido_r(r2) == 0){
      printf("NUMERO INVALIDO\n");
      return (1);
    }
    //armazenando os valores em structs racionais r_operação
    r_soma = soma_r(r1, r2);
    r_subtrai = subtrai_r(r1, r2);
    r_multiplica = multiplica_r(r1, r2);
    r_divide = divide_r(r1, r2);
    if (valido_r(r_divide) == 0){
      printf("DIVISAO INVALIDA\n");
      return (1);
		}
    imprime_r(r_soma);
    imprime_r(r_subtrai);
    imprime_r(r_multiplica);
    imprime_r(r_divide);
    printf("\n");
  }
  return (0) ;
}
