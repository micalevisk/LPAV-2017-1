//
//	[stringparser.hpp]
//	Created by Micael Levi on 04/09/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//

#ifndef STRING_PARSER_HPP
#define STRING_PARSER_HPP



#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct StringParser {

	static vector<string> splitString(const char* str, string delimiter=","){
		vector<string> generated;
		string s(str);
		s.erase(std::remove(s.begin(),s.end(),' '),s.end());//apaga os brancos

		size_t pos = 0;
		string token;
		while((pos = s.find(delimiter)) != string::npos){
			token = s.substr(0, pos);
			if(!token.empty()) generated.push_back(token);
			s.erase(0, pos + delimiter.length());
		}
		generated.push_back(s);

		return generated;
	}

};



#endif
