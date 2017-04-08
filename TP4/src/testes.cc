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

	vector<int> v = {3,4};

	// alterar(v);
	// cout << v[0] << ' ' << v[1] << endl;

	OrdenacaoAnalytics<int> obj(v, "Bubblesort");
	cout << obj << endl;



	return 0;
}
