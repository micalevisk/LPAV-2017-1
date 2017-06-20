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
#include <cassert>

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
	 * Itera sobre um array de qualquer tipo
	 * executando o operador '<<' sobre cada elemento.
	 * @param arr O vetor alvo.
	 * @param N O tamanho do vetor.
	 * @param sep Um caractere para separar os elementos na impressão (opcional).
	 */
	template<class Type>
	static void imprimirElementos(Type* arr, size_t N, char sep=','){
		unsigned i=0;
		for(; i < N-1; ++i) std::cout << arr[i] << sep;
		std::cout << arr[i] << '\n';
	}

	template<class Type>
	static std::vector<Type>& getVectorFromArray(Type* arr){
		std::vector<Type> v(arr, arr + sizeof(arr)/sizeof(Type));
		return v;
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

	/**
	 * Verifica se um vector está ordenado.
	 * Caso não esteja, a assert dispara um erro de checagem.
	 * @param v Vector que será analisado.
	 * @param decrescente Define se o vector deve estar em ordem decrescente (opcional).
	 */
	template<class Type>
	static void isSorted(std::vector<Type> v, bool decrescente=false){
		if(decrescente){
			std::reverse(v.begin(), v.end());
			bool esta_em_ordem_decrescente = std::is_sorted(v.begin(), v.end());
			assert(esta_em_ordem_decrescente);
		}else{
			bool esta_em_ordem_crescente = std::is_sorted(v.begin(), v.end());
			assert(esta_em_ordem_crescente);
		}
	}

};



#endif
