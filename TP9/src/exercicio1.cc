/**
 * Exercício 1: Verificador de Modelos para Redes de Petri
 * @author Micael Levi
 * @date 13/06/2017
 */

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
using namespace std;


//----------------------------------------------------//constantes
list<vector<int>> marcacoesAlcancadas;///armazena as marcações alcançadas

unsigned qtdTransicoes, qtdLugares;/// 't' e 'p'
int **matrizPre, **matrizPos;///matrizes de entrada e saída
vector<int> arrMF;///vetor de marcação final

template <typename T> T** lerMatriz(unsigned, unsigned);
//----------------------------------------------------//globais
#define getI(lugar,transicao) matrizPre[lugar][transicao]
#define getO(lugar,transicao) matrizPos[lugar][transicao]


/**
 * Compara a marcação dada com a final 'arrMF'.
 * @return TRUE se os vetores são iguais (mesmos elementos).
 */
bool marcacoesIguais(const vector<int> arrMarcas){
	for(unsigned lugar=0; lugar < qtdLugares; ++lugar)
		if(arrMarcas[lugar] != arrMF[lugar]) return false;
	return true;
}


/**
 * Verifica se uma transição pode ser disparada,
 * de acordo com um vetor de marcações dado.
 * @return TRUE se uma transição está ativada.
 */
bool estaAtivada(unsigned numTransicao, const vector<int> arrMarcas){
	for(unsigned lugar=0; lugar < qtdLugares; ++lugar)
		if( getI(lugar,numTransicao) > arrMarcas[lugar] ) return false;
	return true;
}


/**
 * Dispara uma transição.
 * Modifica o vetor de marcas para a nova configuração da rede.
 * @return O vetor de marcas atualizado.
 */
vector<int> disparar(unsigned numTransicao, const vector<int> arrMarcas){
	vector<int> marcacoesAtualizadas(arrMarcas);///cria um vetor de marcações a partir do corrente
	///atualiza marcações, i.e., disparado realizado
	for(unsigned lugar=0; lugar < qtdLugares; ++lugar)
		marcacoesAtualizadas.at(lugar) = arrMarcas[lugar] - getI(lugar, numTransicao) + getO(lugar, numTransicao);
	return marcacoesAtualizadas;///retorna as marcações atualizadas
}


/**
 * Um vértice é um vetor de marcações.
 * @return TRUE se as marcações dadas já foram alcançadas.
 */
bool verticeDuplicado(const vector<int> arrMarcasCurr){
	return find(marcacoesAlcancadas.begin(),
				marcacoesAlcancadas.end(),
				arrMarcasCurr) != marcacoesAlcancadas.end();
}

/** Construção da Reachability Tree
Um vértice é um nó contendo uma marcação;
Vértices de fronteira são os que ainda não foram processados;
Vértices interiores são os já processados e produzem um sucessor;
Vértices terminais são os já processados mas não produzem um sucessor;
Vértices duplicatas são os iguais a algum outro nó (interior ou terminal), não precisam ser analisados;

casos bases:
- a marcação corrente é a buscada => retorna true
- marcação corrente já foi profecessada, i.e., vértice duplicado => retorna checar próximo
- não há transições ativas, i.e., vértice terminal => retorna FIM
*/
bool ehAlcancavel(vector<int> arrMarcasCurr){
	if(marcacoesIguais(arrMarcasCurr)) return true;
	if(verticeDuplicado(arrMarcasCurr)) return false;
	marcacoesAlcancadas.push_back(arrMarcasCurr);

	for(unsigned t=0; t < qtdTransicoes; ++t){
		if(estaAtivada(t, arrMarcasCurr)){///verifica se a transição corrente 't' pode ser disparada
			if(ehAlcancavel( disparar(t, arrMarcasCurr) ))
				return true;
		}
	}
	return false;///não há transições ativas, i.e., que podem ser disparadas
}





main()
{
	///ler quantidade de lugares e transições
	cin >> qtdLugares >> qtdTransicoes;

	///ler matriz de pré-condições P x T -> N
	matrizPre = lerMatriz<int>(qtdLugares, qtdTransicoes);

	///ler matriz de pós-condições P x T -> N
	matrizPos = lerMatriz<int>(qtdLugares, qtdTransicoes);

	vector<int> arrMI(qtdLugares);///vetor de marcação inicial/corrente

	///Enquanto não for lido o '-1'
	for(unsigned first; (cin >> first) && (first != -1); ){
		///ler quantidade indefinida de marcação inicial (vetor de dimensão p)
		arrMI.at(0) = first;
		for(unsigned i=1; i < qtdLugares; ++i) cin >> arrMI[i];

		///ler quantidade indefinida de marcação final   (vetor de dimensão p)
		for(unsigned i=0; i < qtdLugares; ++i){
			int curr; cin >> curr;
			arrMF.push_back(curr);
		}

		///verificar modelo ...
		if( ehAlcancavel(arrMI) ) cout << "SIM\n";
		else cout << "NAO\n";

		///limpa o vetor de marcações finais
		arrMF.clear();
		///limpa o vetor de marcações alcançadas
		marcacoesAlcancadas.clear();
	}

}


template <typename T>
T** lerMatriz(unsigned qtdLinhas, unsigned qtdColunas){
	T** m = (T**) malloc(sizeof(T*) * qtdLinhas);
	for(unsigned i=0; i < qtdLinhas; ++i){
		m[i] = (T*) malloc(sizeof(T) * qtdColunas);
		for(unsigned j=0; j < qtdColunas; ++j) cin >> m[i][j];
	}
	return m;
}
