/* 
 * Tipos Abstratos de Dados - TADs
 * Arquivo de implementação para TAD racional.
 * Feito em 20/09/2024 para a disciplina CI1001 - Programação 1.
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
  return ((rand() % (max - min + 1)) + min); 
}

/* Máximo Divisor Comum entre a e b      */
/* calcula o MDC pelo método de Euclides */
long mdc (long a, long b)
{
  if (b == 0){
    if (a >= 0) // garante que o mdc passado é positivo
      return (a);
    return (-a);
  }
  return mdc(b, a % b);
}

/* Mínimo Múltiplo Comum entre a e b */
/* mmc = (a * b) / mdc (a, b)        */
long mmc (long a, long b)
{
  return ((a*b)/mdc(a, b));
}

/* Recebe um número racional e o simplifica.
 * Por exemplo, ao receber 10/8 deve retornar 5/4.
 * Se ambos numerador e denominador forem negativos, deve retornar um positivo.
 * Se o denominador for negativo, o sinal deve migrar para o numerador.
 * Se r for inválido, devolve-o sem simplificar. */
struct racional simplifica_r (struct racional r)
{
  long divisor;
  
  if (valido_r(r) != 0){
 //se     num+ den- ou num- den-, os valores serão acertados
    if ( ((r.num > 0) && (r.den < 0)) || ((r.num < 0) && (r.den < 0)) ){
      r.num = -r.num;
			r.den = -r.den;
		}
    divisor = mdc(r.num, r.den);
    r.num = r.num/divisor;
    r.den = r.den/divisor;
    return (r);
  }
  return (r);
}

struct racional cria_r (long numerador, long denominador)
{
  struct racional r;
  r.num = numerador;
  r.den = denominador;
  return (r);
}

int valido_r (struct racional r)
{
  if (r.den == 0)
    return (0);
  return (1);
}

struct racional sorteia_r (long min, long max)
{
  struct racional r;
  long numerador, denominador;
  numerador = aleat(min, max);
  denominador = aleat(min, max);
  r = cria_r(numerador, denominador);
  return (simplifica_r(r));
}

void imprime_r (struct racional r)
{
  r = simplifica_r(r);
  if (valido_r(r) == 0) //den = 0
    printf("NaN");
  else if (r.num == 0) // num = 0
    printf("0");
  else if (r.den == 1) // den = 1
    printf("%ld", r.num);
  else 
    printf("%ld/%ld", r.num, r.den); 
}

int compara_r (struct racional r1, struct racional r2)
{
  long minimo, numerador_r1, numerador_r2;

  if (valido_r(r1) == 0 || valido_r(r2) == 0)
    return (-2);
  if ((r1.den < 0) && (r1.num == 0))
    r1.den = -r1.den;
  if ((r2.den < 0) && (r2.num == 0))
    r2.den = -r2.den;
  r1 = simplifica_r(r1);
  r2 = simplifica_r(r2);
  minimo = mmc(r1.den, r2.den);
  numerador_r1 = (r1.num*minimo/r1.den);
  numerador_r2 = (r2.num*minimo/r2.den); 
  if (numerador_r1 > numerador_r2)
    return (1);
  if (numerador_r1 == numerador_r2) 
    return (0);
  return (-1);
}

int soma_r (struct racional r1, struct racional r2, struct racional *r3)
{
  long minimo, num1, num2;

  if (r3 == NULL || valido_r(r1) == 0 || valido_r(r2) == 0)
    return (0);
  minimo = mmc(r1.den, r2.den);
  num1 = (r1.num*minimo/r1.den);
  num2 = (r2.num*minimo/r2.den);
  *r3 = cria_r((num1 + num2), minimo);
  return (1);
}

int subtrai_r (struct racional r1, struct racional r2, struct racional *r3)
{	
  long minimo, num1, num2;
  
  if (r3 == NULL || valido_r(r1) == 0 || valido_r(r2) == 0)
    return (0);
  minimo = mmc(r1.den, r2.den);
  num1 = (r1.num*minimo/r1.den);
  num2 = (r2.num*minimo/r2.den);
  *r3 = cria_r((num1 - num2), minimo);
  return (1);
}

int multiplica_r (struct racional r1, struct racional r2, struct racional *r3)
{
  if (r3 == NULL || valido_r(r1) == 0 || valido_r(r2) == 0)
    return (0);
  *r3 = cria_r((r1.num*r2.num), (r1.den*r2.den));
  return (1);
}

int divide_r (struct racional r1, struct racional r2, struct racional *r3)
{
  if (r3 == NULL || valido_r(r1) == 0 || valido_r(r2) == 0)
    return (0);
  *r3 = cria_r((r1.num*r2.den), (r1.den*r2.num));
  return (1);
}
