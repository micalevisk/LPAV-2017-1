//
//	[testeunitario.hpp]
//	Created by Micael Levi on 04/10/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//

#ifndef TESTE_UNITARIO_HPP
#define TESTE_UNITARIO_HPP



template <typename Iterator>
void compararElementosVectors(Iterator f1, Iterator f2, Iterator last) {
	for(Iterator it1=f1, it2=f2; it1!=last; ++it1, ++it2)
		assert(*it1 == *it2);
}

struct TesteUnitario {
	template<typename T, typename A>
	static void compararVectors(vector<T,A> const& v1, vector<T,A> const& v2) {
		assert(v1.size() == v2.size());
		compararElementosVectors(v1.begin(), v2.begin(), v1.end());
	}
};



#endif
