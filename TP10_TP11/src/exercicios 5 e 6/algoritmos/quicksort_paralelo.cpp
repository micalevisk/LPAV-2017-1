//
//	[quicksort_paralelo.cpp]
//	Created by Micael Levi on 06/21/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//

//TODO inserir threads

#include <iostream>
#include <pthread.h>
#include "../ordenacaoAnalytics.hpp"

using namespace std;


struct argThread {
	int* v;
	unsigned inicio, fim;

	argThread(int* _v, unsigned _inicio, unsigned _fim) :
		 v(_v)
		,inicio(_inicio)
		,fim(_fim)
	{}
};


void* particionar(void* arg){//não altera o 'dados'
	argThread* args = (argThread*)arg;
	int* v = args->v;
	unsigned inicio = args->inicio;
	unsigned fim = args->fim;

	if(fim <= inicio) return NULL;
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

	free(args);
	if(j > inicio){
		args = new argThread(v, inicio, j);
		particionar((void*)args);
	}
	if(i < fim){
		//FIXME criar thread aqui e dar join
		args = new argThread(v, i, fim);
		pthread_t thread;
		int rc = pthread_create(&thread, NULL, particionar, (void*)args);
		#ifdef DEBUG
			assert(!rc);
		#endif
		pthread_join(thread, NULL);
		// args = new argThread(v, i, fim);
		// particionar((void*)args);
	}
}

static void quicksort(int* array, size_t qtdElementos){
	argThread* args = new argThread(array, 0, qtdElementos-1);
	particionar((void*)args);
}


Analytics OrdenacaoAnalytics::getAnalytics_quicksort_paralelo(){
	int* dadosLidos = readArrayFromFile();
	Analytics analise = Analytics("quick-paralelo", tamanho);

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
