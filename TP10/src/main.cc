//
//	[main.cc]
//	Created by Micael Levi on 06/19/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//	g++ -std=c++11 -O2 -o testes/main -I./headers ordenacaoAnalytics.cc main.cc algoritmos/quicksort_sequencial.cc -D DEBUG -D VERBOSE
//

#include <iostream>
#include <cstdio>
using namespace std;

#include "ordenacaoAnalytics.hpp"


int main(int argc, char* argv[])
{
	const char* nomeArquivo = argv[1];

	OrdenacaoAnalytics obj(nomeArquivo);

	#ifdef VERBOSE
	cout << "=== ORIGINAL:\n";
	obj.printFileData(',');


	cout << "=== ORDENADO:\n";
	#endif
	obj.getAnalytics_quicksort_sequencial(true);

	return 0;
}
