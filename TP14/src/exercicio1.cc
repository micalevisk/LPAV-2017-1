/**
 * Exercício 1: Ordenando a Lista de Crianças do Papai Noel
 * @author Micael Levi
 * @date 07/07/2017
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void particionar(vector<string>& v, int inicio, int fim){
	int i=inicio, j=fim;
	string pivot = v[(i+j)/2];

	while(i <= j){
		for(; v[i] < pivot; ++i);
		for(; v[j] > pivot; --j);
		if(i <= j){
			string aux = v[i];
			v[i]       = v[j];
			v[j]       = aux;
			i++;
			j--;
		}
	}
	if(j > inicio) particionar(v, inicio, j);
	if(i < fim)    particionar(v, j+1, fim);
}

void quickSort(vector<string>& v){
	particionar(v, 0, v.size()-1);
}



main()
{
	unsigned qtdNomes;
	unsigned statusPessoas[2] = {0,0};

	cin >> qtdNomes;
	vector<string> lista(qtdNomes);

	for(unsigned i=0; i < qtdNomes; ++i){
		char id;
		string nome;

		cin >> id >> nome;
		statusPessoas[ id%3 ]++;
		lista.at(i) = nome;
	}

	quickSort(lista);

	for(auto& nome : lista) cout << nome << endl;
	cout << "\nSe comportaram: " << statusPessoas[1] << " | Nao se comportaram: " << statusPessoas[0] << endl;
}
