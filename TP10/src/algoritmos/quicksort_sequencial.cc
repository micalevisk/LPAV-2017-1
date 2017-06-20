//
//	[quicksort_sequencial.cc]
//	Created by Micael Levi on 06/19/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//

#include <iostream>
#include "ordenacaoAnalytics.hpp"

using namespace std;



/*
ALGORITMO PARA ORDENAÇÃO CRESCENTE O(nlogn) ou O(n²):
-------------------------------------------------------------------------
__________________
Rotina_Particionar
	Recebe:
	- um array 'vetor'
	- números 'inicio' e 'fim'

	Se fim <= inicio, então
		Sair da rotina

	i := inicio
	j := fim
	pivot := vetor[(i+j)/2]

	Enquanto i <= j, faça
		Enquanto vetor[i] < pivot, faça
			i := i + 1
		Enquanto vetor[j] > pivot, faça
			j := j - 1
		Se i <= j, então
			Swap(vetor[i], vetor[j])
			i := i + 1
			j := j - 1
	Se j > inicio, então
		Rotina_Particionar(vetor, inicio, j)
	Se i < fim, então
		Rotina_Particionar(vetor, i, fim)
________________
Rotina_Quicksort
	Recebe:
	- um array 'vetor'
	- quantidade 'N' de elementos nesse array

	Rotina_Particionar(vetor, 0, N-1)
-------------------------------------------------------------------------
*/

void particionar(int* v, unsigned inicio, unsigned fim, Analytics& analise){//não altera o 'dados'
	if(fim <= inicio) return;
	int i=inicio, j=fim;
	int pivot = v[(i+j)/2];

	while(i <= j){
		for(; pivot > v[i]; ++i);
		for(; v[j] > pivot; --j);
		if(i <= j){
			Extras::trocarElementos<int>(v[i], v[j]);
			++i; --j;
		}
	}

	if(j > inicio) particionar(v, inicio, j, analise);
	if(i < fim) particionar(v, i, fim, analise);
}

void quicksort(int* array, size_t qtdElementos, Analytics& analise){
	particionar(array, 0, qtdElementos-1, analise);
}


Analytics OrdenacaoAnalytics::getAnalytics_quicksort_sequencial(bool imprimirResultado=false){
	int* dadosLidos = readArrayFromFile();
	Analytics analise = Analytics("quick-sequencial", tamanho);

	analise.iniciarTempo();
	quicksort(dadosLidos, tamanho, analise);
	analise.pararTempo();

	if(imprimirResultado)
		Extras::imprimirElementos(dadosLidos, tamanho);

	#ifdef DEBUG
		vector<int> copiaDados(dadosLidos, dadosLidos + sizeof(dadosLidos)/sizeof(int));
		Extras::isSorted<int>(copiaDados);
	#endif

	delete[] dadosLidos;

	return analise;
}
