/**
 * Exercício 6: Soma
 * @author Micael Levi
 * @date 03/27/2017
 */

#include <cstdio>
#define isNegative(num) _isNegative((num),(num))

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

void ler_e_executar(){
	int a, b;
	scanf("%d %d", &a, &b);
	if(zero(a) && zero(b)) return;
	printf("%d\n", somar(a, b));

	ler_e_executar();
}

main()
{
	ler_e_executar();
}
