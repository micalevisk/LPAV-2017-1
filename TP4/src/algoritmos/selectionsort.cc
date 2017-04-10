//
//	[selectionsort.cc]
//	Created by Micael Levi on 04/09/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//

///// dependencies
#include "ordenacaoAnalytics.hpp"
using namespace std;



/*
ALGORITMO PARA ORDENAÇÃO CRESCENTE O(n²) ou O(n²):
// COMPARAÇÕES  = (n^2 - n)/2
// MOVIMETAÇÕES = 3 * (n - 1)
-------------------------------------------------------------------------
Recebe:
- um array 'vetor'
- quantidade 'N' de elementos nesse array

Para i de 0 até N-2, faça
	posMenor := i
	Para j de i+1 até N-1, faça
		Se vetor[j] < vetor[posMenor], então
			posMenor := j

	Se i != posMenor, então
		Swap(vetor[i], vetor[posMenor])
-------------------------------------------------------------------------
*/

void selectionsort(T* v, size_t n, Analytics& analise){//não altera o 'dados'
	for(unsigned i=0; i < n-1; ++i){
		unsigned posPivot = i;//pivot é o menor/maior elemento (depende do tipo de ordenação)
		for(unsigned j=i+1; j < n; ++j){
			if(v[posPivot] SINAL v[j]){
				posPivot = j;
				analise.incrementar_qtdComparacoes();
			}
		}

		if(i != posPivot){
			trocarElementos<T>(v[i], v[posPivot]);
			analise.incrementar_qtdTrocas();
		}
	}
}


Analytics OrdenacaoAnalytics::analytics_selectionsort(){
	vector<T> copiaDados(dados);
	T* arr = &copiaDados.at(0);
	size_t tam = copiaDados.size();

	Analytics analise = Analytics("selection");
	analise.iniciarTempo();
	selectionsort(arr, tam, analise);
	analise.pararTempo();
	#ifdef VERBOSE
		cout << "{depois do Selection}: "; foreach(copiaDados);//resultado interno
	#endif

	return analise;
}
