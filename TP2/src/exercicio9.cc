/**
 * Exercício 9: Somatório dos elementos de uma matriz
 * @author Micael Levi
 * @date 03/27/2017
 */

#include <iostream>
#define isNegative(num) _isNegative((num),(num))
using namespace std;

bool zero(int num){ return num==0; }
int  decr(int num){ return num-1;  }
int  incr(int num){ return num+1;  }

unsigned somar(unsigned x, unsigned y){
	if(zero(y)) return x;
	return somar(incr(x), decr(y));
}

int somaColunas(unsigned j){
	if(zero(j)) return 0;
	int valor; cin >> valor;
	return somar( valor, somaColunas(decr(j)) );
}

int somaLinhas(unsigned i, unsigned j){
	if(zero(i)) return 0;
	int somatorioColunas = somaColunas(j);
	return somar( somatorioColunas, somaLinhas(decr(i), j) );
}

main()
{
	unsigned i,j;
	cin >> i >> j;
	cout << somaLinhas(i,j) << endl;
}
