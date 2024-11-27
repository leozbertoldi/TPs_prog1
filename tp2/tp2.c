/* 
 * Tipos Abstratos de Dados - TADs
 * Arquivo do programa principal, que usa o TAD racional.
 * Feito em 24/09/2024 para a disciplina CI1001 - Programação 1.
*/

#include <stdio.h>
#include <stdlib.h>
#include "racional.h"

/*Percorre o vetor até achar um inválido e o substitui com o último elemento do vetor*/
void elimina_v_r (struct racional *v, int *n)
{
  struct racional *p;

  for (p = v; p < v + *n; p++) 
    if (valido_r(*p) == 0){
      *p = v[*n-1];
      (*n)--;
      p--;
    }
}

void ordena_v_r (struct racional *v, int *n)
{
  struct racional aux;
  int compara, i, j;
  
  for (i = 0; i < *n - 1; i++){
    for (j = 0; j < *n - i - 1; j++){
      compara = compara_r(v[j], v[j+1]);
      if (compara == 1){
        aux = v[j];
        v[j] = v[j+1];
        v[j+1] = aux;
      }
    }
  }
}

void soma_v_r (struct racional *v, int *n, struct racional *resultado)
{
  struct racional *p, soma;
  
  soma = cria_r(0,1); // cria um racional válido e neutro para a soma
  for (p = v; p < v + *n; p++)
    soma_r(soma, *p, &soma);
  *resultado = soma;
}



int main ()
{
  struct racional v[100], r, resultado;
  struct racional *p;
  int n;
  long num, den;
  
  scanf("%d", &n);
  while (n <= 0 || n >= 100) // garante que 0<n<100
    scanf("%d", &n);

  for (p = v; p < v + n; p++){
    scanf("%ld %ld", &num, &den);
    r = cria_r(num, den);
    *p = r;
  }
  
  printf("VETOR = ");
  for (p = v; p < v + n; p++){
    imprime_r(*p);
    printf(" ");
  }
  printf("\n");

  p = v;
  elimina_v_r(v, &n);
  
  printf("VETOR = ");
  for (p = v; p < v + n; p++){
    imprime_r(*p);
    printf(" ");
  }
  printf("\n");

  p = v;
  ordena_v_r(v, &n);
  
  printf("VETOR = ");
  for (p = v; p < v + n; p++){
    imprime_r(*p);
    printf(" ");
  }
  printf("\n");

  p = v;
  resultado = cria_r(0,1);
  soma_v_r(v, &n, &resultado);
  printf("SOMA = ");
  imprime_r(resultado);  
  printf("\n");
    
  return (0) ;
}
