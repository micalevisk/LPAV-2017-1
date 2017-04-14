/**
 * Exercício 3: Jogo - Contando
 * @author Micael Levi
 * @date 03/20/2017
 */

#include <bits/stdc++.h> // LIBS: iostream, string, vector, sstream
using namespace std;

/// ------ GLOBAIS ------ ///
int qtdPessoas;
unsigned pessoa, linha;
/// -------------------- ///

void initGlobais(){ linha = 0; pessoa = 1; }

string intToString(int number){	stringstream aux;	aux << number;	return aux.str(); }
bool contemSete(int n){ return (intToString(n).find("7") != string::npos); }
bool numeroValido(int num){ return (num%7==0 || contemSete(num)); }

void proximaPessoa(){
	linha += ((pessoa == 1) || (pessoa >= qtdPessoas));//só incrementa 1 se a pessoa da vez for um dos extremos
	pessoa += (linha % 2 ? 1 : -1);//se a próxima linha for ímpar então soma com 1, senão subtrai de 1
}

main()
{
	int pessoaBuscada;
	unsigned k;
	while((cin >> qtdPessoas) && (qtdPessoas > 0)){
		cin >> pessoaBuscada >> k;

		unsigned seq;
		for(seq=1, initGlobais(); k > 0; ++seq, proximaPessoa()){
			if(pessoa == pessoaBuscada)
				k -= numeroValido(seq);
		}

		cout << --seq << endl;
	}
}
