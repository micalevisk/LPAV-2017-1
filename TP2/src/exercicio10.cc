/**
 * Exercício 10: Palíndromo
 * @author Micael Levi
 * @date 03/27/2017
 */

#include <iostream>
#include <string>
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

bool igual(int x, int y){
	if(zero(x)) return zero(y);
	if(zero(y)) return false;
	return igual(decr(x), decr(y));
}
bool is123(string input){ return igual(input[0],'1') && igual(input[1],'2') && igual(input[2],'3') && igual(input[3],'\0'); }


bool maior_naturais(unsigned x, unsigned y){// para comparar os ASCIIs (números positivos)
	if(zero(x)) return false;
	if(zero(y)) return true;
	return maior_naturais(decr(x), decr(y));
}


bool isPalindromo(string str, int inicio, int fim){
	if( igual(inicio, fim) || maior_naturais(inicio, fim) ) return true;
	if( !igual(str[inicio], str[fim]) ) return false;
	return isPalindromo(str, incr(inicio), decr(fim));
}


void ler_e_executar(){
	string palavra; cin >> palavra;
	if( is123(palavra) || !palavra.length() ) return;
	string ehPalindromo = isPalindromo(palavra, 0, decr(palavra.length())) ? "SIM" : "NAO";
	cout << ehPalindromo << endl;

	ler_e_executar();
}

main()
{
	ler_e_executar();
}


/*
bool isNegative(int num){
	//unsigned deslocar = sizeof(num)*8 - 1;
	return (num >> 31);//verifica se o MSB é 1, i.e., o número é negativo
}

bool maior(int x, int y){
	if(isNegative(x))
			if(isNegative(y))// x e y são < 0
				return zero( maior_naturais(x*-1,y*-1) );
	// y é < 0 mas x > 0, logo x > y
	if(isNegative(y)) return true;
	return maior(x,y);
}
*/
