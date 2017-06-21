/*
gcc -std=gnu11 exercicio1.c -o exercicio1 -lpthread
./exercicio1 4 < <(echo 32000 ; echo {1..32000})
echo {1..32000} | tr ' ' '+' | bc
*/

#include <stdio.h>
#include <pthread.h>
#include <assert.h>
#include <stdlib.h>

typedef struct  __myargs {
	unsigned id;
	unsigned inicio, fim;///índices do vetor
} argThread ;

//------------------------------------------------//
long long int somatorio = 0;
int* vetor = NULL;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
//------------------------------------------------//

void* execSomatorio(void*);


int main(int argc, char* argv[])
{
	if(argc != 2) return 1;

	int qtdThreads = atoi(argv[1]);
	int qtdElementosLidos;
	unsigned qtdElementosParaCada;
	pthread_t* arrThreads;
	argThread** arrArgs;

	fscanf(stdin, "%d", &qtdElementosLidos);
	vetor = malloc(sizeof(int) * qtdElementosLidos);
	for(unsigned i=0; i < qtdElementosLidos; ++i){
		int curr;
		fscanf(stdin, "%d", &curr);
		vetor[i] = curr;
	}

	///
	qtdElementosParaCada = qtdElementosLidos / qtdThreads;
	arrThreads = malloc(sizeof(pthread_t) * qtdThreads);
	arrArgs = malloc(sizeof(argThread*) * qtdThreads);

	//==========================================================================//
	for(unsigned i=0, inicioCurr=0; i < qtdThreads; ++i){
		arrArgs[i] = malloc(sizeof(argThread));
		arrArgs[i]->id = i;
		arrArgs[i]->inicio = inicioCurr;
		arrArgs[i]->fim    = (i==qtdThreads-1 ? qtdElementosLidos : (inicioCurr + qtdElementosParaCada) ) - 1 ;

		#ifdef DEBUG
			fprintf(stderr, "[%u]{ %u , %u }\n", i, inicioCurr, inicioCurr + qtdElementosParaCada -1 );
		#endif

		inicioCurr = arrArgs[i]->fim + 1;

		int rc = pthread_create(arrThreads+i, NULL, execSomatorio, arrArgs[i]);
		assert(!rc);
	}

	for(unsigned i=0; i < qtdThreads; ++i) pthread_join(arrThreads[i], NULL);
	//==========================================================================//

	printf("%lld\n", somatorio);///resultado final
}



void* execSomatorio(void* arg){
	argThread* dados = (argThread*)arg;

	unsigned id     = dados->id;
	unsigned inicio = dados->inicio;
	unsigned fim    = dados->fim;

	for(unsigned i=inicio; i <= fim; ++i){
		pthread_mutex_lock(&mutex);
		somatorio += vetor[i];
		pthread_mutex_unlock(&mutex);
	}
}
