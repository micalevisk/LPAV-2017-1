//
//	[main.cc]
//	Created by Micael Levi on 04/08/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "ordenacaoAnalytics.hpp"
#include "getopts.hpp"



int main(int argc, char* argv[])
{
	srand(time(NULL));
	Parameters params = GetOpts::getParameters(argc, argv);

	vector<T> v(params.qtdElementos);

	/// Gera e insere os números N aleatórios
	for(unsigned i=0; i < params.qtdElementos; ++i) v.at(i) = rand() % 10;

	OrdenacaoAnalytics obj(v);
	#ifdef VERBOSE
		cout << "VALORES: "; obj.printDados(); cout << '\n';
	#endif


	/// Header do CSV
	cout << "instancia,algoritmo,comparacoes,trocas,tempo\n";//regex: '([0-9]+),([a-zA-Z]+),([^)]+),([^)]+),([^)]+)'

	for(const auto& alg : params.algoritmosUtilizados){
		if(alg.second)
			obj.executarAlgoritmo(alg.first);
	}
	/*
	/// Teste do Selection Sort
	analiseCorrente = obj.analytics_selectionsort();
	if(params.algoritmosUtilizados['a'] || params.algoritmosUtilizados[analiseCorrente.nomeAlgoritmo[0]]){
		//cout << analiseCorrente;
		#ifdef VERBOSE
			cout << "[depois do selection]: ";
			obj.printDados();
			cout << endl;
		#endif
	}
	*/

	/*
	/// Teste do Insertion Sort
	cout << obj.analytics_insertionsort();
	#ifdef VERBOSE
		cout << "[depois do insertion]: ";
		obj.printDados();
		cout << endl;
	#endif

	/// Teste do Merge Sort
	cout << obj.analytics_mergesort();
	#ifdef VERBOSE
		cout << "[depois do merge]: ";
		obj.printDados();
		cout << endl;
	#endif
	*/

	/*XXX check cases
	/// Teste do Quick Sort
	cout << obj.analytics_quicksort();
	#ifdef VERBOSE
		cout << "[depois do quick]: ";
		obj.printDados();
		cout << endl;
	#endif
	*/

	/*FIXME
	/// Teste do Heap Sort
	cout << obj.analytics_heapsort();
	#ifdef VERBOSE
		cout << "[depois do heap]: ";
		obj.printDados();
		cout << endl;
	#endif
	*/

	/*
	/// Teste do Bubble Sort
	cout << obj.analytics_bubblesort();
	#ifdef VERBOSE
		cout << "[depois do bubble]: ";
		obj.printDados();
		cout << endl;
	#endif
	*/





	return 0;
}
