/**
 * Exercício 3: Fila do Recreio
 * @author Micael Levi
 * @date 07/07/2017
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Elemento {
	int valor;
	int posInicial, posFinal;

	bool operator <(const Elemento& e){
		return valor < e.valor;
	}
};

bool posicoesIguais(Elemento e){ return e.posInicial == e.posFinal; }


void bubbleSort(vector<Elemento>& v){
	unsigned i, j, n = v.size();
	for(i=0; i < n-1; ++i){
		for(j=0; j < n-1-i; ++j)
			if(v[j] < v[j+1]){
				v[j].posFinal   = j+1;
				v[j+1].posFinal = j;

				Elemento aux = v[j];
				v[j]         = v[j+1];
				v[j+1]       = aux;
			}
	}
}

vector<Elemento> criarArrayLer(size_t tam){
	vector<Elemento> vetor(tam);
	for(unsigned i=0; i < tam; ++i){
		Elemento curr;
		cin >> curr.valor;
		curr.posInicial = curr.posFinal = i;
		vetor.at(i) = curr;
	}
	return vetor;
}



main()
{
	int qtdTestes;
	unsigned qtdAlunos, notaAluno;

	cin >> qtdTestes;
	if(qtdTestes <= 0) return 0;

	do{
		qtdTestes--;
		cin >> qtdAlunos;
		vector<Elemento> fila = criarArrayLer(qtdAlunos);
		bubbleSort(fila);//ORDENAR DECRESCENTE
		cout << count_if(fila.begin(), fila.end(), posicoesIguais) << endl;
	}while(qtdTestes > 0);

}
