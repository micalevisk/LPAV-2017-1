/**
 * Exercício 4: Parafusos e Porcas
 * @author Micael Levi
 * @date 12/07/2017
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
	int qtdTestes;
	unsigned qtdCaixas, num;
	int posCurr, posPrimeiro, posUltimo;

	cin >> qtdTestes;
	while(qtdTestes-- > 0){
		vector<unsigned> lotes;

		cin >> qtdCaixas;
		for(; qtdCaixas > 0; --qtdCaixas){
			unsigned x, y; cin >> x >> y;//tamanhos dos lotes de parafusos e porcas nesta caixa
			for(unsigned j=x; j <=y; ++j) lotes.push_back(j);
		}

		quickSort(lotes);
		cin >> num;

		//===================================================§
		posCurr = binarySearch(lotes, num, 0, lotes.size()-1);
		posPrimeiro = posCurr;
		while(posCurr >= 0){//procurar o mais a esquerda
			posPrimeiro = posCurr;
			posCurr = binarySearch(lotes, num, 0, posPrimeiro-1);
		}

		if(posPrimeiro < 0){//não encontrou a primeira ocorrência
			cout << num << " not found" << endl;
			continue;
		}

		//===================================================§
		posCurr = binarySearch(lotes, num, posPrimeiro, lotes.size()-1);
		posUltimo = posCurr;
		while(posCurr >= 0){//procurar o mais a direita
			posUltimo = posCurr;
			posCurr = binarySearch(lotes, num, posUltimo+1, lotes.size()-1);
		}

		cout << num  << " found from " << posPrimeiro << " to " << posUltimo << endl;
	}
}
