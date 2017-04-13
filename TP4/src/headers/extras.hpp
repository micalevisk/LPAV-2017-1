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

/**
 * Classe (estática) que contém funções auxiliares (genéricas).
 */
struct Extras {

	/**
	 * Troca os endereços de de dois elementos quaisquer.
	 * @param a
	 * @param b
	 */
	template<typename Type>
	static void trocarElementos(Type& a, Type& b){
		Type temp = a;
		a = b;
		b = temp;
	}

	/**
	 * Utiliza iteradores para executar o operador '<<' sobre cada elemento.
	 * @param first O primeiro elemento da estrutura.
	 * @param last O último elemento da estrutura.
	 * @param sep Um caractere para separar os elementos na impressão (opcional).
	 */
	template<class InputIt>
	static void imprimirElementos(InputIt first, InputIt last, char sep=','){
		for(; first != last-1; ++first) std::cout << *first << sep;
		std::cout << *first << '\n';
	}


	/**
	 * Divide/quebra uma cadeia de caracteres de acordo com um delimitador.
	 * @param str A string alvo da divisão.
	 * @param delimiter Uma string que separa termos na 'str'.
	 */
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
