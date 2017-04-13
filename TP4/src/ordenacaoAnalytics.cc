//
//	[ordenacaoAnalytics.cc]
//	Created by Micael Levi on 04/07/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//

#include <iostream>

///// dependencies
#include "ordenacaoAnalytics.hpp"


OrdenacaoAnalytics::OrdenacaoAnalytics(std::vector<T> _dados){
	dados = _dados;
}


void OrdenacaoAnalytics::printDados(char sep){
	Extras::foreach(dados, sep);
}

void OrdenacaoAnalytics::executarAlgoritmo(char inicial){
	switch (inicial) {
		///////////// BUBBLE
		case 'b':{
			std::cout << analytics_bubblesort();
			#ifdef VERBOSE
				std::cout << "[depois do bubble]: ";
				printDados('_');
				std::cout << '\n';
			#endif
			break;
		}

		///////////// SELECTION
		case 's':{
			std::cout << analytics_selectionsort();
			#ifdef VERBOSE
				std::cout << "[depois do selection]: ";
				printDados('_');
				std::cout << '\n';
			#endif
			break;
		}

		///////////// INSERTION
		case 'i':{
			std::cout << analytics_insertionsort();
			#ifdef VERBOSE
				std::cout << "[depois do insertion]: ";
				printDados('_');
				std::cout << '\n';
			#endif
			break;
		}

		///////////// MERGE
		case 'm':{
			std::cout << analytics_mergesort();
			#ifdef VERBOSE
				std::cout << "[depois do merge]: ";
				printDados('_');
				std::cout << '\n';
			#endif
			break;
		}

		///////////// QUICK
		case 'q':{
			std::cout << analytics_quicksort();
			#ifdef VERBOSE
				std::cout << "[depois do quick]: ";
				printDados('_');
				std::cout << '\n';
			#endif
			break;
		}

		///////////// HEAP
		case 'h':{
			std::cout << analytics_heapsort();
			#ifdef VERBOSE
				std::cout << "[depois do heap]: ";
				printDados('_');
				std::cout << '\n';
			#endif
			break;
		}

		default: exit(3);//error
	}

}


// https://isocpp.org/wiki/faq/templates
