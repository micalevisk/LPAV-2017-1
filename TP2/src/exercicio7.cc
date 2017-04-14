/**
 * Exercício 7: Multiplicação
 * @author Micael Levi
 * @date 03/27/2017
 */

#include <cstdio>
#define isNegative(num) _isNegative((num),(num))
#define asPositive(num) _simetrico((num),0,incr)

bool zero(int num){ return num==0; }
int  decr(int num){ return num-1;  }
int  incr(int num){ return num+1;  }

bool _isNegative(int a, int b){
	if(zero(a)) return true;
	if(zero(b)) return false;
	return _isNegative(incr(a), decr(b));
}

int somar(int x, int y){
	if(zero(y)) return x;
	if(isNegative(y)) return somar(decr(x), incr(y));
	return somar(incr(x), decr(y));
}

bool igual(unsigned x, unsigned y){
	if(zero(x)) return zero(y);
	if(zero(y)) return false;
	return igual(decr(x), decr(y));
}

template <class UnaryPredicate>
int _simetrico(int num, int counter, UnaryPredicate pred){
  if(zero(num)) return counter;
  return _simetrico(pred(num), pred(counter), pred);
}


int multiplicar(int acum, int counter){
	if(zero(counter)) return 0;
	return somar( acum, multiplicar(acum, decr(counter)) );
}


void ler_e_executar(){
	int a, b;
	scanf("%d %d", &a, &b);
	if(zero(a) && zero(b)) return;

	if(isNegative(a) && isNegative(b)) printf("%d\n", multiplicar(asPositive(a), asPositive(b)));
	else if(isNegative(a)) printf("%d\n", multiplicar(a, b)); // b é o contador
	else printf("%d\n", multiplicar(b, a)); // a é o contador

	ler_e_executar();
}

main()
{
	ler_e_executar();
}
