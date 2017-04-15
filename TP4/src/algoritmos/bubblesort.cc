//
//	[bubblesort.cc]
//	Created by Micael Levi on 04/08/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//

///// dependencies
#include "ordenacaoAnalytics.hpp"
using namespace std;



/*
ALGORITMO PARA ORDENAÇÃO CRESCENTE O(n) ou O(n²):
// COMPARAÇÕES   = (n^2 - n)/2
// MOVIMENTAÇÕES = 3 * COMPARAÇÕES
-------------------------------------------------------------------------
Recebe:
- um array 'vetor'
- quantidade 'N' de elementos nesse array

Para i de 0 até N-1, faça
	Para j de 0 até (N-1)-i, faça
		Se vetor[j] > vetor[j+1], então
			Swap(vetor[j], vetor[j+1])
-------------------------------------------------------------------------
*/

void bubblesort(int* v, size_t n, Analytics& analise){//não altera o 'dados'
	unsigned i, j;
	for(i=0; i < n-1; ++i){
		for(j=0; j < n-1-i; ++j)
			if( v[j] > v[j+1] ){
				analise.incrementar_qtdComparacoes();
				Extras::trocarElementos<int>(v[j], v[j+1]);
				analise.incrementar_qtdTrocas();
			}
	}
}


Analytics OrdenacaoAnalytics::analytics_bubblesort(){
	int* dadosLidos = readArray();

	Analytics analise = Analytics("bubble", tamanho);
	analise.iniciarTempo();
	bubblesort(dadosLidos, tamanho, analise);
	analise.pararTempo();

	#ifdef VERBOSE
		cout << "{depois do Bubble}: ";
		Extras::imprimirElementos(dadosLidos, tamanho);//resultado interno
	#endif
	#ifdef DEBUG
		vector<int> copiaDados(dadosLidos, dadosLidos + sizeof(dadosLidos)/sizeof(int));
		UnitTest::isSorted<int>(copiaDados);
	#endif

	delete[] dadosLidos;

	return analise;
}
