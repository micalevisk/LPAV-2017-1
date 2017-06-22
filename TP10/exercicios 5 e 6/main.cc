//
//	[main.cc]
//	Created by Micael Levi on 06/19/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//
//	g++ -std=c++11 -o main -I../lib ordenacaoAnalytics.cc main.cc algoritmos/quicksort_sequencial.cpp  algoritmos/quicksort_paralelo.cpp -lpthread -D DEBUG -D VERBOSE -D MILLISECONDS

#include <iostream>
#include <cstdio>
using namespace std;

#include "ordenacaoAnalytics.hpp"

//TODO adicionar opção de escolha de algoritmo
int main(int argc, char* argv[])
{
	if(argc != 2){
		fprintf(stdout, "USAGE: ");
		fprintf(stdout, "%s <nome do arquivo com as entradas>\n", argv[0]);
		return 1;
	}

	const char* nomeArquivo = argv[1];

	OrdenacaoAnalytics analise(nomeArquivo);

	#ifdef VERBOSE
		cout << "ORIGINAL:";
		analise.printFileData(',');
	#endif

	// cout << analise.getAnalytics_quicksort_sequencial();
	cout << analise.getAnalytics_quicksort_paralelo();

	return 0;
}
