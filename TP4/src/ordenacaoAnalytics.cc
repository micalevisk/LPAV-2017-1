//
//	[ordenacaoAnalytics.cc]
//	Created by Micael Levi on 04/07/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//


///// dependencies
#include "ordenacaoAnalytics.hpp"
using namespace std;



OrdenacaoAnalytics::OrdenacaoAnalytics(vector<T> _dados){
	dados = _dados;
}


void OrdenacaoAnalytics::printDados(){
	for(auto d : dados) cout << d << ',';
	cout << endl;
}

// https://isocpp.org/wiki/faq/templates
