/* 
 * Tipos Abstratos de Dados - TADs
 * Arquivo de implementação para TAD racional.
 * Feito em 16/09/2024 para a disciplina CI1001 - Programação 1.
 *
 * Este arquivo deve conter as implementações das funções cujos protótipos
 * foram definidos em racional.h. Neste arquivo também podem ser definidas
 * funções auxiliares para facilitar a implementação daquelas funções.
*/

#include <stdio.h>
#include <stdlib.h>
#include "racional.h"

/* retorna um número aleatório entre min e max, inclusive. */
long aleat (long min, long max)
{
  return ((rand() % ((2*max) + 1)) - max); 
}

/* Máximo Divisor Comum entre a e b      */
/* calcula o MDC pelo método de Euclides */
long mdc (long a, long b)
{
  /* implemente aqui */
}

/* Mínimo Múltiplo Comum entre a e b */
/* mmc = (a * b) / mdc (a, b)        */
long mmc (long a, long b)
{
  /* implemente aqui */
}

/* Recebe um número racional e o simplifica.
 * Por exemplo, ao receber 10/8 deve retornar 5/4.
 * Se ambos numerador e denominador forem negativos, deve retornar um positivo.
 * Se o denominador for negativo, o sinal deve migrar para o numerador.
 * Se r for inválido, devolve-o sem simplificar. */
struct racional simplifica_r (struct racional r)
{
  /* implemente aqui */
}

struct racional cria_r (long numerador, long denominador);
{
  numerador = aleat(-max, max);
  denominador = aleat(-max, max);
}

int valido_r (struct racional r);
{

}

struct racional sorteia_r (long min, long max);
{

}

void imprime_r (struct racional r);
{

}

struct racional soma_r (struct racional r1, struct racional r2);
{

}

struct racional subtrai_r (struct racional r1, struct racional r2);
{

}

struct racional multiplica_r (struct racional r1, struct racional r2);
{
	
}

struct racional divide_r (struct racional r1, struct racional r2);
{

}
