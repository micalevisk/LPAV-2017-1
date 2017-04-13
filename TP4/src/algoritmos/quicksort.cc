//
//	[quicksort.cc]
//	Created by Micael Levi on 04/10/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//
//TODO implementar versão ordem decrescente


///// dependencies
#include "ordenacaoAnalytics.hpp"
using namespace std;



/*
ALGORITMO PARA ORDENAÇÃO CRESCENTE O(nlogn) ou O(n²):
// COMPARAÇÕES  = 2*nlogn
// MOVIMETAÇÕES = (1/3)*nlogn
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
		for(; pivot > v[i]; ++i) analise.incrementar_qtdComparacoes();
		for(; v[j] > pivot; --j) analise.incrementar_qtdComparacoes();
		if(i <= j){
			Extras::trocarElementos<int>(v[i], v[j]);
			++i; --j;
			analise.incrementar_qtdTrocas();
		}
	}

	if(j > inicio) particionar(v, inicio, j, analise);
	if(i < fim) particionar(v, i, fim, analise);
}

void quicksort(int* v, size_t n, Analytics& analise){
	particionar(v, 0, n-1, analise);
}

Analytics OrdenacaoAnalytics::analytics_quicksort(){
	vector<int> copiaDados(dados);
	int* arr = &copiaDados.at(0);
	size_t tam = copiaDados.size();

	Analytics analise = Analytics("quick", tam);
	analise.iniciarTempo();
	quicksort(arr, tam, analise);
	analise.pararTempo();
	#ifdef VERBOSE
		cout << "{depois do quick}: "; Extras::imprimirElementos(copiaDados.begin(), copiaDados.end());//resultado interno
	#endif
	#ifdef DEBUG
		UnitTest::isSorted<int>(copiaDados);
	#endif

	return analise;
}
