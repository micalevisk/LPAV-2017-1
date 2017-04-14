/**
 * Exercício 1: Menor
 * @author Micael Levi
 * @date 03/27/2017
 */

#include <cstdio>

bool zero(int num){ return num==0; }
int  decr(int num){ return num-1;  }

bool menor(unsigned x, unsigned y){
	if(zero(y)) return false;
	if(zero(x)) return true;
	return menor(decr(x), decr(y));
}

void ler_e_executar(){
	unsigned a, b;
	scanf("%u %u", &a, &b);
	if(zero(a)) if(zero(b)) return;
	printf("%s\n", menor(a, b) ? "SIM" : "NAO");

	ler_e_executar();
}

main()
{
	ler_e_executar();
}




/* OLD
#include <cstdio>
#include <iostream>
using namespace std;

int decr(int i){ return i-1; }
bool zero(int i){ return i == 0; }

bool menor(int x, int y){
	if(zero(y)) return false;
	if(zero(x)) return true;
	return menor(decr(x), decr(y));
}

main()
{
	int x,y;
	while((cin >> x >> y) && (x && y))
		printf(menor(x,y) ? "SIM\n" : "NAO\n");
}
*/
