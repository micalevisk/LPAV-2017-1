//
//	[main-getopt.cc]
//	Created by Micael Levi on 04/11/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//


#include "getopts.hpp"

/***********************************************************************************************************
λ g++ -std=c++11 main-getopt.cc -I./headers -I./headers/lib
λ ./a --verbose --descending --type=int -s3 -p13 --algorithms='bubble,selection,insertion,heap,merge,quick'
quantidade de elementos = 3
precisao do tempo de exc= 13
a=0,b=1,h=1,i=1,m=1,q=1,s=1,
***********************************************************************************************************/


int main(int argc, char** argv)
{
	Parameters p = GetOpts::getParameters(argc, argv);
	cout << "quantidade de elementos = " << p.qtdElementos << endl;
	cout << "precisao do tempo de exc= " << p.precisao << endl;
	for(auto& alg : p.algoritmosUtilizados) cout << alg.first << "=" << alg.second << ',';
	cout << '\n';
}
