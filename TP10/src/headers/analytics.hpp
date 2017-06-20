//
//	[analytics.hpp]
//	Created by Micael Levi on 06/19/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//

#ifndef ANALYTICS_HPP
#define ANALYTICS_HPP



#ifndef TIME_PRECISION
	#define TIME_PRECISION 2
#endif

#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <sys/time.h>
#include <cstdlib>


/**
 * Classe para armazenar os dados computados sobre um algoritmo.
 */
struct Analytics {
	std::string nomeAlgoritmo;

	friend std::ostream& operator <<(std::ostream& out, const Analytics& a){//CSV
		out << a.nomeAlgoritmo << ','
			<< a.qtdElementos << ','
			<< std::fixed << std::setprecision(TIME_PRECISION) << a.tempoExecucao
			<< '\n';
		return out;
	}

	/**
	 * Construtor do Analytics
	 * @paam _nomeAlgoritmo String que representa o nome do algoritmo.
	 * @param qtdElementos Quantidade de elementos que estão sendo analisados.
	 */
	Analytics(std::string _nomeAlgoritmo, size_t _qtdElementos) :
		 nomeAlgoritmo(_nomeAlgoritmo)
		,qtdElementos(_qtdElementos)
		,tempoExecucao(0) {}


	/**
	 * Marca o tempo inicial.
	 */
	bool iniciarTempo(){
		return !gettimeofday(&antes, 0);
	}

	/**
	 * Marca o tempo final.
	 */
	void pararTempo(){
		if( gettimeofday(&depois, 0) ) exit(1);///failure
		tempoExecucao = (depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec  + antes.tv_usec /1000000.0);
		#ifdef MILLISECONDS
			tempoExecucao *= 1000;
		#endif
	}

	private:
		struct timeval antes, depois;///tempos marcados
		size_t qtdElementos;
		float tempoExecucao;///seconds
};



#endif
