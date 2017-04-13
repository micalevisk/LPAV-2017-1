//
//	[ordenacaoAnalytics.cc]
//	Created by Micael Levi on 04/07/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//

#include <iostream>

///// dependencies
#include "ordenacaoAnalytics.hpp"

/**
 * Construtor do OrdenacaoAnalytics.
 * @param _dados Vetor que armazena os elementos que deverão analisados.
 * @return instância de OrdenacaoAnalytics.
 */
OrdenacaoAnalytics::OrdenacaoAnalytics(std::vector<int> _dados){
	dados = _dados;
}

/**
 * Imprime os valores do atributo 'dados' separando-os pelo caractere 'sep'.
 * @param sep Separador (visual) dos elementos (opcional).
 */
void OrdenacaoAnalytics::printDados(char sep=' '){
	Extras::imprimirElementos(dados.begin(), dados.end(), sep);
}

/**
 * Seletor para o algoritmo que deverá ser rodado sobre a massa de daddos.
 * Caso o id seja inválido, i.e., não exista um algoritmo com essa inicial, força o fim do programa.
 * @param id Hash para o algoritmo = primeiro caractere do seu nome (minúsculo).
 */
void OrdenacaoAnalytics::executarAlgoritmo(char id){
	switch( tolower(id) ){
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
