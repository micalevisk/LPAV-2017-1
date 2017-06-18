//
//	[randomNumbersGenerator.cpp]
//	Created by Micael Levi on 06/18/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//


#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;


int main(int argc, char* argv[])
{
	srand(time(NULL));

	if(argc != 2){
		cout << "Precisa definir a quantidade de valores\n";
		return 1;
	}

	unsigned long qtdValores = strtoul(argv[1], NULL, 10);

	///Imprime os N números aleatórios
	for(unsigned long i=0; i < qtdValores; ++i)
		cout << rand() << endl;

	return 0;
}
