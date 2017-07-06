/**
 * Exercício 1: Solucionar Jogo Sudoku
 * @author Micael Levi
 * @date 01/07/2017
 */

/******************************
Preencher todas as células sem:
- repetir números numa mesma linha
- repetir números numa mesa coluna
- repetir números numa mesma grade 3x3
******************************/

#include <iostream>
#include <cstdio>
using namespace std;

//----------------------------------------------------------------------------------------//
template<class T> class Matriz {
	T** matriz;
	bool naoEstaAlocado(){return (matriz == NULL) || (!qtdLinhas) || (!qtdColunas);}

	public:
		unsigned qtdLinhas, qtdColunas;
		Matriz(unsigned l, unsigned c);
		~Matriz();
		bool posicaoValida(unsigned i, unsigned j){return (i < qtdLinhas) && (j < qtdColunas);}
		void lerValoresFormatados();
		void imprimirValores();
		bool setElemento(const T newValue, unsigned i, unsigned j);
		T* getElemento(unsigned i, unsigned j);
		bool celulaIgualA(const T value, unsigned i, unsigned j);
};

Matriz<unsigned> tabuleiro = Matriz<unsigned>(9, 9);
//----------------------------------------------------------------------------------------//



//{REGRA 1 & 2} 'val' não está presente na 'linha' ou na 'coluna'
//---------------------------------------------------------------//
bool linhaOuColunaValidaParaValor(const unsigned val, const unsigned linha, const unsigned coluna,
								  const unsigned incrLinha, const unsigned incrColuna)
{
	unsigned curr;
	return !tabuleiro.posicaoValida(linha, coluna)
	|| (	  ( (curr = * tabuleiro.getElemento(linha, coluna)) || true )
			&&	(curr != val)
			&& linhaOuColunaValidaParaValor(val, linha+incrLinha, coluna+incrColuna, incrLinha, incrColuna)
		);
	/*=========================================== SAME ^ ===========================================
	if(!tabuleiro.posicaoValida(linha, coluna)) return true;
	unsigned curr = * tabuleiro.getElemento(linha, coluna);
	return (curr != val) && linhaOuColunaValidaParaValor(val, linha+incrLinha, coluna+incrColuna, incrLinha, incrColuna);
	*/
}
//---------------------------------------------------------------//

//{REGRA 3} 'val' não está presente no seu quadrante 3x3
//-------------------------------------------------------//
bool gradeValidaParaValor(const unsigned val, const unsigned i, const unsigned j){
	unsigned minLinha, maxLinha, minColuna, maxColuna;
	maxLinha =(minLinha =i-i%3)+2;
	maxColuna=(minColuna=j-j%3)+2;

	for(unsigned l = minLinha; l <= maxLinha; ++l){
		for(unsigned c = minColuna; c <= maxColuna; ++c){
			unsigned valCurr = * tabuleiro.getElemento(l, c);//admite coordenadas sempre válidas
			if(valCurr == val) return false;
		}
	}
	return true;
}
//-------------------------------------------------------//


bool regrasValidasPara(const unsigned val, const unsigned i, const unsigned j){
	return	tabuleiro.posicaoValida(i, j)
		&&	linhaOuColunaValidaParaValor(val, i, 0, 0, 1)//checar linha
		&&	linhaOuColunaValidaParaValor(val, 0, j, 1, 0)//checar coluna
		&&	gradeValidaParaValor(val, i,j);
}

bool validarEDefinir(const unsigned val, const unsigned i, const unsigned j){
	return regrasValidasPara(val, i,j) && tabuleiro.setElemento(val, i,j);
}


bool freedomAtRow(const unsigned i, const unsigned j){
	return (i == tabuleiro.qtdLinhas)
	|| (		(j == tabuleiro.qtdColunas) ? freedomAtRow(i+1,0)//if, then
			:	!tabuleiro.celulaIgualA(0, i,j) ? freedomAtRow(i,j+1)//else if, then
			:	(validarEDefinir(1, i,j) && freedomAtRow(i,j+1))//else
			||	(validarEDefinir(2, i,j) && freedomAtRow(i,j+1))
			||	(validarEDefinir(3, i,j) && freedomAtRow(i,j+1))
			||	(validarEDefinir(4, i,j) && freedomAtRow(i,j+1))
			||	(validarEDefinir(5, i,j) && freedomAtRow(i,j+1))
			||	(validarEDefinir(6, i,j) && freedomAtRow(i,j+1))
			||	(validarEDefinir(7, i,j) && freedomAtRow(i,j+1))
			||	(validarEDefinir(8, i,j) && freedomAtRow(i,j+1))
			||	(validarEDefinir(9, i,j) && freedomAtRow(i,j+1))
			||	!tabuleiro.setElemento(0, i,j)
		);
	/*=================================== SAME ^ ===================================
	if(i == tabuleiro.qtdLinhas) return true;//fim
	if(j == tabuleiro.qtdColunas) return freedomAtRow(i+1, 0);//próxima linha
	if(!tabuleiro.celulaIgualA(0, i,j)) return freedomAtRow(i,j+1);//chamar próxima

	for(unsigned valor=1; valor < 10; ++valor)
		if( validarEDefinir(valor, i,j) && freedomAtRow(i,j+1) )
			return true;

	return !tabuleiro.setElemento(0, i,j);//atribui 0 à posição (i,j) e retorna false
	*/
}



main()
{
	tabuleiro.lerValoresFormatados();
	freedomAtRow(0,0);
	tabuleiro.imprimirValores();
}



//========================================================================================//
template<class T> Matriz<T>::Matriz(unsigned l, unsigned c) : qtdLinhas(l), qtdColunas(c) {
	if(!qtdLinhas) return;
	matriz = new (nothrow) T*[qtdLinhas];
	if(matriz == NULL)
		cout << "ERRO AO ALOCAR\n";
	else
		for(unsigned i=0; i<qtdLinhas; ++i) matriz[i] = new T[qtdColunas];
}

template<class T> Matriz<T>::~Matriz(){
	if(naoEstaAlocado()) return;
	for(unsigned i=0; i < qtdLinhas; ++i) delete [] matriz[i];
	delete [] matriz;
	matriz = NULL;
}

template<class T> void Matriz<T>::lerValoresFormatados(){
	if(naoEstaAlocado()) return;
	for(unsigned i=0; i < qtdLinhas; ++i)
		for(unsigned j=0; j < qtdColunas; ++j)
			cin >> matriz[i][j];
}

template<class T> void Matriz<T>::imprimirValores(){
	if(naoEstaAlocado()) return;
	for(unsigned i=0; i < qtdLinhas; ++i){
		for(unsigned j=0; j < qtdColunas; ++j)
			cout << matriz[i][j] << ' ';
		cout << '\n';
	}
}

template<class T> bool Matriz<T>::setElemento(const T newValue, unsigned i, unsigned j){
	return posicaoValida(i,j) && ((matriz[i][j] = newValue) || true);
}

template<class T> T* Matriz<T>::getElemento(unsigned i, unsigned j){
	return posicaoValida(i,j) ? &matriz[i][j] : NULL;
}

template<class T> bool Matriz<T>::celulaIgualA(const T value, unsigned i, unsigned j){
	return posicaoValida(i,j) && (matriz[i][j] == value);
}
