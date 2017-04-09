//
//	[selection.cc]
//	Created by Micael Levi on 04/09/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//

///// dependencies
#include "ordenacaoAnalytics.hpp"
using namespace std;


Analytics analiseSelection = Analytics("selection");

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

void selectionsort(T* v, size_t n){//não altera o 'dados'
	for(unsigned i=0; i < n-1; ++i){
		unsigned posPivot = i;//pivot é o menor/maior elemento (depende do tipo de ordenação)
		for(unsigned j=i+1; j < n; ++j){
			if(v[posPivot] SINAL v[j]){
				posPivot = j;
				analiseSelection.incrementar_qtdComparacoes();
			}
		}

		if(i != posPivot){
			trocarElementos<T>(v[i], v[posPivot]);
			analiseSelection.incrementar_qtdTrocas();
		}
	}
}


Analytics OrdenacaoAnalytics::analytics_selectionsort(){
	vector<T> copiaDados(dados);
	T* arr = &copiaDados.at(0);
	size_t tam = copiaDados.size();

	analiseSelection.iniciarTempo();
	selectionsort(arr, tam);
	analiseSelection.pararTempo();
	#ifdef VERBOSE
		cout << "{depois do Selection}: "; foreach(arr, tam);//resultado interno
	#endif

	return analiseSelection;
}
