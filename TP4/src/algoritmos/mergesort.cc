//
//	[mergesort.cc]
//	Created by Micael Levi on 04/10/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//

///// dependencies
#include "ordenacaoAnalytics.hpp"
using namespace std;



/*
ALGORITMO PARA ORDENAÇÃO CRESCENTE O(nlogn) ou O(nlogn):
// COMPARAÇÕES  = n*logn
-------------------------------------------------------------------------
_________________
Rotina_Intercalar
	Recebe:
	- um array 'vetor'
	- um array auxiliar 'vetorAux'
	- números 'inicio', 'fim' e 'meio'

	k := inicio
	i := inicio
	j := meio + 1

	Enquanto i <= meio e j <= fim, faça
		Se vetor[j] > vetor[i], então
			vetorAux[k] := vetor[i]
			i := i - 1
		Senão, faça
			vetorAux[k] := vetor[j]
			j := j + 1
		k := k + 1
	Para i até meio, faça
		vetorAux[k] := vetor[i]
		i := i + 1
		k := k + 1
	Para j até fim, faça
		vetorAux[k] := vetor[j]
		j := j + 1
		k := k + 1
	Para k de inicio até fim, faça
		vetor[k] := vetorAux[k]

___________________
Rotina_MergeInterno
	Recebe:
	- um array 'vetor'
	- um array auxiliar 'vetorAux'
	- números 'inicio' e 'fim'

	Se inicio < fim, então
		meio := piso((inicio + fim) / 2)
		Rotina_MergeInterno(vetor, vetorAux, inicio, meio)
		Rotina_MergeInterno(vetor, vetorAux, meio+1, fim)
		Rotina_Intercalar(vetor, vetorAux, inicio, fim, meio)


_________________
Rotina_MergeSort
	Recebe:
	- um array 'vetor'
	- quantidade 'N' de elementos nesse array

	Criar um array auxiliar 'vetorAux'
	Rotina_MergeInterno(vetor, vetorAux, 0, N-1)
	Liberar vetorAux
-------------------------------------------------------------------------
*/


static void intercalar(T* v, T* vaux, unsigned inicio, unsigned fim, unsigned meio, Analytics& analise){
	unsigned i, j, k;
	k = i = inicio;
	j = meio+1;

	for(; (i <= meio) && (j <= fim); ++k){
		if(v[j] SINAL v[i]){
			vaux[k] = v[i];
			++i;
		}
		else{
			vaux[k] = v[j];
			++j;
		}
		analise.incrementar_qtdComparacoes();
		analise.incrementar_qtdTrocas();
	}

	for(; i <= meio; ++i, ++k){
		vaux[k] = v[i];
	}

	for(; j <= fim; ++j, ++k){
		vaux[k] = v[j];
	}

	for(k=inicio; k <= fim; ++k){
		v[k] = vaux[k];
	}
}

static void mergeInterno(T* v, T* vaux, unsigned inicio, unsigned fim, Analytics& analise){
	if(inicio < fim){
		unsigned meio = (inicio + fim)/2;
		mergeInterno(v, vaux, inicio, meio, analise);
		mergeInterno(v, vaux, meio+1, fim, analise);
		intercalar(v, vaux, inicio, fim, meio, analise);
	}
}



void mergesort(T* v, size_t n, Analytics& analise){//não altera o 'dados'
	T* vaux = (T*) malloc( sizeof(T)*n );
	mergeInterno(v, vaux, 0, n-1, analise);
	free(vaux);
}


Analytics OrdenacaoAnalytics::analytics_mergesort(){
	vector<T> copiaDados(dados);
	T* arr = &copiaDados.at(0);
	size_t tam = copiaDados.size();

	Analytics analise = Analytics("merge");
	analise.iniciarTempo();
	mergesort(arr, tam, analise);
	analise.pararTempo();
	#ifdef VERBOSE
		cout << "{depois do merge}: "; foreach(copiaDados);
	#endif

	return analise;
}
