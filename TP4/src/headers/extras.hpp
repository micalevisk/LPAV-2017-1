//
//	[extras.hpp]
//	Created by Micael Levi on 04/08/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//

#ifndef EXTRAS_HPP
#define EXTRAS_HPP



#include <iostream>
#include <algorithm>
#include <vector>

template<typename Type>
void trocarElementos(Type& a, Type& b){
	Type temp = a;
	a = b;
	b = temp;
}

template<typename Type>
void foreach(std::vector<Type> v, char delim='-'){
	for_each(v.begin(), v.end(), [delim](const Type& n){
		std::cout << n << delim;
	});
	std::cout << '\n';
}



#endif
