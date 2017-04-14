/**
 * Exercício 1: M-Alternado
 * @author Micael Levi
 * @date 03/17/2017
 */

#include <iostream>
#include <vector>
#include <queue>

#define FIM_CASO { cout << "NAO\n"; goto fim_caso_teste; }
#define nop cout

using namespace std;

template<typename T, class UnaryPredicate>
	bool existe(const vector<int>& v, UnaryPredicate pred){
		typename vector<int>::const_iterator first = v.begin(), last = v.end();
		for(; first!=last; ++first) if( pred(*first) ) return true;
		return false;
}
template<typename T>
	inline T desempilhar(queue<int>& p){ T e = p.front(); p.pop(); return e; }

bool isOdd (int i){ return i % 2; }
bool isEven(int i){ return i % 2 == 0; }

// ======================= MAIN ======================= //
main()
{
	int n;
	unsigned x, count;

	while(cin >> n && n > 0){
		queue<int> valores;
		/// ler todos os dados do caso teste
		do{
			cin >> x; valores.push(x);
			--n;
		}while(n > 0);

		bool ehImpar;//indica a paridade da sequência corrente
		ehImpar = !(desempilhar<int>(valores) % 2);//determina a paridade da segunda sequência (inverso da primeira)

		count=2;
		/// dividir os segmentos verificando se houve alguma divisão incorreta (admite que n > 1)
		do{
			vector<int> seq;//armazena os valores da sequência corrente (deverá ter tamanho 'count')
			for(unsigned i=0; i<count; ++i){//itera sob a pilha para armazenar a sequência corrente
				//sequência de tamanho inválido
				if(valores.empty())	FIM_CASO;
				seq.push_back(desempilhar(valores));
			}
			//se a sequência corrente deve conter só ímpares, procura pelo primeiro número par
			if( find(seq.begin(), seq.end(), (ehImpar) ? isEven:isOdd) ) FIM_CASO;

			ehImpar = !ehImpar;
			++count;
		}while(!valores.empty());
		cout << --count << endl;

		fim_caso_teste: nop;
	}
}
