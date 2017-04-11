//
//	[unittest.hpp]
//	Created by Micael Levi on 04/10/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//

#ifndef TESTE_UNITARIO_HPP
#define TESTE_UNITARIO_HPP



#include <assert.h>
#include <algorithm>
#include <vector>

/*
template <typename Iterator>
void compareVectorsData(Iterator f1, Iterator f2, Iterator last) {
	for(Iterator it1=f1, it2=f2; it1!=last; ++it1, ++it2)
		assert(*it1 == *it2);
}
*/
struct UnitTest {
	/*
	template<typename Type>
	static void compareVectors(std::vector<Type> const& v1, std::vector<Type> const& v2) {
		assert(v1.size() == v2.size());
		compareVectorsData(v1.begin(), v2.begin(), v1.end());
	}
	*/

	template<typename Type>
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
