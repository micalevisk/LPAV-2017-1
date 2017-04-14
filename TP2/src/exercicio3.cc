/**
 * Exercício 3: Igual
 * @author Micael Levi
 * @date 03/27/2017
 */

#include <cstdio>

bool zero(int num){ return num==0; }
int  decr(int num){ return num-1;  }

bool igual(unsigned x, unsigned y){
	if(zero(x)) return zero(y);
	if(zero(y)) return false;
	return igual(decr(x), decr(y));
}

void ler_e_executar(){
	unsigned a, b;
	scanf("%u %u", &a, &b);
	if(zero(a)) if(zero(b)) return;
	printf("%s\n", igual(a, b) ? "SIM" : "NAO");

	ler_e_executar();
}

main()
{
	ler_e_executar();
}
