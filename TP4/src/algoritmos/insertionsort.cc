//
//	[insertionsort.cc]
//	Created by Micael Levi on 04/10/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//

///// dependencies
#include "ordenacaoAnalytics.hpp"
using namespace std;



/*
ALGORITMO PARA ORDENAÇÃO CRESCENTE O(n) ou O(n²):
// COMPARAÇÕES  = (n^2 - n)/2
-------------------------------------------------------------------------
Recebe:
- um array 'vetor'
- quantidade 'N' de elementos nesse array

Para i de 1 até N-1, faça
	pivot := vetor[i]
	Enquanto j >= 0 e vetor[j] > pivot, faça
		vetor[j+1] := v[j]
		j := i - 1
	vetor[j+1] := pivot
-------------------------------------------------------------------------
*/

void insertionsort(int* v, size_t n, Analytics& analise){//não altera o 'dados'
	int pivot;
	for(int i=1, j; i < n; ++i){
		pivot = v[i];
		j = i-1;

		for(; (j >= 0) && (v[j] > pivot); --j){
			v[j+1] = v[j];
			analise.incrementar_qtdComparacoes();
			analise.incrementar_qtdTrocas();
		}
		v[j+1] = pivot;
	}
}


Analytics OrdenacaoAnalytics::analytics_insertionsort(){
	vector<int> copiaDados(dados);
	int* arr = &copiaDados.at(0);
	size_t tam = copiaDados.size();

	Analytics analise = Analytics("insertion", tam);
	analise.iniciarTempo();
	insertionsort(arr, tam, analise);
	analise.pararTempo();
	#ifdef VERBOSE
		cout << "{depois do insertion}: "; Extras::imprimirElementos(copiaDados.begin(), copiaDados.end());//resultado interno
	#endif
	#ifdef DEBUG
		UnitTest::isSorted<int>(copiaDados);
	#endif

	return analise;
}
