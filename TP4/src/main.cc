//
//	[main.cc]
//	Created by Micael Levi on 04/08/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//
// https://isocpp.org/wiki/faq/templates

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "ordenacaoAnalytics.hpp"


void alterar(vector<int> v){//não deve alterar 'v'
	int* arr = &v.at(0);//casting vector TO simple array

	arr[0] = 1;
	arr[1] = 2;
}


int main(){

	vector<int> v = {4,2,5};

	// alterar(v);
	// cout << v[0] << ' ' << v[1] << endl;

	OrdenacaoAnalytics obj(v);

	/// Teste do Bubble Sort
	cout << obj.analytics_bubblesort();
	#ifdef VERBOSE
		cout << "[depois do bubble]: "; obj.printDados();
	#endif
	cout << endl;


	return 0;
}
