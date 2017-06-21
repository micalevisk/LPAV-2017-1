//
//	[exercicio3.cpp]
//	Created by Micael Levi on 06/21/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//


/*
g++ -std=c++11 -I../lib exercicio3.cpp -o exercicio3 -lpthread -D MILLISECONDS
./exercicio3 4 < <(echo 32000 ; echo {1..32000})
*/

#include <pthread.h>
#include <cassert>
#include <cstdlib>
#include <iostream>

#include "analytics.hpp"
using namespace std;

struct argThread {
	unsigned indice;///indice da thread no array de threads
	unsigned inicio, fim;///índices do vetor

	argThread(unsigned _indice, unsigned _inicio, unsigned _fim) :
		 indice(_indice)
		,inicio(_inicio)
		,fim(_fim)
	{}
};

//------------------------------------------------//
long long int somatorio = 0;
long long int* soma_parcial = NULL;
int* vetor = NULL;

void* execSomatorio(void*);
//------------------------------------------------//


int main(int argc, char* argv[])
{
	if(argc != 2){
		fprintf(stdout, "USAGE: ");
		fprintf(stdout, "%s <quantidade de threads a serem criadas>\n", argv[0]);
		return 1;
	}

	int qtdThreads = atoi(argv[1]); assert(qtdThreads >= 0);
	int qtdElementosLidos;
	unsigned qtdElementosParaCada;
	pthread_t* arrThreads;
	argThread** arrArgs;

	cin >> qtdElementosLidos;
	Analytics analise(argv[1], qtdElementosLidos);

	vetor = new int[qtdElementosLidos];
	for(unsigned i=0; i < qtdElementosLidos; ++i) cin >> vetor[i];

	qtdElementosParaCada = qtdElementosLidos / qtdThreads;///para cada thread
	arrThreads = new pthread_t[qtdThreads];///armazenar as threads
	arrArgs = new argThread*[qtdThreads];///armazenar um ponteiro para os argumentos
	soma_parcial = new long long int[qtdThreads];///armazenar a soma acumulada por cada thread

	//==========================================================================//
	for(unsigned i=0, inicioCurr=0; i < qtdThreads; ++i){
		unsigned indice = i;
		unsigned inicio = inicioCurr;
		unsigned fim = (i==qtdThreads-1 ? qtdElementosLidos : (inicioCurr + qtdElementosParaCada) ) - 1;

		#ifdef VERBOSE
			fprintf(stderr, "[%u]{ %u , %u }\n", indice, inicio, fim);
		#endif

		soma_parcial[indice] = 0;
		arrArgs[i] = new argThread(indice, inicio, fim);

		inicioCurr = fim + 1;

		analise.iniciarTempo();
		int rc = pthread_create(arrThreads+i, NULL, execSomatorio, arrArgs[i]);
		#ifdef DEBUG
			assert(!rc);///verifica se a thread foi criada com sucesso
		#endif
	}

	for(unsigned i=0; i < qtdThreads; ++i) pthread_join(arrThreads[i], NULL);
	//==========================================================================//

	for(unsigned i=0; i < qtdThreads; ++i) somatorio += soma_parcial[i];

	analise.pararTempo();
	cout << analise;///<qtdThreads>,<qtdElementos>,<tempoExecucao>

	#ifdef DEBUG
		cout << somatorio << endl;
	#endif

	///fim
	pthread_exit(NULL);

	exit(EXIT_SUCCESS);
}


///função executada por cada thread criada
void* execSomatorio(void* arg){
	argThread* dados = (argThread*)arg;

	unsigned indice = dados->indice;
	unsigned inicio = dados->inicio;
	unsigned fim    = dados->fim;
	long long int somatorioLocal = 0;

	for(unsigned i=inicio; i <= fim; ++i){
		somatorioLocal += vetor[i];
	}

	soma_parcial[indice] = somatorioLocal;

	pthread_exit(NULL);
}
