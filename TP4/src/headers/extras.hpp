//
//	[extras.hpp]
//	Created by Micael Levi on 04/08/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//

#ifndef EXTRAS_HPP
#define EXTRAS_HPP



#include <iostream>

template<typename Type>
void trocarElementos(Type& a, Type& b){
	Type temp = a;
	a = b;
	b = temp;
}

template<typename Type>
void foreach(Type* arr, size_t tam, char delim='-'){
	for(unsigned i=0; i < tam; ++i)
		std::cout << arr[i] << delim;
	std::cout << '\n';
}



#endif
