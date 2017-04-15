//
//	[ordenacaoAnalytics.hpp]
//	Created by Micael Levi on 04/07/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//

#ifndef ORDENACAO_ANALYTICS_HPP
#define ORDENACAO_ANALYTICS_HPP


#include <vector>
#include <fstream>

#define OUTPUT_TEMP_FILENAME ".dadosarray.bin"

///// dependencies
#include "analytics.hpp"
#include "extras.hpp"
#include "unittest.hpp"


/**
 * Classe que contém a implementação de cada algoritmo e as
 * estatísicas da execução dos mesmos sobre a massa de dados.
 */
class OrdenacaoAnalytics {
	size_t tamanho;
	std::fstream outputfile;

	//Algoritmos de ordenação:
	Analytics analytics_bubblesort();
	Analytics analytics_selectionsort();
	Analytics analytics_insertionsort();
	Analytics analytics_mergesort();
	Analytics analytics_quicksort();
	Analytics analytics_heapsort();

	public:
		std::vector<char> nomeAlgoritmos = {'m','q','h','i','s','b'};///em ordem de melhor tempo (será a ordem de execução).
		void printDados(char);
		void printDados(){ printDados(' '); }
		void definirDados(int*,size_t);
		void destruirDados();
		int* readArray();
		OrdenacaoAnalytics();
		void executarAlgoritmo(char);

};



#endif
