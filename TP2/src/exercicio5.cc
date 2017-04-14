/**
 * Exercício 5: Simétrico
 * @author Micael Levi
 * @date 03/27/2017
 */

#include <cstdio>
#define isNegative(num) _isNegative((num),(num))

bool zero(int num){ return num==0; }
int  decr(int num){ return num-1;  }
int  incr(int num){ return num+1;  }

/**
 * @param a - Será incrementado de 1
 * @param b - Será decrementado de 1
 * @return Se 'a' chegar a 0 antes de 'b' então TRUE, senão FALSE
 */
bool _isNegative(int a, int b){
	if(zero(a)) return true;
	if(zero(b)) return false;
	return _isNegative(incr(a), decr(b));// num >> INT_QTD_BITS-1
}

template <class UnaryPredicate>
int simetrico(int num, int contador, UnaryPredicate pred){
  if(zero(num)) return contador;
  return simetrico(pred(num), pred(contador), pred);
}


void ler_e_executar(){
	int num;
	scanf("%d", &num);
	if(zero(num)) return;
	if(isNegative(num)) printf("%d\n", simetrico(num, 0, incr));
	else printf("%d\n", simetrico(num, 0, decr));

	ler_e_executar();
}

main()
{
	ler_e_executar();
}
