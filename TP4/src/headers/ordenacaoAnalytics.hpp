//
//	[ordenacaoAnalytics.hpp]
//	Created by Micael Levi on 04/07/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//

#ifndef ORDENACAO_ANALYTICS_HPP
#define ORDENACAO_ANALYTICS_HPP


#include <vector>

///// dependencies
#include "analytics.hpp"
#include "extras.hpp"
#include "unittest.hpp"


#ifdef DESCENDING
	#define SINAL <
#else
	#define DESCENDING false
	#define SINAL >
#endif

/**
 * Classe que contém a implementação de cada algoritmo e as
 * estatísicas da execução dos mesmos sobre a massa de dados.
 */
class OrdenacaoAnalytics {
	std::vector<int> dados;

	//Algoritmos de ordenação:
	Analytics analytics_bubblesort();
	Analytics analytics_selectionsort();
	Analytics analytics_insertionsort();
	Analytics analytics_mergesort();
	Analytics analytics_quicksort();
	Analytics analytics_heapsort();

	public:
		void printDados(char);
		void printDados(){ printDados(' '); }
		OrdenacaoAnalytics(std::vector<int>);
		void executarAlgoritmo(char);

};



#endif
