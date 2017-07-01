//
//	[ordenacaoAnalytics.cc]
//	Created by Micael Levi on 06/19/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//

#include <iostream>
#include <fstream>
#include "ordenacaoAnalytics.hpp"

/**
 * Construtor.
 * Inicilizar o descritor do arquivo "temporário" que armazenará os dados.
 */
OrdenacaoAnalytics::OrdenacaoAnalytics(string _nomeArquivo) :
	 tamanho(0)
	,nomeArquivo(_nomeArquivo) {}


/**
 * Ler números de arquivo de texto.
 */
int* OrdenacaoAnalytics::readArrayFromFile(){
	int* lidos = NULL;
	ifstream fileWithData(nomeArquivo);
	if(!fileWithData.is_open()){
		exit(EXIT_FAILURE);
	}

	fileWithData >> tamanho;
	lidos = new int[tamanho];
	for(unsigned i=0; i < tamanho; ++i) fileWithData >> lidos[i];

	fileWithData.close();

	return lidos;
}


/**
 * Lê os números do arquivo texto salvando-os
 * em um array e imprime-o logo em seguida de forma sequencial.
 * @param sep [opcional] Separador (visual) dos elementos.
 */
void OrdenacaoAnalytics::printFileData(char sep=' '){
	int* dadosLidos = readArrayFromFile();
	Extras::imprimirElementos<int>(dadosLidos, tamanho, sep);
	delete[] dadosLidos;
}
