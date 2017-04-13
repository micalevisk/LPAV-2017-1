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
#include <string>


struct Extras {

	template<typename Type>
	static void trocarElementos(Type& a, Type& b){
		Type temp = a;
		a = b;
		b = temp;
	}

	template<typename Type>
	static void foreach(const std::vector<Type>& v, char sep=','){
		for(const auto& i : v) std::cout << i << sep;
		std::cout << '\n';
	}


	static std::vector<std::string> splitString(const char* str, std::string delimiter=","){
		std::vector<std::string> generated;
		std::string s(str);
		s.erase(std::remove(s.begin(),s.end(),' '),s.end());//apaga os brancos

		size_t pos = 0;
		std::string token;
		while((pos = s.find(delimiter)) != std::string::npos){
			token = s.substr(0, pos);
			if(!token.empty()) generated.push_back(token);
			s.erase(0, pos + delimiter.length());
		}
		generated.push_back(s);

		return generated;
	}

};



#endif
