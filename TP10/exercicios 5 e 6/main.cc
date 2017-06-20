//
//	[main.cc]
//	Created by Micael Levi on 06/19/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//	g++ -std=c++11 -O2 -o testes/main -I../lib ordenacaoAnalytics.cc main.cc algoritmos/quicksort_sequencial.cc -D DEBUG -D VERBOSE -D MILLISECONDS
//

#include <iostream>
#include <cstdio>
using namespace std;

#include "ordenacaoAnalytics.hpp"


int main(int argc, char* argv[])
{
	if(argc != 2) return 1;
	const char* nomeArquivo = argv[1];

	OrdenacaoAnalytics obj(nomeArquivo);

	#ifdef VERBOSE
		cout << "ORIGINAL:";
		obj.printFileData(',');
	#endif

	cout << obj.getAnalytics_quicksort_sequencial();

	return 0;
}
