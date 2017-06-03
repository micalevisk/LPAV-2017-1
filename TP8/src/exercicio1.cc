/**
 * Exercício 1: Revisão de Contrato
 * @author Micael Levi
 * @date 02/06/2017
 */

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isNotZero(string str){return str.compare("0");}
bool isNotZero(char ch){return ch - '0';}

// http://www.cplusplus.com/reference/string/string/erase/
// http://www.cplusplus.com/reference/algorithm/remove/
string removeCharFrom(string str, char ch){
	str.erase(
		remove( str.begin(), str.end(), ch )
		,str.end()
	);
	return str.empty() ? "0" : str;
}


main()
{
	char D;///dígito que está com problema na máquina
	string N;///número que foi negociado originalmente

	while((cin >> D) && (cin >> N) && isNotZero(D) && isNotZero(N)){
		string corrigido = removeCharFrom(N, D);
		cout << stoul( corrigido.c_str() ) << endl;
	}
}
