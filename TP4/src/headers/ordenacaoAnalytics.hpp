//
//	[ordenacaoAnalytics.hpp]
//	Created by Micael Levi on 04/07/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//

#ifndef ORDENACAO_ANALYTICS_HPP
#define ORDENACAO_ANALYTICS_HPP


///// dependencies
#include "analytics.hpp"

#include <iostream>
#include <vector>
#include <string>


template<typename T>
class OrdenacaoAnalytics {
	std::string nomeAlgoritmo;
	Analytics analise;
	std::vector<T> dados;

	public:
		OrdenacaoAnalytics(std::vector<T>, std::string);

		friend std::ostream& operator<< (std::ostream& out, const OrdenacaoAnalytics<T>& oa){
			out << '#' << oa.nomeAlgoritmo << '\n'
				<< oa.analise << '\n';
			return out;
		}


};




#endif
