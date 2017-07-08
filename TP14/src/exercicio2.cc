/**
 * Exercício 2: Quadro de Medalhas
 * @author Micael Levi
 * @date 07/07/2017
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Participante {
	string nome;
	unsigned qtdOuro, qtdPrata, qtdBronze;

	bool operator <(const Participante& p){
		if(qtdOuro == p.qtdOuro){
			if(qtdPrata == p.qtdPrata){
				if(qtdBronze == p.qtdBronze) return nome < p.nome;
				return qtdBronze > p.qtdBronze;
			}
			return qtdPrata > p.qtdPrata;
		}
		return qtdOuro > p.qtdOuro;
	}
};

ostream& operator<<(ostream& ostr, const vector<Participante>& list){
	for(auto &i : list)
		ostr << i.nome << " " << i.qtdOuro << " " << i.qtdPrata << " " << i.qtdBronze << endl;
	return ostr;
}


void selectionSort(vector<Participante>& v){
	Participante aux;

	for(int i=0, n=v.size(); i < n-1; ++i){
		int posMin = i;
		for(int j=i+1; j < n; ++j){
			if(v[j] < v[posMin]) posMin = j;
		}

		if(i != posMin){
			aux  = v[i];
			v[i] = v[posMin];
			v[posMin] = aux;
		}
	}
}

main()
{
	unsigned qtdParticipantes;
	cin >> qtdParticipantes;

	vector<Participante> participantes(qtdParticipantes);
	for(unsigned i=0; i < qtdParticipantes; ++i){
		Participante pcurr;
		cin >> pcurr.nome;
		cin >> pcurr.qtdOuro >> pcurr.qtdPrata >> pcurr.qtdBronze;
		participantes.at(i) = pcurr;
	}

	selectionSort(participantes);
	cout << participantes;
}
