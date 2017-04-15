//
//	[ordenacaoAnalytics.cc]
//	Created by Micael Levi on 04/07/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//

#include <iostream>

///// dependencies
#include "ordenacaoAnalytics.hpp"


void cleanOutputTempFile(){ std::remove(OUTPUT_TEMP_FILENAME); }

/**
 * Construtor.
 * Inicilizar o descritor do arquivo "temporário" que armazenará os dados.
 */
OrdenacaoAnalytics::OrdenacaoAnalytics(){
	tamanho = 0;
	///Abre o arquivo que armazena a instância
	std::atexit(cleanOutputTempFile);///Para apagar o arquivo criado antes de fechar o programa.
	outputfile.open(OUTPUT_TEMP_FILENAME, std::ios::binary | std::ios::out | std::ios::trunc);
	if(!outputfile.is_open()){ std::cout << "error while opening the file" ; exit(4); }
}


/**
 * Define o array que contém os valores que serão analisados.
 * @param dados Vetor que armazena os valores.
 * @param _tamanho Quantidade de elementos no vetor.
 */
void OrdenacaoAnalytics::definirDados(int* dados, size_t _tamanho){
	tamanho = _tamanho;
	///Escreve o vetor no arquivo binário (aberto pelo método construtor)
	outputfile.write((char*)&dados[0], sizeof(int) * tamanho);
	outputfile.close();
}

void OrdenacaoAnalytics::destruirDados(){
	tamanho = 0;
}

int* OrdenacaoAnalytics::readArray(){
	int* lidos = new int[tamanho];
	std::ifstream fin(OUTPUT_TEMP_FILENAME, std::ios::in | std::ios::binary);
	fin.read((char*)&lidos[0], sizeof(int)*tamanho);
	return lidos;
	/*
	outputfile.seekg(0);
	int* dadosLidos = new int[tamanho];
	outputfile.read((char*)&dadosLidos[0], sizeof(int) * tamanho);
	*/
}

/**
 * Imprime os valores do atributo 'dados' separando-os pelo caractere 'sep'.
 * @param sep Separador (visual) dos elementos (opcional).
 */
void OrdenacaoAnalytics::printDados(char sep=' '){
	int* dadosLidos = readArray();
	Extras::imprimirElementos<int>(dadosLidos, tamanho, sep);
	delete[] dadosLidos;
}

/**
 * Seletor para o algoritmo que deverá ser rodado sobre a massa de daddos.
 * Caso o id seja inválido, i.e., não exista um algoritmo com essa inicial, força o fim do programa.
 * @param id Hash para o algoritmo = primeiro caractere do seu nome (minúsculo).
 */
void OrdenacaoAnalytics::executarAlgoritmo(char id){
	if(!tamanho) return;
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
