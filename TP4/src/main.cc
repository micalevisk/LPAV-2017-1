//
//	[main.cc]
//	Created by Micael Levi on 04/08/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

#include "ordenacaoAnalytics.hpp"
#include "getopts.hpp"


int main(int argc, char* argv[])
{
	srand(time(NULL));
	Parameters params = GetOpts::getParameters(argc, argv);

	if(params.qtdElementos <= 0) return 1;
	vector<int> v(params.qtdElementos);

	/// Gera e insere os números N aleatórios
	for(unsigned i=0; i < params.qtdElementos; ++i) v.at(i) = rand() % 10;

	OrdenacaoAnalytics obj(v);

	#ifdef VERBOSE
		cout << "VALORES: ";
		obj.printDados();
		cout << '\n';
	#endif

	/// Header do CSV
	cout << "instancia,algoritmo,comparacoes,trocas,tempo\n";//regex: '([0-9]+),([a-zA-Z]+),([^)]+),([^)]+),([^)]+)'

	bool runAll = params.algoritmosUtilizados['a'];
	for(const auto& algoritmo : obj.nomeAlgoritmos){
		if(runAll || params.algoritmosUtilizados[algoritmo])
			obj.executarAlgoritmo(algoritmo);
	}


	return 0;
}
