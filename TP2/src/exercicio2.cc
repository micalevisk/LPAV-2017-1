/**
 * Exercício 2: Maior
 * @author Micael Levi
 * @date 03/27/2017
 */

#include <cstdio>

bool zero(int num){ return num==0; }
int  decr(int num){ return num-1;  }

bool maior(unsigned x, unsigned y){
	if(zero(x)) return false;
	if(zero(y)) return true;
	return maior(decr(x), decr(y));
}

void ler_e_executar(){
	unsigned a, b;
	scanf("%u %u", &a, &b);
	if(zero(a)) if(zero(b)) return;
	printf("%s\n", maior(a, b) ? "SIM" : "NAO");

	ler_e_executar();
}

main()
{
	ler_e_executar();
}
