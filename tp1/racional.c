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
  return ((rand() % (max - min + 1)) + min); 
}

/* Máximo Divisor Comum entre a e b      */
/* calcula o MDC pelo método de Euclides */
long mdc(long a, long b) {
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
    printf("INVALIDO ");
  else if (r.num == 0) // num = 0
    printf("0 ");
  else if (r.den == 1) // den = 1
    printf("%ld ", r.num);
	else if (r.den == -1) // den =-1
		printf("%ld ", -r.num);
  else if (r.num == r.den) // num = den
    printf("1 ");
  else if (r.num == (-1)*r.den) // num oposto de den
    printf("-1 ");
  else if ( (r.num > 0 && r.den < 0) || (r.num < 0 && r.den < 0) ){ //se num+ den- ou num- den-, os valores serão acertados
    r.num = -r.num;
    r.den = -r.den;
    printf("%ld/%ld ", r.num, r.den);
  }
  else 
    printf("%ld/%ld ", r.num, r.den); // último caso, num negativo e den positivo
}

struct racional soma_r (struct racional r1, struct racional r2)
{
  long minimo, num1, num2;
  struct racional r;
  minimo = mmc(r1.den, r2.den);
  num1 = (r1.num*minimo/r1.den); // cálculo do numerador resultante de r1
  num2 = (r2.num*minimo/r2.den); // cálculo do denominador resultante de r2
  r = cria_r((num1 + num2), minimo);
  return (r);
}

struct racional subtrai_r (struct racional r1, struct racional r2)
{	
  long minimo, num1, num2;
  struct racional r;
  minimo = mmc(r1.den, r2.den);
  num1 = (r1.num*minimo/r1.den); // cálculo do numerador resultante de r1
  num2 = (r2.num*minimo/r2.den); // cálculo do numerador resultante de r2
  r = cria_r((num1 - num2), minimo);
  return (r);
}

struct racional multiplica_r (struct racional r1, struct racional r2)
{
  struct racional r;
  r = cria_r((r1.num*r2.num), (r1.den*r2.den));
  return (r);
}

struct racional divide_r (struct racional r1, struct racional r2)
{
  struct racional r;
  r = cria_r((r1.num*r2.den), (r1.den*r2.num));
  return (r);
}
