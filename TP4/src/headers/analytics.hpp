//
//	[analytics.hpp]
//	Created by Micael Levi on 04/07/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//

#ifndef ANALYTICS_HPP
#define ANALYTICS_HPP

#include <iostream>

struct Analytics {
	unsigned long qtdComparacoes;
	unsigned long qtdTrocas;
	unsigned tempoExecucao;

	Analytics(){
		qtdComparacoes = qtdTrocas = tempoExecucao = 0;
	}

	friend std::ostream& operator <<(std::ostream& out, const Analytics& a){
		out << "Número de Comparações: " << a.qtdComparacoes << '\n'
			<< "Número de Trocas:      " << a.qtdTrocas << '\n'
			<< "Tempo de Execução:     " << a.tempoExecucao;
		return out;
	}
};


#endif
