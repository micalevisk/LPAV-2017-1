//
//	[main.cc]
//	Created by Micael Levi on 04/08/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "ordenacaoAnalytics.hpp"



int main(){

	vector<int> v = {4,2,5,1,6,3,0,1};//8

	OrdenacaoAnalytics obj(v);

	/// Teste do Bubble Sort
	cout << obj.analytics_bubblesort();
	#ifdef VERBOSE
		cout << "[depois do bubble]: ";
		obj.printDados();
		cout << endl;
	#endif

	/// Teste do Selection Sort
	cout << obj.analytics_selectionsort();
	#ifdef VERBOSE
		cout << "[depois do selection]: ";
		obj.printDados();
		cout << endl;
	#endif

	/// Teste do Insertion Sort
	cout << obj.analytics_insertionsort();
	#ifdef VERBOSE
		cout << "[depois do insertion]: ";
		obj.printDados();
		cout << endl;
	#endif

	/// Teste do Merge Sort
	cout << obj.analytics_mergesort();
	#ifdef VERBOSE
		cout << "[depois do merge]: ";
		obj.printDados();
		cout << endl;
	#endif

	/// Teste do Quick Sort
	cout << obj.analytics_quicksort();
	#ifdef VERBOSE
		cout << "[depois do quick]: ";
		obj.printDados();
		cout << endl;
	#endif

	/// Teste do Heap Sort
	cout << obj.analytics_heapsort();
	#ifdef VERBOSE
		cout << "[depois do heap]: ";
		obj.printDados();
		cout << endl;
	#endif






	return 0;
}
