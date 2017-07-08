/**
 * Exercício 4: Quadro de Medalhas
 * @author Micael Levi
 * @date 07/07/2017
 * PASSOU NO URI 1520
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int binarySearch(vector<unsigned> v, int chave, int inicio, int fim){
	int meio;
	while(inicio <= fim){
		meio = (inicio+fim)/2;
		if(chave == v[meio]) return meio;
		if(chave < v[meio]) fim = meio-1;
		else inicio = meio+1;
	}
	return -1;
}


void particionar(vector<unsigned>& v, int inicio, int fim){
	int i=inicio, j=fim;
	unsigned pivot = v[(i+j)/2];

	while(i <= j){
		for(; v[i] < pivot; ++i);
		for(; v[j] > pivot; --j);
		if(i <= j){
			unsigned aux = v[i];
			v[i] = v[j];
			v[j] = aux;
			i++; j--;
		}
	}
	if(j > inicio) particionar(v, inicio, j);
	if(i < fim)    particionar(v, j+1, fim);
}

void quickSort(vector<unsigned>& v){
	particionar(v, 0, v.size()-1);
}



main()
{
	unsigned qtdTestes;
	cin >> qtdTestes;
	if(qtdTestes <= 0) return 0;

	do{
		qtdTestes--;

		vector<unsigned> lotes;
		unsigned qtdCaixas, num;
		cin >> qtdCaixas;

		for(; qtdCaixas > 0; --qtdCaixas){
			unsigned x, y; cin >> x >> y;//tamanhos dos lotes de parafusos e porcas nesta caixa
			for(unsigned j=x; j <=y; ++j) lotes.push_back(j);
		}

		quickSort(lotes);
		cin >> num;
		int posPrimeiro = binarySearch(lotes, num, 0,lotes.size()-1);

		for(auto l : lotes) cout << l << ',';
		cout << endl;

		//TODO alternativa para a busca recuperar o mais a esq (primeiro) e o mais a direita (ultimo)
		if(posPrimeiro >= 0){
			int posUltimo = binarySearch(lotes, num, posPrimeiro+1, lotes.size()-1);
			cout << num  << " found from " << posPrimeiro << " to " << ultimo << endl;
		}
		else{
			cout << num << " not found" << endl;
		}

	}while(qtdTestes > 0);
}
