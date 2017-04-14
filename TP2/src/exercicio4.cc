/**
 * Exercício 4: Diferente
 * @author Micael Levi
 * @date 03/27/2017
 */

#include <cstdio>

bool zero(int num){ return num==0; }
int  decr(int num){ return num-1;  }
int  incr(int num){ return num+1;  }

// 0 => -1 + 1 = 0 = false
// 1 => 0 + 2  = 1 = true
inline bool notZero(int num){ return decr(num) + incr(num); }

bool diferente(int x, int y){
	if(zero(x)) return notZero(y);
	if(zero(y)) return notZero(x);
	return diferente(decr(x), decr(y));
}

void ler_e_executar(){
	unsigned a, b;
	scanf("%u %u", &a, &b);
	if(zero(a)) if(zero(b)) return;
	printf("%s\n", diferente(a, b) ? "SIM" : "NAO");

	ler_e_executar();
}

main()
{
	ler_e_executar();
}
