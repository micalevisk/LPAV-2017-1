//
//	[analytics.hpp]
//	Created by Micael Levi on 04/07/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//

#ifndef ANALYTICS_HPP
#define ANALYTICS_HPP



#ifndef PRECISION
	#define PRECISION 2
#endif

#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>

struct Analytics {
	friend std::ostream& operator <<(std::ostream& out, const Analytics& a){//CSV
		out << a.qtdElementos << ','
			<< a.nomeAlgoritmo << ','
			<< a.qtdComparacoes << ','
			<< a.qtdTrocas << ','
			<< std::fixed << std::setprecision(PRECISION) << a.tempoExecucao
			<< '\n';
		return out;
	}

	Analytics(std::string _nomeAlgoritmo, size_t _qtdElementos){
		nomeAlgoritmo = _nomeAlgoritmo;
		qtdElementos = _qtdElementos;
		qtdComparacoes = qtdTrocas = 0;
		tempoExecucao = 0;
	}

	void incrementar_qtdComparacoes(){ ++qtdComparacoes; }
	void incrementar_qtdTrocas(){ ++qtdTrocas; }
	void iniciarTempo(){ gettimeofday(&antes, 0); }
	void pararTempo(){
		gettimeofday(&depois, 0);
		#ifdef MILLISECONDS
			tempoExecucao = ((depois.tv_sec * 1000000 + depois.tv_usec) - (antes.tv_sec * 1000000 + antes.tv_usec));
		#else
			tempoExecucao = (depois.tv_sec + depois.tv_usec/1000000.0) - (antes.tv_sec  + antes.tv_usec /1000000.0);
		#endif
	}

	std::string nomeAlgoritmo;
	private:
		struct timeval antes, depois;
		size_t qtdElementos;
		unsigned long qtdComparacoes;
		unsigned long qtdTrocas;
		float tempoExecucao;//default seconds
};



#endif
