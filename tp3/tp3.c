/* 
 * Tipos Abstratos de Dados - TADs
 * Arquivo do programa principal, que usa o TAD racional.
 * Feito em 24/09/2024 para a disciplina CI1001 - Programação 1.
*/

#include <stdio.h>
#include <stdlib.h>
#include "racional.h"

/*Percorre o vetor até achar um inválido e o substitui com o último elemento do vetor*/
void elimina_v_r (struct racional **v, int *n)
{
  int i;

  for (i = 0; i < *n; i++) 
    if (valido_r(v[i]) == 0)
    {
      *v[i] = *v[*n-1]; 
      destroi_r(v[*n-1]);
      v[*n-1] = NULL;
      (*n)--;
      i--;
    }
}

void ordena_v_r (struct racional **v, int *n)
{
  struct racional aux;
  int compara, i, j;
  
  for (i = 0; i < *n - 1; i++){
    for (j = 0; j < *n - i - 1; j++){
      compara = compara_r(v[j], v[j+1]);
      if (compara == 1){
        aux = *(v[j]);
        *(v[j]) = *(v[j+1]);
        *(v[j+1]) = aux;
      }
    }
  }
}

void soma_v_r (struct racional **v, int *n, struct racional *resultado)
{
  int i;

  resultado->num = 0;
  resultado->den = 1;
  for (i = 0; i < *n; i++)
  {
    soma_r(resultado, v[i], resultado);
  }
}

int main ()
{
  int i, n;
	long int num, den;
  struct racional *total, **v;

  scanf("%d", &n);
  while (n <= 0 || n >= 100)
    scanf("%d", &n);

  v = malloc(n * sizeof(struct racional *));
  if (!v)
    return (1);

  for (i = 0; i < n; i++)
  {
    scanf("%ld %ld", &num, &den);
    v[i] =  cria_r(num, den);
  }

  printf("VETOR = ");
  for (i = 0; i < n - 1; i++)
  {
    imprime_r(v[i]);
    printf(" ");
  }
  imprime_r(v[n-1]);
  printf("\n");

  elimina_v_r(v, &n);
  printf("VETOR =");
  if (n == 0)
    printf(" ");
  for (i = 0; i < n; i++)
  {
    printf(" ");
    imprime_r(v[i]);
  }
  printf("\n");
  
  ordena_v_r(v, &n);
  printf("VETOR =");
  if (n == 0)
    printf(" ");
  for (i = 0; i < n; i++)
  {
    printf(" ");
    imprime_r(v[i]);
  }
  printf("\n");

  total = malloc(sizeof(struct racional));
  if (!total)
    return (1);
  soma_v_r(v, &n, total);
  printf("SOMA = ");
  imprime_r(total);
  printf("\n");
  
  printf("VETOR = ");
  if (n != 0)
  {
    for (i = n-1; i >= 0; i--)
    {
      destroi_r(v[i]);
      v[i] = NULL;
    }
    for (i = 0; i < n - 1; i++)
    {
      if (v[i] == NULL)
      {
        printf("NULL");
        printf(" ");
      }
    }
    if (v[n-1] == NULL)
      printf("NULL");
  }
  printf("\n");
  free(v);
  destroi_r(total);
  total = NULL;
  
  return (0) ;
}
