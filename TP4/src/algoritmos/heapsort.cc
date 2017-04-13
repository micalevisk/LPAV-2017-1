//
//	[heapsort.cc]
//	Created by Micael Levi on 04/10/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//


///// dependencies
#include "ordenacaoAnalytics.hpp"
using namespace std;



/*
ALGORITMO PARA ORDENAÇÃO CRESCENTE O(nlogn) ou O(nlogn):
// COMPARAÇÕES  = 2*n*logn+2*n
-------------------------------------------------------------------------
______________
Rotina_Heapify
	Recebe:
	- um array 'vetor'
	- números 'pai' e 'posUltimo'

	eqs := 2 * pai + 1
	dir := esq + 1
	posMaior := pai

	Se esq < posUltimo, então
		Se vetor[esq] > vetor[pai], então
			posMaior := esq
		Se dir <= posUltimo e vetor[dir] > vetor[posMaior], então
			posMaior := dir
	Se posMaior != pai, então
		Swap(vetor[posMaior], vetor[pai])
		Rotina_Heapify(vetor, posMaior, posUltimo)

________________
Rotina_BuildHeap
	Recebe:
	- um array 'vetor'
	- quantidade 'N' de elementos nesse array

	Para i de (N-1)/2 até 0, faça
		Rotina_Heapify(vetor, i, n-1)

_______________
Rotina_Heapsort
	Recebe:
	- um array 'vetor'
	- quantidade 'N' de elementos nesse array

	Rotina_BuildHeap(vetor, N)
	Para i de N-1 até 1, faça
		Swap(vetor[i], vetor[0])
		i := i - 1
		Rotina_Heapify(vetor, 0, i)
-------------------------------------------------------------------------
*/


void heapify(int* v, long int pai, int posUltimo, Analytics& analise){
	long int esq, dir, posMaior;
	esq = 2*pai + 1;
	dir = esq + 1;
	posMaior = pai;

	if((esq <= posUltimo) && (v[esq] > v[posMaior])){
		posMaior = esq;
		analise.incrementar_qtdComparacoes();
	}
	if((dir <= posUltimo) && (v[dir] > v[posMaior])){
		posMaior = dir;
		analise.incrementar_qtdComparacoes();
	}

	if(posMaior != pai){
		Extras::trocarElementos<int>(v[pai], v[posMaior]);
		analise.incrementar_qtdTrocas();
	}

}

void buildHeap(int* v, unsigned n, Analytics& analise){
	for(int i=(n-1)/2; i >= 0; --i)
		heapify(v, i, n-1, analise);
}


void heapsort(int* v, unsigned n, Analytics& analise){
	buildHeap(v, n, analise);
	for(int i=n-1; i > 0;){
		Extras::trocarElementos<int>(v[i], v[0]);
		analise.incrementar_qtdTrocas();
		heapify(v, 0, --i, analise);
	}
}


Analytics OrdenacaoAnalytics::analytics_heapsort(){
	vector<int> copiaDados(dados);
	int* arr = &copiaDados.at(0);
	size_t tam = copiaDados.size();

	Analytics analise = Analytics("heap", tam);
	analise.iniciarTempo();
	heapsort(arr, tam, analise);
	analise.pararTempo();
	#ifdef VERBOSE
		cout << "{depois do heap}: "; Extras::imprimirElementos(copiaDados.begin(), copiaDados.end());//resultado interno
	#endif
	#ifdef DEBUG
		UnitTest::isSorted<int>(copiaDados, DESCENDING);
	#endif

	return analise;
}
