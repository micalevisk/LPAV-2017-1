//
//	[bubblesort.cc]
//	Created by Micael Levi on 04/08/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//

///// dependencies
#include "ordenacaoAnalytics.hpp"
using namespace std;


Analytics analise = Analytics("bubble");

// O(n) ou O(n²)
void _bubblesort(T* v, size_t n){//não altera o 'dados'
	unsigned i, j;
	for(i=0; i < n-1; ++i){
		for(j=0; j < n-1-i; ++j)
			if( v[j] SINAL v[j+1] ){
				analise.incrementar_qtdComparacoes();
				trocarElementos<T>(v[j], v[j+1]);
				analise.incrementar_qtdTrocas();
			}
	}
}


Analytics OrdenacaoAnalytics::analytics_bubblesort(){
	vector<T> copiaDados(dados);
	T* arr = &copiaDados.at(0);
	size_t tam = copiaDados.size();

	analise.iniciarTempo();
	_bubblesort(arr, tam);
	analise.pararTempo();
	#ifdef VERBOSE
		cout << "{depois do Bubble}: "; foreach(arr, tam);//resultado interno
	#endif

	return analise;
}
