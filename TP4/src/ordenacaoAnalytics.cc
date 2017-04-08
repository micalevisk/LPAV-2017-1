//
//	[ordenacaoAnalytics.cc]
//	Created by Micael Levi on 04/07/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//


///// dependencies
#include "ordenacaoAnalytics.hpp"
using namespace std;

template class OrdenacaoAnalytics<int>;


template<typename T>
OrdenacaoAnalytics<T>::OrdenacaoAnalytics(vector<T> _dados, string _nomeAlgoritmo){
	nomeAlgoritmo = _nomeAlgoritmo;
	analise = Analytics();
	dados = _dados;
}

// https://isocpp.org/wiki/faq/templates
