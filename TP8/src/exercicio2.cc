/**
 * Exercício 2: Onde está Waldorf?
 * @author Micael Levi
 * @date 02/06/2017
 */

#include <iostream>
#include <algorithm>
using namespace std;

//----------------------------//
unsigned qtdLinhas, qtdColunas;
char** matriz;
//----------------------------//

bool posValida(int i, int j){ return (i >= 0 && i < qtdLinhas) && (j >=0 && j < qtdColunas); }

bool procurar(string str, size_t pos, int i, int j, int incrI, int incrJ){
	if(pos >= str.length()) return true;
	if(!posValida(i,j)) return false;

	return ( matriz[i][j] == str.at(pos) ) ?
		procurar(str, pos+1, i+incrI,j+incrJ, incrI,incrJ) : false;
}

void buscarPalavra(string str){
	if(str.empty()) return;
	for(unsigned i=0; i < qtdLinhas; ++i)
		for(unsigned j=0; j < qtdColunas; ++j){
			if(   procurar(str, 0, i,j, -1,0)//norte
			   || procurar(str, 0, i,j,  1,0)//sul
			   || procurar(str, 0, i,j,  0,1)//leste
			   || procurar(str, 0, i,j,  0,-1)//oeste
			   || procurar(str, 0, i,j, -1,-1)//NO
			   || procurar(str, 0, i,j,  -1,1)//NE
			   || procurar(str, 0, i,j,   1,1)//SE
			   || procurar(str, 0, i,j,  1,-1)//S0
			){
				cout << i+1 << ' ' << j+1 << endl;
				return;
			}
		}
}

main()
{
	int qtdPalavras;
	cin >> qtdLinhas >> qtdColunas;

	matriz = (char**) malloc(sizeof(char*) * qtdLinhas);

	//ler matriz
	for(unsigned i=0; i < qtdLinhas; ++i){
		matriz[i] = (char*) malloc(sizeof(char) * qtdColunas);
		for(unsigned j=0; j < qtdColunas; ++j){
			char lido; cin >> lido;
			matriz[i][j] = tolower(lido);
		}
	}

	//ler palavras
	for(cin >> qtdPalavras; qtdPalavras >= 0; --qtdPalavras){
		string palavraCurr; cin >> palavraCurr;
		transform(palavraCurr.begin(), palavraCurr.end(), palavraCurr.begin(), ::tolower);
		buscarPalavra( palavraCurr );
	}
}
