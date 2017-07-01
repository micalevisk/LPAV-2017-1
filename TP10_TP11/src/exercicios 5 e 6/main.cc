//
//	[main.cc]
//	Created by Micael Levi on 06/19/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//
//	g++ -std=c++11 -o main -I../lib ordenacaoAnalytics.cc main.cc algoritmos/quicksort_sequencial.cpp  algoritmos/quicksort_paralelo.cpp -lpthread -D DEBUG -D VERBOSE -D MILLISECONDS
// FIXME modo de leitura do arquivo e armazenamento dos dados

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#include "ordenacaoAnalytics.hpp"

int main(int argc, char* argv[])
{
	if(argc < 2){
		fprintf(stdout, "USAGE: ");
		fprintf(stdout, "%s <nome do arquivo com as entradas> [-p, --paralelo]\n", argv[0]);
		return 1;
	}

	const char* nomeArquivo = argv[1];

	OrdenacaoAnalytics analise(nomeArquivo);

	#ifdef VERBOSE
		cout << "ORIGINAL:";
		analise.printFileData(',');
	#endif

	if(argc == 3 && (!strcmp(argv[2],"-p") || !strcmp(argv[2],"--paralelo")))
		cout << analise.getAnalytics_quicksort_paralelo();
	else
		cout << analise.getAnalytics_quicksort_sequencial();

	return 0;
}
