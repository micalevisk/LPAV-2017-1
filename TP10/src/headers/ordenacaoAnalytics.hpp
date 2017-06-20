//
//	[ordenacaoAnalytics]
//	Created by Micael Levi on 06/19/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//

#ifndef ORDENACAO_ANALYTICS_HPP
#define ORDENACAO_ANALYTICS_HPP



#include <vector>
#include <string>
#include "analytics.hpp"
#include "extras.hpp"

using namespace std;

/**
 * Classe que contém a implementação de cada algoritmo e as
 * estatísicas da execução dos mesmos sobre a massa de dados.
 */
class OrdenacaoAnalytics {
	size_t tamanho;///quantidade de elementos a se ordenar
	string nomeArquivo;

	public:
		OrdenacaoAnalytics(string);
		int* readArrayFromFile();
		void printFileData(char);

		Analytics getAnalytics_quicksort_sequencial(bool);
};



#endif
