//
//	[ordenacaoAnalytics.hpp]
//	Created by Micael Levi on 04/07/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//

#ifndef ORDENACAO_ANALYTICS_HPP
#define ORDENACAO_ANALYTICS_HPP



///// dependencies
#include "analytics.hpp"
#include "extras.hpp"

#include <iostream>
#include <vector>


#ifndef T
	#define T int
#endif

#ifdef DECRESCENTE
	#define SINAL <
#else
	#define SINAL >
#endif

class OrdenacaoAnalytics {
	std::vector<T> dados;

	public:
		void printDados();//for tests
		OrdenacaoAnalytics(std::vector<T>);

		//Algoritmos de ordenação:
		Analytics analytics_bubblesort();
		Analytics analytics_selectionsort();
		Analytics analytics_insertionsort();
};



#endif
