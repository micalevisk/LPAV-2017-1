//
//	[main.cc]
//	Created by Micael Levi on 04/08/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//
// http://www.cplusplus.com/doc/tutorial/dynamic/

#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

#include "ordenacaoAnalytics.hpp"
#include "getopts.hpp"


int main(int argc, char* argv[])
{
	srand(time(NULL));
	Parameters params = GetOpts::getParameters(argc, argv);

	if(params.qtdElementos <= 0) return 1;

	OrdenacaoAnalytics obj;

	if(!params.silencioso)
		///Header do CSV
		cout << "algoritmo,instancia,comparacoes,trocas,tempo\n";

	///Aloca dinamicamente o array que armazenará os dados
	int* vetor = new int[params.qtdElementos];// delete[] vetor

	///Gera e insere os N números aleatórios
	for(unsigned i=0; i < params.qtdElementos; ++i) vetor[i] = rand()%10;
	obj.definirDados(vetor, params.qtdElementos);

	#ifdef VERBOSE
		cout << "VALORES: "; obj.printDados();
	#endif

	const auto& nomeAlgorimtos = obj.nomeAlgoritmos;
	bool runAll = params.algoritmosUtilizados['a'];

	if(runAll){
		for(const auto& algoritmo : nomeAlgorimtos)
			obj.executarAlgoritmo(algoritmo);
	}
	else{
		for(const auto& algoritmo : nomeAlgorimtos){
			if(params.algoritmosUtilizados[algoritmo])
				obj.executarAlgoritmo(algoritmo);
		}
	}

	obj.destruirDados();


	return 0;
}
