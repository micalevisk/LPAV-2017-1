//
//	[quicksort_sequencial.cpp]
//	Created by Micael Levi on 06/19/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//

//FIXME seg fault para uma instância de 100

#include <iostream>
#include "../ordenacaoAnalytics.hpp"

using namespace std;


void particionar(int* v, unsigned inicio, unsigned fim){//não altera o 'dados'
	if(fim <= inicio) return;
	int i=inicio, j=fim;
	int pivot = v[(i+j)/2];

	while(i < j){
		while(v[i] <= pivot) i++;
		while(v[j] > pivot)  j--;
		if(i < j){
			int aux = v[i];
			v[i]    = v[j];
			v[j]    = aux;
		}
	}

	if(j > inicio) particionar(v, inicio, j);
	if(i < fim) particionar(v, i, fim);
}

static void quicksort(int* array, size_t qtdElementos){
	particionar(array, 0, qtdElementos-1);
}


Analytics OrdenacaoAnalytics::getAnalytics_quicksort_sequencial(){
	int* dadosLidos = readArrayFromFile();
	Analytics analise = Analytics("quick-sequencial", tamanho);

	analise.iniciarTempo();
	quicksort(dadosLidos, tamanho);
	analise.pararTempo();

	#ifdef VERBOSE
		cout << "ORDENADO:";
		Extras::imprimirElementos(dadosLidos, tamanho);
	#endif

	#ifdef DEBUG
		vector<int> copiaDados(dadosLidos, dadosLidos + sizeof(dadosLidos)/sizeof(int));
		Extras::isSorted<int>(copiaDados);
	#endif

	delete[] dadosLidos;

	return analise;
}
