/**
 * Exercício 8: Somatório dos elementos de um vetor
 * @author Micael Levi
 * @date 03/27/2017
 */

#include <iostream>
#define isNegative(num) _isNegative((num),(num))
using namespace std;

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


int soma(unsigned i){
	if(zero(i)) return 0;
	int valor; cin >> valor;
	return somar(valor, soma(decr(i)));
}

void ler_e_executar(){
	unsigned qtdElementos; cin >> qtdElementos;
	cout << soma(qtdElementos) << endl;
}

main()
{
	ler_e_executar();
}
